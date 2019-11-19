#ifndef OBJECTMANAGER_HH
#define OBJECTMANAGER_HH

#include "interfaces/iobjectmanager.h"
#include "tiles/tilebase.h"
#include "core/coordinate.h"
#include "core/gameobject.h"

#include <vector>
#include <memory>
#include <iostream>

using ObjectId = unsigned int;

namespace Student {

class ObjectManager : public Course::iObjectManager
{
public:
    ObjectManager();

    void addTiles(const std::vector<std::shared_ptr<Course::TileBase>>& tiles);

    std::shared_ptr<Course::TileBase> getTile(
            const Course::Coordinate& coordinate);

    std::shared_ptr<Course::TileBase> getTile(const ObjectId& id);

    std::vector<std::shared_ptr<Course::TileBase>> getTiles(
            const std::vector<Course::Coordinate>& coordinates);

    std::vector<std::shared_ptr<Course::TileBase>> tiili();

private:
    std::vector<std::shared_ptr<Course::TileBase>> tileVector;
    std::vector<std::shared_ptr<Course::GameObject>> objectVector;
};

} // namespace Student

#endif // OBJECTMANAGER_HH
