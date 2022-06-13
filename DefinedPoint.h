#ifndef DEFINEDPOINT_H
#define DEFINEDPOINT_H

#include "TruePoint.h"
#include <QRandomGenerator>
#include <QDebug>

class DefinedPoint
{
private:
    const TruePoint m_truePoint;
    const double m_coordinateX;
    const double m_coordinateY;
    double GenerateRandomError(const double maxNoiseError) const;
public:
    DefinedPoint(const double trueCoordinateX, const double trueCoordinateY, const double maxNoiseError = 3.0);
    double getCoordX() const;
    double getCoordY() const;
};

#endif // DEFINEDPOINT_H
