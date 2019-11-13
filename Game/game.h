#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "gamescene.h"
#include "interfaces/igameeventhandler.h"
#include "objectmanager.hh"


namespace Ui {
class Game;
}

class Game : public QMainWindow
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();

public slots:
    void startGameSlot (int playerAmount, unsigned int mapWidth, unsigned int mapHeight);

private:
    Ui::Game *ui;
    QDialog* dialoq_;

    std::shared_ptr<Course::iGameEventHandler> eveHandler_ = nullptr;
    std::shared_ptr<Student::GameScene> gameScene_ = nullptr;
    std::shared_ptr<Student::ObjectManager> objManager_ = nullptr;
};

#endif // GAME_H
