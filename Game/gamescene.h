#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

#include <map>
#include "interfaces/igameeventhandler.h"
#include "graphics/simplegamescene.h"
#include "objectmanager.hh"

namespace Student {



class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    GameScene();

    // piirtää pelilaudan
    void drawGameBoard(int x, int y);

    /**
     * @brief draw a new item to the map.
     * @param obj shared ptr to the object
     * @pre obj must have a valid coordinate property.
     * @post Exception guarantee: None
     */
    void drawItem( std::shared_ptr<Course::GameObject> obj);

    void reset();

private:

    std::shared_ptr<Student::ObjectManager> ObjManager_ = nullptr;
    std::shared_ptr<Course::iGameEventHandler> m_GEHandler = nullptr;



};

}
#endif // GAMESCENE_H


