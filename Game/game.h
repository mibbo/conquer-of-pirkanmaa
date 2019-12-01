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
     * @brief sets the next players turn
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

    //tekee ja piirtää UI setit (nappulat summuut)
    /**
     * @brief Adds buildingButtons and workerButtons to button-vector
     */
    void displayMainMenu();


    void updateView();
	void connectButtons();
    void highscores(std::shared_ptr<Student::Player> winner, int turnCount);


signals:
    void playInTurnSignal(std::shared_ptr<Student::Player> playerInTurn_);
    void buildingSignal(std::string building);

public slots:
    void startGameSlot (unsigned int mapWidth, unsigned int mapHeight, QString playerOne, QString playerTwo,
                        QColor playerOneColor, QColor playerTwoColor);
    void updateViewSlot();
    // Slot that sends button text.
    void sendButtonText();
    void updateInformationSlot(int movesLeft);
    void gameOverSlot(std::shared_ptr<Student::Player> winner, int turnCount);
    void logMessageSlot(std::string message);
    void logMessageSlot(QString message);
    void enableButtonsSlot();


private slots:
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
