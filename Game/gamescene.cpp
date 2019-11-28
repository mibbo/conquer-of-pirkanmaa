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
#include "sawmill.h"
#include "workers/workerbase.h"

#include <QDebug>
#include <QEvent>
#include <QGraphicsSceneMouseEvent>
#include <memory>
#include <stdlib.h>
#include <map>
#include <QColor>
#include <random>

#include <math.h>

#include <iostream>
#include <cstdlib>
#include <ctime>

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
    srand(time(NULL));

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
    // keskikohta-muuttuja joelle
    int center = m_width/2-1;
    // jokilaatan x muuttuja jota randomoidaan
    int randX = size_x/2-1;

    // käy läpi ruudukon Y-arvot (keskeltä ylös)
    for (int y = m_height/2-1; y >= 0; y--) {
        // käy läpi ruudukon X-arvot (vasemmalta oikealle)
        for (int x = 0; x < m_width; x++) {
            // Kun löytää halutun x arvon --> asettaa jokilaatan siihen
            if (x == randX) {
                for (unsigned long int i = 0; i < tiles.size(); i++) {
                    std::shared_ptr<Course::TileBase> tile1 = objectManager_->getTile(Course::Coordinate(randX, y));
                    std::shared_ptr<Course::TileBase> tile2 = objectManager_->getTile(Course::Coordinate(randX+1, y));
                    std::shared_ptr<Course::TileBase> tileMirror1 = objectManager_->getTile(Course::Coordinate(m_width-x-2, m_height-y-1));
                    std::shared_ptr<Course::TileBase> tileMirror2 = objectManager_->getTile(Course::Coordinate(m_width-x-1, m_height-y-1));
                    if (tiles.at(i) == tile1) {
                        tiles.at(i) = std::make_shared<Student::River>(Course::Coordinate(x,y), eventHandler_, objectManager_);
                    }
                    if (tiles.at(i) == tile2) {
                        tiles.at(i) = std::make_shared<Student::River>(Course::Coordinate(x+1,y), eventHandler_, objectManager_);
                    }
                    if (tiles.at(i) == tileMirror1) {
                        tiles.at(i) = std::make_shared<Student::River>(Course::Coordinate(m_width-x-2,m_height-y-1), eventHandler_, objectManager_);
                    }
                    if (tiles.at(i) == tileMirror2) {
                        tiles.at(i) = std::make_shared<Student::River>(Course::Coordinate(m_width-x-1,m_height-y-1), eventHandler_, objectManager_);
                    }
                }
            }
        }
        // 20% että pysyy paikallaan
        if(rand() <= RAND_MAX * 0.20 or randX < 0 or randX > m_width) {
            continue;
        //jos keskellä niin 50% tsäänssiliikkua sivuille
        }else if (inRange(center-1, center+1, randX)) {
            if(rand() <= RAND_MAX * 0.5 or randX < 0) {
                randX++;
            } else  {
                randX--;
            }
        // jos kaksi tai kolme vasemmalla niin 60% tsäänssi mennä keskemmälle
        }else if (inRange(center-3, center-2, randX)) {
            if(rand() <= RAND_MAX * 0.6) {
                randX++;
            } else  {
                randX--;
            }
        // jos kaksi tai kolme oikealla niin 60& tsäänssi mennä keskemmälle
        }else if (inRange(center+2, center+3, randX)) {
            if(rand() <= RAND_MAX * 0.6  or randX > m_width) {
                randX--;
            } else  {
                randX++;
            }
        // jos neljä vasemmalla niin 70& tsäänssi mennä keskemmälle
        }else if (inRange(center-4, center-4, randX)) {
            if(rand() <= RAND_MAX * 0.7  or randX > m_width) {
                randX--;
            } else  {
                randX++;
            }
        // jos neljä oikealla niin 70& tsäänssi mennä keskemmälle
        }else if (inRange(center+4, center+4, randX)) {
            if(rand() <= RAND_MAX * 0.7  or randX > m_width) {
                randX--;
            } else  {
                randX++;
            }
        // muuuten jos liian lähellä reunaa (yli 5 laattaa keskeltä) niin menee keskemmälle
        } else {
            if (inRange(0, center-5, randX)) {
                randX++;
            } else {
                randX--;
            }
        }
    }
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
//            removeItem(object);
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

                    // lisää HIGHLIGHITIT workeriä painaessa

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
                    // tää esti rakentamisen kun oli jo klikattu const workeriä
                    menuBuildingButtonClicked_ = false;
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
                    if (movableObject_->getType() == "Warrior" &&
                            objectManager_->getTile(coor)->getBuildingCount() == 1 &&
                            objectManager_->getTile(coor)->getBuildings().at(0)->getType() == "HeadQuarters" &&
                            objectManager_->getTile(coor)->getBuildings().at(0)->getOwner() != playerInTurn_) {
                        emit gameOverSignal(playerInTurn_);
                    }
                    // Clear the player's selection and update the view
                    movableObjectSelected_ = false;
                    vec.clear();
                    GameScene::updateViewSignal();

                // Check if two opponent warriors meet
                } else if (movableObjectSelected_ == true && objectManager_->getTile(coor)->getWorkers().size() == 1
                           && objectManager_->getTile(coor)->getWorkers().at(0)->getType() == "Warrior"
                           && movableObject_->getType() == "Warrior"
                           && objectManager_->getTile(coor)->getWorkers().at(0)->getOwner() != playerInTurn_
                           && (abs(movableObject_->getCoordinate().x() - coor.x()) +
                               abs(movableObject_->getCoordinate().y() - coor.y())) <= playerMovesLeft_) {

                    // Remove the moves from player
                    playerMovesLeft_ -= (abs(movableObject_->getCoordinate().x() - coor.x()) +
                            abs(movableObject_->getCoordinate().y() - coor.y()));

                    // Create a vector with both players' vectors to randomize the battle's winner
                    // with a weight on player's owned tiles
                    auto playerOneTiles = playerOne_->getTiles();
                    auto playerTwoTiles = playerTwo_->getTiles();
                    playerOneTiles.insert(playerOneTiles.end(), playerTwoTiles.begin(), playerTwoTiles.end());

                    // Create the neccessary pointers
                    std::shared_ptr<Student::Player> winner = nullptr;
                    std::shared_ptr<Student::Warrior> warrior1 = nullptr;
                    std::shared_ptr<Student::Warrior> warrior2 = nullptr;

                    // Set the pointers to right players' warriors
                    if (objectManager_->getTile(coor)->getWorkers().at(0)->getOwner() == playerOne_) {
                        warrior1 = std::dynamic_pointer_cast<Student::Warrior>(objectManager_->getTile(coor)->getWorkers().at(0));
                        warrior2 = std::dynamic_pointer_cast<Student::Warrior>(movableObject_);
                    } else {
                        warrior1 = std::dynamic_pointer_cast<Student::Warrior>(movableObject_);
                        warrior2 = std::dynamic_pointer_cast<Student::Warrior>(objectManager_->getTile(coor)->getWorkers().at(0));
                    }

                    // Loop until one of the warriors dies
                    while (true) {
                        // Randomize the damage taking warrior by getting a random tile from the vector with both players' tiles
                        // and then check its owner
                        int randNum = rand()%(playerOneTiles.size());
                        if (playerOneTiles.at(randNum)->getOwner() == playerOne_) {
                            warrior2->setHitPoints(warrior2->getHitPoints() - 1);
                        } else {
                            warrior1->setHitPoints(warrior1->getHitPoints() - 1);
                        }
                        // Break when either one of the warriors has died
                        if (warrior2->getHitPoints() <= 0) {
                            winner = playerOne_;
                            break;
                        }
                        if (warrior1->getHitPoints() <= 0) {
                            winner = playerTwo_;
                            break;
                        }
                    }

                    // If winning player was the player in turn, move the object to the new tile and remove the
                    // other player's warrior
                    if (winner == playerInTurn_) {
                        auto realTileOwner = objectManager_->getTile(coor)->getOwner();
                        auto worker = objectManager_->getTile(coor)->getWorkers().at(0);
                        objectManager_->getTile(coor)->removeWorker(worker);
                        objectManager_->getTile(coor)->setOwner(playerInTurn_);
                        objectManager_->getTile(movableObject_->getCoordinate())->removeWorker(movableObject_);
                        objectManager_->getTile(coor)->addWorker(movableObject_);
                        objectManager_->getTile(coor)->setOwner(realTileOwner);
                        GameScene::updateItem(movableObject_);
                        GameScene::removeItem(worker);
                        GameScene::updateViewSignal();
                    // Otherwise just simply remove the in turn player's warrior
                    } else {
                        objectManager_->getTile(movableObject_->getCoordinate())->removeWorker(movableObject_);
                        GameScene::removeItem(movableObject_);
                        GameScene::updateViewSignal();
                    }
                    movableObjectSelected_ = false;
                } else {
                    movableObjectSelected_ = false;
                }

                // kun rakennusnappia painaa niin rakentaa halutun rakennuksen (temporary variable buildingToAdd)
                // Prevents the player from adding multiple buildings to a single tile.
                if (menuBuildingButtonClicked_ == true && objectManager_->getTile(coor)->getBuildings().size() == 0 &&
                        objectManager_->getTile(coor)->getOwner() == playerInTurn_ &&
                        BuildingTileIsCorrect(buildingToAdd_, objectManager_->getTile(coor)) == true &&
                        playerInTurn_->modifyResources(buildingToAdd_->BUILD_COST) == true
                        ) {

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
                    std::vector<std::shared_ptr<Course::GameObject>> tiles;
                    if (buildingToAdd_->getType() == "Outpost") {
                        tiles = objectManager_->getNeighbourTiles(buildingToAdd_, 3);
                    } else {
                        tiles = objectManager_->getNeighbourTiles(buildingToAdd_);

                    }
                    playerInTurn_->addTiles(tiles);
                    GameScene::updateAndDrawTileOwners();

                    // TULOSTAA puuttuvien resurssien määrän
                } else if (menuBuildingButtonClicked_ == true && objectManager_->getTile(coor)->getBuildings().size() == 0 /*&& playerInTurn_->modifyResources(buildingToAdd_->BUILD_COST) == false*/) {
                    std::cout <<  playerInTurn_->getName() << " ei pysty rakentamaan ";
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


// tarkistaa voiko rakentaa kyseistä rakennusta valitulle tiilelle ja että onko siinä construction workkeriä
bool GameScene::BuildingTileIsCorrect(std::shared_ptr<Course::GameObject> building, std::shared_ptr<Course::TileBase> tile)
{
    if (tile->getWorkerCount() == 0) {
        return false;
    } else if (tile->getWorkers().at(0)->getType() == "ConstructionWorker"){
        bool wasCorrectTile = false;
       if (building->getType() == "Farm" && tile->getType() == "Grassland") {
           wasCorrectTile = true;
       } else if (building->getType() == "Mine" && tile->getType() == "Mountain") {
           wasCorrectTile = true;
       }else if (building->getType() == "Quarry" && tile->getType() == "Cobblestone") {
           wasCorrectTile = true;
       }else if (building->getType() == "Sawmill" && tile->getType() == "Forest") {
           wasCorrectTile = true;
       }else if (building->getType() == "Outpost") {
           wasCorrectTile = true;
       }

       if (wasCorrectTile) {
           movableObjectSelected_ = false;
           // poistaa mahdollisten liikkeiden paikat
           for (auto object : possibleMovementTiles_) {
//               removeItem(object);
               delete object;
           }
           possibleMovementTiles_.clear();
           return true;
       }
    }

    return false;
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
//        removeItem(object);
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
    } else if (buttonString == "Sawmill") {
        menuBuildingButtonClicked_ = true;
        buildingToAdd_ = std::make_shared<Student::Sawmill>(eventHandler_, objectManager_, playerInTurn_);
    // Workers
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
                } else if (building->getType() == "Sawmill") {
                    playerInTurn_->modifyResources(Student::ConstResourceMaps::SAWMILL_PRODUCTION);
                }
            }
        }
    }
}

bool GameScene::inRange(int low, int high, int x)
{
    return ((x-high)*(x-low) <= 0);
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
//        removeItem(object);
        delete object;
    }
    possibleMovementTiles_.clear();

    generateResources();
}

void GameScene::removeItem(std::shared_ptr<Course::GameObject> obj)
{
    QList<QGraphicsItem*> items_list = items();
    if ( items_list.size() == 1 ){
        qDebug() << "Nothing to be removed at the location pointed by given obj.";
    } else {
        for ( auto item : items_list ){
            Student::MapItem* mapitem = static_cast<Student::MapItem*>(item);
            if ( mapitem->isSameObj(obj) ){
                delete mapitem;
            }
        }
    }
}

}
