#ifndef MODEL_H
#define MODEL_H

#include "Analyzer.h"
#include "Visor.h"
#include "LogManager.h"

class  Model
{
private:
    int m_baseL;
    Visor m_visor1;
    Visor m_visor2;
    Analyzer m_analyzer;
    LogManager m_logManager;
public:
    Model(const int trueCoordinateX, const int trueCoordinateY, const int baseL, const int maxAngleError, int position = 0);
    void Iteration(int position);
};

#endif // MODEL_H
