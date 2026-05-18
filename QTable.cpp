#include "QTable.h"
#include <fstream>

QTable::QTable(int states, int actions)
{
    table.resize(states, std::vector<double>(actions, 0.0));
}

double QTable::getQ(int state, int action) const
{
    return table[state][action];
}

void QTable::setQ(int state, int action, double value)
{
    table[state][action] = value;
}

int QTable::getBestAction(int state) const
{
    int bestAction = 0;
    double bestValue = table[state][0];

    for(int a = 1; a < table[state].size(); a++)
    {
        if(table[state][a] > bestValue)
        {
            bestValue = table[state][a];
            bestAction = a;
        }
    }

    return bestAction;
}

void QTable::save(const std::string& filename)
{
    std::ofstream file(filename);

    for(auto& row : table)
    {
        for(double value : row)
        {
            file << value << " ";
        }

        file << "\n";
    }
}

void QTable::load(const std::string& filename)
{
    std::ifstream file(filename);

    for(auto& row : table)
    {
        for(double& value : row)
        {
            file >> value;
        }
    }
}