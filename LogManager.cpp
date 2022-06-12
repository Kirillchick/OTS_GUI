#include "LogManager.h"

LogManager::LogManager(int diagonal1, int diagonal2)
{
    std::vector<int> currentLog = {m_logNum, diagonal1, diagonal2};
    m_logTable.push_back(currentLog);
    ++m_logNum;
}

void LogManager::Iteration(int diagonal1, int diagonal2)
{
    LogManager(diagonal1, diagonal2);
}

std::vector<std::vector<int>> LogManager::GetLogTable()
{
    return m_logTable;
}
