#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "gamescene.h"
#include "interfaces/igameeventhandler.h"
#include "objectmanager.hh"
#include "core/playerbase.h"
#include "player.h"


namespace Ui {
class Game;
}

class Game : public QMainWindow
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();

    // turn
    std::shared_ptr<Student::Player> getTurn();
    void setTurn(std::shared_ptr<Student::Player> player);
    void changeTurn();

    void setupPlayers(QString playerOneName, QString playerTwoName);

    void displayMainMenu();


public slots:
    void startGameSlot (int playerAmount, unsigned int mapWidth, unsigned int mapHeight, QString playerOne, QString playerTwo);

private slots:
    void on_turnButton_clicked();

private:
    Ui::Game *ui;
    QDialog* dialoq_;
    std::shared_ptr<Student::Player> playerInTurn_ = nullptr;
    std::shared_ptr<Student::Player> playerOne_ = nullptr;
    std::shared_ptr<Student::Player> playerTwo_ = nullptr;



    std::shared_ptr<Course::iGameEventHandler> eveHandler_ = nullptr;
    std::shared_ptr<Student::GameScene> gameScene_ = nullptr;
    std::shared_ptr<Student::ObjectManager> objManager_ = nullptr;
};

#endif // GAME_H
