#include "player.h"
#include "algorithm"
#include <iostream>

namespace Student {



Player::Player(const std::string& name,
                       const std::vector<std::shared_ptr<Course::GameObject> > objects):
    Course::PlayerBase(
        name,
        objects)
{
    m_resources = {
        {Course::BasicResource::MONEY, 500},
        {Course::BasicResource::FOOD, 500},
        {Course::BasicResource::WOOD, 500},
        {Course::BasicResource::STONE, 500},
        {Course::BasicResource::ORE, 500}
    };

    m_color = Qt::black;
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

void Player::addTile(std::shared_ptr<Course::TileBase> tile)
{
    for (auto m_tile : m_tiles) {
        if (tile->hasSameCoordinateAs(m_tile)) {
            return;
        }
    }
    if (tile->getOwner() == nullptr) {
        m_tiles.push_back(tile);
    }
}

void Player::addTiles(const std::vector<std::shared_ptr<Course::GameObject> > &tiles)
{  
    for (auto tile : tiles) {
        bool tileFound = false;
        for (auto m_tile : m_tiles) {
            if (tile->hasSameCoordinateAs(m_tile)) {
                tileFound = true;
                break;
            }
        }
        if (!tileFound && tile->getOwner() == nullptr) {
            m_tiles.push_back(tile);
        }
    }
}

std::vector<std::shared_ptr<Course::GameObject>> Player::getTiles() const
{
    return m_tiles;
}



Course::ResourceMap Player::getResources()
{
    return m_resources;
}

QColor Player::getColor()
{
    return m_color;
}

void Player::setColor(QColor color)
{
    m_color = color;
}

}
