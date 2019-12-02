#ifndef MINE_HH
#define MINE_HH


#include "buildings/buildingbase.h"
#include "core/resourcemaps.h"
#include "resourcemaps.hh"

namespace Student {

/**
 * @brief The Mine class represents a mine-building in the game.
 *
 * The Mine products ore-resource to the player
 * Mine can only be placed on a Mountain-typed tile when there is
 * a Construction worker on the tile
 */
class Mine : public Course::BuildingBase
{
public:

    Mine() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler points to the student's GameEventHandler.
     * @param owner points to the owning player.
     * @param tile points to the tile upon which the building is constructed.
     *
     * @post Exception Guarantee: No guarantee.
     * @exception OwnerConflict - if the building conflicts with tile's
     * ownership.
     */
    explicit Mine(
            const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost = Student::ConstResourceMaps::MINE_BUILD_COST,
            const Course::ResourceMap& production = Student::ConstResourceMaps::MINE_PRODUCTION
            );

    /**
     * @brief Default destructor.
     */
    virtual ~Mine() = default;

    /**
     * @brief getType Returns a string describing objects type.
     * This should be overriden in each inherited class.
     * Makes checking object's type easier for students.
     * @return std::string that represents Object's type.
     * @post Exception guarantee: No-throw
     * @note You can use this in e.g. debugging and similar printing.
     */
    virtual std::string getType() const override;

    // not in use
    virtual void onBuildAction() override;

};

}
#endif // MINE_HH
