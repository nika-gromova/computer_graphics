#include "face.h"

face::face()
{
    topLeft.setX(225);
    topLeft.setY(225);
    bottomRight.setX(320);
    bottomRight.setY(320);
}

/*face::face(double x_tl, double y_tl, double x_br, double y_br)
{
    topLeft.setX(x_tl);
    topLeft.setY(y_tl);
    bottomRight.setX(x_br);
    bottomRight.setY(y_br);
}*/

QRectF face::boundingRect() const
{
    return QRectF(topLeft, bottomRight);
}

void face::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect(topLeft, bottomRight);
    QBrush brush(Qt::yellow);
    painter->setPen(Qt::darkYellow);
    painter->setBrush(brush);
    painter->drawEllipse(rect);
}
