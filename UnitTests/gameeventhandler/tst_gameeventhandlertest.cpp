#include <QString>
#include <QtTest>

class GameeventhandlerTest : public QObject
{
    Q_OBJECT

public:
    GameeventhandlerTest();

private Q_SLOTS:
    void testCase1();
};

GameeventhandlerTest::GameeventhandlerTest()
{
}

void GameeventhandlerTest::testCase1()
{
    QVERIFY(true == false);
}

QTEST_APPLESS_MAIN(GameeventhandlerTest)

#include "tst_gameeventhandlertest.moc"
