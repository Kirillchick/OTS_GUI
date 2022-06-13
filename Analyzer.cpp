#include "Analyzer.h"

Analyzer::Analyzer(const Visor& visor1, const Visor& visor2)
{
    InitializeAttributes(visor1, visor2);
}
void Analyzer::InitializeAttributes(const Visor& visor1, const Visor& visor2)
{
    CalculateK1(visor1, visor2);
    CalculateK2(visor1, visor2);
    CalculateK3(visor1, visor2);
    CalculateK4(visor1, visor2);
    CalculateDiagonals();

}
void Analyzer::CalculateK1(const Visor& visor1, const Visor& visor2)
{
    double tanA = qTan(visor1.GetAngle() + visor1.GetPositiveErrorRay().GetAngleSign() * visor1.GetMaxAngleErorr()); // pos
    double tanB = qTan(visor2.GetAngle() + visor1.GetPositiveErrorRay().GetAngleSign() * visor2.GetMaxAngleErorr()); // pos
    m_k1.first = (tanA * visor1.GetPosition() + tanA * INITIAL_POSITION - tanB * visor2.GetPosition() - tanB * INITIAL_POSITION)
            / (tanA - tanB);

    m_k1.second = tanA * (m_k1.first - visor1.GetPosition());
}
void Analyzer::CalculateK2(const Visor& visor1, const Visor& visor2)
{
    double tanA = qTan(visor1.GetAngle() + visor1.GetPositiveErrorRay().GetAngleSign() * visor1.GetMaxAngleErorr()); // pos
    double tanB = qTan(visor2.GetAngle() + visor1.GetNegativeErrorRay().GetAngleSign() * visor2.GetMaxAngleErorr()); // neg
    m_k2.first = (tanA * visor1.GetPosition() + tanA * INITIAL_POSITION - tanB * visor2.GetPosition() - tanB * INITIAL_POSITION)
            / (tanA - tanB);

    m_k2.second = tanA * (m_k2.first - visor1.GetPosition());
}
void Analyzer::CalculateK3(const Visor& visor1, const Visor& visor2)
{
    double tanA = qTan(visor1.GetAngle() + visor1.GetNegativeErrorRay().GetAngleSign() * visor1.GetMaxAngleErorr()); // neg
    double tanB = qTan(visor2.GetAngle() + visor1.GetNegativeErrorRay().GetAngleSign() * visor2.GetMaxAngleErorr()); // neg
    m_k3.first = (tanA * visor1.GetPosition() + tanA * INITIAL_POSITION - tanB * visor2.GetPosition() - tanB * INITIAL_POSITION)
            / (tanA - tanB);

    m_k3.second = tanA * (m_k3.first - visor1.GetPosition());
}
void Analyzer::CalculateK4(const Visor& visor1, const Visor& visor2)
{
    double tanA = qTan(visor1.GetAngle() + visor1.GetNegativeErrorRay().GetAngleSign() * visor1.GetMaxAngleErorr()); // neg
    double tanB = qTan(visor2.GetAngle() + visor1.GetPositiveErrorRay().GetAngleSign() * visor2.GetMaxAngleErorr()); // pos
    m_k4.first = (tanA * visor1.GetPosition() + tanA * INITIAL_POSITION - tanB * visor2.GetPosition() - tanB * INITIAL_POSITION)
            / (tanA - tanB);

    m_k4.second = tanA * (m_k4.first - visor1.GetPosition());
}

void Analyzer::CalculateDiagonals()
{
    m_diagonal1 = qSqrt(pow(m_k3.first - m_k1.first, 2) + pow(m_k3.second - m_k1.second, 2));
    m_diagonal2 = qSqrt(pow(m_k2.first - m_k4.first, 2) + pow(m_k2.second - m_k4.second, 2));
    qDebug() << "Diagonal 1 - " << m_diagonal1;
    qDebug() << "Diagonal 2 - " << m_diagonal2;
}

void Analyzer::Recalculate(const Visor &visor1, const Visor &visor2)
{
    InitializeAttributes(visor1, visor2);
}

double Analyzer::GetDiagonal1() const
{
    return m_diagonal1;
}

double Analyzer::GetDiagonal2() const
{
    return m_diagonal2;
}

std::vector<std::pair<double, double>> Analyzer::GetDots() const
{
    std::vector<std::pair<double, double>> dotsContainer {m_k1, m_k2, m_k3, m_k4};
    return dotsContainer;
}
