#ifndef VISOR_H
#define VISOR_H
#define INITIAL_POSITION 0

#include "Ray.h"

class Visor
{
private:
    double m_position;
    const double m_maxAngleError;
    const DefinedPoint m_point;
    Vector m_vectorCoordinate;
    Angle m_angle;
    Ray m_positiveErrorRay;
    Ray m_negativeErrorRay;
public:
    // Если что добавить что ошибки разные в конструктор
    Visor(const double trueCoordinateX, const double trueCoordinateY, const double currentPosition, const double maxAngleError);
    Ray GetPositiveErrorRay() const;
    Ray GetNegativeErrorRay() const;
    double GetMaxAngleErorr() const;
    double GetAngle() const;
    double GetPosition() const;
    void Recalculate(const int position);
};
#endif // VISOR_H
