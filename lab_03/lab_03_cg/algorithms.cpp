#include "algorithms.h"

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
    {
        int tmp = dx;
        dx = dy;
        dy = tmp;
    }
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
    {
        int tmp = dx;
        dx = dy;
        dy = tmp;
    }
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
    int a, h, l, s;
    QColor color(painter.pen().color());
    color.getHsl(&h, &s, &l, &a);
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
    {
        int tmp = dx;
        dx = dy;
        dy = tmp;
    }
    double m = (double)dy / (double)dx;
    double e = imax * 0.5;
    m = m * imax;
    double w = imax - m;
    l = (int) e;
    color.setHsl(h, s, l, a);
    painter.setPen(color);
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
        l = (int) e;
        color.setHsl(h, s, l, a);
        painter.setPen(color);
        painter.drawPoint(x, y);
    }
    color.setHsl(h, s, 255, a);
    painter.setPen(color);
}

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
    int degree = step;
    double x = x_end;
    double y = y_end;
    while (degree <= 360)
    {
        draw_line(xc, yc, (int)x, (int)y, painter);
        rotate_point(xc, yc, x, y, step);
        degree += step;
    }
}
