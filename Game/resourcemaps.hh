#ifndef RESOURCEMAPS_HH
#define RESOURCEMAPS_HH

#include "core/basicresources.h"

namespace Student {

namespace ConstResourceMaps {

const Course::ResourceMap EMPTY = {};

const Course::ResourceMap MOUNTAIN_BP = {
    {Course::MONEY, 2},
    {Course::FOOD, 5},
    {Course::WOOD, 1},
    {Course::STONE, 1},
    {Course::ORE, 0},
};

const Course::ResourceMap COBBLESTONE_BP = {
    {Course::MONEY, 2},
    {Course::FOOD, 5},
    {Course::WOOD, 1},
    {Course::STONE, 1},
    {Course::ORE, 0},
};

const Course::ResourceMap RIVER_BP = {
    {Course::MONEY, 2},
    {Course::FOOD, 5},
    {Course::WOOD, 1},
    {Course::STONE, 1},
    {Course::ORE, 0},
};

const Course::ResourceMap BW_RECRUITMENT_COST= {
    {Course::MONEY, 10},
    {Course::FOOD, 30},
    {Course::WOOD, 0},
    {Course::STONE, 0},
    {Course::ORE, 0},
};

const Course::ResourceMapDouble CW_WORKER_EFFICIENCY = {
    {Course::MONEY, 0.25},
    {Course::FOOD, 1.00},
    {Course::WOOD, 0.75},
    {Course::STONE, 0.50},
    {Course::ORE, 0.50}
};

const Course::ResourceMap CW_RECRUITMENT_COST = {
    {Course::MONEY, 500},
    {Course::FOOD, 25},
    {Course::WOOD, 0},
    {Course::STONE, 0},
    {Course::ORE, 0},
};

const Course::ResourceMapDouble WARRIOR_WORKER_EFFICIENCY = {
    {Course::MONEY, 0.25},
    {Course::FOOD, 1.00},
    {Course::WOOD, 0.75},
    {Course::STONE, 0.50},
    {Course::ORE, 0.50}
};

const Course::ResourceMap WARRIOR_RECRUITMENT_COST = {
    {Course::MONEY, 50},
    {Course::FOOD, 100},
    {Course::WOOD, 0},
    {Course::STONE, 0},
    {Course::ORE, 0},
};

const Course::ResourceMap QUARRY_BUILD_COST = {
    {Course::MONEY, 10},
    {Course::FOOD, 5},
    {Course::WOOD, 50},
    {Course::STONE, 5},
    {Course::ORE, 5},
};

const Course::ResourceMap QUARRY_PRODUCTION = {
    {Course::MONEY, -10},
    {Course::FOOD, 0},
    {Course::WOOD, -10},
    {Course::STONE, -100},
    {Course::ORE, 0},
};

const Course::ResourceMap MINE_BUILD_COST = {
    {Course::MONEY, 10},
    {Course::FOOD, 35},
    {Course::WOOD, 5},
    {Course::STONE, 50},
    {Course::ORE, 5},
};

const Course::ResourceMap MINE_PRODUCTION = {
    {Course::MONEY, -10},
    {Course::FOOD, 0},
    {Course::WOOD, 0},
    {Course::STONE, -20},
    {Course::ORE, -100},
};

const Course::ResourceMap FARM_PRODUCTION = {
    {Course::MONEY, -5},
    {Course::FOOD, -55},
    {Course::WOOD, -5},
    {Course::STONE, -0},
    {Course::ORE, -0},
};

const Course::ResourceMap SAWMILL_BUILD_COST = {
    {Course::MONEY, 5},
    {Course::FOOD, 10},
    {Course::WOOD, 10},
    {Course::STONE, 25},
    {Course::ORE, 10},
};

const Course::ResourceMap SAWMILL_PRODUCTION = {
    {Course::MONEY, -5},
    {Course::FOOD, 0},
    {Course::WOOD, -35},
    {Course::STONE, -5},
    {Course::ORE, 0},
};

const Course::ResourceMap OUTPOST_BUILD_COST = {
    {Course::MONEY, 150},
    {Course::FOOD, 200},
    {Course::WOOD, 200},
    {Course::STONE, 25},
    {Course::ORE, 0},
};

const Course::ResourceMap FARM_BUILD_COST = {
    {Course::MONEY, 50},
    {Course::FOOD, 100},
    {Course::WOOD, 25},
    {Course::STONE, 0},
    {Course::ORE, 0},
};
}
}

#endif // RESOURCEMAPS_HH
