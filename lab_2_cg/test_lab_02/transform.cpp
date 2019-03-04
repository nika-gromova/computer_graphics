#include <math.h>
#include "transform.h"
#include <stdio.h>
void move_point(QPoint &point, double dx, double dy)
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
}

void scale_point(QPoint &point, double cx, double cy, double kx, double ky)
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
}

void rotate_point(QPoint &point, double cx, double cy, double degree)
{
    double radians = (degree * M_PI) / 180;
    double tmp_x = point.x();
    double tmp_y = point.y();
    point.setX(cx + (tmp_x - cx) * cos(radians) + (tmp_y - cy) * sin(radians));
    point.setY(cy - (tmp_x - cx) * sin(radians) + (tmp_y - cy) * cos(radians));
}

void change_ellipse_params(QPoint &point_top, QPoint &point_bottom)
{
    int tmp_x;
    int tmp_y;
    if (!(point_top.x() < point_bottom.x()) || !(point_top.y() < point_bottom.y()))
    {
        if (point_top.x() > point_bottom.x())
        {
            if (point_top.y() > point_bottom.y())
            {
                tmp_x = point_top.x();
                tmp_y = point_top.y();
                point_top.setX(point_bottom.x());
                point_top.setY(point_bottom.y());
                point_bottom.setX(tmp_x);
                point_bottom.setY(tmp_y);
            }
            else
            {
                tmp_x = point_top.x();
                point_top.setX(point_bottom.x());
                point_bottom.setX(tmp_x);
            }
        }
        else
        {
            tmp_y = point_top.y();
            point_top.setY(point_bottom.y());
            point_bottom.setY(tmp_y);
        }
    }
}

void rotate_ellipse(QPoint &point_top, QPoint &point_bottom, double cx, double cy, double degree)
{
    QPoint center;
    int width = point_bottom.x() - point_top.x();
    int height = point_bottom.y() - point_top.y();
    center.setX((point_top.x() + point_bottom.x()) / 2);
    center.setY((point_top.y() + point_bottom.y()) / 2);
    rotate_point(center, cx, cy, degree);
    point_top.setX(center.x() - width / 2);
    point_top.setY(center.y() - height / 2);
    point_bottom.setX(center.x() + width / 2);
    point_bottom.setY(center.y() + height / 2);
    //rotate_point(point_top, center.x(), center.y(), degree);
    //rotate_point(point_bottom, center.x(), center.y(), degree);
    //change_ellipse_params(point_top, point_bottom);
}


void rotate_pic(pic *my_pic, double cx, double cy, double degree)
{
    /*rotate_point((my_pic->pic_points)[4], cx, cy, degree);
    rotate_point((my_pic->pic_points)[5], cx, cy, degree);
    printf("%d %d\n", (my_pic->pic_points[4]).x(), (my_pic->pic_points[4]).y());
    printf("%d %d\n", (my_pic->pic_points[5]).x(), (my_pic->pic_points[5]).y());
    change_ellipse_params((my_pic->pic_points)[4], (my_pic->pic_points)[5]);
    printf("%d %d\n", (my_pic->pic_points[4]).x(), (my_pic->pic_points[4]).y());
    printf("%d %d\n", (my_pic->pic_points[5]).x(), (my_pic->pic_points[5]).y());
    rotate_point((my_pic->pic_points)[24], cx, cy, degree);*/
    rotate_ellipse(my_pic->pic_points[0], my_pic->pic_points[1], cx, cy, degree);
    for (int i = 6; i < my_pic->pic_points.size(); i++)
    {
        rotate_point((my_pic->pic_points)[i], cx, cy, degree);
    }
}
