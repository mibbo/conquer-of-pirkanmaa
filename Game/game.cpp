#include "game.h"
#include "ui_game.h"
#include "mapitem.h"

Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);

    // set up the scene
    ui->graphicsView->setScene(&scene_);

    MapItem *box = new MapItem();
    scene_.addItem(box);

}

Game::~Game()
{
    delete ui;
}

