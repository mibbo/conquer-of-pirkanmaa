#include "gamescene.h"
#include "iostream"
#include "core/worldgenerator.h"
#include "tiles/forest.h"
#include "tiles/grassland.h"
#include "mapitem.h"

#include "graphics/simplemapitem.h"



#include <QEvent>
#include <QGraphicsSceneMouseEvent>
#include <memory>

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
    m_scale(50)

{

}

void GameScene::drawGameBoard(unsigned int size_x,
                              unsigned int size_y,
                              unsigned int seed, //randomoidaan jossain kohtaa
                              const std::shared_ptr<ObjectManager> &objectmanager,
                              const std::shared_ptr<Course::iGameEventHandler> &eventhandler) {

    Course::WorldGenerator& worldGen = Course::WorldGenerator::getInstance();
    worldGen.addConstructor<Course::Forest>(1);
    worldGen.addConstructor<Course::Grassland>(1);
    worldGen.generateMap(size_x, size_y, 2, objectmanager, eventhandler);
    std::vector<std::shared_ptr<Course::TileBase>> tiles = objectmanager->tiili();
    std::cout << tiles.size() << std::endl;

    for(auto x: tiles){
        GameScene::drawObject(x);
    }


}

void GameScene::drawObject(std::shared_ptr<Course::GameObject> obj) {

    MapItem* newItem = new MapItem(obj, m_scale);
    addItem(newItem);

}

void GameScene::reset()
{

}

}
