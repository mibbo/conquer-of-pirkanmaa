#ifndef OBJECTMANAGER_HH
#define OBJECTMANAGER_HH

#include "interfaces/iobjectmanager.h"

namespace Student {

class ObjectManager : public Course::iObjectManager
{
public:
    ObjectManager();
};

} // namespace Student

#endif // OBJECTMANAGER_HH
