#include "player.h"
#include <iostream>

namespace Student {



Player::Player(const std::string& name,
                       const std::vector<std::shared_ptr<Course::GameObject> > objects):
    Course::PlayerBase(
        name,
        objects)
{
    m_resources = {
        {Course::BasicResource::MONEY, 1000},
        {Course::BasicResource::FOOD, 1000},
        {Course::BasicResource::WOOD, 1000},
        {Course::BasicResource::STONE, 1000},
        {Course::BasicResource::ORE, 1000}
    };
}
bool Player::operator==(const Player& other) const
{
    return m_name == other.m_name;
}

bool Player::modifyResource(Course::BasicResource resource, int amount)
{
    std::cout << m_resources[resource] << std::endl;
    if (m_resources[resource] < amount) {
        return false;
    } else {
        m_resources[resource] -= amount;
        std::cout << m_resources[resource] << std::endl;
        return true;
    }
}

bool Player::modifyResources(Course::ResourceMap resources)
{
    for (auto resource : resources) {
        if (m_resources[resource.first] < resource.second) {
            return false;
        }
    }
    for (auto resource : resources) {
        Player::modifyResource(resource.first, resource.second);
    }
    return true;
}

}
