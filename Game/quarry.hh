#ifndef QUARRY_HH
#define QUARRY_HH


#include "buildings/buildingbase.h"
#include "core/resourcemaps.h"
#include "resourcemaps.hh"

namespace Student {

/**
 * @brief The Quarry class represents a quarry-building in the game.
 *
 * The Quarry products stone-resource to the player
 * Quarry can only be placed on a Cobblestone-typed tile when there is
 * a Construction worker on the tile
 */
class Quarry : public Course::BuildingBase
{
public:

    Quarry() = delete;

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
    explicit Quarry(
            const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost = Student::ConstResourceMaps::QUARRY_BUILD_COST,
            const Course::ResourceMap& production = Student::ConstResourceMaps::QUARRY_PRODUCTION
            );

    /**
     * @brief Default destructor.
     */
    virtual ~Quarry() = default;

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

#endif // QUARRY_HH
