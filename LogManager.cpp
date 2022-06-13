#include "LogManager.h"

LogManager::LogManager(double diagonal1, double diagonal2)
{
    std::vector<double> currentLog = {double(m_logNum), diagonal1, diagonal2};
    m_logTable.push_back(currentLog);
    ++m_logNum;
}

void LogManager::Iteration(double diagonal1, double diagonal2)
{
    LogManager(diagonal1, diagonal2);
}

std::vector<std::vector<double>> LogManager::GetLogTable()
{
    return m_logTable;
}
