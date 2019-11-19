#include "gameeventhandler.hh"
#include "player.h"

namespace Student {

GameEventHandler::GameEventHandler()
{

}

bool GameEventHandler::modifyResource(std::shared_ptr<Course::PlayerBase> player, Course::BasicResource resource, int amount)
{
    std::shared_ptr<Student::Player> studentPlayer = std::dynamic_pointer_cast<Student::Player>(player);
    bool hasResources = studentPlayer->modifyResource(resource, amount);
    if (hasResources) {
        return true;
    } else {
        return false;
    }
}

bool GameEventHandler::modifyResources(std::shared_ptr<Course::PlayerBase> player, Course::ResourceMap resources)
{
    std::shared_ptr<Student::Player> studentPlayer = std::dynamic_pointer_cast<Student::Player>(player);
    bool hasResources = studentPlayer->modifyResources(resources);
    if (hasResources) {
        return true;
    } else {
        return false;
    }
}

} // Student namespace
