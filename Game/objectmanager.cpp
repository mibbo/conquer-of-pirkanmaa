#include "objectmanager.hh"
#include "core/coordinate.h"

#include <vector>
#include <math.h>
#include <iostream>

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
    return nullptr;
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

std::vector<std::shared_ptr<Course::GameObject> > ObjectManager::getNeighbourTiles(std::shared_ptr<Course::GameObject> object, const int &radius)
{
    //Huom! palauttaa naapurilaattojen lisäksi objectin alla olevan laatan.
    std::vector<std::shared_ptr<Course::GameObject>> neighbourTiles;

    int x_lower = object->getCoordinate().x() - radius;
    int y_lower = object->getCoordinate().y() - radius;
    int x_upper = object->getCoordinate().x() + radius;
    int y_upper = object->getCoordinate().y() + radius;

    Course::Coordinate coordinate = object->getCoordinate();

    neighbourTiles.push_back(ObjectManager::getTile(coordinate));

    for( int x = x_lower; x <= x_upper; ++x )
    {
        for( int y = y_lower; y <= y_upper; ++y )
        {
            if (ObjectManager::getTile(Course::Coordinate(x,y)) == nullptr) {
                std::cout << "yli rajojen (" << x << "," << y << ")" <<std::endl;
            } else {
                std::cout << "sallittu    (" << x << "," << y << ")" << std::endl;
                neighbourTiles.push_back(ObjectManager::getTile(Course::Coordinate(x,y)));
            }
        }
    }
    return neighbourTiles;
}

std::vector<std::shared_ptr<Course::TileBase>> ObjectManager::tiili()
{
    return tileVector;
}

} // namespace Student
