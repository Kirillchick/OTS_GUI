#ifndef RAY_H
#define RAY_H

#include "Vector.h"
#include "Angle.h"

class Ray
{
private:
    //const int m_maxAngleError;
    int m_angleValue;
    //std::pair<int, int> m_rayCoordinate;
    int m_errorSign;
    int m_position;
public:
    enum ErrorSign
    {
        POSITIVE = 1,
        NEGATIVE = -1
    };
    //Ray(Vector vectorCoordinate, Angle angle, int maxAngleError, int errorSign, int position);
    Ray(const Angle angle, const int errorSign, const int position, const int maxAngleError);
    int GetAngleSign() const;
    int GetAngle() const;
    void Recalculate(const Angle angle, const int errorSign, const int position, const int maxAngleError);
};

#endif // RAY_H
