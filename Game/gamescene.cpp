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
#include "workers/basicworker.h"
#include "game.h"
#include "buildings/farm.h"

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

    //saa signaalin rakennusnapista ja lähettää metodiin rakennuksen nimen (string)
    // metodi muuttaa private muuttujat buildingToAdd (rakennettava rakennus) ja rakennusnappibool (onko raknnusnappia painettu)
    connect(parent, SIGNAL(buildingSignal(std::string)), this, SLOT(addBuilding(std::string)));



}

void GameScene::drawGameBoard(unsigned int size_x,
                              unsigned int size_y,

                              unsigned int seed, //randomoidaan jossain kohtaa ja poistetaan parametreista

                              const std::shared_ptr<Student::ObjectManager> &objectmanager,
                              const std::shared_ptr<Student::GameEventHandler> &eventhandler,
                              const std::shared_ptr<Student::Player>& playerOne,
                              const std::shared_ptr<Student::Player>& playerTwo ) {

    // asettaa skaalan ja kartan koon
    m_width = size_x;
    m_height = size_y;
    m_scale = 800/size_x;
    eventHandler_ = eventhandler;
    objectManager_ = objectmanager;
    playerOne_ = playerOne;
    playerTwo_ = playerTwo;

    seed = rand();


    Course::WorldGenerator& worldGen = Course::WorldGenerator::getInstance();
    worldGen.addConstructor<Course::Forest>(1);
    worldGen.addConstructor<Course::Grassland>(1);
    worldGen.generateMap(m_width, m_height, seed, objectManager_, eventHandler_);
    std::vector<std::shared_ptr<Course::TileBase>> tiles = objectManager_->tiili();

    // Prints tiles amount
    std::cout << tiles.size() << std::endl;

    for(auto x: tiles){
        GameScene::drawObject(x);
    }
    GameScene::generateHeadQuarters();

    std::shared_ptr<Course::BasicWorker> ukko = std::make_shared<Course::BasicWorker>(eventHandler_, objectManager_, playerOne_);
    objectManager_->getTile(44)->setOwner(playerOne_);
    ukko->setOwner(playerOne_);
    objectManager_->getTile(44)->addWorker(ukko);
    GameScene::drawObject(ukko);
    movableObject_ = ukko;




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

                // worker move testing
                auto coor = static_cast<Student::MapItem*>(pressed)->getBoundObject()->getCoordinate();

                auto vec = objectManager_->getTile(coor)->getWorkers();
                qDebug() << vec.size();
                if (vec.size() > 0) {
                    movableObjectSelected_ = true;
                    movableObject_ = vec.at(0);
                } else if (movableObjectSelected_ == true) {
                    objectManager_->getTile(coor)->setOwner(playerOne_);
                    objectManager_->getTile(movableObject_->getCoordinate())->removeWorker(movableObject_);
                    objectManager_->getTile(coor)->addWorker(movableObject_);
                    GameScene::updateItem(movableObject_);
                    movableObjectSelected_ = false;
                    vec.clear();
                    GameScene::updateViewSignal();
                }

                // kun rakennusnappia painaa
                if (buildingButtonClicked == true) {
                    std::cout << "rakennetaan: " << buildingToAdd->getType() << std::endl;
                    objectManager_->getTile(coor)->setOwner(playerOne_);
                    objectManager_->getTile(coor)->addBuilding(buildingToAdd);
                    GameScene::drawObject(buildingToAdd);
                    buildingButtonClicked = false;
                    GameScene::updateViewSignal();


                }


            }
        }
    }

     return QGraphicsScene::event(event);;
}

void GameScene::generateHeadQuarters()
{
    // Randomize the coordinates for the leftside player and mirror the coordinates for rightside player
    int xBoundary = floor(m_width / 5);
    int leftX = floor(rand() % (xBoundary));
    int rightX = m_width - 1 - leftX;
    int leftY = floor(rand() % (m_height));
    int rightY = m_height - 1 - leftY;

    std::shared_ptr<Course::HeadQuarters> hq1 = std::make_shared<Course::HeadQuarters>(eventHandler_, objectManager_, playerOne_);
    objectManager_->getTile(Course::Coordinate(leftX, leftY))->addBuilding(hq1);
    GameScene::drawObject(hq1);

    std::shared_ptr<Course::HeadQuarters> hq2 = std::make_shared<Course::HeadQuarters>(eventHandler_, objectManager_, playerTwo_);
    objectManager_->getTile(Course::Coordinate(rightX, rightY))->addBuilding(hq2);
    GameScene::drawObject(hq2);
}

void GameScene::updateItem(std::shared_ptr<Course::GameObject> obj)
{
    QList<QGraphicsItem*> items_list = items();
    if ( items_list.size() == 1 ){
        qDebug() << "Nothing to update.";
    } else {
        for ( auto item : items_list ){
            MapItem* mapItem = static_cast<MapItem*>(item);
            if (mapItem->isSameObj(obj)){
                mapItem->updateLoc();
            }
        }
    }
}

void GameScene::addBuilding(std::string building)
{
    buildingButtonClicked = true;
    // playerOne tilalle playerInTurn
    buildingToAdd = std::make_shared<Course::Farm>(eventHandler_, objectManager_, playerOne_);


}

void GameScene::reset()
{

}

}
