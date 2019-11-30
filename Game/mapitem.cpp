#include "mapitem.h"


#include "game.h"
#include <QPixmap>
#include <QBitmap>


namespace Student {

std::map<std::string, QColor> MapItem::c_mapcolors = {};

MapItem::MapItem(const std::shared_ptr<Course::GameObject> &obj, int size, QColor color ):
    m_gameobject(obj), m_scenelocation(m_gameobject->getCoordinatePtr()->asQpoint()), m_size(size)
{
    // Set tile colors
    c_mapcolors["Forest"] = Qt::darkGreen;
    c_mapcolors["Grassland"] = Qt::green;
    c_mapcolors["Mountain"] = Qt::darkGray;
    c_mapcolors["Cobblestone"] = Qt::gray;
    c_mapcolors["River"] = Qt::blue;

    m_color = color;

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
    // Check if the object to be drawn is a tile
    if (m_gameobject->getType() == "Grassland" ||
                m_gameobject->getType() == "Forest" ||
                m_gameobject->getType() == "Mountain" ||
                m_gameobject->getType() == "Cobblestone" ||
                m_gameobject->getType() == "River") {

        // Create and set the pen for painter (to have "frames" in tiles)
        QPen pen(m_color);
        pen.setWidth(4);
        painter->setPen(pen);

        // Set the brush color to tile's color
        painter->setBrush(QBrush(Qt::transparent));

        QPixmap px = MapItem::getPixMap(m_gameobject->getType());
        // Paint the pixmap
        QRect pixRect(MapItem::boundingRectForImages().x(),
                   MapItem::boundingRectForImages().y(),
                   MapItem::boundingRectForImages().width(),
                   MapItem::boundingRectForImages().height());
        painter->drawPixmap(pixRect, px);

        // Create and paint a new rect from mapitem's boundingRect with few graphical adjustments
        QRect rect(MapItem::boundingRect().x()-3,
                   MapItem::boundingRect().y()-3,
                   MapItem::boundingRect().width(),
                   MapItem::boundingRect().height());
        painter->drawRoundedRect(rect, 1, 1);







    } else {
        // Get the right pixmap for the object that is not a tile
        QPixmap px = MapItem::getPixMap(m_gameobject->getType());

        // Create a mask for the pixmap so it can be colored with player's color
        auto mask = px.createMaskFromColor(Qt::black, Qt::MaskOutColor);
        px.fill(m_color);
        px.setMask(mask);

        // Paint the pixmap
        QRect rect(MapItem::boundingRectForImages().x(),
                   MapItem::boundingRectForImages().y(),
                   MapItem::boundingRectForImages().width()-2,
                   MapItem::boundingRectForImages().height()-2);
        painter->drawPixmap(rect, px);
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

QPixmap MapItem::getPixMap(std::string type)
{
    if (type == "HeadQuarters") {
        return QPixmap(":/images/HQ.png");
    } else if (type == "BasicWorker") {
        return QPixmap(":/images/basicworker.png");
    } else if (type == "Outpost") {
        return QPixmap(":/images/outpost.png");
    }  else if (type == "Farm") {
        return QPixmap(":/images/farm.png");
    } else if (type == "Warrior") {
        return QPixmap(":/images/warrior.png");
    } else if (type == "Quarry") {
        return QPixmap(":/images/quarry.png");
    } else if (type == "ConstructionWorker") {
        return QPixmap(":/images/constructionworker.png");
    } else if (type == "Mine") {
        return QPixmap(":/images/mine.png");
    } else if (type == "Sawmill") {
            return QPixmap(":/images/player2.png");

        //tiilet
    } else if (type == "Grassland") {
        return QPixmap(":/images/multi_grass.png");
    } else if (type == "Forest") {
        return QPixmap(":/images/multi_grass.png");
    } else if (type == "Mountain") {
        return QPixmap(":/images/multi_grass.png");
    } else if (type == "Cobblestone") {
        return QPixmap(":/images/multi_grass.png");
    } else if (type == "River") {
        return QPixmap(":/images/multi_grass.png");
    }
    else {
    return QPixmap();
    }
}

void MapItem::drawOwnership(QColor color)
{
    m_color = color;
    update();
}


} // namespace Student

