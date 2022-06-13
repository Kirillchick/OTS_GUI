#include "TruePoint.h"

TruePoint::TruePoint(const double coordinateX, const double coordinateY)
    : m_trueX(coordinateX),
      m_trueY(coordinateY) {}

/*
int TruePoint::GenerateRandomPoint(const int fieldSize) const
{
    std::seed_seq sseq(0, fieldSize);
    QRandomGenerator randomNumber(sseq);
    return randomNumber.bounded(0, fieldSize);
}
*/

int TruePoint::GetTrueX() const
{
    return m_trueX;
}

int TruePoint::GetTrueY() const
{
    return m_trueY;
}
