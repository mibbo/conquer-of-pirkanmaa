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
                       const std::shared_ptr<Course::iGameEventHandler>& eventhandler);

    void drawObject(std::shared_ptr<Course::GameObject> obj);

    void reset();

private:
    QGraphicsItem* m_mapBoundRect;
    int m_width;
    int m_height;
    int m_scale;

};

}
#endif // GAMESCENE_H


