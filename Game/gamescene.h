#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>


class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    GameScene();

    // piirtää pelilaudan
    void drawGameBoard(int x, int y);

    void reset();

private:

};

#endif // GAMESCENE_H


