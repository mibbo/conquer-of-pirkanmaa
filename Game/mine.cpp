#include "mine.hh"
#include "tiles/tilebase.h"


namespace Student {

Mine::Mine(
        const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
        const std::shared_ptr<Course::iObjectManager>& objectmanager,
        const std::shared_ptr<Course::PlayerBase>& owner,
        const int& tilespaces,
        const Course::ResourceMap& buildcost,
        const Course::ResourceMap& production):
    BuildingBase(
        eventhandler,
        objectmanager,
        owner,
        tilespaces,
        buildcost,
        production)
{
}

std::string Mine::getType() const
{
    return "Mine";
}

void Mine::onBuildAction()
{
    std::vector< std::shared_ptr<Course::TileBase> > neighbours =
            lockObjectManager()->getTiles(getCoordinatePtr()->neighbours(3));

    for(auto it = neighbours.begin(); it != neighbours.end(); ++it)
    {
        // If the Tile doesn't have owner, set it's owner to buildings owner.
        if( not (*it)->getOwner() )
        {
            (*it)->setOwner(getOwner());
        }
    }
}


}
