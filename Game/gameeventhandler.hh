#ifndef GAMEEVENTHANDLER_HH
#define GAMEEVENTHANDLER_HH

#include "interfaces/igameeventhandler.h"

namespace Student {

class GameEventHandler : public Course::iGameEventHandler
{
public:
    GameEventHandler();
};

} // namespace Student

#endif // GAMEEVENTHANDLER_HH
