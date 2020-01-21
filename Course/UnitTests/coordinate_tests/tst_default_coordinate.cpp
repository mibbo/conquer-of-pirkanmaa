#include <QtTest>

#include <ctime>
#include <cstdlib>

#include "core/coordinate.h"


using namespace Course;

class default_coordinate : public QObject
{
    Q_OBJECT

public:
    default_coordinate();
    ~default_coordinate();

private slots:
    void test_copy_constructor();
    void test_copy_constructor_with_direction();
    void test_copy_constructor_with_direction_data();

    void test_copy_constructor_with_direction_and_distance();
    void test_copy_constructor_with_direction_and_distance_data();

    // Travelling test
    void test_travel();

    // Neighbour tests
    void test_neighbour_at();
    void test_neighbour_at_data();
    void test_neighbours();
    void test_neighbours_data();

    // Coordinate combining tests
    void test_operator_plus();
    void test_operator_plus_data();
    void test_operator_plus_assign();
    void test_operator_plus_assign_data();

    void test_operator_minus();
    void test_operator_minus_data();
    void test_operator_minus_assign();
    void test_operator_minus_assign_data();

    void test_operator_assign();


    // Comparison operator tests
    void test_comp_eq();
    void test_comp_eq_data();
    void test_comp_neq();
    void test_comp_neq_data();
    void test_comp_lt();
    void test_comp_lt_data();
    void test_comp_gt();
    void test_comp_gt_data();
    void test_comp_elt();
    void test_comp_elt_data();
    void test_comp_egt();
    void test_comp_egt_data();

private:
    const Coordinate ORIGIN = Coordinate(0,0);
};



default_coordinate::default_coordinate()
{
}

default_coordinate::~default_coordinate()
{
}

void default_coordinate::test_copy_constructor()
{
    srand((unsigned)time(0));
    int x = 0;
    int y = 0;

    for( int i = 0; i < 5; ++i)
    {
        x = rand();
        y = rand();

        Coordinate original = Coordinate(x ,y);
        Coordinate copy = Coordinate(original);

        QVERIFY(original.x() == copy.x() and original.y() == copy.y());
    }
}

void default_coordinate::test_copy_constructor_with_direction()
{
    QFETCH(int, direction_int);
    QFETCH(int, x);
    QFETCH(int, y);

    Coordinate copy = Coordinate(ORIGIN, (Direction)direction_int);

    QCOMPARE(copy.x(), x);
    QCOMPARE(copy.y(), y);
}

void default_coordinate::test_copy_constructor_with_direction_data()
{
    QTest::addColumn<int>("direction_int");
    QTest::addColumn<int>("x");
    QTest::addColumn<int>("y");

    QTest::newRow("N") << 0 <<  0 << 1;
    QTest::newRow("NE") << 1 << 1 << 1;
    QTest::newRow("E") << 2 << 1 << 0;
    QTest::newRow("SE") << 3 << 1 << -1;
    QTest::newRow("S") << 4 << 0 << -1;
    QTest::newRow("SW") << 5 << -1 << -1;
    QTest::newRow("W") << 6 << -1 << 0;
    QTest::newRow("NW") << 7 << -1 << 1;
}

void default_coordinate::test_copy_constructor_with_direction_and_distance()
{
    QFETCH(int, direction_int);
    QFETCH(int, x);
    QFETCH(int, y);
    QFETCH(int, distance);

    Coordinate copy = Coordinate(ORIGIN, (Direction)direction_int, distance);

    QCOMPARE(copy.x(), x);
    QCOMPARE(copy.y(), y);
}

void default_coordinate::test_copy_constructor_with_direction_and_distance_data()
{
    QTest::addColumn<int>("direction_int");
    QTest::addColumn<int>("x");
    QTest::addColumn<int>("y");
    QTest::addColumn<int>("distance");

    QTest::newRow("N, 0") << 0 <<  0 << 0 << 0;
    QTest::newRow("NE, 2") << 1 << 2 << 2 << 2;
    QTest::newRow("E, -1") << 2 << -1 << 0 << -1;
    QTest::newRow("SE, 3") << 3 << 3 << -3 << 3;
}


void default_coordinate::test_travel()
{
    Coordinate traveller = Coordinate(ORIGIN);
    QVERIFY(traveller.x() == 0 and traveller.y() == 0);
    traveller.travel(Direction::N, 3);
    QVERIFY(traveller.x() == 0 and traveller.y() == 3);
    traveller.travel(Direction::SE, 2);
    QVERIFY(traveller.x() == 2 and traveller.y() == 1);
    traveller.travel(Direction::W, 7);
    QVERIFY(traveller.x() == -5 and traveller.y() == 1);
}

void default_coordinate::test_neighbour_at()
{
    QFETCH(int, direction);
    QFETCH(int, origin_x);
    QFETCH(int, origin_y);
    QFETCH(int, neighbour_x);
    QFETCH(int, neighbour_y);
    QFETCH(int, distance);

    Coordinate origin(origin_x, origin_y);
    Coordinate neighbour(origin.neighbour_at((Direction)direction, distance));

    QVERIFY(neighbour.x() == neighbour_x and neighbour.y() == neighbour_y);

}

void default_coordinate::test_neighbour_at_data()
{
    QTest::addColumn<int>("direction");
    QTest::addColumn<int>("origin_x");
    QTest::addColumn<int>("origin_y");
    QTest::addColumn<int>("neighbour_x");
    QTest::addColumn<int>("neighbour_y");
    QTest::addColumn<int>("distance");


    QTest::newRow("0,0 --(N,1)--> 0,1") << 0 <<  0 << 0 << 0 << 1 << 1;
    QTest::newRow("1,4 --(NE,2)--> 3,6") << 1 << 1 << 4 << 3 << 6 << 2;
    QTest::newRow("3,3 --(E,-1)--> 2,3") << 2 << 3 << 3 << 2 << 3 << -1;
    QTest::newRow("-2,-1 --(SE,3)--> 1,-4") << 3 << -2 << -1 << 1 << -4 << 3;
}

void default_coordinate::test_neighbours()
{
    QFETCH(int, origin_x);
    QFETCH(int, origin_y);
    QFETCH(int, radius);

    Coordinate origin(origin_x, origin_y);

    std::vector<Coordinate> neighbours = origin.neighbours(radius);

    int x_lower_limit = origin_x - radius;
    int x_upper_limit = origin_x + radius;
    int y_lower_limit = origin_y - radius;
    int y_upper_limit = origin_y + radius;

    unsigned int size_x = radius * 2 + 1;

    unsigned int total_coords = size_x * size_x - 1;

    std::string msg =
            "size: " + std::to_string(neighbours.size()) +
            "  total_coords: " + std::to_string(total_coords);

    QVERIFY2(neighbours.size() == total_coords, msg.c_str());

    for( auto it = neighbours.begin(); it != neighbours.end(); ++it )
    {
        bool found = false;

        for( int x = x_lower_limit; x <= x_upper_limit; ++x )
        {
            if( x == it->x() )
            {
                for( int y = y_lower_limit; y <= y_upper_limit; ++y )
                {
                    if( y == it->y() )
                    {
                        QVERIFY2(not( (it->y() == origin_y) and
                                (it->x() == origin_x)),
                                 msg.c_str() );
                        found = true;
                        goto loop_exit;
                    }
                }
            }
        }
        loop_exit:

        QVERIFY(found);
    }
}

void default_coordinate::test_neighbours_data()
{
    QTest::addColumn<int>("origin_x");
    QTest::addColumn<int>("origin_y");
    QTest::addColumn<int>("radius");

    QTest::newRow("0,0 radius 1") << 0 << 0 << 1;
    QTest::newRow("1,-4 radius 4") << 1 << -4 << 4;
}

void default_coordinate::test_operator_plus()
{
    QFETCH(int, origin_x);
    QFETCH(int, origin_y);
    QFETCH(int, plus_x);
    QFETCH(int, plus_y);

    Coordinate origin(origin_x, origin_y);
    Coordinate plus(plus_x, plus_y);

    Coordinate res = origin + plus;

    QVERIFY(origin.x() == origin_x and origin.y() == origin_y);
    QVERIFY(plus.x() == plus_x and plus.y() == plus_y);
    QVERIFY(res.x() == (origin_x + plus_x) and res.y() == (origin_y + plus_y));

}

void default_coordinate::test_operator_plus_data()
{
    QTest::addColumn<int>("origin_x");
    QTest::addColumn<int>("origin_y");
    QTest::addColumn<int>("plus_x");
    QTest::addColumn<int>("plus_y");

    QTest::newRow("0,0 + 1,1") << 0 << 0 << 1 << 1;
    QTest::newRow("3,2 + -1,3") << 3 << 2 << -1 << 3;
    QTest::newRow("-3,12 + 0,-1") << 3 << -12 << 0 << -1;
    QTest::newRow("5,2 + -4,-1") << 5 << 2 << -4 << -1;

}

void default_coordinate::test_operator_plus_assign()
{
    QFETCH(int, origin_x);
    QFETCH(int, origin_y);
    QFETCH(int, plus_x);
    QFETCH(int, plus_y);

    Coordinate origin(origin_x, origin_y);
    Coordinate plus(plus_x, plus_y);

    origin += plus;

    QVERIFY(plus.x() == plus_x and plus.y() == plus_y);
    QVERIFY(origin.x() == (origin_x + plus_x) and
            origin.y() == (origin_y + plus_y));
}

void default_coordinate::test_operator_plus_assign_data()
{
    QTest::addColumn<int>("origin_x");
    QTest::addColumn<int>("origin_y");
    QTest::addColumn<int>("plus_x");
    QTest::addColumn<int>("plus_y");

    QTest::newRow("0,0 += 1,1") << 0 << 0 << 1 << 1;
    QTest::newRow("3,2 += -1,3") << 3 << 2 << -1 << 3;
    QTest::newRow("-3,12 += 0,-1") << 3 << -12 << 0 << -1;
    QTest::newRow("5,2 += -4,-1") << 5 << 2 << -4 << -1;
}

void default_coordinate::test_operator_minus()
{
    QFETCH(int, origin_x);
    QFETCH(int, origin_y);
    QFETCH(int, plus_x);
    QFETCH(int, plus_y);

    Coordinate origin(origin_x, origin_y);
    Coordinate plus(plus_x, plus_y);

    Coordinate res = origin - plus;

    QVERIFY(origin.x() == origin_x and origin.y() == origin_y);
    QVERIFY(plus.x() == plus_x and plus.y() == plus_y);
    QVERIFY(res.x() == (origin_x - plus_x) and res.y() == (origin_y - plus_y));
}

void default_coordinate::test_operator_minus_data()
{
    QTest::addColumn<int>("origin_x");
    QTest::addColumn<int>("origin_y");
    QTest::addColumn<int>("plus_x");
    QTest::addColumn<int>("plus_y");

    QTest::newRow("0,0 - 1,1") << 0 << 0 << 1 << 1;
    QTest::newRow("3,2 - -1,3") << 3 << 2 << -1 << 3;
    QTest::newRow("-3,12 - 0,-1") << 3 << -12 << 0 << -1;
    QTest::newRow("5,2 - -4,-1") << 5 << 2 << -4 << -1;
}

void default_coordinate::test_operator_minus_assign()
{
    QFETCH(int, origin_x);
    QFETCH(int, origin_y);
    QFETCH(int, plus_x);
    QFETCH(int, plus_y);

    Coordinate origin(origin_x, origin_y);
    Coordinate plus(plus_x, plus_y);

    origin -= plus;

    QVERIFY(plus.x() == plus_x and plus.y() == plus_y);
    QVERIFY(origin.x() == (origin_x - plus_x) and
            origin.y() == (origin_y - plus_y));
}

void default_coordinate::test_operator_minus_assign_data()
{
    QTest::addColumn<int>("origin_x");
    QTest::addColumn<int>("origin_y");
    QTest::addColumn<int>("plus_x");
    QTest::addColumn<int>("plus_y");

    QTest::newRow("0,0 -= 1,1") << 0 << 0 << 1 << 1;
    QTest::newRow("3,2 -= -1,3") << 3 << 2 << -1 << 3;
    QTest::newRow("-3,12 -= 0,-1") << 3 << -12 << 0 << -1;
    QTest::newRow("5,2 -= -4,-1") << 5 << 2 << -4 << -1;
}

void default_coordinate::test_operator_assign()
{
    Coordinate other(1,1);
    QVERIFY(other.x() != ORIGIN.x() and other.y() != ORIGIN.y());
    other = ORIGIN;
    QVERIFY( other.x() == ORIGIN.x() and other.y() == ORIGIN.y());
}

void default_coordinate::test_comp_eq()
{      
    QFETCH(int, l_x);
    QFETCH(int, l_y);
    QFETCH(int, r_x);
    QFETCH(int, r_y);
    QFETCH(bool, eq);

    Coordinate l(l_x, l_y);
    Coordinate r(r_x, r_y);

    QVERIFY( (l == r) == eq );
}

void default_coordinate::test_comp_eq_data()
{
    QTest::addColumn<int>("l_x");
    QTest::addColumn<int>("l_y");
    QTest::addColumn<int>("r_x");
    QTest::addColumn<int>("r_y");
    QTest::addColumn<bool>("eq");

    QTest::addRow("1,1 == 1,1") << 1 << 1 << 1 << 1 << true;
    QTest::addRow("1,1 == 0,0") << 1 << 1 << 0 << 0 << false;
    QTest::addRow("1,-1 == 1,1") << 1 << -1 << 1 << 1 << false;
    QTest::addRow("1,-1 == 1,-1") << 1 << -1 << 1 << -1 << true;
    QTest::addRow("-2,5 == 2,5") << -2 << 5 << 2 << 5 << false;
    QTest::addRow("-2,5 == -2,5") << -2 << 5 << -2 << 5 << true;
    QTest::addRow("-2,-5 == 2,5") << -2 << -5 << 2 << 5 << false;
    QTest::addRow("-2,-5 == -2,-5") << -2 << -5 << -2 << -5 << true;
}

void default_coordinate::test_comp_neq()
{
    QFETCH(int, l_x);
    QFETCH(int, l_y);
    QFETCH(int, r_x);
    QFETCH(int, r_y);
    QFETCH(bool, eq);

    Coordinate l(l_x, l_y);
    Coordinate r(r_x, r_y);

    QVERIFY( (l != r) != eq );
}

void default_coordinate::test_comp_neq_data()
{
    QTest::addColumn<int>("l_x");
    QTest::addColumn<int>("l_y");
    QTest::addColumn<int>("r_x");
    QTest::addColumn<int>("r_y");
    QTest::addColumn<bool>("eq");

    QTest::addRow("1,1 == 1,1") << 1 << 1 << 1 << 1 << true;
    QTest::addRow("1,1 == 0,0") << 1 << 1 << 0 << 0 << false;
    QTest::addRow("1,-1 == 1,1") << 1 << -1 << 1 << 1 << false;
    QTest::addRow("1,-1 == 1,-1") << 1 << -1 << 1 << -1 << true;
    QTest::addRow("-2,5 == 2,5") << -2 << 5 << 2 << 5 << false;
    QTest::addRow("-2,5 == -2,5") << -2 << 5 << -2 << 5 << true;
    QTest::addRow("-2,-5 == 2,5") << -2 << -5 << 2 << 5 << false;
    QTest::addRow("-2,-5 == -2,-5") << -2 << -5 << -2 << -5 << true;

}

void default_coordinate::test_comp_lt()
{
    QFETCH(int, l_x);
    QFETCH(int, l_y);
    QFETCH(int, r_x);
    QFETCH(int, r_y);
    QFETCH(bool, res);

    Coordinate l(l_x, l_y);
    Coordinate r(r_x, r_y);

    QVERIFY( (l < r) == res );
}

void default_coordinate::test_comp_lt_data()
{
    QTest::addColumn<int>("l_x");
    QTest::addColumn<int>("l_y");
    QTest::addColumn<int>("r_x");
    QTest::addColumn<int>("r_y");
    QTest::addColumn<bool>("res");

    QTest::addRow("1,1 < 2,2") << 1 << 1 << 2 << 2 << true;
    QTest::addRow("1,1 < 2,1") << 1 << 1 << 2 << 1 << true;
    QTest::addRow("1,1 < 2,0") << 1 << 1 << 2 << 0 << true;
    QTest::addRow("1,1 < 1,2") << 1 << 1 << 1 << 2 << true;
    QTest::addRow("1,1 < 1,1") << 1 << 1 << 1 << 1 << false;
    QTest::addRow("1,1 < 1,0") << 1 << 1 << 1 << 0 << false;
    QTest::addRow("1,1 < 0,2") << 1 << 1 << 0 << 2 << false;
    QTest::addRow("1,1 < 0,1") << 1 << 1 << 0 << 1 << false;
    QTest::addRow("1,1 < 0,0") << 1 << 1 << 0 << 0 << false;
}

void default_coordinate::test_comp_gt()
{

    QFETCH(int, l_x);
    QFETCH(int, l_y);
    QFETCH(int, r_x);
    QFETCH(int, r_y);
    QFETCH(bool, res);

    Coordinate l(l_x, l_y);
    Coordinate r(r_x, r_y);

    QVERIFY( (l > r) == res );
}

void default_coordinate::test_comp_gt_data()
{
    QTest::addColumn<int>("l_x");
    QTest::addColumn<int>("l_y");
    QTest::addColumn<int>("r_x");
    QTest::addColumn<int>("r_y");
    QTest::addColumn<bool>("res");

    QTest::addRow("1,1 > 2,2") << 1 << 1 << 2 << 2 << false;
    QTest::addRow("1,1 > 2,1") << 1 << 1 << 2 << 1 << false;
    QTest::addRow("1,1 > 2,0") << 1 << 1 << 2 << 0 << false;
    QTest::addRow("1,1 > 1,2") << 1 << 1 << 1 << 2 << false;
    QTest::addRow("1,1 > 1,1") << 1 << 1 << 1 << 1 << false;
    QTest::addRow("1,1 > 1,0") << 1 << 1 << 1 << 0 << true;
    QTest::addRow("1,1 > 0,2") << 1 << 1 << 0 << 2 << true;
    QTest::addRow("1,1 > 0,1") << 1 << 1 << 0 << 1 << true;
    QTest::addRow("1,1 > 0,0") << 1 << 1 << 0 << 0 << true;
}

void default_coordinate::test_comp_elt()
{

    QFETCH(int, l_x);
    QFETCH(int, l_y);
    QFETCH(int, r_x);
    QFETCH(int, r_y);
    QFETCH(bool, res);

    Coordinate l(l_x, l_y);
    Coordinate r(r_x, r_y);

    QVERIFY( (l <= r) == res );
}

void default_coordinate::test_comp_elt_data()
{
    QTest::addColumn<int>("l_x");
    QTest::addColumn<int>("l_y");
    QTest::addColumn<int>("r_x");
    QTest::addColumn<int>("r_y");
    QTest::addColumn<bool>("res");

    QTest::addRow("1,1 <= 2,2") << 1 << 1 << 2 << 2 << true;
    QTest::addRow("1,1 <= 2,1") << 1 << 1 << 2 << 1 << true;
    QTest::addRow("1,1 <= 2,0") << 1 << 1 << 2 << 0 << true;
    QTest::addRow("1,1 <= 1,2") << 1 << 1 << 1 << 2 << true;
    QTest::addRow("1,1 <= 1,1") << 1 << 1 << 1 << 1 << true;
    QTest::addRow("1,1 <= 1,0") << 1 << 1 << 1 << 0 << false;
    QTest::addRow("1,1 <= 0,2") << 1 << 1 << 0 << 2 << false;
    QTest::addRow("1,1 <= 0,1") << 1 << 1 << 0 << 1 << false;
    QTest::addRow("1,1 <= 0,0") << 1 << 1 << 0 << 0 << false;
}

void default_coordinate::test_comp_egt()
{

    QFETCH(int, l_x);
    QFETCH(int, l_y);
    QFETCH(int, r_x);
    QFETCH(int, r_y);
    QFETCH(bool, res);

    Coordinate l(l_x, l_y);
    Coordinate r(r_x, r_y);

    QVERIFY( (l >= r) == res );
}

void default_coordinate::test_comp_egt_data()
{
    QTest::addColumn<int>("l_x");
    QTest::addColumn<int>("l_y");
    QTest::addColumn<int>("r_x");
    QTest::addColumn<int>("r_y");
    QTest::addColumn<bool>("res");

    QTest::addRow("1,1 >= 2,2") << 1 << 1 << 2 << 2 << false;
    QTest::addRow("1,1 >= 2,1") << 1 << 1 << 2 << 1 << false;
    QTest::addRow("1,1 >= 2,0") << 1 << 1 << 2 << 0 << false;
    QTest::addRow("1,1 >= 1,2") << 1 << 1 << 1 << 2 << false;
    QTest::addRow("1,1 >= 1,1") << 1 << 1 << 1 << 1 << true;
    QTest::addRow("1,1 >= 1,0") << 1 << 1 << 1 << 0 << true;
    QTest::addRow("1,1 >= 0,2") << 1 << 1 << 0 << 2 << true;
    QTest::addRow("1,1 >= 0,1") << 1 << 1 << 0 << 1 << true;
    QTest::addRow("1,1 >= 0,0") << 1 << 1 << 0 << 0 << true;
}

QTEST_APPLESS_MAIN(default_coordinate)

#include "tst_default_coordinate.moc"
