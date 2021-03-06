#ifndef RIVER_HH
#define RIVER_HH


#include "tiles/tilebase.h"
#include "resourcemaps.hh"

namespace Student {

/**
 * @brief The Mountain class represents Mountain in the gameworld.
 *
 * River tile does not support any buildings or workers but it can be owned by a player.
 */
class River : public Course::TileBase
{
public:

    River() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param location is the Coordinate where the Tile is located in the game.
     * @param eventhandler points to the student's GameEventHandler.
     */
    River(const Course::Coordinate& location,
           const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const unsigned int& max_build = 2,
           const unsigned int& max_work = 3,
           const Course::ResourceMap& production = Student::ConstResourceMaps::RIVER_BP);

    virtual ~River() = default;

    /**
     * @brief getType Returns a string describing objects type.
     * This should be overriden in each inherited class.
     * Makes checking object's type easier for students.
     * @return std::string that represents Object's type.
     * @post Exception guarantee: No-throw
     * @note You can use this in e.g. debugging and similar printing.
     */
    virtual std::string getType() const override;

    /**
     * @brief Adds a new building-object to the tile.
     *
     * Phases: \n
     * 1. Check that there is space for the building. \n
     * 2. Call parent's addBuilding \n
     *
     * @post Exception guarantee: Strong
     * @exception OwnerConflict - If the tile's ownership prevents placing the
     * \b building.
     * @exception NoSpace - If the tile doesn't have enough space for
     * the \b building.
     */
    void addBuilding(const std::shared_ptr<Course::BuildingBase>& building) override;
};

}

#endif // RIVER_HH
