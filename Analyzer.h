#ifndef ANALYZER_H
#define ANALYZER_H

#include "Visor.h"
#include <QtMath>
#include <QDebug>

class Analyzer
{
private:
    std::pair<double, double> m_k1;
    std::pair<double, double> m_k2;
    std::pair<double, double> m_k3;
    std::pair<double, double> m_k4;
    double m_diagonal1;
    double m_diagonal2;
    void InitializeAttributes(const Visor& visor1, const Visor& visor2);
    void CalculateK1(const Visor& visor1, const Visor& visor2);
    void CalculateK2(const Visor& visor1, const Visor& visor2);
    void CalculateK3(const Visor& visor1, const Visor& visor2);
    void CalculateK4(const Visor& visor1, const Visor& visor2);
    void CalculateDiagonals();
public:
    Analyzer(const Visor& visor1, const Visor& visor2);
    double GetDiagonal1() const;
    double GetDiagonal2() const;
    void Recalculate(const Visor& visor1, const Visor& visor2);
    std::vector<std::pair<double, double>> GetDots() const;
};

#endif // ANALYZER_H
