#include "game.h"
#include "ui_game.h"
#include "mapitem.h"
#include "startwindow.h"

#include "tiles/forest.h"
#include "tiles/grassland.h"


#include <math.h>
#include <memory>
#include <iostream>

Game::Game(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::Game),
    eveHandler_(std::shared_ptr<Course::iGameEventHandler>()),
    gameScene_(new Student::GameScene(this)),
    objManager_(std::make_shared<Student::ObjectManager>())
{
    ui->setupUi(this);



    // StartWindow
    dialoq_ = new StartWindow();
    connect(dialoq_, SIGNAL(startGame(int, unsigned int, unsigned int)), this, SLOT(startGameSlot(int, unsigned int, unsigned int)));
    dialoq_->exec();

    Game::showMaximized();
    ui->graphicsView->setFixedSize(1400,800);
    gameScene_->setSceneRect(0,0,1400,800);

    // GameScene
    Student::GameScene* sgs_rawptr = gameScene_.get();
    ui->graphicsView->setScene(dynamic_cast<QGraphicsScene*>(sgs_rawptr));


    // singe tile test
    //
    //MapItem *box = new MapItem();
    //gameScene_->addItem(box);

}

Game::~Game()
{
    delete ui;
}

void Game::startGameSlot(int playerAmount, unsigned int mapWidth, unsigned int mapHeight)
{
    gameScene_->drawGameBoard(mapWidth, mapHeight, 2, objManager_, eveHandler_);
}

