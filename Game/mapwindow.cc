#include "mapwindow.hh"
#include "ui_mapwindow.h"

#include "graphics/simplemapitem.h"
#include "gameeventhandler.hh"
#include "objectmanager.hh"
#include "core/worldgenerator.h"
#include "tiles/forest.h"
#include "tiles/grassland.h"
#include "startwindow.hh"

#include <math.h>
#include <memory>
#include <iostream>

MapWindow::MapWindow(QWidget *parent,
                     std::shared_ptr<Course::iGameEventHandler> handler):
    QMainWindow(parent),
    m_ui(new Ui::MapWindow),
    m_GEHandler(handler),
    m_simplescene(new Course::SimpleGameScene(this)),
    m_OBManager(std::make_shared<Student::ObjectManager>())
{
    m_ui->setupUi(this);

    Course::SimpleGameScene* sgs_rawptr = m_simplescene.get();

    m_ui->graphicsView->setScene(dynamic_cast<QGraphicsScene*>(sgs_rawptr));

<<<<<<< HEAD
    startwindow_ = new StartWindow();
    connect(startwindow_, SIGNAL(startGame(int, int, int)), this, SLOT(startGameSlot(int,int,int)));
    startwindow_->exec();
=======
    Course::WorldGenerator& worldGen = Course::WorldGenerator::getInstance();
    worldGen.addConstructor<Course::Forest>(1);
    worldGen.addConstructor<Course::Grassland>(1);
    worldGen.generateMap(3,3,2, m_OBManager, m_GEHandler);
    std::vector<std::shared_ptr<Course::TileBase>> tiles = m_OBManager->tiili();
    std::cout<< tiles.size()<<   std::endl;
    for(auto x: tiles){
        MapWindow::drawItem(x);
>>>>>>> dev

//    Course::WorldGenerator& worldGen = Course::WorldGenerator::getInstance();
//    worldGen.addConstructor<Course::Forest>(1);
//    worldGen.addConstructor<Course::Grassland>(1);
//    worldGen.generateMap(3,3,2, m_OBManager, m_GEHandler);
//    std::vector<std::shared_ptr<Course::TileBase>> tiles = m_OBManager->tiili();
//    std::cout<< tiles.size()<< std::endl;
//    for(auto x: tiles){
//        MapWindow::drawItem(x);

//    }
}


MapWindow::~MapWindow()
{
    delete m_ui;
}

void MapWindow::setGEHandler(
        std::shared_ptr<Course::iGameEventHandler> nHandler)
{
    m_GEHandler = nHandler;
}

void MapWindow::setSize(int width, int height)
{
    m_simplescene->setSize(width, height);
}

void MapWindow::setScale(int scale)
{
    m_simplescene->setScale(scale);
}

void MapWindow::resize()
{
    m_simplescene->resize();
}

void MapWindow::updateItem(std::shared_ptr<Course::GameObject> obj)
{
    m_simplescene->updateItem(obj);
}

void MapWindow::startGame(int playerAmount, int mapWidth, int mapHeight)
{
    std::cout << playerAmount << "  " << mapWidth << "  " << mapHeight << std::endl;
}

void MapWindow::startGameSlot(int playerAmount, int mapWidth, int mapHeight)
{
    startGame(playerAmount, mapWidth, mapHeight);
}


void MapWindow::removeItem(std::shared_ptr<Course::GameObject> obj)
{
    m_simplescene->removeItem(obj);
}

void MapWindow::drawItem( std::shared_ptr<Course::GameObject> obj)
{
    m_simplescene->drawItem(obj);
}
