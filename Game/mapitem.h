    #ifndef MAPITEM_H
#define MAPITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include <memory>
#include <map>
#include "core/gameobject.h"
#include <QBitmap>



#include "game.h"

namespace Student  {


/**
 * @brief The MapItem class is a custom QGraphicsItem that
 * acts as a single GameObject's graphical element.
 */

class MapItem : public QGraphicsItem
{
public:
    /**
     * @brief Constructor
     * @param obj shared_ptr to the obj.
     * @param size of the created item in pixels.
     * @pre obj must have a valid Coordinate.
     */
    MapItem(const std::shared_ptr<Course::GameObject> &obj, int size, QColor color = Qt::black);

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

    /**
     * @brief boundingRectForImages
     * @return the bounding rectangle of this item.
     */
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

    /**
     * @brief returns a pixmap according to the gameobjects type
     * @param std::string gameobjects name
     * @return QPixmap
     */
    QPixmap getPixMap(std::string type);

    /**
     * @brief sets mapitems color according to player color
     * @param QColor players color
     */
    void drawOwnership(QColor color);

    /**
     * @brief Sets the mapitem pixmap
     * @param QPixmap image
     */
    void setPixMap(QPixmap pix);

private:
    const std::shared_ptr<Course::GameObject> m_gameobject;
    QPoint m_scenelocation;
    int m_size;
    QColor m_color;

    static std::map<std::string, QColor> c_mapcolors;
    static void addNewColor(std::string type);

    QPixmap pix_;
    QBitmap mask_;


};
}
#endif // MAPITEM_H


