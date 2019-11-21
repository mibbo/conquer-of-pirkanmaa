#include "constructionworker.hh"
#include "tiles/tilebase.h"
#include "interfaces/igameeventhandler.h"
#include "interfaces/iobjectmanager.h"

namespace Student {

ConstrutionWorker::ConstrutionWorker(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
                         const std::shared_ptr<Course::iObjectManager>& objectmanager,
                         const std::shared_ptr<Course::PlayerBase>& owner,
                         const int& tilespaces,
                         const Course::ResourceMap& cost,
                         const Course::ResourceMapDouble& efficiency):
    WorkerBase(
        eventhandler,
        objectmanager,
        owner,
        tilespaces,
        cost,
        efficiency)
{
}

std::string ConstrutionWorker::getType() const
{
    return "ConstructionWorker";
}

bool ConstrutionWorker::canBePlacedOnTile(const std::shared_ptr<Course::TileBase> &target) const
{
    return target->getOwner() == getOwner() and
            WorkerBase::canBePlacedOnTile(target);
}

void ConstrutionWorker::doSpecialAction()
{

}

const Course::ResourceMapDouble ConstrutionWorker::tileWorkAction()
{

}


}


