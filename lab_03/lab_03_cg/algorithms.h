#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <QPainter>
#include <math.h>

void dda(int x_start, int y_start, int x_end, int y_end, QPainter &painter);
void bre_double(int x_start, int y_start, int x_end, int y_end, QPainter &painter);
void bre_int(int x_start, int y_start, int x_end, int y_end, QPainter &painter);
void bre_stairs(int x_start, int y_start, int x_end, int y_end, QPainter &painter);
void decorator(int x_start, int y_start, int x_end, int y_end, QPainter &painter);
void draw_sun(int xc, int yc, int x_end, int y_end, int step, QPainter &painter, void (*draw_line)(int, int, int, int, QPainter &));

#endif // ALGORITHMS_H
