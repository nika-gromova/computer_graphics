#ifndef MATH_MODULE_H
#define MATH_MODULE_H

#include "my_paintwidget.h"
#include <math.h>
#define EPS 1e-10

void vector_mult(vector_type &a, vector_type &b, vector_type &res);
int scalar_mult(vector_type &a, vector_type &b);
double distance(QPoint &p1, QPoint &p2);
double distance_to_point(QPoint &p1, QPoint &p2, QPoint &p);
QPoint calculate_P(const QPoint &p1, const QPoint &p2, double t);
QPoint normal_point(QPoint &A, QPoint &B, QPoint &C);

#endif // MATH_MODULE_H
