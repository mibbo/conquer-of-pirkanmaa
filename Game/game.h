#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "gamescene.h"


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
    void startGameSlot (int playerAmount, int mapWidth, int mapHeight);

private:
    Ui::Game *ui;
    QGraphicsScene scene_;               /**< Manages drawable objects. */
    QDialog* dialoq_;
    Student::GameScene* gameScene_;
};

#endif // GAME_H
