#include "gameeventhandler.hh"

namespace Student {

GameEventHandler::GameEventHandler()
{

}

bool GameEventHandler::modifyResource(std::shared_ptr<Course::PlayerBase> player, Course::BasicResource resource, int amount)
{
    // return true;
}

bool GameEventHandler::modifyResources(std::shared_ptr<Course::PlayerBase> player, Course::ResourceMap resources)
{
    // return true;
}

} // Student namespace
