#include "mountain.hh"
#include "core/resourcemaps.h"
#include "resourcemaps.hh"

namespace Student {

Mountain::Mountain(const Course::Coordinate& location,
               const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
               const std::shared_ptr<Course::iObjectManager>& objectmanager,
               const unsigned int& max_build,
               const unsigned int& max_work,
               const Course::ResourceMap& production):
    TileBase(location,
             eventhandler,
             objectmanager,
             max_build,
             max_work,
             production)
{
}

std::string Mountain::getType() const
{
    return "Mountain";
}

void Mountain::addBuilding(const std::shared_ptr<Course::BuildingBase>& building)
{
    Course::TileBase::addBuilding(building);
    building->addHoldMarkers(1);
}

}
