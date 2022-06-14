#include "LogManager.h"

LogManager::LogManager(double diagonal1, double diagonal2)
{
    //Iteration(diagonal1, diagonal2);
}

void LogManager::Iteration(double diagonal1, double diagonal2)
{
    //std::vector<double> currentLog = {double(m_logNum * 2), diagonal1, diagonal2};
    std::vector<double> currentLog = {diagonal1, diagonal2};
    m_logTable.push_back(currentLog);
    ++m_logNum;
}

std::vector<std::vector<double>> LogManager::GetLogTable()
{
    return m_logTable;
}
