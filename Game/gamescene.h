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
     * @pre 0 < width <= 100 && 0 < height <= 100 && 0 < scale <= 500. Otherwise
     * default values are used for the created object.
     */
    GameScene(QWidget* qt_parent = nullptr,
                    int width = 10,
                    int height = 10,
                    int scale = 50
            );

    // piirtää pelilaudan
    void drawGameBoard(unsigned int size_x,
                       unsigned int size_y,
                       unsigned int seed,
                       const std::shared_ptr<Student::ObjectManager>& objectmanager,
                       const std::shared_ptr<Student::GameEventHandler>& eventhandler,
                       const std::shared_ptr<Student::Player>& playerOne,
                       const std::shared_ptr<Student::Player>& playerTwo);

    void drawObject(std::shared_ptr<Course::GameObject> obj, QColor color = Qt::transparent);

    /**
     * @brief simple event handler that notifies when objects or the play     * area is clicked.
     * @param event that has happened.
     * @return True: if event was  handled in the handler.
     * False: if the event handling was passed over.
     */
    virtual bool event(QEvent* event) override;

    void generateStartingObjects();

    void updateItem(std::shared_ptr<Course::GameObject> obj);

    //palauttaa pelaajan object-vektorista halutun objectin (vertailee nimiä eli jos pelaajalla usea samanniminen objekti niin HOMMA KUSEE)
    std::shared_ptr<Course::GameObject> returnPlayerObject(std::string objectName);

    bool BuildingTileIsCorrect(std::shared_ptr<Course::GameObject> building, std::shared_ptr<Course::TileBase> tile);

    void reset();

    void updateAndDrawTileOwners();

    void generateResources();

    void removeItem(std::shared_ptr<Course::GameObject> obj);

    // Returns true if x is in range [low..high], else false
    bool inRange(int low, int high, int x) ;

    void drawTileGraphics(std::vector<std::shared_ptr<Course::TileBase>> tiles);

signals:
    void updateViewSignal();
    void updateInformationSignal(int movesLeft);
    void gameOverSignal(std::shared_ptr<Student::Player> player, int turnCount);

public slots:
    void playerInTurnSlot(std::shared_ptr<Student::Player> playerInTurn);
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


