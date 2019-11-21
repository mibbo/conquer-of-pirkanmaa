#include "warrior.hh"
#include "tiles/tilebase.h"
#include "interfaces/igameeventhandler.h"
#include "interfaces/iobjectmanager.h"

namespace Student {

Warrior::Warrior(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
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

std::string Warrior::getType() const
{
    return "Warrior";
}

bool Warrior::canBePlacedOnTile(const std::shared_ptr<Course::TileBase> &target) const
{
    return target->getOwner() == getOwner() and
            WorkerBase::canBePlacedOnTile(target);
}

void Warrior::doSpecialAction()
{

}

const Course::ResourceMapDouble Warrior::tileWorkAction()
{

}


}
