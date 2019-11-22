#ifndef PLAYER_H
#define PLAYER_H
#include "core/playerbase.h"
//#include "core/gameobject.h"
#include "core/basicresources.h"
#include <QColor>

namespace Student {

class Player : public Course::PlayerBase
{
public:
    /**
     * @brief Constructor for the class
     * @param name A std::string for player's name
     * @param objects (optional) A std::vector of shared-pointers to
     * GameObjects.
     */
    Player(const std::string& name,
               const std::vector<std::shared_ptr<Course::GameObject>> objects ={});

    /**
     * @brief Default destructor
     */
    virtual ~Player() = default;

    /**
     * @brief operator == Checks if a coordinate has same x and y values as this
     * @param other The other Coordinate
     * @return
     * True - if the coordinates have same values.
     * @post Exception guarantee: No-throw
     */
    bool operator==(const Player& other) const;

    bool modifyResource(Course::BasicResource resource, int amount);

    bool modifyResources(Course::ResourceMap resources);

    Course::ResourceMap getResources();

    QColor getColor();

    void setColor(QColor color);

private:
    std::string m_name;
    std::vector<std::weak_ptr<Course::GameObject> > m_objects;
    Course::ResourceMap m_resources;
    QColor m_color;
};

}

#endif // PLAYER_H

