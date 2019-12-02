#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "gamescene.h"
#include "interfaces/igameeventhandler.h"
#include "objectmanager.hh"
#include "core/playerbase.h"
#include "player.h"
#include "gameeventhandler.hh"
#include "QPushButton"
#include "vector"
#include "QLabel"


namespace Ui {
class Game;
}

/**
 * @class Game
 * @brief Game class is inherited from QMainWindow class
 *
 * The class can be used to show items in the game mainwindow
 */
class Game : public QMainWindow
{
    Q_OBJECT

public:

    explicit Game(QWidget *parent = nullptr);
    /**
     * @brief Default destructor.
     */
    ~Game();

    /**
     * @brief getType Returns the player-class whose turn it is
     * @return Student::Player whose turn it is
     */
    std::shared_ptr<Student::Player> getTurn();

    /**
     * @brief sets the next players turn,
     * emits playerInTurnSignal
     * @param Student::Player, the next players turn.
     */
    void setTurn(std::shared_ptr<Student::Player> player);

    /**
     * @brief method that is called when end turn- button is pressed
     */
    void changeTurn();

    /**
     * @brief Creates players and randomizes starting player
     * @param Student::Player, player one
     * @param Student::Player, player two
     */
    void setupPlayers(QString playerOneName, QString playerTwoName);

    /**
     * @brief Adds buildingButtons and workerButtons to button-vector
     */
    void displayMainMenu();

    /**
     * @brief updates widgets and other graphics
     */
    void updateView();

    /**
     * @brief conncects building- and worker-buttons click signals to slot that
     * sends the button info. Also connects buttons info to logmessage slot
     */
	void connectButtons();

signals:
    /**
     * @brief emits player whose turn it is
     * is emitted in game.cpp SetTurn method
     * @param Student::Player whose turn it is
     */
    void playInTurnSignal(std::shared_ptr<Student::Player> playerInTurn_);

    /**
     * @brief emits player whose turn it is
     * is emitted game.cpp sendButtonText method
     * is connected in gamescene.cpp
     * @param Student::Player whose turn it is
     */
    void buildingSignal(std::string building);

public slots:
    /**
     * @brief setups both players names and colors,
     * calls drawGameboard and displays all player infos in ui
     * @param unsigned int maps width
     * @param unsigned int maps height
     * @param QString player one name
     * @param QString player two name
     * @param QColor player one color
     * @param QColor player two color
     */
    void startGameSlot (unsigned int mapWidth, unsigned int mapHeight, QString playerOne, QString playerTwo,
                        QColor playerOneColor, QColor playerTwoColor);

    /**
     * @brief updates viewport so all the changes in gamescene is visible
     */
    void updateViewSlot();

    /**
     * @brief Slot that sends button text when pressed
     * emits buildingsignal
     */
    void sendButtonText();

    /**
     * @brief updates both players information in ui
     * @param int how many moves player has
     */
    void updateInformationSlot(int movesLeft);

    /**
     * @brief updates both players information in ui
     * @param Student::Player a shared pointer of player who won
     * @param int how many turns in total during the whole game
     */
    void gameOverSlot(std::shared_ptr<Student::Player> winner, int turnCount);

    /**
     * @brief dislpays buildings and workers resource costs in ui
     * when hovering the buttons
     * @param message emitted
     */
    void logMessageSlot(std::string message);
    /**
     * @brief unchecks buttons
     */
    void enableButtonsSlot();


private slots:
    /**
     * @brief when turnbutton clicked calls changeTurn method
     */
    void on_turnButton_clicked();



private:
    Ui::Game *ui;
    QDialog* dialoq_;
    std::vector<QPushButton*> objectButtonsVector_;
    std::vector<QLabel*> costVector_;
    std::vector<QLabel*> productionVector_;

    std::shared_ptr<Student::Player> playerInTurn_ = nullptr;
    std::shared_ptr<Student::Player> playerOne_ = nullptr;
    std::shared_ptr<Student::Player> playerTwo_ = nullptr;

    std::shared_ptr<Student::GameEventHandler> eveHandler_ = nullptr;
    std::shared_ptr<Student::GameScene> gameScene_ = nullptr;
    std::shared_ptr<Student::ObjectManager> objManager_ = nullptr;
};

#endif // GAME_H
