#include "DefinedPoint.h"

DefinedPoint::DefinedPoint(const int trueCoordinateX, const int tureCoordinateY, const int maxNoiseError)
        : m_truePoint(TruePoint(trueCoordinateX, tureCoordinateY)),
        m_coordinateX(m_truePoint.GetTrueX() + GenerateRandomError(maxNoiseError)),
        m_coordinateY(m_truePoint.GetTrueY() + GenerateRandomError(maxNoiseError)) {}

int DefinedPoint::GenerateRandomError(const int maxNoiseError) const
{
    std::seed_seq sseq(0, 100);
    QRandomGenerator randomNumber(sseq);
    return randomNumber.bounded(-maxNoiseError, maxNoiseError);
}

int DefinedPoint::getCoordX() const
{
    return m_coordinateX;
}

int DefinedPoint::getCoordY() const
{
    return m_coordinateY;
}
