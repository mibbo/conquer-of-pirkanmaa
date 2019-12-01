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
    const Course::ResourceMap enoughResources = {
            {Course::MONEY, 2},
            {Course::FOOD, 5},
            {Course::WOOD, 1},
            {Course::STONE, 1},
            {Course::ORE, 0},
        };
        const Course::ResourceMap toolittleResources = {
            {Course::MONEY, 2000},
            {Course::FOOD, 5},
            {Course::WOOD, 50000},
            {Course::STONE, 1},
            {Course::ORE, 0},
        };

        int enoughMoney = 500;
        int toolittleMoney = 2000;


        Student::GameEventHandler evehandler;
        std::shared_ptr<Student::Player> testPlayerStudent = std::make_shared<Student::Player>("testname");
        std::shared_ptr<Course::PlayerBase> testPlayer = std::make_shared<Course::PlayerBase>("testname");

        bool test = evehandler.modifyResources(testPlayer, enoughResources);
        bool test2 = evehandler.modifyResources(testPlayer, toolittleResources);
//        bool test3 = evehandler.modifyResource(testPlayer, Course::MONEY, enoughMoney);
//        bool test4= evehandler.modifyResource(testPlayer, Course::MONEY, toolittleMoney);

        QVERIFY(test == true);
        QVERIFY(test2 == false);
//        QVERIFY(test3 == false);
//        QVERIFY(test4 == false);
}

QTEST_APPLESS_MAIN(GameeventhandlerTest)

#include "tst_gameeventhandlertest.moc"
