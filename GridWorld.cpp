#include "GridWorld.h"

GridWorld::GridWorld()
{
    int temp[HEIGHT][WIDTH] =
    {
        {0,0,0,0,0},
        {0,1,1,1,0},
        {0,0,0,1,0},
        {0,1,0,0,0},
        {0,0,0,1,2}
    };

    for(int y = 0; y < HEIGHT; y++)
    {
        for(int x = 0; x < WIDTH; x++)
        {
            grid[y][x] = temp[y][x];
        }
    }
}

bool GridWorld::isValidPosition(int x, int y) const
{
    if(x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
        return false;

    return grid[y][x] != WALL;
}

bool GridWorld::isGoal(int x, int y) const
{
    return grid[y][x] == GOAL;
}

int GridWorld::getReward(int x, int y) const
{
    if(!isValidPosition(x, y))
        return -100;

    if(isGoal(x, y))
        return 100;

    return -1;
}

void GridWorld::printWorld(int agentX, int agentY) const
{
    for(int y = 0; y < HEIGHT; y++)
    {
        for(int x = 0; x < WIDTH; x++)
        {
            if(agentX == x && agentY == y)
            {
                std::cout << "A ";
            }
            else if(grid[y][x] == WALL)
            {
                std::cout << "# ";
            }
            else if(grid[y][x] == GOAL)
            {
                std::cout << "G ";
            }
            else
            {
                std::cout << ". ";
            }
        }

        std::cout << "\n";
    }

    std::cout << "\n";
}