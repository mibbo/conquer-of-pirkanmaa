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
    connect(sgs_rawptr, SIGNAL(gameOverSignal(std::shared_ptr<Student::Player>)), this, SLOT(gameOverSlot(std::shared_ptr<Student::Player>)));

    //tekee ja piirtää UI setit (nappulat summuut)
    displayMainMenu();

    // LOG
    ui->log->setReadOnly(true);

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
    //add buildingButtons and workerButtons to vector
    buildingButtonsVector_ = {ui->farmButton, ui->mineButton, ui->outpostButton, ui->quarryButton, ui->sawmillButton,
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

void Game::gameOverSlot(std::shared_ptr<Student::Player> winner)
{
    std::cout << "Olet viineri - " << winner->getName()  << std::endl;
}

void Game::connectButtons() {
    for (auto button : buildingButtonsVector_) {
        connect(button, SIGNAL(clicked()), this, SLOT(sendButtonText()));

    }
}

void Game::logMessage(std::string message)
{
    ui->log->setPlainText(QString::fromStdString(message));
}

void Game::logMessage(QString message)
{
    ui->log->setPlainText(message);

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

