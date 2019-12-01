#ifndef PLAYER_H
#define PLAYER_H
#include "core/playerbase.h"
#include "core/gameobject.h"
#include "core/basicresources.h"
#include <QColor>
#include <tiles/tilebase.h>

namespace Student {
/**
 * @brief The Player class has all the information for the two players and
 * the methods related to these informations.
 *
 * Both player has following private variables:
 * * Name
 * * player owned objects in a vector
 * * resources in a Course::ResourceMap-class
 * * player owned tiles in a vector
 * * Color
 */
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

    /**
     * @brief Stores a weak GameObject-pointer.
     * @param object Is a weak pointer to the stored GameObject
     * @post Exception guarantee: Strong
     * @exception See std::vector::push_back()
     */
    void addTile(std::shared_ptr<Course::TileBase> tile);

    /**
     * @brief Stores a vector of weak GameObject-pointers.
     * @param objects Is an std::vector of weak GameObject-pointers.
     * @post Exception guarantee: Strong
     * @exception See std::vector::insert()
     */
    void addTiles(const std::vector<std::shared_ptr<Course::GameObject>> &tiles);

    /**
     * @brief Returns the vector of weak TileBase-pointers
     *  that are currently stored in the Player-object.
     * @return Copy of m_tiles -vector
     * @post Exception guarantee: Strong
     */
    std::vector<std::shared_ptr<Course::GameObject>> getTiles() const;

    Course::ResourceMap getResources();

    QColor getColor();

    void setColor(QColor color);

private:
    std::string m_name;
    std::vector<std::weak_ptr<Course::GameObject>> m_objects;
    Course::ResourceMap m_resources;
    std::vector<std::shared_ptr<Course::GameObject>> m_tiles;
    QColor m_color;
};

}

#endif // PLAYER_H

