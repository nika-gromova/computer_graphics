#ifndef EYES_H
#define EYES_H

#include <QPainter>
#include <QGraphicsItem>

class eyes : public QGraphicsItem
{
public:
    eyes();

    QPoint topLeft_1;
    QPoint bottomRight_1;
    QPoint topLeft_2;
    QPoint bottomRight_2;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // EYES_H
