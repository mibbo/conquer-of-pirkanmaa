#ifndef MAPITEM_H
#define MAPITEM_H

#include <QGraphicsRectItem>
#include "game.h"


class MapItem : public QGraphicsRectItem
{
public:
    MapItem(QGraphicsItem *parent=0);
    ~MapItem();

    void mousePressEvent(QGraphicsSceneMouseEvent* event);

    // tää ehkä mieluummin tile fileen hmmm
    void setColor(QColor color);

    //asettaa laatan
    //void placeTile(Tile* tile)

private:
    QString owner;
};

#endif // MAPITEM_H
