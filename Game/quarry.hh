#ifndef QUARRY_HH
#define QUARRY_HH


#include "buildings/buildingbase.h"
#include "core/resourcemaps.h"
#include "resourcemaps.hh"

namespace Student {

class Quarry : public Course::BuildingBase
{
public:

    Quarry() = delete;

    explicit Quarry(
            const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost = Student::ConstResourceMaps::QUARRY_BUILD_COST,
            const Course::ResourceMap& production = Student::ConstResourceMaps::QUARRY_PRODUCTION
            );

    virtual ~Quarry() = default;

    virtual std::string getType() const override;

    virtual void onBuildAction() override;

};

}

#endif // QUARRY_HH