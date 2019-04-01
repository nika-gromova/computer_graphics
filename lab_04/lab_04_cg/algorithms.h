#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <QPainter>
#include <math.h>
void canon_circle(int &xc, int &yc, int &r, QPainter &painter, bool act);
void canon_ellipse(int &xc, int &yc, int &a, int &b, QPainter &painter, bool act);
void param_circle(int &xc, int &yc, int &r, QPainter &painter, bool act);
void param_ellipse(int &xc, int &yc, int &a, int &b, QPainter &painter, bool act);
void bre_circle(int &xc, int &yc, int &r, QPainter &painter, bool act);
void bre_ellipse(int &xc, int &yc, int &a, int &b, QPainter &painter, bool act);
void midpoint_circle(int &xc, int &yc, int &r, QPainter &painter, bool act);
void midpoint_ellipse(int &xc, int &yc, int &a, int &b, QPainter &painter, bool act);

void lib_circle(int &xc, int &yc, int &r, QPainter &painter, bool act);
void lib_ellipse(int &xc, int &yc, int &a, int &b, QPainter &painter, bool act);


void draw_circles(int &xc, int &yc, int &r_start, int &r_end, int &step, QPainter &painter, void (*draw_circle)(int &, int&, int &, QPainter &, bool));
void draw_ellipses(int &xc, int &yc, int &a_start, int &b_start, int &step, int &n, QPainter &painter, void (*draw_ellipse)(int &, int&, int &, int &, QPainter &, bool));
#endif // ALGORITHMS_H
