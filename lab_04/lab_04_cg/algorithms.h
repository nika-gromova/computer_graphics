#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <QPainter>
#include <math.h>
void canon_circle(int &xc, int &yc, int &r, QPainter &painter);
void canon_ellipse(int &xc, int &yc, int &a, int &b, QPainter &painter);
void param_circle(int &xc, int &yc, int &r, QPainter &painter);
void param_ellipse(int &xc, int &yc, int &a, int &b, QPainter &painter);
void bre_circle(int &xc, int &yc, int &r, QPainter &painter);
void bre_ellipse(int &xc, int &yc, int &a, int &b, QPainter &painter);
void midpoint_circle(int &xc, int &yc, int &r, QPainter &painter);
void midpoint_ellipse(int &xc, int &yc, int &a, int &b, QPainter &painter);

void lib_circle(int &xc, int &yc, int &r, QPainter &painter);
void lib_ellipse(int &xc, int &yc, int &a, int &b, QPainter &painter);


void draw_circles(int &xc, int &yc, int &r_start, int &r_end, int &step, QPainter &painter, void (*draw_circle)(int &, int&, int &, QPainter &));
void draw_ellipses(int &xc, int &yc, int &a_start, int &b_start, int &step, int &n, QPainter &painter, void (*draw_ellipse)(int &, int&, int &, int &, QPainter &));
#endif // ALGORITHMS_H
