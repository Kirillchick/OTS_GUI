#ifndef ANGLE_H
#define ANGLE_H

#include "Vector.h"
#include <QtMath>

class Angle
{
private:
    double m_angleValue; // degree
    double СalculateAngle(const Vector vectorCoordinate) const;
public:
    Angle(const Vector vectorCoordinate);
    double GetAngle() const;
    void Recalculate(const Vector vectorCoordinate);
};

#endif // ANGLE_H
