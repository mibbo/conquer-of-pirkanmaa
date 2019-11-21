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
#include "mountain.hh"
#include "cobblestone.hh"
#include "graphics/simplemapitem.h"
#include "river.hh"
#include "constructionworker.hh"
#include "warrior.hh"
#include "quarry.hh"
#include "mine.hh"
#include "buildings/outpost.h"

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

    connect(parent, SIGNAL(playInTurnSignal(std::shared_ptr<Student::Player>)), this, SLOT(playerInTurnSlot(std::shared_ptr<Student::Player>)));
    playerMovesLeft_ = 3;

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

    // Create the map with worldGenerator
    Course::WorldGenerator& worldGen = Course::WorldGenerator::getInstance();
    worldGen.addConstructor<Course::Forest>(1);
    worldGen.addConstructor<Course::Grassland>(1);
    worldGen.addConstructor<Student::Mountain>(1);
    worldGen.addConstructor<Student::Cobblestone>(1);
    worldGen.generateMap(m_width, m_height, seed, objectManager_, eventHandler_);
    std::vector<std::shared_ptr<Course::TileBase>> tiles = objectManager_->tiili();

    // Prints tiles amount
    std::cout << tiles.size() << std::endl;

    for(auto x: tiles){
        GameScene::drawObject(x);
    }
    GameScene::generateStartingObjects();
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

                // Worker moving
                auto coor = static_cast<Student::MapItem*>(pressed)->getBoundObject()->getCoordinate(); // Coordinate for the pressed object
                auto vec = objectManager_->getTile(coor)->getWorkers(); // Get the vector that has all the workers on the tile (maximum of 1

                // Check if the tile had any of in-turn player's workers
                if (vec.size() > 0 && vec.at(0)->getOwner() == playerInTurn_ && playerMovesLeft_ > 0) {
                    movableObjectSelected_ = true;
                    movableObject_ = vec.at(0);

                // Check if a worker has been "selected" and if the clicked tile has any other workers
                } else if (movableObjectSelected_ == true && objectManager_->getTile(coor)->getWorkers().size() == 0) {
                    // Calculate the distance in tiles that player chose
                    int distance = abs(movableObject_->getCoordinate().x() - coor.x()) +
                            abs(movableObject_->getCoordinate().y() - coor.y());
                    // If the player has enough moves left move the object
                    if (distance <= playerMovesLeft_) {
                        playerMovesLeft_ -= distance;
                        objectManager_->getTile(coor)->setOwner(playerInTurn_);
                        objectManager_->getTile(movableObject_->getCoordinate())->removeWorker(movableObject_);
                        objectManager_->getTile(coor)->addWorker(movableObject_);
                        GameScene::updateItem(movableObject_);
                    } else {
                        qDebug() << "Too far!";
                    }
                    // Clear the player's selection and update the view
                    movableObjectSelected_ = false;
                    vec.clear();
                    GameScene::updateViewSignal();
                }

                // kun rakennusnappia painaa niin rakentaa halutun rakennuksen (temporary variable buildingToAdd)
                // Prevents the player from adding multiple buildings to a single tile.
                if (buildingButtonClicked_ == true && objectManager_->getTile(coor)->getBuildings().size() == 0) {
                    std::cout << "Pelaaja: " << playerInTurn_->getName()<< " --- rakentaa: " << buildingToAdd->getType() << std::endl;
                    objectManager_->getTile(coor)->setOwner(playerInTurn_);
                    objectManager_->getTile(coor)->addBuilding(buildingToAdd);
                    GameScene::drawObject(buildingToAdd);
                    // Tunnistaa, että rakennettavaa paikkaa on painettu -> asettaa false
                    buildingButtonClicked_ = false;
                    GameScene::updateViewSignal();

                }


            }
        }
    }
    emit updateInformationSignal(playerMovesLeft_);
     return QGraphicsScene::event(event);
}

void GameScene::generateStartingObjects()
{
    // Randomize the coordinates for the leftside player and mirror the coordinates for rightside player
    int xBoundary = floor(m_width / 5);
    int leftX = floor(rand() % (xBoundary));
    int rightX = m_width - 1 - leftX;
    int leftY = floor(rand() % (m_height));
    int rightY = m_height - 1 - leftY;

    // Add and draw the HQ's
    std::shared_ptr<Course::HeadQuarters> hq1 = std::make_shared<Course::HeadQuarters>(eventHandler_, objectManager_, playerOne_);
    objectManager_->getTile(Course::Coordinate(leftX, leftY))->addBuilding(hq1);
    GameScene::drawObject(hq1);

    std::shared_ptr<Course::HeadQuarters> hq2 = std::make_shared<Course::HeadQuarters>(eventHandler_, objectManager_, playerTwo_);
    objectManager_->getTile(Course::Coordinate(rightX, rightY))->addBuilding(hq2);
    GameScene::drawObject(hq2);

    // Add and draw the BasicWorkers
    std::shared_ptr<Course::BasicWorker> bw1 = std::make_shared<Course::BasicWorker>(eventHandler_, objectManager_, playerOne_);
    objectManager_->getTile(Course::Coordinate(leftX + 1, leftY))->setOwner(playerOne_);
    objectManager_->getTile(Course::Coordinate(leftX + 1, leftY))->addWorker(bw1);
    GameScene::drawObject(bw1);
    std::shared_ptr<Course::BasicWorker> bw2 = std::make_shared<Course::BasicWorker>(eventHandler_, objectManager_, playerTwo_);
    objectManager_->getTile(Course::Coordinate(rightX - 1, rightY))->setOwner(playerTwo_);
    objectManager_->getTile(Course::Coordinate(rightX - 1, rightY))->addWorker(bw2);
    GameScene::drawObject(bw2);
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
    qDebug() << "asd";
    // poistaa muiden nappien painallukset
    movableObjectSelected_ = false;
    //tunnistaa, että buildingButtonia on painettu->
    buildingButtonClicked_ = true;
    if (building == "Farm") {
        buildingToAdd = std::make_shared<Course::Farm>(eventHandler_, objectManager_, playerInTurn_);
    } else if (building == "Mine") {
        buildingToAdd = std::make_shared<Student::Mine>(eventHandler_, objectManager_, playerInTurn_);
    } else if (building == "Outpost") {
        buildingToAdd = std::make_shared<Course::Outpost>(eventHandler_, objectManager_, playerInTurn_);
    } else if (building == "Quarry") {
        buildingToAdd = std::make_shared<Student::Quarry>(eventHandler_, objectManager_, playerInTurn_);
    }



}
void GameScene::reset()
{
}

void GameScene::playerInTurnSlot(std::shared_ptr<Player> playerInTurn)
{
    playerInTurn_ = playerInTurn;
    playerMovesLeft_ = 3;
    emit updateInformationSignal(playerMovesLeft_);
}

}
