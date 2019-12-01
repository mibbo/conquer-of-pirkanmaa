#include "mapitem.h"


#include "game.h"
#include <QPixmap>
#include <QBitmap>
#include <QGraphicsColorizeEffect>


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
    //Allow responding to hover
    setAcceptHoverEvents(true);
    //Test
    pix_ = MapItem::getPixMap(m_gameobject->getType());
    if (m_gameobject->getType() == "Grassland" ||
                m_gameobject->getType() == "Forest" ||
                m_gameobject->getType() == "Mountain" ||
                m_gameobject->getType() == "Cobblestone" ||
                m_gameobject->getType() == "River") {
        pix_ = MapItem::getPixMap(m_gameobject->getType());
    } else {
        pix_ = MapItem::getPixMap(m_gameobject->getType());
        mask_ = pix_.createMaskFromColor(QColor(0,0,0), Qt::MaskOutColor);
        //        pix_.fill(m_color);
        //        pix_.setMask(mask_);
    }
    if (m_gameobject->getType() == "ConstructionWorker" ||
            m_gameobject->getType() == "BasicWorker" ||
            m_gameobject->getType() == "Warrior") {
        this->setZValue(1);
    }
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
        pen.setStyle(Qt::DotLine);
        painter->setPen(pen);

        // Set the brush color to tile's color
        painter->setBrush(QBrush(Qt::transparent));

        QRect pixRect(MapItem::boundingRectForImages().x(),
                   MapItem::boundingRectForImages().y(),
                   MapItem::boundingRectForImages().width(),
                   MapItem::boundingRectForImages().height());
        painter->drawPixmap(pixRect, pix_);

        QRect rect(MapItem::boundingRect().x()-3,
                   MapItem::boundingRect().y()-3,
                   MapItem::boundingRect().width(),
                   MapItem::boundingRect().height());
        painter->drawRoundedRect(rect, 6, 6);


        // Create and paint a new rect from mapitem's boundingRect with few graphical adjustments
//        QRect rect(MapItem::boundingRect().x()-3,
//                   MapItem::boundingRect().y()-3,
//                   MapItem::boundingRect().width(),
//                   MapItem::boundingRect().height());
//        painter->drawRoundedRect(rect, 1, 1);

    } else {
        QRect rect(MapItem::boundingRectForImages().x()-1,
                   MapItem::boundingRectForImages().y()-1,
                   MapItem::boundingRectForImages().width()-5,
                   MapItem::boundingRectForImages().height()-5);
        painter->drawPixmap(rect, pix_);
        painter->setPen(m_color);
        painter->drawPixmap(rect, mask_, mask_.rect());

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
        return QPixmap(":/images/sprite/Outpost.png");
    }  else if (type == "Farm") {
        return QPixmap(":/images/farm.png");
    } else if (type == "Warrior") {
        return QPixmap(":/images/warrior.png");
    } else if (type == "Quarry") {
        return QPixmap(":/images/quarry.png");
    } else if (type == "ConstructionWorker") {
        return QPixmap(":/images/constructionworker.png");
    } else if (type == "Mine") {
        return QPixmap(":/images/sprite/Mine_b.png");
    } else if (type == "Sawmill") {
        return QPixmap(":/images/sprite/Sawmill.png");
    // Tiles
    } else if (type == "Grassland") {
        return QPixmap(":/images/sprite/Grassland_bigger.png");
    } else if (type == "Forest") {
        return QPixmap(":/images/sprite/Forest2_b.png");
    } else if (type == "Mountain") {
        return QPixmap(":/images/sprite/Mountain_b.png");
    } else if (type == "Cobblestone") {
        return QPixmap(":/images/sprite/quarry_b.png");
    } else if (type == "River") {
        return QPixmap(":/images/sprite/waifu2x.png");
    } else {
        return QPixmap();
    }
}

void MapItem::drawOwnership(QColor color)
{
    m_color = color;
    update();
}

void MapItem::setPixMap(QPixmap pix)
{
    pix_ = pix;
    update();
}

void MapItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    if(event){
        //std::cout << m_gameobject->getType() << std::endl;
    }

}

void MapItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    if(event){
        //std::cout <<  "leave" << std::endl;
    }

}


} // namespace Student

