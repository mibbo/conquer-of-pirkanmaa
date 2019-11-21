#ifndef CONSTRUCTIONWORKER_HH
#define CONSTRUCTIONWORKER_HH

#include "workers/workerbase.h"
#include "core/resourcemaps.h"
#include "player.h"
#include "resourcemaps.hh"

namespace Student {

class ConstrutionWorker : public Course::WorkerBase
{
public:
    ConstrutionWorker() = delete;

    ConstrutionWorker(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
                const std::shared_ptr<Course::iObjectManager>& objectmanager,
                const std::shared_ptr<Course::PlayerBase>& owner,
                const int& tilespaces = 1,
                const Course::ResourceMap& cost =
                    Student::ConstResourceMaps::CW_RECRUITMENT_COST,
                const Course::ResourceMapDouble& efficiency =
                    Student::ConstResourceMaps::CW_WORKER_EFFICIENCY
                );

    virtual ~ConstrutionWorker() = default;

    virtual std::string getType() const override;

    virtual bool canBePlacedOnTile(
            const std::shared_ptr<Course::TileBase> &target) const override;

    virtual void doSpecialAction() override;

    virtual const Course::ResourceMapDouble tileWorkAction() override;

private:

};

}

#endif // CONSTRUCTIONWORKER_HH
