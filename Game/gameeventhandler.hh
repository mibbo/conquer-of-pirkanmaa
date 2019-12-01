#ifndef GAMEEVENTHANDLER_HH
#define GAMEEVENTHANDLER_HH

#include "interfaces/igameeventhandler.h"

namespace Student {

/**
 * @brief GameEventHandler is used when player Class need information on resource changes
 *
 */
class GameEventHandler : public Course::iGameEventHandler
{
public:
    GameEventHandler();

    // iGameEventHandler interface
public:
    bool modifyResource(std::shared_ptr<Course::PlayerBase> player, Course::BasicResource resource, int amount);

    bool modifyResources(std::shared_ptr<Course::PlayerBase> player, Course::ResourceMap resources);
};

} // namespace Student

#endif // GAMEEVENTHANDLER_HH
