#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QGraphicsScene>


namespace Ui {
class Game;
}

class Game : public QMainWindow
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();

private:
    Ui::Game *ui;
    QGraphicsScene scene_;               /**< Manages drawable objects. */

};

#endif // GAME_H
