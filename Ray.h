#ifndef RAY_H
#define RAY_H

#include "Angle.h"

class Ray
{
private:
    //const int m_maxAngleError;
    double m_angleValue;
    //std::pair<int, int> m_rayCoordinate;
    int m_errorSign;
    double m_position;
public:
    enum ErrorSign
    {
        POSITIVE = 1,
        NEGATIVE = -1
    };
    //Ray(Vector vectorCoordinate, Angle angle, int maxAngleError, int errorSign, int position);
    Ray(const Angle angle, const int errorSign, const double position, const double maxAngleError);
    int GetAngleSign() const;
    double GetAngle() const;
    void Recalculate(const Angle angle, const int errorSign, const double position, const double maxAngleError);
};

#endif // RAY_H
