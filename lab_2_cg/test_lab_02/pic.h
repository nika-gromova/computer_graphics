#ifndef PIC_H
#define PIC_H

#include <QPainter>
#include <QGraphicsItem>

class pic : public QGraphicsItem
{
public:
    pic();
    QPoint face_top_left;
    QPoint face_bootom_right;
    QPoint eye_top_left_1;
    QPoint eye_bottom_rigth_1;
    QPoint eye_top_left_2;
    QPoint eye_bottom_rigth_2;
    QPoint hair_top_1;
    QPoint hair_bottom_1;
    QPoint hair_top_2;
    QPoint hair_bottom_2;
    QPoint hair_top_3;
    QPoint hair_bottom_3;
    QPoint hair_top_4;
    QPoint hair_bottom_4;
    QPoint nose_up;
    QPoint nose_left;
    QPoint nose_right;
    QPoint mounth_left;
    QPoint mounth_right;
    QPoint mounth_bottom;
    QPoint pupil_top_1;
    QPoint pupil_bot_1;
    QPoint pupil_top_2;
    QPoint pupil_bot_2;

    QPoint test;

    QPolygon pic_points;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // PIC_H
