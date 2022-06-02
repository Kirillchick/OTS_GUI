#ifndef LOGMАNАGER_H
#define LOGMАNАGER_H
#include <vector>

class LogManager
{
private:
    std::vector<std::vector<int>> m_logTable;
    int m_logNum = 0;
public:
    LogManager(int diagonal1, int diagonal2);
    void Iteration(int diagonal1, int diagonal2);
    std::vector<std::vector<int>> GetLogTable();
};

#endif // LOGMАNАGER_H
