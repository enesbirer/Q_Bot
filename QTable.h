#pragma once

#include <vector>
#include <string>

class QTable
{
public:
    QTable(int states, int actions);

    double getQ(int state, int action) const;
    void setQ(int state, int action, double value);

    int getBestAction(int state) const;

    void save(const std::string& filename);
    void load(const std::string& filename);

private:
    std::vector<std::vector<double>> table;
};