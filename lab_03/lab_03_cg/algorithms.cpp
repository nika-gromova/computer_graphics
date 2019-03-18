#include "algorithms.h"
#define EPS 1e-10
void dda(int x_start, int y_start, int x_end, int y_end, QPainter &painter)
{
    int dx = x_end - x_start;
    int dy = y_end - y_start;
    int len = (abs(dx) > abs(dy) ? abs(dx) : abs(dy));
    double sx = ((double)dx / (double)len);
    double sy = ((double)dy / (double)len);
    double x = x_start;
    double y = y_start;
    for (int i = 0; i < len + 1; i++)
    {
        painter.drawPoint((int)x, (int)y);
        x += sx;
        y += sy;
    }
}

int sign(int x)
{
    if (x > 0)
        return 1;
    else if (x == 0)
        return 0;
    return -1;
}

int sign(double x)
{
    if (x > EPS)
        return 1;
    else if (x == EPS)
        return 0;
    return -1;
}

void swap_num(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

void bre_double(int x_start, int y_start, int x_end, int y_end, QPainter &painter)
{
    int dx = x_end - x_start;
    int dy = y_end - y_start;
    int x = x_start;
    int y = y_start;
    int sx = sign(dx);
    int sy = sign(dy);
    dx = abs(dx);
    dy = abs(dy);
    bool swap = (dx > dy ? false : true);
    if (swap)
        swap_num(dx, dy);
    double m = (double)dy / (double)dx;
    double e = m - 0.5;
    for (int i = 0; i < dx + 1; i++)
    {
        painter.drawPoint(x, y);
        if (e >= 0.0)
        {
            if (!swap)
                y += sy;
            else
                x += sx;
            e -= 1;
        }
        if (!swap)
            x += sx;
        else
            y += sy;
        e += m;
    }
}

void bre_int(int x_start, int y_start, int x_end, int y_end, QPainter &painter)
{
    int dx = x_end - x_start;
    int dy = y_end - y_start;
    int x = x_start;
    int y = y_start;
    int sx = sign(dx);
    int sy = sign(dy);
    dx = abs(dx);
    dy = abs(dy);
    bool swap = (dx > dy ? false : true);
    if (swap)
        swap_num(dx, dy);
    int e = 2 * dy - dx;
    for (int i = 0; i < dx + 1; i++)
    {
        painter.drawPoint((int)x, (int)y);
        if (e >= 0.0)
        {
            if (!swap)
                y += sy;
            else
                x += sx;
            e -= 2 * dx;
        }
        if (!swap)
            x += sx;
        else
            y += sy;
        e += 2 * dy;
    }
}

void bre_stairs(int x_start, int y_start, int x_end, int y_end, QPainter &painter)
{
    int imax = 255;
    QColor color(painter.pen().color()); // текущий цвет
    int dx = x_end - x_start;
    int dy = y_end - y_start;
    int x = x_start;
    int y = y_start;
    int sx = sign(dx);
    int sy = sign(dy);
    dx = abs(dx);
    dy = abs(dy);
    bool swap = (dx > dy ? false : true);
    if (swap)
        swap_num(dx, dy);
    double m = (double)dy / (double)dx;
    double e = imax * 0.5;
    m = m * imax;
    double w = imax - m;
    color.setAlphaF(e / imax);
    painter.setPen(color); // установление самого цвета
    painter.drawPoint(x, y);
    for (int i = 0; i < dx; i++)
    {
        if (e < w)
        {
            if (!swap)
                x += sx;
            else
                y += sy;
            e += m;
        }
        else
        {
            x += sx;
            y += sy;
            e -= w;
        }
        color.setAlphaF(e / imax);
        painter.setPen(color);
        painter.drawPoint(x, y);
    }
    color.setAlphaF(1);
    painter.setPen(color);
}

void wu_smoth(int x_start, int y_start, int x_end, int y_end, QPainter &painter)
{
    int imax = 255;
    QColor color(painter.pen().color());

    int dx = abs(x_end - x_start);
    int dy = abs(y_end - y_start);
    double m;
    double y_iter = 0;
    double x_iter = 0;
    if (dy < dx)
    {
        if (x_end < x_start)
        {
            swap_num(x_start, x_end);
            swap_num(y_start, y_end);
        }
        m = (double)dy / (double)dx;
        if (y_end < y_start)
            m = -m;
        y_iter = y_start + m;
        painter.drawPoint(x_start, y_start);
        painter.drawPoint(x_end, y_end);
        for (int x = x_start + 1; x < x_end; x++)
        {
            color.setAlphaF((imax - fabs(y_iter - (int)y_iter) * imax) / imax);
            painter.setPen(color);
            painter.drawPoint(x, (int)y_iter);
            color.setAlphaF((fabs(y_iter - (int)y_iter) * imax) / imax);
            painter.setPen(color);
            painter.drawPoint(x, (int)(y_iter) + 1);
            y_iter += m;
        }
    }
    else
    {
        if (y_end < y_start)
        {
            swap_num(x_start, x_end);
            swap_num(y_start, y_end);
        }
        m = (double)dx / (double)dy;
        if (x_end < x_start)
            m = -m;
        x_iter = x_start + m;
        painter.drawPoint(x_start, y_start);
        painter.drawPoint(x_end, y_end);
        for (int y = y_start + 1; y < y_end; y++)
        {
            color.setAlphaF((imax - fabs(x_iter - (int)x_iter) * imax) / imax);
            painter.setPen(color);
            painter.drawPoint((int)x_iter, y);
            color.setAlphaF((fabs(x_iter - (int)x_iter) * imax) / imax);
            painter.setPen(color);
            painter.drawPoint((int)x_iter + 1, y);
            x_iter += m;
        }
    }
    color.setAlphaF(1);
    painter.setPen(color);
}

/*void wu_smoth(int x_start, int y_start, int x_end, int y_end, QPainter &painter)
{
    int imax = 255;
    int a, h, l, s;
    QColor color(painter.pen().color());
    color.getHsl(&h, &s, &l, &a);

    bool swap = (abs(y_end - y_start) > abs(x_end - x_start));
    if (swap)
    {
        swap_num(x_start, y_start);
        swap_num(x_end, y_end);
    }
    if (x_start > x_end)
    {
        swap_num(x_start, x_end);
        swap_num(y_start, y_end);
    }
    painter.drawPoint((swap ? y_start : x_start), (swap ? x_start : y_start));
    painter.drawPoint((swap ? y_end : x_end), (swap ? x_end : y_end));
    int dx = x_end - x_start;
    int dy = y_end - y_start;
    double m = (double)dy / (double)dx;
    double y = y_start + m;
    for (int x = x_start + 1; x < x_end; x++)
    {
        l = imax - (y - (int)y) * imax;
        color.setHsl(h, s, l, a);
        painter.setPen(color);
        painter.drawPoint((swap ? (int)y : x), (swap ? x : (int)y));
        l = (y - (int)y) * imax;
        color.setHsl(h, s, l, a);
        painter.setPen(color);
        painter.drawPoint((swap ? (int)(y + 1) : x), (swap ? x : (int)(y + 1)));
        y += m;
    }

    color.setHsl(h, s, 255, a);
    painter.setPen(color);
}*/

void rotate_point(int xc, int yc, double &x, double &y, int degree)
{
    double radians = (degree * M_PI) / 180;
    double tmp_x = x;
    double tmp_y = y;
    x = xc + (tmp_x - xc) * cos(radians) + (tmp_y - yc) * sin(radians);
    y = yc - (tmp_x - xc) * sin(radians) + (tmp_y - yc) * cos(radians);
}

void decorator(int x_start, int y_start, int x_end, int y_end, QPainter &painter)
{
    painter.drawLine(x_start, y_start, x_end, y_end);
}

void draw_sun(int xc, int yc, int x_end, int y_end, int step, QPainter &painter, void (*draw_line)(int, int, int, int, QPainter &))
{
    double x = x_end;
    double y = y_end;
    int len = x_end - xc;
    double angle = 0.0;
    while (angle <= 360.0)
    {

        draw_line(xc, yc, (int)x, (int)y, painter);
        x = (int)(round(xc + len * cos(angle)));
        y = (int)(round(yc + len * sin(angle)));
        angle += (step * M_PI) / 180;
    }
}
