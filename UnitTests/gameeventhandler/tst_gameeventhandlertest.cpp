#include <QString>
#include <QtTest>
#include "core/resourcemaps.h"
#include "core/basicresources.h"
#include "gameeventhandler.hh"
#include "core/playerbase.h"
#include "player.h"

class GameeventhandlerTest : public QObject
{
    Q_OBJECT

public:
    GameeventhandlerTest();

private Q_SLOTS:
    void testCase1();
    void modifyResourcesTest();
};

GameeventhandlerTest::GameeventhandlerTest()
{
}

void GameeventhandlerTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

void GameeventhandlerTest::modifyResourcesTest()
{
    // Creata a resourcemap of costs where every cost is lower than player's resources
    const Course::ResourceMap enoughResources = {
        {Course::MONEY, 2},
        {Course::FOOD, 5},
        {Course::WOOD, 1},
        {Course::STONE, 1},
        {Course::ORE, 0},
    };

    // Creata a resourcemap of costs where some of the costs are higher than player's resources
    const Course::ResourceMap toolittleResources = {
        {Course::MONEY, 2000},
        {Course::FOOD, 5},
        {Course::WOOD, 50000},
        {Course::STONE, 1},
        {Course::ORE, 0},
    };

    // Create two int variables that are both over and under of the player's amount of money
    int enoughMoney = 500;
    int toolittleMoney = 2000;

    // Create the eventHandler and the student type player
    Student::GameEventHandler evehandler;
    std::shared_ptr<Student::Player> testPlayerStudent = std::make_shared<Student::Player>("testname");

    // Test modifyResources method when the player has enough resources
    bool test = evehandler.modifyResources(testPlayerStudent, enoughResources);

    // Test modifyResources method when the player doesn't have enough resources
    bool test2 = evehandler.modifyResources(testPlayerStudent, toolittleResources);

    // Test modifyResource method when the player has enough of the resource
    bool test3 = evehandler.modifyResource(testPlayerStudent, Course::MONEY, enoughMoney);

    // Test modifyResource method when the player doesn't have enough of the resource
    bool test4= evehandler.modifyResource(testPlayerStudent, Course::MONEY, toolittleMoney);

    QVERIFY(test == true);
    QVERIFY(test2 == false);
    QVERIFY(test3 == true);
    QVERIFY(test4 == false);
}

QTEST_APPLESS_MAIN(GameeventhandlerTest)

#include "tst_gameeventhandlertest.moc"
