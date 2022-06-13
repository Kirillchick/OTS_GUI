#ifndef TRUEPOINT_H
#define TRUEPOINT_H

#include <QRandomGenerator>

class TruePoint
{
private:
    const double m_fieldSizeX = 500;
    const int m_fieldSizeY = 500;
    const int m_trueX;
    const int m_trueY;
    //int GenerateRandomPoint(const int fieldSize) const;
public:
    explicit TruePoint(const int coordinateX, const int coordinateY);
    int GetTrueX() const;
    int GetTrueY() const;
};

#endif // TRUEPOINT_H
