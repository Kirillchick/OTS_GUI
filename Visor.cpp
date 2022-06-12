#include "Visor.h"

Visor::Visor(const int trueCoordinateX, const int trueCoordinateY, const int currentPosition, const int maxAngleError)
        : m_position(currentPosition),
          m_maxAngleError(maxAngleError),
          m_point(DefinedPoint(trueCoordinateX, trueCoordinateY)),
          m_vectorCoordinate(Vector(m_point, m_position)),
          m_angle(Angle(m_vectorCoordinate)),
          m_positiveErrorRay(Ray(m_angle, Ray::POSITIVE, currentPosition, m_maxAngleError)),
          m_negativeErrorRay(Ray(m_angle, Ray::NEGATIVE, currentPosition, m_maxAngleError))
{

};

Ray Visor::GetPositiveErrorRay() const
{
    return m_positiveErrorRay;
}

Ray Visor::GetNegativeErrorRay() const
{
    return m_negativeErrorRay;
}

int Visor::GetMaxAngleErorr() const
{
    return m_maxAngleError;
}

int Visor::GetAngle() const
{
    return m_angle.GetAngle();
}

int Visor::GetPosition() const
{
    return m_position;
}

void Visor::Recalculate(const int position)
{
    m_vectorCoordinate.Recalculate(position);
    m_angle.Recalculate(m_vectorCoordinate);
    m_positiveErrorRay.Recalculate(m_angle, Ray::POSITIVE, position, m_maxAngleError);
    m_negativeErrorRay.Recalculate(m_angle, Ray::NEGATIVE, position, m_maxAngleError);
}
