#include "PaintWidget.h"

PaintWidget::PaintWidget(QWidget *parent){

}

void PaintWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPen MyBlackPen(Qt::black, 1, Qt::SolidLine);
    QPen MyBluePen(Qt::blue, 1, Qt::SolidLine);
    QPen MyPinkPen(QColorConstants::Svg::pink, 1, Qt::DashLine);
    painter.setPen(MyBlackPen);
    int sizeRect = 390;
    painter.drawRect(0,0,sizeRect,sizeRect);
    int radiusCircle = rad * cf;
    int radiusCircleLink = radLink * cf;

    for (int i = 0 ; i < vecNode.size(); i++){
        if (i == 0){
            double firstX = (vecNode)[i].pos.first * cf;
            double firstY = (vecNode)[i].pos.second * cf;

            int ScrX,ScrY;
            RealToScreen(0, sizeRect, 0, sizeRect, firstX, firstY, ScrX, ScrY);
            QPen MyRedPen(Qt::red, 1, Qt::SolidLine);
            painter.setPen(MyRedPen);
            painter.drawEllipse(ScrX-radiusCircle/2 , ScrY-radiusCircle/2 , radiusCircle , radiusCircle );
            painter.drawPoint(ScrX, ScrY);
            painter.setPen(MyPinkPen);
            painter.drawEllipse(ScrX-radiusCircleLink/2 , ScrY-radiusCircleLink/2, radiusCircleLink , radiusCircleLink);
            continue;
        }
        if ((vecNode)[i].energy > 0){
            double x  = (vecNode)[i].pos.first * cf;
            double y = (vecNode)[i].pos.second * cf;
            int ScrX,ScrY;
            RealToScreen(0, sizeRect, 0, sizeRect, x, y, ScrX, ScrY);
            painter.setPen(MyBlackPen);
            painter.drawEllipse(ScrX-radiusCircle/2 , ScrY-radiusCircle/2 , radiusCircle , radiusCircle);
            painter.setPen(MyPinkPen);
            painter.drawEllipse(ScrX-radiusCircleLink/2 , ScrY-radiusCircleLink/2 , radiusCircleLink, radiusCircleLink);
            painter.setPen(MyBlackPen);
            painter.drawPoint(ScrX, ScrY);
            painter.drawText(ScrX, ScrY, QString::number(vecNode[i].num));
        }

            clear_func(&vecNode);
            std::queue <int> q;
            int current = 0;
            q.push(current);
            (vecNode)[current].mark = true;
            while (!q.empty())
            {
                current = q.front();
                q.pop();
                for (auto it = (vecNode)[current].c_arr.begin(); it != (vecNode)[current].c_arr.end(); ++it)
                {
                    if ((vecNode[*it].energy <= 0) && (*it != 0))
                            continue;
                    if ((vecNode)[*it].mark == false)
                    {
                        (vecNode)[*it].mark = true;
                        int ScrXi,ScrYi;
                        int ScrXj,ScrYj;
                        RealToScreen(0, sizeRect, 0, sizeRect, (vecNode)[current].pos.first * cf, (vecNode)[current].pos.second * cf, ScrXi, ScrYi);
                        RealToScreen(0, sizeRect, 0, sizeRect, (vecNode)[*it].pos.first * cf, (vecNode)[*it].pos.second * cf, ScrXj, ScrYj);
                        painter.setPen(MyBluePen);
                        painter.drawLine(ScrXi, ScrYi, ScrXj, ScrYj);
                        q.push(*it);
                    }
                }
            }
    }
}

void GraphWidget::SetNodeXY(double NewNodeX,double NewNodeY){
    nodeX=NewNodeX;
    nodeY=NewNodeY;
}

void GraphWidget::SetPtrVecNode(std::vector <node>* argPtrVecNode){
    vecNode = *argPtrVecNode;
};

void GraphWidget::SetCf(double argCf){
    cf = argCf;
};

void GraphWidget::RealToScreen(double x_min, double x_max, double y_min, double y_max,double X, double Y, int &ScrX, int &ScrY)
{
        ScrX = (width() - 1)*(X - x_min) / (x_max - x_min);
        ScrY = (height() - 1)*(y_max - Y) / (y_max - y_min);
}
void GraphWidget::SetRadius(double arg_rad){
    rad = arg_rad;
}
void GraphWidget::SetRadiusLink(double arg_radLink)
{
    radLink = arg_radLink;
}

