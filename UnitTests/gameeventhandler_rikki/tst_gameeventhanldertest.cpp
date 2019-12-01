#include <QtTest>

#include "gameeventhandler"
#include "core/playerbase"


// add necessary includes here

class gameeventhanldertest : public QObject
{
    Q_OBJECT

public:
    gameeventhanldertest();
    ~gameeventhanldertest();

private slots:
    void test_case1();
    void modifyResource_test();

};

gameeventhanldertest::gameeventhanldertest()
{

}

gameeventhanldertest::~gameeventhanldertest()
{

}

void gameeventhanldertest::test_case1()
{

}

void gameeventhanldertest::modifyResource_test()
{
    //Student::
}


QTEST_APPLESS_MAIN(gameeventhanldertest)

#include "tst_gameeventhanldertest.moc"
