#include "mapitem.h"


#include "game.h"
#include <QPixmap>


namespace Student {

std::map<std::string, QColor> MapItem::c_mapcolors = {};

MapItem::MapItem(const std::shared_ptr<Course::GameObject> &obj, int size ):
    m_gameobject(obj), m_scenelocation(m_gameobject->getCoordinatePtr()->asQpoint()), m_size(size)
{
    c_mapcolors["Forest"] = Qt::darkGreen;
    c_mapcolors["Grassland"] = Qt::green;
    c_mapcolors["Mountain"] = Qt::darkGray;
    c_mapcolors["Cobblestone"] = Qt::gray;
    c_mapcolors["River"] = Qt::blue;

    addNewColor(m_gameobject->getType());
}


QRectF MapItem::boundingRect() const
{
    return QRectF(m_scenelocation * m_size, m_scenelocation * m_size + QPoint(m_size, m_size));
}

const std::shared_ptr<Course::GameObject> &MapItem::getBoundObject()
{
    return m_gameobject;
}

void MapItem::addNewColor(std::string type)
{
    if ( c_mapcolors.find(type) == c_mapcolors.end() ){
        std::size_t hash = std::hash<std::string>{}(type);
        c_mapcolors.insert({type, QColor((hash & 0xFF0000) >> 16, (hash & 0x00FF00 ) >> 8, (hash & 0x0000FF))});
    }

}

void MapItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED( option ); Q_UNUSED( widget );
    painter->setBrush(QBrush(c_mapcolors.at(m_gameobject->getType())));
    if ( m_gameobject->getType() == "HeadQuarters" ){
        painter->drawPixmap(boundingRectForImages(), QPixmap(":/images/HQ.png"));
    } else if ( m_gameobject->getType() == "BasicWorker") {
        painter->drawPixmap(boundingRectForImages(), QPixmap(":/images/fedora.jpg"));
    } else {
        painter->drawRect(boundingRect());
    }
}

QRect MapItem::boundingRectForImages()
{
    return QRect(m_scenelocation * m_size, m_scenelocation * m_size + QPoint(m_size, m_size));
}

void MapItem::updateLoc()
{
    if ( !m_gameobject ){
        delete this;
    } else {
        update(boundingRect()); // Test if necessary
        m_scenelocation = m_gameobject->getCoordinate().asQpoint();
    }
}

bool MapItem::isSameObj(std::shared_ptr<Course::GameObject> obj)
{
    return obj == m_gameobject;
}


} // namespace Student

