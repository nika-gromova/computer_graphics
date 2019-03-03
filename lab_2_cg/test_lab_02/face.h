#ifndef FACE_H
#define FACE_H

#include <QPainter>
#include <QGraphicsItem>


class face : public QGraphicsItem
{
public:
    face();

    QPoint topLeft;
    QPoint bottomRight;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // FACE_H
