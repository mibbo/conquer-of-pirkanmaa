#ifndef WARRIOR_HH
#define WARRIOR_HH


#include "workers/workerbase.h"
#include "core/resourcemaps.h"
#include "player.h"
#include "resourcemaps.hh"

namespace Student {

/**
 * @brief The Warrior class represents a worker that can be
 * used to attack the enemy HeadQuarter-building.
 *
 * Warrior has 5 hit points and can attack the other players
 * warriors by moving to the same tile with them.
 * Player wins the game when his/her warrior moves to the enemys
 * headquarter
 */
class Warrior : public Course::WorkerBase
{
public:

    Warrior() = delete;

    Warrior(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
                const std::shared_ptr<Course::iObjectManager>& objectmanager,
                const std::shared_ptr<Course::PlayerBase>& owner,
                const int& tilespaces = 1,
                const Course::ResourceMap& cost =
                    Student::ConstResourceMaps::WARRIOR_RECRUITMENT_COST,
                const Course::ResourceMapDouble& efficiency =
                    Student::ConstResourceMaps::WARRIOR_WORKER_EFFICIENCY
                );

    virtual ~Warrior() = default;

    virtual std::string getType() const override;

    virtual bool canBePlacedOnTile(
            const std::shared_ptr<Course::TileBase> &target) const override;

    virtual void doSpecialAction() override;

    virtual const Course::ResourceMapDouble tileWorkAction() override;

    int getHitPoints();

    void setHitPoints(int amount);

private:
    int hitPoints_;

};

}

#endif // WARRIOR_HH
