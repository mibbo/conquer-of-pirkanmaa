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

public:

    /**
     * @brief Modify Player's resource. Can be used to both sum or subtract.
     * @param player Pointer to the Player whose resource is being modified.
     * @param resource Defines the modified resource.
     * @param amount Defines the amount of change.
     * @post Exception guarantee: Basic
     * @return
     * True - Modification was succesful. \n
     * False - Modification failed. \n
     */
    bool modifyResource(std::shared_ptr<Course::PlayerBase> player, Course::BasicResource resource, int amount);

    /**
     * @brief Modify Player's resources. Can be used to both sum or subtract
     * @param player Pointer to the Player whose resources are being modified.
     * @param resources ResourceMap containing change amounts.
     * @return
     * True - Modification was succesful. \n
     * False - Modification failed. \n
     */
    bool modifyResources(std::shared_ptr<Course::PlayerBase> player, Course::ResourceMap resources);
};

} // namespace Student

#endif // GAMEEVENTHANDLER_HH
