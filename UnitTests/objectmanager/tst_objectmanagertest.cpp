#include <QString>
#include <QtTest>
#include <vector>
#include "gameeventhandler.hh"
#include "objectmanager.hh"
#include "tiles/forest.h"
#include "mountain.hh"
#include "cobblestone.hh"
#include "core/coordinate.h"
#include "core/gameobject.h"
#include "tiles/tilebase.h"

class ObjectmanagerTest : public QObject
{
    Q_OBJECT

public:
    ObjectmanagerTest();

private Q_SLOTS:
    void testCase1();
    void tileTest();
};

ObjectmanagerTest::ObjectmanagerTest()
{
}

void ObjectmanagerTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

void ObjectmanagerTest::tileTest()
{
    // Create the objectManager and the gameEventHandler
    std::shared_ptr<Student::ObjectManager> objManager = std::make_shared<Student::ObjectManager>();
    std::shared_ptr<Student::GameEventHandler> eveHandler = std::make_shared<Student::GameEventHandler>();

    // Create the coordinates for the soon to be created tiles
    Course::Coordinate mountainTileCoordinate(0,0);
    Course::Coordinate cobbleTileCoordinate(10,10);
    Course::Coordinate forestTileCoordinate(20, 20);
    Course::Coordinate otherForestTileCoordinate(50, 30);
    Course::Coordinate forestNeighbourCoordinate(20, 21);

    // Create the tiles from the previously created coordinates
    std::shared_ptr<Student::Mountain> mountainTile = std::make_shared<Student::Mountain>(mountainTileCoordinate, eveHandler, objManager);
    std::shared_ptr<Student::Cobblestone> cobbleTile = std::make_shared<Student::Cobblestone>(cobbleTileCoordinate, eveHandler, objManager);
    std::shared_ptr<Course::Forest> forestTile = std::make_shared<Course::Forest>(forestTileCoordinate, eveHandler, objManager);
    std::shared_ptr<Student::Mountain> forestNeighbour = std::make_shared<Student::Mountain>(forestNeighbourCoordinate, eveHandler, objManager);
    std::shared_ptr<Course::Forest> otherForestTile = std::make_shared<Course::Forest>(otherForestTileCoordinate, eveHandler, objManager);

    // Create a vector of some of the tiles and add it to the
    std::vector<std::shared_ptr<Course::TileBase>> tileVector = {mountainTile, cobbleTile, forestTile, forestNeighbour};
    objManager->addTiles(tileVector);

    // Test if the addTiles method and returnTiles method "have" the same tiles as the manually created tileVector
    bool test1 = (objManager->returnTiles() == tileVector);

    // Test if the getTile(coordinate) gives the right tile
    bool test2 = (objManager->getTile(forestTileCoordinate)->getType() == tileVector.at(2)->getType());

    // Test if the getTile(id) gives the right tile
    bool test3 = (objManager->getTile(1)->getType() == tileVector.at(1)->getType());

    // Createa a vector of some of the coordinates and a vector of tiles that have those coordinates in the same order
    std::vector<Course::Coordinate> coordinateVector = {mountainTileCoordinate, cobbleTileCoordinate};
    std::vector<std::shared_ptr<Course::TileBase>> tileVectorForCoordinates = {mountainTile, cobbleTile};

    // Test if the getTiles(vector with coordinates) returns a vector with the right tiles
    bool test4 = (objManager->getTiles(coordinateVector) == tileVectorForCoordinates);

    // Get a vector of the forestTile's neighbours
    std::vector<std::shared_ptr<Course::GameObject>> neighbourTiles = objManager->getNeighbourTiles(forestTile);

    // Test if the last tile (first tile is the tested tile itself) has the same type as the supposed neighbour tile
    bool test5 = (neighbourTiles.size() > 0 && neighbourTiles.at(neighbourTiles.size()-1)->getType() == forestNeighbour->getType());

    // Create a new vector of the previously created tiles and update the objectManager's vector of tiles
    std::vector<std::shared_ptr<Course::TileBase>> otherTileVector = {forestTile, cobbleTile, otherForestTile};
    objManager->updateTileVector(otherTileVector);

    // Test if the returnTiles() returns a vector with the right tiles
    bool test6 = (objManager->returnTiles() == otherTileVector);

    QVERIFY(test1 == true);
    QVERIFY(test2 == true);
    QVERIFY(test3 == true);
    QVERIFY(test4 == true);
    QVERIFY(test5 == true);
    QVERIFY(test6 == true);

}
QTEST_APPLESS_MAIN(ObjectmanagerTest)

#include "tst_objectmanagertest.moc"
