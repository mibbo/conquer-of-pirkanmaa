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
    std::shared_ptr<Student::ObjectManager> objManager = std::make_shared<Student::ObjectManager>();
    std::shared_ptr<Student::GameEventHandler> eveHandler = std::make_shared<Student::GameEventHandler>();

    Course::Coordinate mountainTileCoordinate(0,0);
    Course::Coordinate cobbleTileCoordinate(10,10);
    Course::Coordinate forestTileCoordinate(20, 20);
    Course::Coordinate otherForestTileCoordinate(50, 30);


    Course::Coordinate forestNeighbourCoordinate(20, 21);

    Course::Coordinate noneTileCoordinate(25, 5);


    std::shared_ptr<Student::Mountain> mountainTile = std::make_shared<Student::Mountain>(mountainTileCoordinate, eveHandler, objManager);
    std::shared_ptr<Student::Cobblestone> cobbleTile = std::make_shared<Student::Cobblestone>(cobbleTileCoordinate, eveHandler, objManager);
    std::shared_ptr<Course::Forest> forestTile = std::make_shared<Course::Forest>(forestTileCoordinate, eveHandler, objManager);
    std::shared_ptr<Student::Mountain> forestNeighbour = std::make_shared<Student::Mountain>(forestNeighbourCoordinate, eveHandler, objManager);
    std::shared_ptr<Course::Forest> otherForestTile = std::make_shared<Course::Forest>(otherForestTileCoordinate, eveHandler, objManager);

    std::vector<std::shared_ptr<Course::TileBase>> tileVector = {mountainTile, cobbleTile, forestTile, forestNeighbour};

    objManager->addTiles(tileVector);

    bool test1 = (objManager->returnTiles() == tileVector);
    bool test2 = (objManager->getTile(forestTileCoordinate)->getType() == tileVector.at(2)->getType());
    bool test3 = (objManager->getTile(1)->getType() == tileVector.at(1)->getType());

    std::vector<Course::Coordinate> coordinateVector = {mountainTileCoordinate, cobbleTileCoordinate};
    std::vector<std::shared_ptr<Course::TileBase>> tileVectorForCoordinates = {mountainTile, cobbleTile};

    bool test4 = (objManager->getTiles(coordinateVector) == tileVectorForCoordinates);

    std::vector<std::shared_ptr<Course::GameObject>> neighbourTiles = objManager->getNeighbourTiles(forestTile);

    bool test5 = (neighbourTiles.size() > 0 && neighbourTiles.at(neighbourTiles.size()-1)->getType() == forestNeighbour->getType());

    std::vector<std::shared_ptr<Course::TileBase>> otherTileVector = {forestTile, cobbleTile, otherForestTile};

    objManager->updateTileVector(otherTileVector);

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
