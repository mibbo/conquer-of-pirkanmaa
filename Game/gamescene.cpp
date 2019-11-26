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
#include "workers/basicworker.h"
#include "constructionworker.hh"
#include "warrior.hh"
#include "resourcemaps.hh"

#include <QDebug>
#include <QEvent>
#include <QGraphicsSceneMouseEvent>
#include <memory>
#include <stdlib.h>
#include <map>
#include <QColor>

#include <math.h>

#define stringify( name ) # name

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
    connect(parent, SIGNAL(buildingSignal(std::string)), this, SLOT(addButtonObject(std::string)));





    connect(parent, SIGNAL(playInTurnSignal(std::shared_ptr<Student::Player>)), this, SLOT(playerInTurnSlot(std::shared_ptr<Student::Player>)));
    playerMovesLeft_ = 5;

}

void GameScene::drawGameBoard(unsigned int size_x,
                              unsigned int size_y,

                              unsigned int seed, //randomoidaan jossain kohtaa ja poistetaan parametreista

                              const std::shared_ptr<Student::ObjectManager> &objectmanager,
                              const std::shared_ptr<Student::GameEventHandler> &eventhandler,
                              const std::shared_ptr<Student::Player>& playerOne,
                              const std::shared_ptr<Student::Player>& playerTwo ) {

    // Set scale, eventhandler, objectmanager and players
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

void GameScene::drawObject(std::shared_ptr<Course::GameObject> obj, QColor color) {

    MapItem* newItem = new MapItem(obj, m_scale, color);
    addItem(newItem);
}

bool GameScene::event(QEvent *event)
{
    if(event->type() == QEvent::GraphicsSceneMousePress)
    {
        for (auto object : possibleMovementTiles_) {
            removeItem(object);
            delete object;
        }
        possibleMovementTiles_.clear();

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

                    // Possible moving directions

                    for (int y = playerMovesLeft_; y >= -playerMovesLeft_; y--) {
                        for (int x = playerMovesLeft_ - abs(y); x >= -(playerMovesLeft_ - abs(y)); x--) {
                            int x_coor = movableObject_->getCoordinate().x() + x;
                            int y_coor = movableObject_->getCoordinate().y() + y;
                            std::cout << x_coor << y_coor << std::endl;
                            auto coor = Course::Coordinate(x_coor, y_coor);
                            if (x_coor >= 0 && y_coor >= 0 && x_coor <= m_width - 1 && y_coor <= m_height - 1
                                    && movableObject_->getCoordinate() != coor
                                    && objectManager_->getTile(coor)->getWorkerCount() == 0) {
                                QPointF point(coor.x(), coor.y());
                                auto graphitems = items(point * m_scale);
                                auto graphitem = graphitems.at(graphitems.size()-1);
                                auto boundrect = static_cast<Student::MapItem*>(graphitem)->boundingRect();
                                auto movementrect = this->addRect(QRect(boundrect.x(),
                                                     boundrect.y(),
                                                     boundrect.width()-3,
                                                     boundrect.height()-3),
                                              QPen(),
                                              QBrush(playerInTurn_->getColor(), Qt::Dense3Pattern));
                                possibleMovementTiles_.push_back(movementrect);
                            }
                        }
                    }

                // Check if a worker has been "selected" and if the clicked tile has any other workers
                } else if (movableObjectSelected_ == true && objectManager_->getTile(coor)->getWorkers().size() == 0) {
                    // Calculate the distance in tiles that player chose
                    int distance = abs(movableObject_->getCoordinate().x() - coor.x()) +
                            abs(movableObject_->getCoordinate().y() - coor.y());
                    // If the player has enough moves left move the object
                    if (distance <= playerMovesLeft_) {
                        playerMovesLeft_ -= distance;
                        auto realTileOwner = objectManager_->getTile(coor)->getOwner();
                        objectManager_->getTile(coor)->setOwner(playerInTurn_);
                        objectManager_->getTile(movableObject_->getCoordinate())->removeWorker(movableObject_);
                        objectManager_->getTile(coor)->addWorker(movableObject_);
                        objectManager_->getTile(coor)->setOwner(realTileOwner);
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
                if (menuBuildingButtonClicked_ == true && objectManager_->getTile(coor)->getBuildings().size() == 0 &&
                        objectManager_->getTile(coor)->getOwner() == playerInTurn_ &&
                        playerInTurn_->modifyResources(buildingToAdd_->BUILD_COST) == true) {
                    std::cout <<  playerInTurn_->getName() << "Resources: " << std::endl;

                    for (auto resource : playerInTurn_->getResources()) {
                        std::cout << resource.first << ": " << resource.second << std::endl;
                    }
                    std::cout << "Pelaaja: " << playerInTurn_->getName()<< " --- rakentaa: " << buildingToAdd_->getType() << std::endl;
                    objectManager_->getTile(coor)->addBuilding(buildingToAdd_);
                    //asettaa pelaajan tietoihin rakennuksen
                    playerInTurn_->addObject(buildingToAdd_);
                    GameScene::drawObject(buildingToAdd_, playerInTurn_->getColor());
                    // Tunnistaa, että rakennettavaa paikkaa on painettu -> asettaa false
                    menuBuildingButtonClicked_ = false;
                    GameScene::updateViewSignal();

                    // saa tarvittavat laatat (naapurit + rakennuksen laatta)
                    std::vector<std::shared_ptr<Course::GameObject>> tiles = objectManager_->getNeighbourTiles(buildingToAdd_);
                    playerInTurn_->addTiles(tiles);
                    GameScene::updateAndDrawTileOwners();

                    // TULOSTAA puuttuvien resurssien määrän
                } else if (menuBuildingButtonClicked_ == true && objectManager_->getTile(coor)->getBuildings().size() == 0 /*&& playerInTurn_->modifyResources(buildingToAdd_->BUILD_COST) == false*/) {
                    std::cout <<  playerInTurn_->getName() << " ei pygee rakentaa ko ";
                    if (playerInTurn_->getName() == "mibbo") {
                        std::cout << playerInTurn_->getName() << " on niin jumala, et sen ei tarvi rakentaa tommotteisii paskahuussei" << std::endl;
                    } else if (playerInTurn_->getName() == "brutus") {
                        std::cout << playerInTurn_->getName() << " on niin vammane, känsärunkku, kyrpäyrjö, kullilutka ja persaukine luuskapillu et ei osaa ees vittu pelaa" << std::endl;
                    }
                    const char* resourceNames[] =
                      {
                      stringify( Money ),
                      stringify( Food ),
                      stringify( Wood ),
                      stringify( Stone ),
                      stringify( Ore )
                      };
                    for (auto resource : playerInTurn_->getResources()) {
                        for (auto cost : buildingToAdd_->BUILD_COST) {
                            if (resource.first == cost.first && resource.second < cost.second) {
                                std::cout << "resurssia " << resourceNames[cost.first-1] << " puuttuu: " << cost.second-resource.second << " yksikköä" << std::endl;
                            }
                        }
                    }
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
    GameScene::drawObject(hq1, playerOne_->getColor());
    playerOne_->addObject(hq1);
    playerOne_->addTiles(objectManager_->getNeighbourTiles(hq1));

    std::shared_ptr<Course::HeadQuarters> hq2 = std::make_shared<Course::HeadQuarters>(eventHandler_, objectManager_, playerTwo_);
    objectManager_->getTile(Course::Coordinate(rightX, rightY))->addBuilding(hq2);
    GameScene::drawObject(hq2, playerTwo_->getColor());
    playerTwo_->addObject(hq2);
    playerTwo_->addTiles(objectManager_->getNeighbourTiles(hq2));

    // Add and draw the BasicWorkers
    std::shared_ptr<Course::BasicWorker> bw1 = std::make_shared<Course::BasicWorker>(eventHandler_, objectManager_, playerOne_);
    objectManager_->getTile(Course::Coordinate(Course::Coordinate(leftX, leftY), Course::Direction::E))->setOwner(playerOne_);
    objectManager_->getTile(Course::Coordinate(Course::Coordinate(leftX, leftY), Course::Direction::E))->addWorker(bw1);
    GameScene::drawObject(bw1, playerOne_->getColor());
    playerOne_->addObject(bw1);
    
    std::shared_ptr<Course::BasicWorker> bw2 = std::make_shared<Course::BasicWorker>(eventHandler_, objectManager_, playerTwo_);
    objectManager_->getTile(Course::Coordinate(Course::Coordinate(rightX, rightY), Course::Direction::W))->setOwner(playerTwo_);
    objectManager_->getTile(Course::Coordinate(Course::Coordinate(rightX, rightY), Course::Direction::W))->addWorker(bw2);
    GameScene::drawObject(bw2, playerTwo_->getColor());
    playerTwo_->addObject(bw2);

    //Test
    GameScene::updateAndDrawTileOwners();
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


std::shared_ptr<Course::GameObject> GameScene::returnPlayerObject(std::string objectName)  // tähän olis voinu asettaa mahdollisuudeksi laittaa myös player parametriksi: player = playerInTurn_, mutta paska ei toiminu ulisee vaa jotai
{
    for (auto object : playerInTurn_->getObjects()) {
        if (object->getType() == objectName)
            return object;
    }
}

void GameScene::addButtonObject(std::string buttonString)
{
    // DEBUG honmaa
    // tulostaa pelaajan omistamat objektit
    if (playerInTurn_->getObjects().size() == 0) {
        std::cout << "pelaajalla " << playerInTurn_->getName() << " ei objekteja" << std::endl;
    } else {
        std::cout << playerInTurn_->getName() << " -- Objects: ";
        for (auto object : playerInTurn_->getObjects()) {
            std::cout << "ID:" << object->ID << object->getType() << ", ";
//-----------------------------------------------------------------------------------------------
              // asettaa objektille uuden descriptionin ja tulostaa sen
//            object->setDescription("on", "kiva");
//            for (auto desc : object->getDescriptions()) {
//                std::cout << "      desc: " << desc.first << " - " << desc.second << std::endl;
//            }
            //std::cout << "ID:" << object->getDescriptions() << object->getType() << ", ";
//-----------------------------------------------------------------------------------------------


        }
        std::cout << std::endl;
    }

    // poistaa muiden nappien painallukset
    movableObjectSelected_ = false;
    menuBuildingButtonClicked_ = false;

    // poistaa mahdollisten liikkeiden paikat
    for (auto object : possibleMovementTiles_) {
        removeItem(object);
        delete object;
    }
    possibleMovementTiles_.clear();
    //tunnistaa, että buildingButtonia on painettu->
    // Buildings
    if (buttonString == "Farm") {
        menuBuildingButtonClicked_ = true;
        buildingToAdd_ = std::make_shared<Course::Farm>(eventHandler_, objectManager_, playerInTurn_);
    } else if (buttonString == "Mine") {
        menuBuildingButtonClicked_ = true;
        buildingToAdd_ = std::make_shared<Student::Mine>(eventHandler_, objectManager_, playerInTurn_);
    } else if (buttonString == "Outpost") {
        menuBuildingButtonClicked_ = true;
        buildingToAdd_ = std::make_shared<Course::Outpost>(eventHandler_, objectManager_, playerInTurn_);
    } else if (buttonString == "Quarry") {
        menuBuildingButtonClicked_ = true;
        buildingToAdd_ = std::make_shared<Student::Quarry>(eventHandler_, objectManager_, playerInTurn_);
    // Workers
        //pitää tehä näihin erikseen että addaa ne HQ läheisyyteen
    } else if (buttonString == "Basic Worker") {
        workerToAdd_ = std::make_shared<Course::BasicWorker>(eventHandler_, objectManager_, playerInTurn_);
        //etsii spawnauspaikan(hq) coordinaatit
        Course::Coordinate hqCoordinates = returnPlayerObject("HeadQuarters")->getCoordinate();

        // etsii lähimmän mahdollisen koordinaatin
        objectManager_->getTile(hqCoordinates)->setOwner(playerInTurn_);
        objectManager_->getTile(hqCoordinates)->addWorker(workerToAdd_);
        GameScene::drawObject(workerToAdd_, playerInTurn_->getColor());
        playerInTurn_->addObject(workerToAdd_);


    } else if (buttonString == "Construction Worker") {
        workerToAdd_ = std::make_shared<Student::ConstrutionWorker>(eventHandler_, objectManager_, playerInTurn_);

        Course::Coordinate hqCoordinates = returnPlayerObject("HeadQuarters")->getCoordinate();
        objectManager_->getTile(hqCoordinates)->setOwner(playerInTurn_);
        objectManager_->getTile(hqCoordinates)->addWorker(workerToAdd_);
        GameScene::drawObject(workerToAdd_, playerInTurn_->getColor());
        playerInTurn_->addObject(workerToAdd_);


    } else if (buttonString == "Warrior") {
        workerToAdd_ = std::make_shared<Student::Warrior>(eventHandler_, objectManager_, playerInTurn_);

        Course::Coordinate hqCoordinates = returnPlayerObject("HeadQuarters")->getCoordinate();
        objectManager_->getTile(hqCoordinates)->setOwner(playerInTurn_);
        objectManager_->getTile(hqCoordinates)->addWorker(workerToAdd_);
        GameScene::drawObject(workerToAdd_, playerInTurn_->getColor());
        playerInTurn_->addObject(workerToAdd_);

    }
}
void GameScene::reset()
{
}

void GameScene::updateAndDrawTileOwners()
{
    for (auto tile : playerOne_->getTiles()) {
        tile->setOwner(playerOne_);
        auto coor = tile->getCoordinate();
        QPointF point(coor.x(), coor.y());
        auto graphitems = items(point * m_scale);
        auto graphitem = graphitems.at(graphitems.size()-1);
        static_cast<Student::MapItem*>(graphitem)->drawOwnership(playerOne_->getColor());
    }

    for (auto tile : playerTwo_->getTiles()) {
        tile->setOwner(playerTwo_);
        auto coor = tile->getCoordinate();
        QPointF point(coor.x(), coor.y());
        auto graphitems = items(point * m_scale);
        auto graphitem = graphitems.at(graphitems.size()-1);
        static_cast<Student::MapItem*>(graphitem)->drawOwnership(playerTwo_->getColor());
    }
}

void GameScene::generateResources()
{
    for (auto object : playerInTurn_->getObjects()) {
        if (object->getType() == "BasicWorker") {
            auto buildingVector =
                    objectManager_->getTile(object->getCoordinate())->getBuildings();
            if (buildingVector.size() > 0) {
                auto building = buildingVector.at(0);
                if (building->getType() == "Farm") {
                    playerInTurn_->modifyResources(Student::ConstResourceMaps::FARM_PRODUCTION);
                } else if (building->getType() == "Mine") {
                    playerInTurn_->modifyResources(Student::ConstResourceMaps::MINE_PRODUCTION);
                } else if (building->getType() == "Quarry") {
                    playerInTurn_->modifyResources(Student::ConstResourceMaps::QUARRY_PRODUCTION);
                }
            }
        }
    }
}

void GameScene::playerInTurnSlot(std::shared_ptr<Player> playerInTurn)
{
    playerInTurn_ = playerInTurn;
    playerMovesLeft_ = 5;
    emit updateInformationSignal(playerMovesLeft_);

    // poistaa muiden nappien painallukset
    movableObjectSelected_ = false;
    menuBuildingButtonClicked_ = false;

    // poistaa mahdollisten liikkeiden paikat
    for (auto object : possibleMovementTiles_) {
        removeItem(object);
        delete object;
    }
    possibleMovementTiles_.clear();

    generateResources();
}

}
