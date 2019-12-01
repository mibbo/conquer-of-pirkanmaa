#ifndef MOUNTAIN_HH
#define MOUNTAIN_HH

#include "tiles/tilebase.h"
#include "resourcemaps.hh"

namespace Student {

/**
 * @brief The Mountain class represents Mountain in the gameworld.
 *
 * Mountain tile supports 1 Mine-type building and worker at a time.
 */
class Mountain : public Course::TileBase
{
public:

    Mountain() = delete;

    Mountain(const Course::Coordinate& location,
           const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const unsigned int& max_build = 2,
           const unsigned int& max_work = 3,
           const Course::ResourceMap& production = Student::ConstResourceMaps::MOUNTAIN_BP);

    virtual ~Mountain() = default;

    virtual std::string getType() const override;

    void addBuilding(const std::shared_ptr<Course::BuildingBase>& building) override;
};

}

#endif // MOUNTAIN_HH
