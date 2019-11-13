#include "game.h"
#include "ui_game.h"
#include "mapitem.h"
#include "startwindow.h"

#include "gameeventhandler.hh"
#include "objectmanager.hh"
#include "core/worldgenerator.h"
#include "tiles/forest.h"
#include "tiles/grassland.h"

#include <math.h>
#include <memory>
#include <iostream>


Game::Game(QWidget *parent,
           std::shared_ptr<Course::iGameEventHandler> handler)
    : QMainWindow(parent)
    , ui(new Ui::Game)

    // create new EventHandler
    , m_GEHandler(handler)

    // create new ObjectManager
    , ObjManager_(std::make_shared<Student::ObjectManager>())
{
    ui->setupUi(this);


    // startwindow stuff
    dialoq_ = new StartWindow();
    connect(dialoq_, SIGNAL(startGame(int, int, int)), this, SLOT(startGameSlot(int, int, int)));
    dialoq_->exec();

    gameScene_ = new Student::GameScene();




    // set up the scene
    ui->graphicsView->setScene(&scene_);

    MapItem *box = new MapItem();
    scene_.addItem(box);


}

Game::~Game()
{
    delete ui;
}

void Game::startGameSlot(int playerAmount, int mapWidth, int mapHeight)
{
    gameScene_->drawGameBoard(mapWidth, mapHeight);
}

