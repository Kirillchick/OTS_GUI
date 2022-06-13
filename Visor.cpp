#include "Visor.h"

Visor::Visor(const double trueCoordinateX, const double trueCoordinateY, const double currentPosition, const double maxAngleError)
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

double Visor::GetMaxAngleErorr() const
{
    return m_maxAngleError;
}

double Visor::GetAngle() const
{
    return m_angle.GetAngle();
}

double Visor::GetPosition() const
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
