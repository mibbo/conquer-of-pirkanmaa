#include "game.h"
#include "ui_game.h"
#include "mapitem.h"
#include "startwindow.h"

#include "tiles/forest.h"
#include "tiles/grassland.h"

#include <QDebug>
#include <iostream>

#include <math.h>
#include <memory>
#include <iostream>

Game::Game(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::Game),
    eveHandler_(std::make_shared<Student::GameEventHandler>()),
    gameScene_(new Student::GameScene(this)),
    objManager_(std::make_shared<Student::ObjectManager>())
{
    ui->setupUi(this);



    // StartWindow
    dialoq_ = new StartWindow();
    connect(dialoq_, SIGNAL(startGame(int, unsigned int, unsigned int, QString,  QString)),
            this, SLOT(startGameSlot(int, unsigned int, unsigned int,  QString,  QString)));
    dialoq_->exec();

    Game::showMaximized();
    gameScene_->setSceneRect(0,0,795,795);
    ui->graphicsView->setFixedSize(805,805);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setAlignment(Qt::AlignTop|Qt::AlignLeft);
    //ui->graphicsView->centerOn()

    // GameScene
    Student::GameScene* sgs_rawptr = gameScene_.get();
    ui->graphicsView->setScene(dynamic_cast<QGraphicsScene*>(sgs_rawptr));

    displayMainMenu();


}

Game::~Game()
{
    delete ui;
}

std::shared_ptr<Student::Player> Game::getTurn()
{
    return playerInTurn_;
}

void Game::setTurn(std::shared_ptr<Student::Player> player)
{

    playerInTurn_ = player;
    ui->turnLabel->setText("Turn: " + QString::fromStdString(playerInTurn_->getName()));
    std::cout << "Turn: " << playerInTurn_->getName() << std::endl;

}

void Game::changeTurn()
{
    playerInTurn_->getName();

    if(getTurn() == playerTwo_) {
        setTurn(playerOne_);
    } else {
        setTurn(playerTwo_);
    }
}



void Game::setupPlayers(QString playerOneName, QString playerTwoName)
{
    playerOne_ = std::make_shared<Student::Player>(playerOneName.toStdString());
    playerOne_->setName(playerOneName.toStdString());
    playerTwo_ = std::make_shared<Student::Player>(playerTwoName.toStdString());
    playerTwo_->setName(playerTwoName.toStdString());

    std::cout << "p1: " << playerOne_->getName()<< std::endl;
    std::cout << "p2: " << playerTwo_->getName()<< std::endl;
    setTurn(playerOne_);
}

void Game::displayMainMenu()
{
    qDebug() << "displaymainemenu";
}

void Game::startGameSlot(int playerAmount, unsigned int mapWidth, unsigned int mapHeight, QString playerOneName, QString playerTwoName)
{
    setupPlayers(playerOneName, playerTwoName);
    gameScene_->drawGameBoard(mapWidth, mapHeight, 2, objManager_, eveHandler_);
}


void Game::on_turnButton_clicked()
{
    changeTurn();
}

