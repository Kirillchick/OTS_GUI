#ifndef VISOR_H
#define VISOR_H
#define INITIAL_POSITION 0

#include "Ray.h"

class Visor
{
private:
    int m_position;
    const int m_maxAngleError;
    const DefinedPoint m_point;
    Vector m_vectorCoordinate;
    Angle m_angle;
    Ray m_positiveErrorRay;
    Ray m_negativeErrorRay;
public:
    // Если что добавить что ошибки разные в конструктор
    Visor(const int trueCoordinateX, const int trueCoordinateY, const int currentPosition, const int maxAngleError);
    Ray GetPositiveErrorRay() const;
    Ray GetNegativeErrorRay() const;
    int GetMaxAngleErorr() const;
    int GetAngle() const;
    int GetPosition() const;
    void Recalculate(const int position);
};
#endif // VISOR_H
