#include "game.h"
#include "ui_game.h"
#include "mapitem.h"
#include "startwindow.h"
#include "core/basicresources.h"

#include "tiles/forest.h"
#include "tiles/grassland.h"

#include <QDebug>
#include <iostream>
#include <fstream>

#include <math.h>
#include <memory>
#include <iostream>

#include <QWidget>
#include <resourcemaps.hh>

#define stringify( name ) # name

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
    // if dialogs X-button is pressed, shuts down the game properly
    if (dialoq_->exec() == QDialog::Rejected) {
        QTimer::singleShot(0, this, SLOT(close()));
    }


    Game::showMaximized();
    gameScene_->setSceneRect(0,0,795,795);
    ui->graphicsView->setFixedSize(802,802);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setAlignment(Qt::AlignTop|Qt::AlignLeft);
    //ui->graphicsView->centerOn()

    // GameScene
    Student::GameScene* sgs_rawptr = gameScene_.get();
    ui->graphicsView->setScene(dynamic_cast<QGraphicsScene*>(sgs_rawptr));

    connect(sgs_rawptr, SIGNAL(updateViewSignal()), this, SLOT(updateViewSlot()));
    connect(sgs_rawptr, SIGNAL(updateInformationSignal(int)), this, SLOT(updateInformationSlot(int)));
    connect(sgs_rawptr, SIGNAL(gameOverSignal(std::shared_ptr<Student::Player>, int)), this, SLOT(gameOverSlot(std::shared_ptr<Student::Player>, int)));

    // connectaa gamescenen signaalin gameen
    connect(sgs_rawptr, SIGNAL(enableButtonsSignal()), this, SLOT(enableButtonsSlot()));

    //tekee ja piirtää UI setit (nappulat summuut)
    displayMainMenu();

    // LOG
    ui->log->setReadOnly(true);

    costVector_ = {ui->moneyLabel, ui->foodLabel, ui->woodLabel, ui->stoneLabel, ui->oreLabel};
    productionVector_ = {ui->moneyProductionLabel, ui->foodProductionLabel, ui->woodProductionLabel,
                         ui->stoneProductionLabel, ui->oreProductionLabel};
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

    int randomPlayer = rand()%2;
    if (randomPlayer == 0) {
        setTurn(playerOne_);
    } else {
        setTurn(playerTwo_);
    }
}

void Game::displayMainMenu()
{
    qDebug() << "displaymainemenu";
    //add buildingButtons and workerButtons to vector
    objectButtonsVector_ = {ui->farmButton, ui->mineButton, ui->outpostButton, ui->quarryButton, ui->sawmillButton,
                              ui->basicWorkerButton, ui->constWorkerButton, ui->warriorButton};
    connectButtons();
}

void Game::updateView()
{
    update();
}

void Game::sendButtonText() {
    QObject* sender = QObject::sender();
      if (sender != nullptr) {
        QAbstractButton* button = dynamic_cast<QAbstractButton*>(sender);
        if (button != nullptr) {
          //emits buildingButtons name
          emit buildingSignal(button->text().toStdString());
            if (button->isChecked() == true) {
                std::cout << "haloo" << std::endl;
                button->setChecked(false);
            } else {
                button->setChecked(true);
            }
        }
      }
}

void Game::updateInformationSlot(int movesLeft)
{
    Course::ResourceMap resources = playerInTurn_->getResources();

    if (playerInTurn_ == playerOne_) {
        ui->movesP1->display(movesLeft);
        ui->moneyP1->display(resources[Course::MONEY]);
        ui->foodP1->display(resources[Course::FOOD]);
        ui->woodP1->display(resources[Course::WOOD]);
        ui->stoneP1->display(resources[Course::STONE]);
        ui->oreP1->display(resources[Course::ORE]);
        int tileAmount = playerOne_->getTiles().size();
        ui->tilesP1->display(tileAmount);
    } else {
        ui->movesP2->display(movesLeft);
        ui->moneyP2->display(resources[Course::MONEY]);
        ui->foodP2->display(resources[Course::FOOD]);
        ui->woodP2->display(resources[Course::WOOD]);
        ui->stoneP2->display(resources[Course::STONE]);
        ui->oreP2->display(resources[Course::ORE]);
        int tileAmount = playerTwo_->getTiles().size();
        ui->tilesP2->display(tileAmount);
    }

    float ownedTilesAmount = playerOne_->getTiles().size() + playerTwo_->getTiles().size();
    int powerP1 = playerOne_->getTiles().size() / ownedTilesAmount * 100;
    ui->powerP1->display(powerP1);
    int powerP2 = 100 - powerP1;
    ui->powerP2->display(powerP2);
}

void Game::gameOverSlot(std::shared_ptr<Student::Player> winner, int turn)
{
    std::cout << "Olet viineri - " << winner->getName()  << std::endl;
}


void Game::connectButtons() {
    for (auto button : objectButtonsVector_) {
        connect(button, SIGNAL(clicked()), this, SLOT(sendButtonText()));
        connect(button, SIGNAL(buttonInfoSignal(std::string)), this, SLOT(logMessageSlot(std::string)));
    }
}


void Game::startGameSlot(unsigned int mapWidth, unsigned int mapHeight, QString playerOneName, QString playerTwoName,
                         QColor playerOneColor, QColor playerTwoColor)
{
    setupPlayers(playerOneName, playerTwoName);
    playerOne_->setColor(playerOneColor);
    playerTwo_->setColor(playerTwoColor);
    gameScene_->drawGameBoard(mapWidth, mapHeight, 2, objManager_, eveHandler_, playerOne_, playerTwo_);

    // Display both players' resources etc.
    Course::ResourceMap resourcesP1 = playerInTurn_->getResources();
    ui->playerNameP1->setText(QString::fromStdString(playerOne_->getName()));
    ui->movesP1->display(0);
    ui->moneyP1->display(resourcesP1[Course::MONEY]);
    ui->foodP1->display(resourcesP1[Course::FOOD]);
    ui->woodP1->display(resourcesP1[Course::WOOD]);
    ui->stoneP1->display(resourcesP1[Course::STONE]);
    ui->oreP1->display(resourcesP1[Course::ORE]);
    int tileAmountP1 = playerOne_->getTiles().size();
    ui->tilesP1->display(tileAmountP1);
    ui->powerP1->display(50);

    Course::ResourceMap resourcesP2 = playerInTurn_->getResources();
    ui->playerNameP2->setText(QString::fromStdString(playerTwo_->getName()));
    ui->movesP2->display(0);
    ui->moneyP2->display(resourcesP2[Course::MONEY]);
    ui->foodP2->display(resourcesP2[Course::FOOD]);
    ui->woodP2->display(resourcesP2[Course::WOOD]);
    ui->stoneP2->display(resourcesP2[Course::STONE]);
    ui->oreP2->display(resourcesP2[Course::ORE]);
    int tileAmountP2 = playerTwo_->getTiles().size();
    ui->tilesP2->display(tileAmountP2);
    ui->powerP2->display(50);
}

void Game::logMessageSlot(std::string message)
{
    ui->buildingNameLabel->setText(QString::fromStdString(message));
    ui->buildCostLabel->setText("Cost");

    const char* resourceNames[] =
      {
      stringify( Money ),
      stringify( Food ),
      stringify( Wood ),
      stringify( Stone ),
      stringify( Ore )
      };

    Course::ResourceMap costResourceMap;
    Course::ResourceMap productionResourceMap;

    if (message == "Farm") {
        costResourceMap = Student::ConstResourceMaps::FARM_BUILD_COST;
        productionResourceMap = Student::ConstResourceMaps::FARM_PRODUCTION;

    } else if (message == "Quarry") {
        costResourceMap = Student::ConstResourceMaps::QUARRY_BUILD_COST;
        productionResourceMap = Student::ConstResourceMaps::QUARRY_PRODUCTION;

    } else if (message == "Mine") {
        costResourceMap = Student::ConstResourceMaps::MINE_BUILD_COST;
        productionResourceMap = Student::ConstResourceMaps::MINE_PRODUCTION;

    } else if (message == "Sawmill") {
        costResourceMap = Student::ConstResourceMaps::SAWMILL_BUILD_COST;
        productionResourceMap = Student::ConstResourceMaps::SAWMILL_PRODUCTION;

    } else if (message == "Outpost") {
        costResourceMap = Student::ConstResourceMaps::OUTPOST_BUILD_COST;

    } else if (message == "Basic Worker") {
        costResourceMap = Student::ConstResourceMaps::BW_RECRUITMENT_COST;

    } else if (message == "Construction Worker") {
        costResourceMap = Student::ConstResourceMaps::CW_RECRUITMENT_COST;

    } else if (message == "Warrior") {
        costResourceMap = Student::ConstResourceMaps::WARRIOR_RECRUITMENT_COST;

    } else {
        return;
    }


    if (message == "Farm" || message == "Sawmill" || message == "Quarry" || message == "Mine" ) {
        ui->productionLabel->setText("Production");

        int i = 0;
        for (auto mapC : costResourceMap) {
            costVector_.at(i)->setText(QString::fromStdString(resourceNames[mapC.first-1]) + ": " + QString::number(mapC.second));
            i++;
        }

        int k = 0;
        for (auto mapP : productionResourceMap) {
            productionVector_.at(k)->setText(QString::fromStdString(resourceNames[mapP.first-1]) + ": " + QString::number(abs(mapP.second)));
            k++;
        }

    } else {
        ui->productionLabel->setText("");

        int i = 0;
        for (auto map : costResourceMap) {
            costVector_.at(i)->setText(QString::fromStdString(resourceNames[map.first-1]) + ": " + QString::number(map.second));
            productionVector_.at(i)->setText("");
            i++;
        }
    }
}

void Game::logMessageSlot(QString message)
{
    ui->log->setPlainText(message);

}

void Game::enableButtonsSlot()
{
    for (auto button : objectButtonsVector_) {
        button->setChecked(false);
    }
}

void Game::updateViewSlot()
{
    ui->graphicsView->viewport()->update();
}


void Game::on_turnButton_clicked()
{
    changeTurn();
}

