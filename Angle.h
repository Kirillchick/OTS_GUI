#ifndef ANGLE_H
#define ANGLE_H

#include "Vector.h"
#include <QtMath>

class Angle
{
private:
    int m_angleValue; // degree
    int СalculateAngle(const Vector vectorCoordinate) const;
public:
    Angle(const Vector vectorCoordinate);
    int GetAngle() const;
    void Recalculate(const Vector vectorCoordinate);
};

#endif // ANGLE_H
