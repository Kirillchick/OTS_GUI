#include "Angle.h"

Angle::Angle(Vector vectorCoordinate)
    : m_angleValue(СalculateAngle(vectorCoordinate)) {}

double Angle::GetAngle() const
{
    return m_angleValue;
}

double Angle::СalculateAngle(const Vector vectorCoordinate) const
{
    qDebug() << "AngleSize";
    qDebug() << qAtan2(vectorCoordinate.GetVectorCoordinate().second, vectorCoordinate.GetVectorCoordinate().first);
    return qAtan2(vectorCoordinate.GetVectorCoordinate().second, vectorCoordinate.GetVectorCoordinate().first);
}

void Angle::Recalculate(const Vector vectorCoordinate)
{
    m_angleValue = СalculateAngle(vectorCoordinate);
}
