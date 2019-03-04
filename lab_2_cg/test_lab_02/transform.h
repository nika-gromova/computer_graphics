#ifndef TRANSFORM_H
#define TRANSFORM_H
#include <QPoint>
#include "face.h"
#include "eyes.h"
#include "pic.h"

void move_pic(pic *my_pic, double dx, double dy);
void scale_pic(pic *my_pic, double cx, double cy, double kx, double ky);
void rotate_pic(pic *my_pic, double cx, double cy, double degree);

#endif // TRANSFORM_H
