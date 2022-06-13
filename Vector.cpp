#include "Vector.h"

Vector::Vector(const DefinedPoint point, const double initalPosition)
    : m_point(point),
      m_initalPosition(initalPosition)
{

    SetVectorCoordinate(m_initalPosition);
}

std::pair<double, double> Vector::CalculateVectorCoordinate(const double initalPosition) const
{
    return std::pair<double, double>(m_point.getCoordX() - initalPosition, m_point.getCoordY() - ZERO);
}

void Vector::SetVectorCoordinate(const double initalPosition)
{
    m_vectorCoordinate = CalculateVectorCoordinate(initalPosition);
}

std::pair<double, double> Vector::GetVectorCoordinate() const
{
    return m_vectorCoordinate;
}

void Vector::Recalculate(double position)
{
    SetVectorCoordinate(position);
}
