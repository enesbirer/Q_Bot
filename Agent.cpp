#include "Agent.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

Agent::Agent()
    : qtable(25, 4)
{
    alpha = 0.1;
    gamma = 0.9;
    epsilon = 0.2;

    std::srand(std::time(nullptr));
}

int Agent::getState(int x, int y)
{
    return y * 5 + x;
}

int Agent::chooseAction(int state)
{
    double randomValue =
        (double)std::rand() / RAND_MAX;

    if(randomValue < epsilon)
    {
        return std::rand() % 4;
    }

    return qtable.getBestAction(state);
}

void Agent::move(int action)
{
    switch(action)
    {
        case 0: y--; break;
        case 1: y++; break;
        case 2: x--; break;
        case 3: x++; break;
    }
}

int Agent::maxQ(int state)
{
    return qtable.getQ(state,
        qtable.getBestAction(state));
}

void Agent::train(GridWorld& world, int episodes)
{
    for(int episode = 0; episode < episodes; episode++)
    {
        x = 0;
        y = 0;

        for(int step = 0; step < 100; step++)
        {
            int state =
                getState(x, y);

            int action =
                chooseAction(state);

            int oldX = x;
            int oldY = y;

            move(action);

            int reward =
                world.getReward(x, y);

            if(!world.isValidPosition(x, y))
            {
                x = oldX;
                y = oldY;
            }

            int nextState =
                getState(x, y);

            double currentQ =
                qtable.getQ(state, action);

            double newQ =
                currentQ +
                alpha *
                (
                    reward +
                    gamma * maxQ(nextState)
                    - currentQ
                );

            qtable.setQ(state, action, newQ);

            if(world.isGoal(x, y))
            {
                break;
            }
        }
    }

    qtable.save("qtable.txt");
}

void Agent::demo(GridWorld& world)
{
    x = 0;
    y = 0;

    std::cout << "\n=== AI DEMO ===\n\n";

    for(int step = 0; step < 30; step++)
    {
        world.printWorld(x, y);

        if(world.isGoal(x, y))
        {
            std::cout << "Goal reached!\n";
            break;
        }

        int state =
            getState(x, y);

        int action =
            qtable.getBestAction(state);

        move(action);
    }
}