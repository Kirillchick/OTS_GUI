#ifndef RAY_H
#define RAY_H

#include "Angle.h"

class Ray
{
private:
    const int m_maxAngleError;
    double m_angleValue;
    const int m_errorSign;
    double m_position;
public:
    enum ErrorSign
    {
        POSITIVE = 1,
        NEGATIVE = -1
    };
    Ray(const Angle angle, const int errorSign, const double position, const double maxAngleError);
    int GetAngleSign() const;
    double GetAngle() const;
    void Recalculate(const Angle angle, const double position);
};

#endif // RAY_H
