#include "pic.h"
#include <stdio.h>

void get_ellipse(double a, double b, double xc, double yc, QPolygonF &poly)
{
    double tmp;
    int count;
    double a2 = a * a;
    double b2 = b * b;
    for (int i = -a; i <= 0; i++)
    {
        tmp = (-1) * sqrt(((a2 * b2) - (i * i) * b2) / a2);
        poly << QPointF(double(i + xc), tmp + yc);
    }
    for (int i = 1; i < a + 1; i++)
    {
        tmp = (-1) * sqrt(((a2 * b2) - (i * i) * b2) / a2);
        poly << QPointF(double(i + xc), tmp + yc);
    }
    count = poly.size();
    for (int i = count - 1; i >= 0; i--)
        poly << QPointF(poly[i].x(), yc + fabs(poly[i].y() - yc));
}

pic::pic()
{
    get_ellipse(50.0, 50.0, 270.0, 270.0, face);

    get_ellipse(10.0, 10.0, 250.0, 260.0, eye_1);
    get_ellipse(10.0, 10.0, 290.0, 260.0, eye_2);

    hair_top_1.setX(255.0);
    hair_top_1.setY(225.0);
    hair_top_2.setX(265.0);
    hair_top_2.setY(225.0);
    hair_top_3.setX(275.0);
    hair_top_3.setY(225.0);
    hair_top_4.setX(285.0);
    hair_top_4.setY(225.0);
    hair_bottom_1.setX(240.0);
    hair_bottom_1.setY(245.0);
    hair_bottom_2.setX(250.0);
    hair_bottom_2.setY(245.0);
    hair_bottom_3.setX(290.0);
    hair_bottom_3.setY(245.0);
    hair_bottom_4.setX(300.0);
    hair_bottom_4.setY(245.0);

    nose_up.setX(270.0);
    nose_up.setY(270.0);
    nose_left.setX(260.0);
    nose_left.setY(290.0);
    nose_right.setX(280.0);
    nose_right.setY(290.0);

    mounth_left.setX(255.0);
    mounth_left.setY(300.0);
    mounth_right.setX(285.0);
    mounth_right.setY(300.0);
    mounth_bottom.setX(270.0);
    mounth_bottom.setY(315.0);

    get_ellipse(3.0, 3.0, 250.0, 260.0, pupil_1);
    get_ellipse(3.0, 3.0, 290.0, 260.0, pupil_2);


    pic_points << hair_top_1 << hair_bottom_1 << hair_top_2 << hair_bottom_2 << hair_top_3 << hair_bottom_3 << hair_top_4 << hair_bottom_4;
    pic_points << nose_up << nose_left << nose_right << mounth_left << mounth_right << mounth_bottom;

    ellipses.push_back(face);
    ellipses.push_back(eye_1);
    ellipses.push_back(eye_2);
    ellipses.push_back(pupil_1);
    ellipses.push_back(pupil_2);
}

QRectF pic::boundingRect() const
{
    return QRectF(pic_points[0], pic_points[13]);
}

void pic::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setPen(Qt::darkYellow);
    painter->setBrush(Qt::yellow);
    painter->drawPolygon(ellipses[0]);

    painter->setPen(Qt::darkGray);
    painter->setBrush(Qt::white);
    painter->drawPolygon(ellipses[1]);
    painter->drawPolygon(ellipses[2]);

    painter->setBrush(Qt::black);
    painter->drawPolygon(ellipses[3]);
    painter->drawPolygon(ellipses[4]);


    painter->setPen(Qt::black);
    painter->drawLine(pic_points[0], pic_points[1]);
    painter->drawLine(pic_points[2], pic_points[3]);
    painter->drawLine(pic_points[4], pic_points[5]);
    painter->drawLine(pic_points[6], pic_points[7]);

    painter->setBrush(Qt::yellow);
    QPolygonF nose;
    nose << pic_points[8] << pic_points[9] << pic_points[10];
    painter->drawPolygon(nose);

    painter->setBrush(Qt::darkRed);
    QPolygonF mounth;
    mounth << pic_points[11] << pic_points[12] << pic_points[13];
    painter->drawPolygon(mounth);
}

