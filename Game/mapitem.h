#ifndef MAPITEM_H
#define MAPITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include <memory>
#include <map>
#include "core/gameobject.h"




#include "game.h"

namespace Student  {




class MapItem : public QGraphicsItem
{
public:
    /**
     * @brief Constructor
     * @param obj shared_ptr to the obj.
     * @param size of the created item in pixels.
     * @pre obj must have a valid Coordinate.
     */
    MapItem(const std::shared_ptr<Course::GameObject> &obj, int size);

    /**
     * @brief boundingRect
     * @return the bounding rectangle of this item.
     */
    QRectF boundingRect() const override;

    /**
     * @brief getBoundObject
     * @return the object this item is bound to.
     */
    const std::shared_ptr<Course::GameObject> &getBoundObject();

    /**
     * @brief paints the item
     * @param painter
     * @param option
     * @param widget
     * @note The GraphicsView containing the scene this belongs to
     * usually calls this function.
     */
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    QRect boundingRectForImages();

    /**
     * @brief updateLoc moves the item if the position has changed.
     */
    void updateLoc();

    /**
     * @brief checks if this instance has obj as bound obj.
     * @param obj to compare to.
     * @return True: if obj is pointing to the same object as this item.
     * False otherwise.
     */
    bool isSameObj(std::shared_ptr<Course::GameObject> obj);

private:
    const std::shared_ptr<Course::GameObject> m_gameobject;
    QPoint m_scenelocation;
    int m_size;

    static std::map<std::string, QColor> c_mapcolors;
    static void addNewColor(std::string type);
};
}
#endif // MAPITEM_H


