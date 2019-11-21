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

    connect(sgs_rawptr, SIGNAL(updateViewSignal()), this, SLOT(updateViewSlot()));

    //add buildingButtons to vector
//    buildingButtons_.push_back());
//    buildingButtons_->push_back();
//    buildingButtons_.push_back()
    buildingButtons_.push_back(ui->farmButton);
    buildingButtons_.push_back(ui->mineButton);
    buildingButtons_.push_back(ui->outpostButton);
    buildingButtons_.push_back(ui->quarryButton);

    for (unsigned long i=0; i<buildingButtons_.size(); ++i) {
        qDebug() << "button: " << buildingButtons_.at(i);

    }

    //for (ui->buildingsLayout->itemAt(0); ) {
    qDebug() << "layout: " << ui->buildingsLayout->count();
    qDebug() << "farmibutton: " << ui->farmButton->text();


//    // käy gridlayoutin läpi ja tulostaa
//    for (int i = 0; i < ui->buildingsLayout->count(); ++i) {
//        qDebug() << "button: " << ui->buildingsLayout->itemAt(i);
//        //buildingButtons_.push_back(ui->buildingsLayout->itemAt(i));
//    }






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

void Game::updateView()
{
    update();
}

void Game::startGameSlot(int playerAmount, unsigned int mapWidth, unsigned int mapHeight, QString playerOneName, QString playerTwoName)
{
    setupPlayers(playerOneName, playerTwoName);
    gameScene_->drawGameBoard(mapWidth, mapHeight, 2, objManager_, eveHandler_, playerOne_, playerTwo_);
}

void Game::updateViewSlot()
{
    ui->graphicsView->viewport()->update();
}


void Game::on_turnButton_clicked()
{
    changeTurn();
}


void Game::on_farmButton_clicked()
{
    emit buildingSignal("Farm");
    qDebug() << ui->farmButton->text();
}
