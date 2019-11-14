#include "player.h"

namespace Student {



Player::Player(const std::string& name,
                       const std::vector<std::shared_ptr<Course::GameObject> > objects):
    Course::PlayerBase(
        name,
        objects)

{
}


bool Player::operator==(const Player& other) const
{
    return m_name == other.m_name;
}

}
