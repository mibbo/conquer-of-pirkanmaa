#ifndef Sawmill_HH
#define Sawmill_HH


#include "buildings/buildingbase.h"
#include "core/resourcemaps.h"
#include "resourcemaps.hh"

namespace Student {

class Sawmill : public Course::BuildingBase
{
public:

    Sawmill() = delete;

    explicit Sawmill(
            const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost = Student::ConstResourceMaps::SAWMILL_BUILD_COST,
            const Course::ResourceMap& production = Student::ConstResourceMaps::SAWMILL_PRODUCTION
            );

    virtual ~Sawmill() = default;

    virtual std::string getType() const override;

    virtual void onBuildAction() override;

};

}

#endif // Sawmill_HH
