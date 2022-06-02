#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H
#include <QWidget>
#include <QPainter>
#include <QtGui>

class PaintWidget : public QWidget
{
    Q_OBJECT
private:
    double nodeX;
    double nodeY;
    double cf;
    double rad;
    double radLink;
    std::vector <node> vecNode;
public:
    PaintWidget(QWidget *parent = Q_NULLPTR);
    void paintEvent(QPaintEvent *event);
    void SetNodeXY(double NewNodeX,double NewNodeY);
    void SetPtrVecNode(std::vector <node>* argPtrVecNode);
    void SetCf(double argCf);
    void SetRadius(double arg_rad);
    void SetRadiusLink(double arg_radLink);
    void RealToScreen(double x_min, double x_max, double y_min,
           double y_max,double X, double Y, int &ScrX, int &ScrY);
};
#endif // PAINTWIDGET_H
