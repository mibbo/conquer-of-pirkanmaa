#ifndef MINE_HH
#define MINE_HH


#include "buildings/buildingbase.h"
#include "core/resourcemaps.h"
#include "resourcemaps.hh"

namespace Student {

class Mine : public Course::BuildingBase
{
public:

    Mine() = delete;

    explicit Mine(
            const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost = Student::ConstResourceMaps::MINE_BUILD_COST,
            const Course::ResourceMap& production = Student::ConstResourceMaps::MINE_PRODUCTION
            );

    virtual ~Mine() = default;

    virtual std::string getType() const override;

    virtual void onBuildAction() override;

};

}
#endif // MINE_HH
