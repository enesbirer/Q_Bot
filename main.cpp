#include "GridWorld.h"
#include "Agent.h"

int main()
{
    GridWorld world;

    Agent agent;

    agent.train(world, 5000);

    agent.demo(world);

    return 0;
}