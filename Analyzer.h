#ifndef ANALYZER_H
#define ANALYZER_H

#include "Visor.h"
#include <QtMath> // ?

class Analyzer
{
private:
    std::pair<int, int> m_k1;
    std::pair<int, int> m_k2;
    std::pair<int, int> m_k3;
    std::pair<int, int> m_k4;
    int m_diagonal1;
    int m_diagonal2;
    void InitializeAttributes(const Visor& visor1, const Visor& visor2);
    void CalculateK1(const Visor& visor1, const Visor& visor2);
    void CalculateK2(const Visor& visor1, const Visor& visor2);
    void CalculateK3(const Visor& visor1, const Visor& visor2);
    void CalculateK4(const Visor& visor1, const Visor& visor2);
    void CalculateDiagonals();
public:
    Analyzer(const Visor& visor1, const Visor& visor2);
    int GetDiagonal1(); // ?
    int GetDiagonal2(); // ?
};

#endif // ANALYZER_H
