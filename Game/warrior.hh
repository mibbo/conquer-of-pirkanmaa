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

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler points to the student's GameEventHandler.
     * @param owner points to the owning player.
     * @param descriptions contains descriptions and flavor texts.
     */
    Warrior(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
                const std::shared_ptr<Course::iObjectManager>& objectmanager,
                const std::shared_ptr<Course::PlayerBase>& owner,
                const int& tilespaces = 1,
                const Course::ResourceMap& cost =
                    Student::ConstResourceMaps::WARRIOR_RECRUITMENT_COST,
                const Course::ResourceMapDouble& efficiency =
                    Student::ConstResourceMaps::WARRIOR_WORKER_EFFICIENCY
                );

    /**
     * @brief Default destructor.
     */
    virtual ~Warrior() = default;

    /**
     * @brief getType Returns a string describing objects type.
     * This should be overriden in each inherited class.
     * Makes checking object's type easier for students.
     * @return std::string that represents Object's type.
     * @post Exception guarantee: No-throw
     * @note You can use this in e.g. debugging and similar printing.
     */
    virtual std::string getType() const override;

    /**
     * @brief Check if the worker can be placed on the Tile according to
     * it's placement rule. Only rule is that the Tile must have same owner
     * as the worker.
     * @param target is the Tile that worker is being placed on.
     * @return
     * True - If baseclass' method return true and target Tile has space
     * for worker.
     * False - If both conditions aren't met.
     * @note Override to change placement rules for derived worker.
     * @post Exception guarantee: Basic
     */
    virtual bool canBePlacedOnTile(
            const std::shared_ptr<Course::TileBase> &target) const override;

    // not used
    virtual void doSpecialAction() override;

    // not used
    virtual const Course::ResourceMapDouble tileWorkAction() override;

    /**
     * @brief get warriors hitpoints
     */
    int getHitPoints();

    /**
     * @brief set warriors hitpoints
     */
    void setHitPoints(int amount);

private:
    int hitPoints_;

};

}

#endif // WARRIOR_HH
