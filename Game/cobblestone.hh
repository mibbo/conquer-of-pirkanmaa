#ifndef COBBLESTONE_HH
#define COBBLESTONE_HH

#include "tiles/tilebase.h"
#include "resourcemaps.hh"

namespace Student {

/**
 * @brief The Cobblestone class represents Cobblestone in the gameworld.
 *
 * Cobblestone tile supports 1 Quarry-type building and worker at a time.
 */
class Cobblestone : public Course::TileBase
{
public:

    Cobblestone() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param location is the Coordinate where the Tile is located in the game.
     * @param eventhandler points to the student's GameEventHandler.
     */
    Cobblestone(const Course::Coordinate& location,
           const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const unsigned int& max_build = 2,
           const unsigned int& max_work = 3,
           const Course::ResourceMap& production = Student::ConstResourceMaps::COBBLESTONE_BP);

    virtual ~Cobblestone() = default;

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

#endif // COBBLESTONE_HH
