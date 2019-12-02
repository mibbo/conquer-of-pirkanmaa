#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <functional>
#include <map>
#include <memory>
#include "interfaces/igameeventhandler.h"
#include "objectmanager.hh"
#include "tiles/tilebase.h"
#include "gameeventhandler.hh"
#include "player.h"
#include "workers/workerbase.h"
#include "core/gameobject.h"


namespace Student {

/**
 * @brief The GameScene class is a custom QGraphicsScene that shows
 * a rendering of the game map.
 */
class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    /**
     * @brief Constructor for the class.
     *
     * @param qt_parent points to the parent object per Qt's parent-child-system.
     * @param width in tiles for the game map.
     * @param height in tiles for the game map.
     * @param scale is the size in pixels of a single square tile.
     *
     */
    GameScene(QWidget* qt_parent = nullptr,
                    int width = 10,
                    int height = 10,
                    int scale = 50
            );

    /**
     * @brief Draws the gameboard and adds the tiles to objectManager
     *
     * @param unsigned int map x size
     * @param unsigned int map y size
     * @param unsigned int seed for rand
     * @param Student::ObjectManager a shared ptr to objectmanager
     * @param Student::GameEventHandler a shared ptr to eventhandler
     * @param Student::Player a shared ptr to player one
     * @param Student::Player a shared ptr to player two
     */
    void drawGameBoard(unsigned int size_x,
                       unsigned int size_y,
                       unsigned int seed,
                       const std::shared_ptr<Student::ObjectManager>& objectmanager,
                       const std::shared_ptr<Student::GameEventHandler>& eventhandler,
                       const std::shared_ptr<Student::Player>& playerOne,
                       const std::shared_ptr<Student::Player>& playerTwo);

    /**
     * @brief
     *
     * @param Course::GameObject a shared ptr for the object to draw
     *
     */
    void drawObject(std::shared_ptr<Course::GameObject> obj, QColor color = Qt::transparent);

    /**
     * @brief Event handler that notifies when objects or the play
     * area is clicked.
     * @param event that has happened.
     * @return True: if event was  handled in the handler.
     * False: if the event handling was passed over.
     */
    virtual bool event(QEvent* event) override;

    /**
     * @brief Adds the HQ and one BasicWorker for both players in opposite coordinates
     */
    void generateStartingObjects();

    /**
     * @brief updates the position of obj.
     * @param obj shared ptr to the obj being updated.
     */
    void updateItem(std::shared_ptr<Course::GameObject> obj);

    /**
     * @brief returns single object from player-class object-vector
     * @param std::string objects name
     * @return Course::GameObject a shared pointer for object
     */
    std::shared_ptr<Course::GameObject> returnPlayerObject(std::string objectName);

    /**
     * @brief Checks if you can build selected building to a tile and
     * checks if the tile has construction worker
     * @param Course::Gameobject a shared pointer of building to build
     * @param Course::TileBase a shared pointer of tile where to build
     * @return True: if it is possible to build
     * False: if it's not possible to build
     */
    bool BuildingTileIsCorrect(std::shared_ptr<Course::GameObject> building, std::shared_ptr<Course::TileBase> tile);

    void reset();

    /**
     * @brief Draws the borders to players' owned tiles
     */
    void updateAndDrawTileOwners();

    /**
     * @brief Generates the resources for the playerInTurn_ at the start of the turn
     */
    void generateResources();

    /**
     * @brief removes item object
     *
     * @param Course::Gameobject a shared pointer of object to remove
     */
    void removeItem(std::shared_ptr<Course::GameObject> obj);

    /**
     * @brief Returns true if x is in range [low..high], else false
     * @param int lowest number
     * @param int highest number
     * @param int the number to check
     * @return True: if the number is in range
     * False: if the number is not in range
     */
    bool inRange(int low, int high, int x) ;

    /**
     * @brief Updates river and forest tiles so that their graphics connect
     *
     * @param std::vector that contains Course::TileBase shared pointers
     */
    void drawTileGraphics(std::vector<std::shared_ptr<Course::TileBase>> tiles);

signals:
    /**
     * @brief updates graphics and gamescene when action happens
     */
    void updateViewSignal();

    /**
     * @brief updates information to ui
     * is emitted after a click in the map and in gamescenes playerInTurnSlot
     * connected in gamescene.cpp constructor
     * @param int number of moves left for player
     */
    void updateInformationSignal(int movesLeft);

    /**
     * @brief signal that updates both players information in ui
     * @param Student::Player a shared pointer of player who won
     * @param int how many turns in total during the whole game
     */
    void gameOverSignal(std::shared_ptr<Student::Player> player, int turnCount);

    /**
     * @brief unchecks buttons
     */
    void enableButtonsSignal();

public slots:
    /**
     * @brief resets player moves and calls generateResources after turn changes
     *
     * @param Student::Player a shared ptr of whose turn it is
     */
    void playerInTurnSlot(std::shared_ptr<Student::Player> playerInTurn);

    /**
     * @brief does all the action when certain button is clicked
     *
     * @param std::string buttons string
     */
    void addButtonObject(std::string buttonString);

private:
    QGraphicsItem* m_mapBoundRect;
    int m_width;
    int m_height;
    int m_scale;
    std::shared_ptr<Student::GameEventHandler> eventHandler_ = nullptr;
    std::shared_ptr<Student::ObjectManager> objectManager_ = nullptr;
    std::shared_ptr<Student::Player> playerOne_ = nullptr;
    std::shared_ptr<Student::Player> playerTwo_ = nullptr;
    std::shared_ptr<Student::Player> playerInTurn_ = nullptr;
    bool movableObjectSelected_ = false;
    std::shared_ptr<Course::WorkerBase> movableObject_ = nullptr;
    int playerMovesLeft_;
    bool menuBuildingButtonClicked_ = false;
    std::shared_ptr<Course::BuildingBase> buildingToAdd_ = nullptr;
    std::shared_ptr<Course::WorkerBase> workerToAdd_ = nullptr;
    std::vector<QGraphicsRectItem*> possibleMovementTiles_;
    int turnCount_ = 0;

};

}
#endif // GAMESCENE_H


