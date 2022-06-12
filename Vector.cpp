#include "Vector.h"

Vector::Vector(const DefinedPoint point, const int initalPosition) : m_point(point), m_initalPosition(initalPosition)
{

    SetVectorCoordinate(m_initalPosition);
}

std::pair<int, int> Vector::CalculateVectorCoordinate(const int initalPosition) const
{
    return std::pair<int, int>(m_point.getCoordX() - initalPosition, m_point.getCoordY() - ZERO);
}

void Vector::SetVectorCoordinate(const int initalPosition)
{
    m_vectorCoordinate = CalculateVectorCoordinate(initalPosition);
}

std::pair<int, int> Vector::GetVectorCoordinate() const
{
    return m_vectorCoordinate;
}

void Vector::Recalculate(int position)
{
    SetVectorCoordinate(position);
}
