#ifndef COBBLESTONE_HH
#define COBBLESTONE_HH

#include "tiles/tilebase.h"
#include "resourcemaps.hh"

namespace Student {

class Cobblestone : public Course::TileBase
{
public:

    Cobblestone() = delete;

    Cobblestone(const Course::Coordinate& location,
           const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const unsigned int& max_build = 2,
           const unsigned int& max_work = 3,
           const Course::ResourceMap& production = Student::ConstResourceMaps::COBBLESTONE_BP);

    virtual ~Cobblestone() = default;

    virtual std::string getType() const override;

    void addBuilding(const std::shared_ptr<Course::BuildingBase>& building) override;
};

}

#endif // COBBLESTONE_HH
