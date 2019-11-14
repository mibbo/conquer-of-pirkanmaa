#include "mapitem.h"


#include "game.h"


namespace Student {

std::map<std::string, QColor> MapItem::c_mapcolors = {};

MapItem::MapItem(const std::shared_ptr<Course::GameObject> &obj, int size ):
    m_gameobject(obj), m_scenelocation(m_gameobject->getCoordinatePtr()->asQpoint()), m_size(size)
{
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
    if ( m_gameobject->getType() == "" ){
        // Draw different types in different shapes
    }
    painter->drawRect(boundingRect());
}




} // namespace Student

