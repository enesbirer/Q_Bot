#pragma once

#include <vector>
#include <iostream>

class GridWorld
{
public:
    static const int WIDTH = 5;
    static const int HEIGHT = 5;

    enum Cell
    {
        EMPTY = 0,
        WALL = 1,
        GOAL = 2
    };

    GridWorld();

    bool isValidPosition(int x, int y) const;
    bool isGoal(int x, int y) const;

    int getReward(int x, int y) const;

    void printWorld(int agentX, int agentY) const;

private:
    int grid[HEIGHT][WIDTH];
};