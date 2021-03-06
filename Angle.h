#ifndef ANGLE_H
#define ANGLE_H

#include "Vector.h"
#include <QtMath>

class Angle
{
private:
    int m_angleValue; // degree
    int –°alculateAngle(const Vector vectorCoordinate) const;
public:
    Angle(const Vector vectorCoordinate);
    int GetAngle() const;
};

#endif // ANGLE_H
