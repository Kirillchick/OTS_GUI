#ifndef DEFINEDPOINT_H
#define DEFINEDPOINT_H

#include "TruePoint.h"

class DefinedPoint
{
private:
    const TruePoint m_truePoint;
    const int m_coordinateX;
    const int m_coordinateY;
    int GenerateRandomError(const int maxNoiseError) const;
public:
    DefinedPoint(const int trueCoordinateX, const int trueCoordinateY, const int maxNoiseError = 3);
    int getCoordX() const;
    int getCoordY() const;
};

#endif // DEFINEDPOINT_H
