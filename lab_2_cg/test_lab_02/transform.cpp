#include <math.h>
#include "transform.h"
#include <stdio.h>
void move_point(QPointF &point, double dx, double dy)
{
    double tmp_x = point.x();
    double tmp_y = point.y();
    point.setX(tmp_x + dx);
    point.setY(tmp_y + dy);
}

/*void move_pic(face *k_face, eyes *k_eyes, double dx, double dy)
{
    move_point(&(k_face->topLeft), dx, dy);
    move_point(&(k_face->bottomRight), dx, dy);
    move_point(&(k_eyes->topLeft_1), dx, dy);
    move_point(&(k_eyes->topLeft_2), dx, dy);
    move_point(&(k_eyes->bottomRight_1), dx, dy);
    move_point(&(k_eyes->bottomRight_2), dx, dy);
}*/


void move_pic(pic *my_pic, double dx, double dy)
{
    for (int i = 0; i < my_pic->pic_points.size(); i++)
    {
        move_point((my_pic->pic_points)[i], dx, dy);
    }
    for (int i = 0; i < my_pic->ellipses.size(); i++)
    {
        for (int j = 0; j < my_pic->ellipses[i].size(); j++)
            move_point(my_pic->ellipses[i][j], dx, dy);
    }
}

void scale_point(QPointF &point, double cx, double cy, double kx, double ky)
{
    double tmp_x = point.x();
    double tmp_y = point.y();
    point.setX(tmp_x * kx + (1 - kx) * cx);
    point.setY(tmp_y * ky + (1 - ky) * cy);
}

void scale_pic(pic *my_pic, double cx, double cy, double kx, double ky)
{
    for (int i = 0; i < my_pic->pic_points.size(); i++)
    {
        scale_point((my_pic->pic_points)[i], cx, cy, kx, ky);
    }
    for (int i = 0; i < my_pic->ellipses.size(); i++)
    {
        for (int j = 0; j < my_pic->ellipses[i].size(); j++)
            scale_point(my_pic->ellipses[i][j], cx, cy, kx, ky);
    }
}

void rotate_point(QPointF &point, double cx, double cy, double degree)
{
    double radians = (degree * M_PI) / 180;
    double tmp_x = point.x();
    double tmp_y = point.y();
    point.setX(cx + (tmp_x - cx) * cos(radians) + (tmp_y - cy) * sin(radians));
    point.setY(cy - (tmp_x - cx) * sin(radians) + (tmp_y - cy) * cos(radians));
}

void rotate_pic(pic *my_pic, double cx, double cy, double degree)
{
    for (int i = 0; i < my_pic->pic_points.size(); i++)
    {
        rotate_point((my_pic->pic_points)[i], cx, cy, degree);
    }
    for (int i = 0; i < my_pic->ellipses.size(); i++)
    {
        for (int j = 0; j < my_pic->ellipses[i].size(); j++)
            rotate_point(my_pic->ellipses[i][j], cx, cy, degree);
    }
}

void copy_pic(pic *dst, pic *src)
{
    for (int i = 0; i < dst->ellipses.size(); i++)
    {
        for (int j = 0; j < dst->ellipses[i].size(); j++)
        {
            dst->ellipses[i][j].setX(src->ellipses[i][j].x());
            dst->ellipses[i][j].setY(src->ellipses[i][j].y());
        }
    }
    for (int i = 0; i < dst->pic_points.size(); i++)
    {
        dst->pic_points[i].setX(src->pic_points[i].x());
        dst->pic_points[i].setY(src->pic_points[i].y());
    }
}
