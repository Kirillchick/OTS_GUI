#include "DefinedPoint.h"

DefinedPoint::DefinedPoint(const double trueCoordinateX, const double tureCoordinateY, const double maxNoiseError)
        : m_truePoint(TruePoint(trueCoordinateX, tureCoordinateY)),
        m_coordinateX(m_truePoint.GetTrueX() + GenerateRandomError(maxNoiseError)),
        m_coordinateY(m_truePoint.GetTrueY() + GenerateRandomError(maxNoiseError)) {}

double DefinedPoint::GenerateRandomError(const double maxNoiseError) const
{
    std::uniform_real_distribution<double> distr(-maxNoiseError, maxNoiseError);
    double randVal = distr(*QRandomGenerator::global());
    qDebug() << randVal;
    return QString::number(randVal, 'f', 2).toDouble();
}

double DefinedPoint::getCoordX() const
{
    return m_coordinateX;
}

double DefinedPoint::getCoordY() const
{
    return m_coordinateY;
}
