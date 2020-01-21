#include <QString>
#include <QtTest>

#include <memory>
#include "core/playerbase.h"
#include "core/coordinate.h"
#include "tiles/tilebase.h"
#include "core/placeablegameobject.h"
#include "exceptions/ownerconflict.h"


using namespace Course;


class default_test : public QObject
{
    Q_OBJECT

public:
    default_test();

private Q_SLOTS:
    void test_canBePlacedOnTile_same_owner();
    void test_canBePlacedOnTile_ownerconflict();
    void test_canBePlacedOnTile_no_owner_for_tile();
    void test_canBePlacedOnTile_no_owner_for_object();
    void test_canBePlacedOnTile_no_owners();


    void test_setLocationTile();
    void test_unsetLocationTile();
    void test_setLocationTile_exception();

    void test_currentLocationTile_expired_ptr();

    void cleanup();

private:
    std::shared_ptr<PlayerBase> player1;
    std::shared_ptr<PlayerBase> player2;
    std::shared_ptr<TileBase> tile;

    const Coordinate tile_coordinate = {1,1};

    std::shared_ptr<PlaceableGameObject> default_object;
};

default_test::default_test()
{
    player1 = std::make_shared<PlayerBase>("player1");
    player2 = std::make_shared<PlayerBase>("player2");
    tile = std::make_shared<TileBase>(tile_coordinate, nullptr, nullptr);
    default_object = std::make_shared<PlaceableGameObject>(
                nullptr, nullptr, nullptr, 1);
}


void default_test::cleanup()
{
    tile = std::make_shared<TileBase>(tile_coordinate, nullptr, nullptr);
    default_object = std::make_shared<PlaceableGameObject>(
                nullptr, nullptr, nullptr, 1);
}

void default_test::test_canBePlacedOnTile_same_owner()
{
    tile->setOwner(player1);
    default_object->setOwner(player1);

    QVERIFY(default_object->getOwner() == player1);
    QVERIFY(tile->getOwner() == player1);
    QVERIFY(default_object->canBePlacedOnTile(tile));
}

void default_test::test_canBePlacedOnTile_ownerconflict()
{
    tile->setOwner(player1);
    default_object->setOwner(player2);

    QVERIFY(default_object->getOwner() == player2);
    QVERIFY(tile->getOwner() == player1);
    QVERIFY(not default_object->canBePlacedOnTile(tile));
}

void default_test::test_canBePlacedOnTile_no_owner_for_tile()
{
    default_object->setOwner(player1);

    QVERIFY(default_object->getOwner() == player1);
    QVERIFY(tile->getOwner() == nullptr);
    QVERIFY(default_object->canBePlacedOnTile(tile));
}

void default_test::test_canBePlacedOnTile_no_owner_for_object()
{
    tile->setOwner(player1);

    QVERIFY(default_object->getOwner() == nullptr);
    QVERIFY(tile->getOwner() == player1);
    QVERIFY(default_object->canBePlacedOnTile(tile));
}

void default_test::test_canBePlacedOnTile_no_owners()
{
    QVERIFY(default_object->getOwner() == nullptr);
    QVERIFY(tile->getOwner() == nullptr);
    QVERIFY(default_object->canBePlacedOnTile(tile));
}

void default_test::test_setLocationTile()
{
    QVERIFY(default_object->currentLocationTile() == nullptr);
    default_object->setLocationTile(tile);
    QVERIFY(default_object->currentLocationTile() == tile);
}

void default_test::test_unsetLocationTile()
{
    QVERIFY(default_object->currentLocationTile() == nullptr);
    default_object->setLocationTile(tile);
    QVERIFY(default_object->currentLocationTile() == tile);
    default_object->setLocationTile(nullptr);
    QVERIFY(default_object->currentLocationTile() == nullptr);
}

void default_test::test_setLocationTile_exception()
{
    default_object->setOwner(player1);
    tile->setOwner(player2);

    QVERIFY(not default_object->canBePlacedOnTile(tile));
    QVERIFY_EXCEPTION_THROWN(default_object->setLocationTile(tile),
                             OwnerConflict);
}


void default_test::test_currentLocationTile_expired_ptr()
{
    QVERIFY(default_object->currentLocationTile() == nullptr);
    default_object->setLocationTile(tile);
    QVERIFY(default_object->currentLocationTile() == tile);
    tile = {};
    QVERIFY(default_object->currentLocationTile() == nullptr);
}



QTEST_APPLESS_MAIN(default_test)

#include "tst_default_test.moc"
