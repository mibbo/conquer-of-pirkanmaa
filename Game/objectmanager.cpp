#include "objectmanager.hh"

#include <vector>
#include <math.h>

namespace Student {

ObjectManager::ObjectManager()
{

}

void ObjectManager::addTiles(
        const std::vector<std::shared_ptr<Course::TileBase>>& tiles) {
    for (auto tile : tiles) {
        tileVector.push_back(tile);
        objectVector.push_back(tile);
    }
}

std::shared_ptr<Course::TileBase> ObjectManager::getTile(const Course::Coordinate &coordinate) // need to implement boundaries
{
    for (auto tile : tileVector) {
        if (tile->getCoordinate() == coordinate) {
            return tile;
        }
    }
}

std::shared_ptr<Course::TileBase> ObjectManager::getTile(const ObjectId &id) // need to implement boundaries
{
//    unsigned int row_size = tileVector.size() / tileVector.size();
//    int x = std::floor(id / row_size);
//    int y = id % row_size;
    return (tileVector.at(id));
}

std::vector<std::shared_ptr<Course::TileBase> > ObjectManager::getTiles(const std::vector<Course::Coordinate> &coordinates) // need to implement boundaries
{
    std::vector<std::shared_ptr<Course::TileBase>> foundTiles;
    for (auto coordinate : coordinates) {
        foundTiles.push_back(ObjectManager::getTile(coordinate));
    }
    return foundTiles;
}

std::vector<std::shared_ptr<Course::TileBase>> ObjectManager::tiili()
{
    return tileVector;
}

} // namespace Student
