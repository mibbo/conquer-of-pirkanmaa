#include "game.h"
#include "ui_game.h"
#include "mapitem.h"
#include "startwindow.h"
#include "core/basicresources.h"

#include "tiles/forest.h"
#include "tiles/grassland.h"

#include <QDebug>
#include <iostream>

#include <math.h>
#include <memory>
#include <iostream>

#include <QWidget>

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
    connect(dialoq_, SIGNAL(startGame(unsigned int, unsigned int, QString,  QString, QColor, QColor)),
            this, SLOT(startGameSlot(unsigned int, unsigned int,  QString,  QString, QColor, QColor)));
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
    connect(sgs_rawptr, SIGNAL(updateInformationSignal(int)), this, SLOT(updateInformationSlot(int)));

    //tekee ja piirtää UI setit (nappulat summuut)
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
    emit playInTurnSignal(playerInTurn_);
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
    //add buildingButtons to vector
    buildingButtons_.push_back(ui->farmButton);
    buildingButtons_.push_back(ui->mineButton);
    buildingButtons_.push_back(ui->outpostButton);
    buildingButtons_.push_back(ui->quarryButton);
    //
    connectButtons();
}

void Game::updateView()
{
    update();
}

void Game::printButtonText() {
    QObject* sender = QObject::sender();
      if (sender != NULL) {
        QAbstractButton* button = dynamic_cast<QAbstractButton*>(sender);
        if (button != NULL) {
          qDebug() << button->text();
          //emits buildingButtons name
          emit buildingSignal(button->text().toStdString());
        }
      }
}

void Game::updateInformationSlot(int movesLeft)
{
    Course::ResourceMap resources = playerInTurn_->getResources();
    ui->moves->display(movesLeft);
    ui->money->display(resources[Course::MONEY]);
    ui->food->display(resources[Course::FOOD]);
    ui->wood->display(resources[Course::WOOD]);
    ui->stone->display(resources[Course::STONE]);
    ui->ore->display(resources[Course::ORE]);
}

void Game::connectButtons() {
    for (unsigned long i=0; i<buildingButtons_.size(); ++i) {
      qDebug() << "button: " << buildingButtons_.at(i);
      connect(buildingButtons_[i], SIGNAL(clicked()), this, SLOT(printButtonText()));
    }
}

void Game::startGameSlot(unsigned int mapWidth, unsigned int mapHeight, QString playerOneName, QString playerTwoName,
                         QColor playerOneColor, QColor playerTwoColor)
{
    setupPlayers(playerOneName, playerTwoName);
    playerOne_->setColor(playerOneColor);
    playerTwo_->setColor(playerTwoColor);
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

