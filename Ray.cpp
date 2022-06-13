#include "Ray.h"

/*Ray::Ray(Vector vectorCoordinate, Angle angle, int maxAngleError, int errorSign, int position)
    : m_maxAngleError(maxAngleError),
      m_position(position)
{

}*/

Ray::Ray(const Angle angle, const int errorSign, const double position, const double maxAngleError)
    : m_maxAngleError(maxAngleError),
      m_angleValue(angle.GetAngle() + errorSign * m_maxAngleError),
      m_errorSign(errorSign),
      m_position(position) {}

void Ray::Recalculate(const Angle angle, const double position)
{
    m_angleValue = angle.GetAngle() + m_errorSign * m_maxAngleError;
    m_position = position;
}

double Ray::GetAngle() const
{
    return m_angleValue;
}


int Ray::GetAngleSign() const
{
    return m_errorSign;
}
