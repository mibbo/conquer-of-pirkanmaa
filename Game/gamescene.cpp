#include "gamescene.h"
#include "iostream"
#include "mapitem.h"

#include "graphics/simplemapitem.h"
#include "gameeventhandler.hh"
#include "objectmanager.hh"
#include "core/worldgenerator.h"
#include "tiles/forest.h"
#include "tiles/grassland.h"

namespace Student {

GameScene::GameScene()
{

}

void GameScene::drawGameBoard(int x, int y)
{
    Course::WorldGenerator& worldGen = Course::WorldGenerator::getInstance();
    worldGen.addConstructor<Course::Forest>(1);
    worldGen.addConstructor<Course::Grassland>(1);
    worldGen.generateMap(3,3,2, ObjManager_, m_GEHandler);
    std::vector<std::shared_ptr<Course::TileBase>> tiles = ObjManager_->tiili();
    std::cout<< tiles.size()<<   std::endl;
    for(auto x: tiles){
        GameScene::drawItem(x);

    }
}

void GameScene::drawItem( std::shared_ptr<Course::GameObject> obj)
{

    MapItem *box = new MapItem();
    addItem(box);
    //MapItem* nItem = new SimpleMapItem(obj, m_scale);
    //addItem(nItem);
}

void GameScene::reset()
{

}

}
