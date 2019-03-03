#include <math.h>
#include "transform.h"

void move_point(QPoint *point, double dx, double dy)
{
    double tmp_x = point->x();
    double tmp_y = point->y();
    point->setX(tmp_x + dx);
    point->setY(tmp_y + dy);
}

void move_pic(face *k_face, eyes *k_eyes, double dx, double dy)
{
    move_point(&(k_face->topLeft), dx, dy);
    move_point(&(k_face->bottomRight), dx, dy);
    move_point(&(k_eyes->topLeft_1), dx, dy);
    move_point(&(k_eyes->topLeft_2), dx, dy);
    move_point(&(k_eyes->bottomRight_1), dx, dy);
    move_point(&(k_eyes->bottomRight_2), dx, dy);
}

/*QPoint scale(QPoint point, double cx, double cy, double kx, double ky)
{

}*/
