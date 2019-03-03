#include "eyes.h"

eyes::eyes()
{
    topLeft_1.setX(245);
    topLeft_1.setY(255);
    topLeft_2.setX(280);
    topLeft_2.setY(255);
    bottomRight_1.setX(265);
    bottomRight_1.setY(275);
    bottomRight_2.setX(300);
    bottomRight_2.setY(275);
}


/*eyes::eyes(double x_1, double x_2, double x_3, double x_4, double y_up, double y_down)
{
    topLeft_1.setX(x_1);
    topLeft_1.setY(y_up);
    topLeft_2.setX(x_3);
    topLeft_2.setY(y_up);
    bottomRight_1.setX(x_2);
    bottomRight_1.setY(y_down);
    bottomRight_2.setX(x_4);
    bottomRight_2.setY(y_down);
}*/

QRectF eyes::boundingRect() const
{
    return QRectF(topLeft_1, bottomRight_2);
}

void eyes::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect_1(topLeft_1, bottomRight_1);
    QRectF rect_2(topLeft_2, bottomRight_2);
    QBrush brush(Qt::green);
    painter->setPen(Qt::black);
    painter->setBrush(brush);
    painter->drawEllipse(rect_1);
    painter->drawEllipse(rect_2);
}
