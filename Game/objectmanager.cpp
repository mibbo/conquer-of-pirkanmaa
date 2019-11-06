#include "objectmanager.hh"

#include <vector>

namespace Student {

ObjectManager::ObjectManager()
{

}

void ObjectManager::addTiles(
        const std::vector<std::shared_ptr<Course::TileBase>>& tiles) {
    this->tileVector = tiles;
}

std::shared_ptr<Course::TileBase> ObjectManager::getTile(const Course::Coordinate &coordinate)
{

}

std::shared_ptr<Course::TileBase> ObjectManager::getTile(const ObjectId &id)
{

}

std::vector<std::shared_ptr<Course::TileBase> > ObjectManager::getTiles(const std::vector<Course::Coordinate> &coordinates)
{

}

std::vector<std::shared_ptr<Course::TileBase>> ObjectManager::tiili()
{
    return tileVector;
}

} // namespace Student
