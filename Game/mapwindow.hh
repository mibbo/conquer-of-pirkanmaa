#ifndef MAPWINDOW_HH
#define MAPWINDOW_HH

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

#include <map>

#include "interfaces/igameeventhandler.h"
#include "graphics/simplegamescene.h"
#include "objectmanager.hh"

namespace Ui {
class MapWindow;
}

class MapWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MapWindow(QWidget *parent = 0,
                       std::shared_ptr<Course::iGameEventHandler> GEHandler = {}
                       );
    ~MapWindow();

    void setGEHandler(std::shared_ptr<Course::iGameEventHandler> nHandler);

    void setSize(int width, int height);
    void setScale(int scale);
    void resize();

    void drawItem( std::shared_ptr<Course::GameObject> obj);
    void removeItem( std::shared_ptr<Course::GameObject> obj);
    void updateItem( std::shared_ptr<Course::GameObject> obj);


private:
    Ui::MapWindow* m_ui;
    std::shared_ptr<Course::iGameEventHandler> m_GEHandler = nullptr;
    std::shared_ptr<Course::SimpleGameScene> m_simplescene = nullptr;
    std::shared_ptr<Student::ObjectManager> m_OBManager = nullptr;

};

#endif // MapWINDOW_HH

