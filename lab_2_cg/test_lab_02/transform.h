#ifndef TRANSFORM_H
#define TRANSFORM_H
#include <QPoint>
#include "pic.h"

void move_pic(pic *my_pic, double dx, double dy);
void scale_pic(pic *my_pic, double cx, double cy, double kx, double ky);
void rotate_pic(pic *my_pic, double cx, double cy, double degree);
void copy_pic(pic *dst, pic *src);

#endif // TRANSFORM_H
