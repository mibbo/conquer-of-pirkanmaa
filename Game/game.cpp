#include "game.h"
#include "ui_game.h"
#include "mapitem.h"
#include "startwindow.h"

Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);


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

