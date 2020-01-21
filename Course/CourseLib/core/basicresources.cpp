#include "basicresources.h"

namespace Course {


ResourceMap mergeResourceMaps(const ResourceMap& left,
                              const ResourceMap& right)
{
    ResourceMap new_map = right;

    for( auto it = left.begin(); it != left.end(); ++it)
    {
        if(new_map.find(it->first) == new_map.end())
        {
            new_map[it->first] = it->second;
        }
        else
        {
            new_map[it->first] = new_map[it->first] + it->second;
        }
    }

    return new_map;
}

ResourceMap multiplyResourceMap(const ResourceMap& resmap,
                                const ResourceMapDouble& multmap)
{
    ResourceMap new_map = resmap;

    for( auto it = new_map.begin(); it != new_map.end(); ++it)
    {
        if(multmap.find(it->first) != multmap.end())
        {
            new_map[it->first] =  new_map[it->first] * it->second;
        }
    }

    return new_map;
}

ResourceMapDouble mergeResourceMapDoubles(const ResourceMapDouble& left,
                                    const ResourceMapDouble& right)
{
    ResourceMapDouble new_map = right;

    for( auto it = left.begin(); it != left.end(); ++it)
    {
        if(new_map.find(it->first) == new_map.end())
        {
            new_map[it->first] = it->second;
        }
        else
        {
            new_map[it->first] = new_map[it->first] + it->second;
        }
    }

    return new_map;
}

}
