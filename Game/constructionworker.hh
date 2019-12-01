#ifndef CONSTRUCTIONWORKER_HH
#define CONSTRUCTIONWORKER_HH

#include "workers/workerbase.h"
#include "core/resourcemaps.h"
#include "player.h"
#include "resourcemaps.hh"

namespace Student {

/**
 * @brief The ConstructionWorker class represents a worker that can be
 * used to build buildings in the game.
 *
 * ConstructionWorker has to be in a tile location where you want to
 * build a building
 */
class ConstrutionWorker : public Course::WorkerBase
{
public:
    ConstrutionWorker() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler points to the student's GameEventHandler.
     * @param owner points to the owning player.
     * @param descriptions contains descriptions and flavor texts.
     */
    ConstrutionWorker(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
                const std::shared_ptr<Course::iObjectManager>& objectmanager,
                const std::shared_ptr<Course::PlayerBase>& owner,
                const int& tilespaces = 1,
                const Course::ResourceMap& cost =
                    Student::ConstResourceMaps::CW_RECRUITMENT_COST,
                const Course::ResourceMapDouble& efficiency =
                    Student::ConstResourceMaps::CW_WORKER_EFFICIENCY
                );

    /**
     * @brief Default destructor.
     */
    virtual ~ConstrutionWorker() = default;

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

private:

};

}

#endif // CONSTRUCTIONWORKER_HH
