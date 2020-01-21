#include <QtTest>

#include <memory>
#include "core/gameobject.h"
#include "core/playerbase.h"
#include "exceptions/keyerror.h"

using namespace Course;

class default_gameobjects : public QObject
{
    Q_OBJECT

public:
    default_gameobjects();
    ~default_gameobjects();

private slots:
    void test_setOwner();

    void test_setCoordinate_from_shared_ptr();
    void test_setCoordinate_from_instance();
    void test_unsetCoordinate();

    void test_setDescription();
    void test_setDescriptions();
    void test_addDescription();
    void test_addDescription_exception();

    void test_removeDescription();
    void test_removeDescription_exception();
    void test_clearDescriptions();

    void test_getDescription();
    void test_getDescription_exception();

    void cleanup();
private:
    const std::string DEF_PLAYER_NAME = "Player 1";
    const DescriptionMap DEF_DESCRIPTIONS = {
        {"title", "Default Object"},
        {"description", "Like goggles, I do nothing."}
    };
    const int DEF_COORDINATE_X = 0;
    const int DEF_COORDINATE_Y = 0;

    std::unique_ptr<GameObject> default_instance;

    std::shared_ptr<PlayerBase> def_player;
    std::shared_ptr<Coordinate> def_coordinate;

    bool descriptionMapsMatch(const DescriptionMap &l, const DescriptionMap &r);
};



default_gameobjects::default_gameobjects()
{
    default_instance = std::make_unique<GameObject>();
    def_player = std::make_shared<PlayerBase>(DEF_PLAYER_NAME);
    def_coordinate = std::make_shared<Coordinate>(DEF_COORDINATE_X,
                                                  DEF_COORDINATE_Y);
}

default_gameobjects::~default_gameobjects()
{

}

void default_gameobjects::cleanup()
{
    default_instance = std::make_unique<GameObject>();
    def_player = std::make_shared<PlayerBase>(DEF_PLAYER_NAME);
    def_coordinate = std::make_shared<Coordinate>(DEF_COORDINATE_X,
                                                  DEF_COORDINATE_Y);
}

bool default_gameobjects::descriptionMapsMatch(const DescriptionMap& l,
                                               const DescriptionMap& r)
{
    if(l.size() != r.size())
    {
        return false;
    }

    for( auto it = l.begin(); it != l.end(); ++it)
    {
        std::string l_key = (*it).first;
        std::string l_value = (*it).second;
        auto r_it = r.find(l_key);
        if(r_it == r.end())
        {
            return false;
        }
        if((*r_it).second != l_value)
        {
            return false;
        }
    }

    return true;
}


void default_gameobjects::test_setOwner()
{
    QVERIFY(not default_instance->getOwner());
    default_instance->setOwner(def_player);
    QVERIFY(default_instance->getOwner().get() == def_player.get());

    auto other_player = std::make_shared<PlayerBase>("Player 2");
    default_instance->setOwner(other_player);
    QVERIFY(default_instance->getOwner().get() == other_player.get());

}

void default_gameobjects::test_setCoordinate_from_shared_ptr()
{
    QVERIFY(not default_instance->getCoordinatePtr());
    default_instance->setCoordinate(def_coordinate);
    QVERIFY(*(default_instance->getCoordinatePtr().get()) ==
            *(def_coordinate.get()));

    auto other_coordinate = std::make_shared<Coordinate>(5,2);
    default_instance->setCoordinate(other_coordinate);
    QVERIFY(*(default_instance->getCoordinatePtr().get()) ==
            *(other_coordinate.get()));

}

void default_gameobjects::test_setCoordinate_from_instance()
{
    QVERIFY(not default_instance->getCoordinatePtr());

    Coordinate new_coordinate = Coordinate(1,2);
    Coordinate other_coordinate = Coordinate(3,5);

    default_instance->setCoordinate(new_coordinate);

    QVERIFY(*(default_instance->getCoordinatePtr().get()) ==
            new_coordinate);

    default_instance->setCoordinate(other_coordinate);

    QVERIFY(*(default_instance->getCoordinatePtr().get()) ==
            other_coordinate);
}

void default_gameobjects::test_unsetCoordinate()
{
    QVERIFY(not default_instance->getCoordinatePtr());
    default_instance->setCoordinate(def_coordinate);
    QVERIFY(*(default_instance->getCoordinatePtr().get()) ==
            *(def_coordinate.get()));
    default_instance->unsetCoordinate();
    QVERIFY(not default_instance->getCoordinatePtr());
}

void default_gameobjects::test_setDescription()
{
    QVERIFY(default_instance->getDescriptions().empty());
    default_instance->setDescriptions(DEF_DESCRIPTIONS);
    std::string key = DEF_DESCRIPTIONS.begin()->first;
    std::string old_content = DEF_DESCRIPTIONS.begin()->second;
    std::string new_content = "Hello!";
    QVERIFY(old_content != new_content);
    QVERIFY(default_instance->getDescription(key) == old_content);
    default_instance->setDescription(key, new_content);
    QVERIFY(default_instance->getDescription(key) == new_content);
}


void default_gameobjects::test_setDescriptions()
{
    QVERIFY(default_instance->getDescriptions().empty());
    default_instance->setDescriptions(DEF_DESCRIPTIONS);
    QVERIFY(descriptionMapsMatch(default_instance->getDescriptions(),
                                 DEF_DESCRIPTIONS));
}


void default_gameobjects::test_addDescription()
{
    QVERIFY(default_instance->getDescriptions().empty());
    std::string key = "title";
    std::string content = "Hello!";
    default_instance->addDescription(key, content);
    QVERIFY(default_instance->getDescription(key) == content);
}

void default_gameobjects::test_addDescription_exception()
{
    QVERIFY(default_instance->getDescriptions().empty());
    std::string key = "title";
    std::string content = "Hello!";
    default_instance->addDescription(key, content);
    QVERIFY(default_instance->getDescription(key) == content);
    QVERIFY_EXCEPTION_THROWN(default_instance->addDescription(key, "Bye!"),
                             KeyError);
    QVERIFY(default_instance->getDescription(key) == content);
}

void default_gameobjects::test_removeDescription()
{
    QVERIFY(default_instance->getDescriptions().empty());
    default_instance->setDescriptions(DEF_DESCRIPTIONS);
    std::string key = "greeting";
    std::string content = "Hello!";
    default_instance->addDescription(key, content);

    QVERIFY(default_instance->getDescriptions().size() ==
            DEF_DESCRIPTIONS.size() + 1);
    default_instance->removeDescription(key);

    QVERIFY(descriptionMapsMatch(default_instance->getDescriptions(),
                                 DEF_DESCRIPTIONS));
}

void default_gameobjects::test_removeDescription_exception()
{
    QVERIFY(default_instance->getDescriptions().empty());
    QVERIFY_EXCEPTION_THROWN(default_instance->removeDescription("any"),
                             KeyError);
    default_instance->setDescriptions(DEF_DESCRIPTIONS);
    QVERIFY(descriptionMapsMatch(default_instance->getDescriptions(),
                                 DEF_DESCRIPTIONS));
    QVERIFY_EXCEPTION_THROWN(default_instance->removeDescription("any"),
                             KeyError);
    QVERIFY(descriptionMapsMatch(default_instance->getDescriptions(),
                                 DEF_DESCRIPTIONS));
}

void default_gameobjects::test_clearDescriptions()
{
    QVERIFY(default_instance->getDescriptions().empty());
    default_instance->setDescriptions(DEF_DESCRIPTIONS);
    QVERIFY(descriptionMapsMatch(default_instance->getDescriptions(),
                                 DEF_DESCRIPTIONS));
    default_instance->removeDescriptions();
    QVERIFY(default_instance->getDescriptions().empty());
}

void default_gameobjects::test_getDescription()
{
    QVERIFY(default_instance->getDescriptions().empty());
    default_instance->setDescriptions(DEF_DESCRIPTIONS);
    QVERIFY(default_instance->getDescription(
                DEF_DESCRIPTIONS.begin()->first) ==
            DEF_DESCRIPTIONS.begin()->second);
}

void default_gameobjects::test_getDescription_exception()
{
    QVERIFY(default_instance->getDescriptions().empty());
    QVERIFY_EXCEPTION_THROWN(default_instance->getDescription("any"),
                             KeyError);
    default_instance->setDescriptions(DEF_DESCRIPTIONS);
    QVERIFY_EXCEPTION_THROWN(default_instance->getDescription("any"),
                             KeyError);
}

QTEST_APPLESS_MAIN(default_gameobjects)

#include "tst_default_gameobjects.moc"
