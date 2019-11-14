#include "gamescene.h"
#include "iostream"
#include "core/worldgenerator.h"
#include "tiles/forest.h"
#include "tiles/grassland.h"
#include "mapitem.h"
#include "buildings/headquarters.h"
#include "core/playerbase.h"
#include "core/resourcemaps.h"
#include "core/basicresources.h"

#include "graphics/simplemapitem.h"


#include <QDebug>
#include <QEvent>
#include <QGraphicsSceneMouseEvent>
#include <memory>
#include <stdlib.h>
#include <map>

#include <math.h>

namespace Student {

GameScene::GameScene(QWidget* parent,
                     int width,
                     int height,
                     int scale):
    QGraphicsScene(parent),
    m_mapBoundRect(nullptr),
    m_width(10),
    m_height(10),
    m_scale(80)

{

}

void GameScene::drawGameBoard(unsigned int size_x,
                              unsigned int size_y,

                              unsigned int seed, //randomoidaan jossain kohtaa ja poistetaan parametreista

                              const std::shared_ptr<Student::ObjectManager> &objectmanager,
                              const std::shared_ptr<Student::GameEventHandler> &eventhandler) {

    // asettaa skaalan
    m_scale = 800/size_x;

    seed = rand();

    Course::WorldGenerator& worldGen = Course::WorldGenerator::getInstance();
    worldGen.addConstructor<Course::Forest>(1);
    worldGen.addConstructor<Course::Grassland>(1);
    worldGen.generateMap(size_x, size_y, seed, objectmanager, eventhandler);
    std::vector<std::shared_ptr<Course::TileBase>> tiles = objectmanager->tiili();

    // Prints tiles amount
    std::cout << tiles.size() << std::endl;

    for(auto x: tiles){
        GameScene::drawObject(x);
    }

    std::shared_ptr<Course::PlayerBase> player1 = std::make_shared<Course::PlayerBase>("Pekka");

    std::shared_ptr<Course::HeadQuarters> hq = std::make_shared<Course::HeadQuarters>(eventhandler, objectmanager, player1);

    // tiles.at(0)->addBuilding(hq);
    std::vector<Course::Coordinate> tili;
    tili.push_back(Course::Coordinate(0,0));
    tili.push_back(Course::Coordinate(1,2));
    tili.push_back(Course::Coordinate(6,6));
    for (auto x : objectmanager->getTiles(tili)) {
        std::cout << x->getType();
    }
}

void GameScene::drawObject(std::shared_ptr<Course::GameObject> obj) {

    MapItem* newItem = new MapItem(obj, m_scale);
    addItem(newItem);

}

bool GameScene::event(QEvent *event)
{
    if(event->type() == QEvent::GraphicsSceneMousePress)
    {
        QGraphicsSceneMouseEvent* mouse_event =
                dynamic_cast<QGraphicsSceneMouseEvent*>(event);

        if ( sceneRect().contains(mouse_event->scenePos())){

            QPointF point = mouse_event->scenePos() / m_scale;

            point.rx() = floor(point.rx());
            point.ry() = floor(point.ry());

            QGraphicsItem* pressed = itemAt(point * m_scale, QTransform());

            if ( pressed == m_mapBoundRect ){
                qDebug() << "Click on map area.";
            }else{
                qDebug() << "ObjID: " <<
                            static_cast<Student::MapItem*>(pressed)
                            ->getBoundObject()->ID << " pressed.";
                qDebug() << " - Coordinates: (" <<
                            static_cast<Student::MapItem*>(pressed)
                            ->getBoundObject()->getCoordinate().x() <<
                            "," <<
                            static_cast<Student::MapItem*>(pressed)
                            ->getBoundObject()->getCoordinate().y() << ") pressed.";
                return true;
            }

        }
    }

    return false;
}

void GameScene::reset()
{

}

}
