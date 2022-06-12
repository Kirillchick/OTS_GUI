#include "Angle.h"

Angle::Angle(Vector vectorCoordinate) : m_angleValue(СalculateAngle(vectorCoordinate)) {}

int Angle::GetAngle() const
{
    return m_angleValue;
}

int Angle::СalculateAngle(const Vector vectorCoordinate) const
{
    // Понять что возвращат градус или радиан?
    return qAtan2(vectorCoordinate.GetVectorCoordinate().second, vectorCoordinate.GetVectorCoordinate().first);
}

void Angle::Recalculate(const Vector vectorCoordinate)
{
    m_angleValue = СalculateAngle(vectorCoordinate);
}
