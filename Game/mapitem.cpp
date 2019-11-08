#include "mapitem.h"
#include "game.h"

//extern MainWindow *mainwindow;
MapItem::MapItem(QGraphicsItem *parent):QGraphicsRectItem(parent) {

    // asettaa koon ja muut settingsit

    setRect(0,0,100,100);


}

MapItem::~MapItem()
{
    delete this;
}




void MapItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}

void MapItem::setColor(QColor color)
{

}
