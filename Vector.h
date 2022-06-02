#ifndef VECTOR_H
#define VECTOR_H
#define ZERO 0

#include "DefinedPoint.h"
#include <vector>
class Vector
{
private:
    const DefinedPoint m_point;
    int m_initalPosition;
    std::pair<int, int> m_vectorCoordinate;
    void SetVectorCoordinate(const int initalPosition);
    std::pair<int, int> CalculateVectorCoordinate(const int initalPosition) const;
public:
    explicit Vector(const DefinedPoint point, const int initalPosition);
    std::pair<int, int> GetVectorCoordinate() const;
};

#endif // VECTOR_H
