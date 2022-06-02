#ifndef RAY_H
#define RAY_H

#include "Vector.h"
#include "Angle.h"

class Ray
{
    // Добавить position ??
private:
    const int m_maxAngleError;
    int m_angleValue;
    std::pair<int, int> m_rayCoordinate;

public:
    enum ErrorSign
    {
        POSITIVE = 1,
        NEGATIVE = -1
    };
    Ray(Vector vectorCoordinate, Angle angle, int maxAngleError, int errorSign);
    int GetAngleSign() const;
};

#endif // RAY_H
