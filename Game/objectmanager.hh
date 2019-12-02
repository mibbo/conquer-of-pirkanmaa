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

/**
 * @brief The ObjectManager handles tile related actions
 *
 */
class ObjectManager : public Course::iObjectManager
{
public:
    ObjectManager();

    /**
     * @brief Adds new tiles to the ObjectManager.
     * @param tiles a vector that contains the Tiles to be added.
     * @post The tile-pointers in the vector are stored in the ObjectManager.
     * Exception Guarantee: Basic
     *
     */
    void addTiles(const std::vector<std::shared_ptr<Course::TileBase>>& tiles);

    /**
     * @brief Returns a shared pointer to a Tile that has specified coordinate.
     * @param coordinate Requested Tile's Coordinate
     * @return a pointer to a Tile that has the given coordinate.
     * If no for the coordinate exists, return empty pointer.
     * @post Exception Guarantee: Basic
     */
    std::shared_ptr<Course::TileBase> getTile(
            const Course::Coordinate& coordinate);

    /**
     * @brief Returns a shared pointer to a Tile that has specified ID
     * @param id Tile's ObjectId.
     * @return a pointer to the Tile that has the given ID
     * If no for the id exists, return empty pointer.
     * @post Exception Guarantee: Basic
     */
    std::shared_ptr<Course::TileBase> getTile(const ObjectId& id);

    /**
     * @brief Returns a vector of shared pointers to Tiles specified by
     * a vector of Coordinates.
     * @param coordinates a vector of Coordinates for the requested Tiles
     * @return Vector of that contains pointers to Tile's that match
     * the coordinates. The vector is empty if no matches were made.
     * @post Exception Guarantee: Basic
     */
    std::vector<std::shared_ptr<Course::TileBase>> getTiles(
            const std::vector<Course::Coordinate>& coordinates);

    /**
     * @brief Returns a vector of all the neighbourTiles and the tile under the object
     * @param GameObject for the requested neighbour Tiles
     *
     * @return vector of Coordinates in the order of directions.
     * @post Exception guarantee: Strong
     */
    std::vector<std::shared_ptr<Course::GameObject>> getNeighbourTiles(std::shared_ptr<Course::GameObject> object,
                                                                    const int &radius = 1);

    /**
     * @brief Returns a vector of shared pointers to Tiles specified by
     * a vector of Coordinates.
     * @param coordinates a vector of Coordinates for the requested Tiles
     * @return Vector of that contains pointers to Tile's that match
     */
    std::vector<std::shared_ptr<Course::TileBase>> returnTiles();

    /**
     * @brief updates tile vector
     * @param coordinates a vector of Coordinates for the requested Tiles
     */
    void updateTileVector(std::vector<std::shared_ptr<Course::TileBase>> tiles);

private:
    std::vector<std::shared_ptr<Course::TileBase>> tileVector;
    std::vector<std::shared_ptr<Course::GameObject>> objectVector;
};

} // namespace Student

#endif // OBJECTMANAGER_HH
