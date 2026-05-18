#pragma once

#include "GridWorld.h"
#include "QTable.h"

class Agent
{
public:
    Agent();

    void train(GridWorld& world, int episodes);

    void demo(GridWorld& world);

private:
    int x;
    int y;

    double alpha;
    double gamma;
    double epsilon;

    QTable qtable;

    int getState(int x, int y);

    int chooseAction(int state);

    void move(int action);

    int maxQ(int state);
};