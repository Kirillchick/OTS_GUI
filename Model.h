#ifndef MODEL_H
#define MODEL_H

#include "Analyzer.h"
#include "Visor.h"
#include "LogManager.h"

class  Model
{
private:
    double m_baseL;
    Visor m_visor1;
    Visor m_visor2;
    Analyzer m_analyzer;
    LogManager m_logManager;
public:
    Model(const double trueCoordinateX, const double trueCoordinateY, const double baseL, const double maxAngleError, const double position = 0.0);
    void Iteration(double position);
    std::vector<std::vector<double>> GetLogTable();
};

#endif // MODEL_H
