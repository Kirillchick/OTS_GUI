#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <vector>

class LogManager
{
private:
    std::vector<std::vector<double>> m_logTable;
    int m_logNum = 0;
public:
    LogManager(double diagonal1, double diagonal2);
    void Iteration(double diagonal1, double diagonal2);
    std::vector<std::vector<double>> GetLogTable();
};

#endif // LOGMANAGER_H
