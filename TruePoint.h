#ifndef TRUEPOINT_H
#define TRUEPOINT_H

class TruePoint
{
private:
    const double m_fieldSizeX = 500.0;
    const double m_fieldSizeY = 500.0;
    const double m_trueX;
    const double m_trueY;
    //int GenerateRandomPoint(const int fieldSize) const;
public:
    explicit TruePoint(const double coordinateX, const double coordinateY);
    int GetTrueX() const;
    int GetTrueY() const;
};

#endif // TRUEPOINT_H
