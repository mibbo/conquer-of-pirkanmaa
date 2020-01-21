#include <QString>
#include <QtTest>

#include "core/basicresources.h"

using namespace Course;

class Resourcemap_operationsTest : public QObject
{
    Q_OBJECT

public:
    Resourcemap_operationsTest();

private Q_SLOTS:
    void merge_RM();
    void merge_RMD();
    void multiply();

private:

    const ResourceMap RM1 = {
        {NONE, 10},
        {MONEY, 20},
        {FOOD, 30},
        {WOOD, 40},
        {STONE, 50},
        {ORE, 60}
    };
    const ResourceMap RM_SHORT = {
        {NONE, 5},
        {MONEY, 5},
        {FOOD, 5}
    };

    const ResourceMap RM_NEG = {
        {NONE, -5},
        {MONEY, 6},
        {FOOD, -1},
        {WOOD, -20},
        {STONE, 0},
        {ORE, -100}
    };


    const ResourceMapDouble RMD1 = {
        {NONE, 1.0},
        {MONEY, 2.0},
        {FOOD, 3.0},
        {WOOD, 4.0},
        {STONE, 5.0},
        {ORE, 6.0}
    };

    const ResourceMapDouble RMD_HALF = {
        {NONE, 0.5},
        {MONEY, 0.5},
        {FOOD, 0.5},
        {WOOD, 0.5},
        {STONE, 0.5},
        {ORE, 0.5}
    };

};

Resourcemap_operationsTest::Resourcemap_operationsTest()
{
}

void Resourcemap_operationsTest::merge_RM()
{
    ResourceMap result = {
        {NONE, 15},
        {MONEY, 25},
        {FOOD, 35},
        {WOOD, 40},
        {STONE, 50},
        {ORE, 60}
    };

    QVERIFY(result == mergeResourceMaps(RM1, RM_SHORT));
}

void Resourcemap_operationsTest::merge_RMD()
{
    const ResourceMapDouble result = {
        {NONE, 1.5},
        {MONEY, 2.5},
        {FOOD, 3.5},
        {WOOD, 4.5},
        {STONE, 5.5},
        {ORE, 6.5}
    };

    QVERIFY(result == mergeResourceMapDoubles(RMD1, RMD_HALF));
}

void Resourcemap_operationsTest::multiply()
{
    const ResourceMap result = {
        {NONE, 5},
        {MONEY, 10},
        {FOOD, 15},
        {WOOD, 20},
        {STONE, 25},
        {ORE, 30}
    };

    QVERIFY(result == multiplyResourceMap(RM1, RMD_HALF));
}



QTEST_APPLESS_MAIN(Resourcemap_operationsTest)

#include "tst_resourcemap_operationstest.moc"
