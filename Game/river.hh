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

    River(const Course::Coordinate& location,
           const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const unsigned int& max_build = 2,
           const unsigned int& max_work = 3,
           const Course::ResourceMap& production = Student::ConstResourceMaps::RIVER_BP);

    virtual ~River() = default;

    virtual std::string getType() const override;

    void addBuilding(const std::shared_ptr<Course::BuildingBase>& building) override;
};

}

#endif // RIVER_HH
