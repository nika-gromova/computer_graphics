#ifndef PIC_H
#define PIC_H

#include <QPainter>
#include <QGraphicsItem>
#include <QPoint>
#include <QPointF>
#include <QPolygon>
#include <QPolygonF>
#include <math.h>

class pic : public QGraphicsItem
{
public:
    pic();

    QPointF hair_top_1;
    QPointF hair_bottom_1;
    QPointF hair_top_2;
    QPointF hair_bottom_2;
    QPointF hair_top_3;
    QPointF hair_bottom_3;
    QPointF hair_top_4;
    QPointF hair_bottom_4;
    QPointF nose_up;
    QPointF nose_left;
    QPointF nose_right;
    QPointF mounth_left;
    QPointF mounth_right;
    QPointF mounth_bottom;

    QPolygonF pic_points;
    QPolygonF face;
    QPolygonF eye_1;
    QPolygonF eye_2;
    QPolygonF pupil_1;
    QPolygonF pupil_2;
    QVector <QPolygonF> ellipses;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PIC_H
