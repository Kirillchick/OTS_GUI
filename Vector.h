#ifndef VECTOR_H
#define VECTOR_H
#define ZERO 0

#include "DefinedPoint.h"
#include <vector>
class Vector
{
private:
    const DefinedPoint m_point;
    double m_initalPosition;
    std::pair<double, double> m_vectorCoordinate;

    void SetVectorCoordinate(const double initalPosition);
    std::pair<double, double> CalculateVectorCoordinate(const double initalPosition) const;
public:
    explicit Vector(const DefinedPoint point, const double initalPosition);
    void Recalculate(const double position);
    std::pair<double, double> GetVectorCoordinate() const;
};

#endif // VECTOR_H
