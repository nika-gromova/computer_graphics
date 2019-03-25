#include "algorithms.h"

void canon_circle(int &xc, int &yc, int &r, QPainter &painter)
{
    double x, y;
    int x_rounded, y_rounded;
    double r2 = r * r;
    for (int x = 0; x <= r; x++)
    {
        y = sqrt(r2 - x * x);
        y_rounded = (int)(round(y));
        painter.drawPoint(xc + x, yc + y_rounded);
        painter.drawPoint(xc - x, yc + y_rounded);
        painter.drawPoint(xc + x, yc - y_rounded);
        painter.drawPoint(xc - x, yc - y_rounded);
    }
    for (int y = 0; y <= r; y++)
    {
        x = sqrt(r2 - y * y);
        x_rounded = (int)(round(x));
        painter.drawPoint(xc + x_rounded, yc + y);
        painter.drawPoint(xc - x_rounded, yc + y);
        painter.drawPoint(xc + x_rounded, yc - y);
        painter.drawPoint(xc - x_rounded, yc - y);
    }
}

void param_circle(int &xc, int &yc, int &r, QPainter &painter)
{
    int len = (int)(round(M_PI * r / 2));
    int x, y;
    for (int i = 0; i <= len; i++)
    {
        x = (int)(round(r * cos((double)i / r)));
        y = (int)(round(r * sin((double)i / r)));
        painter.drawPoint(xc + x, yc + y);
        painter.drawPoint(xc - x, yc + y);
        painter.drawPoint(xc + x, yc - y);
        painter.drawPoint(xc - x, yc - y);
    }
}


void bre_circle(int &xc, int &yc, int &r, QPainter &painter)
{
    int x = 0, y = r;
    int d = 2 * (1 - r);
    int d1 = 0, d2 = 0;
    int y_end = 0;
    while (y >= y_end)
    {
        painter.drawPoint(xc + x, yc + y);
        painter.drawPoint(xc - x, yc + y);
        painter.drawPoint(xc + x, yc - y);
        painter.drawPoint(xc - x, yc - y);
        if (d < 0)
        {
           d1 = 2 * (d + y) - 1;
           x += 1;
           if (d1 < 0)
               d = d + 2 * x + 1;
           else
           {
               y -= 1;
               d = d + 2 * (x - y + 1);
           }
        }
        else if (d == 0)
        {
            x += 1;
            y -= 1;
            d = d + 2 * (x - y + 1);
        }
        else
        {
            d2 = 2 * (d - x) - 1;
            y -= 1;
            if (d2 < 0)
            {
                x += 1;
                d = d + 2 * (x - y + 1);
            }
            else
                d = d - 2 * y + 1;
        }
    }
}


void lib_circle(int &xc, int &yc, int &r, QPainter &painter)
{
    QPoint center = QPoint(xc, yc);
    painter.drawEllipse(center, r, r);
}

void canon_ellipse(int &xc, int &yc, int &a, int &b, QPainter &painter)
{
    double x, y;
    int x_rounded, y_rounded;
    double a2 = a * a;
    double b2 = b * b;
    if (a != 0)
    {
        for (int x = 0; x <= a; x++)
        {
            y = b * sqrt(1.0 - x * x / a2);
            y_rounded = (int)(round(y));
            painter.drawPoint(xc + x, yc + y_rounded);
            painter.drawPoint(xc - x, yc + y_rounded);
            painter.drawPoint(xc + x, yc - y_rounded);
            painter.drawPoint(xc - x, yc - y_rounded);
        }
    }
    if (b != 0)
    {
        for (int y = 0; y <= b; y++)
        {
            x = a * sqrt(1.0 - y * y / b2);
            x_rounded = (int)(round(x));
            painter.drawPoint(xc + x_rounded, yc + y);
            painter.drawPoint(xc - x_rounded, yc + y);
            painter.drawPoint(xc + x_rounded, yc - y);
            painter.drawPoint(xc - x_rounded, yc - y);
        }
    }
}

void param_ellipse(int &xc, int &yc, int &a, int &b, QPainter &painter)
{
    /*
    int max_r = (a > b) ? a : b;
    double delta = 2 * M_PI / max_r;
    double coef = M_PI / 180;
    int x, y;
    for (int i = 0; i <= 90; i++)
    {
        x = (int)(round(a * cos((double)i * coef)));
        y = (int)(round(b * sin((double)i * coef)));
        painter.drawPoint(xc + x, yc + y);
        painter.drawPoint(xc - x, yc + y);
        painter.drawPoint(xc + x, yc - y);
        painter.drawPoint(xc - x, yc - y);
    }
    */
    int max_r = (a > b) ? a : b;
    int len = (int)(round(M_PI * max_r / 2));
    int x, y;
    for (int i = 0; i <= len; i++)
    {
        x = (int)(round(a * cos((double)i / max_r)));
        y = (int)(round(b * sin((double)i / max_r)));
        painter.drawPoint(xc + x, yc + y);
        painter.drawPoint(xc - x, yc + y);
        painter.drawPoint(xc + x, yc - y);
        painter.drawPoint(xc - x, yc - y);
    }
}

void bre_ellipse(int &xc, int &yc, int &a, int &b, QPainter &painter)
{
    int x = 0, y = (b != 0) ? b : a;
    int a2 = a * a;
    int b2 = b * b;
    int da2 = 2 * a2;
    int db2 = 2 * b2;
    int d = b2 - da2 * b + a2;
    int d1 = 0, d2 = 0;
    int y_end = 0;
    while (y >= y_end)
    {
        painter.drawPoint(xc + x, yc + y);
        painter.drawPoint(xc - x, yc + y);
        painter.drawPoint(xc + x, yc - y);
        painter.drawPoint(xc - x, yc - y);
        if (d < 0)
        {
           d1 = 2 * d + da2 * y - a2;
           x += 1;
           if (d1 < 0)
               d = d + db2 * x + b2;
           else
           {
               y -= 1;
               d = d + db2 * x - da2 * y + a2 + b2;
           }
        }
        else if (d == 0)
        {
            x += 1;
            y -= 1;
            d = d + db2 * x - da2 * y + a2 + b2;
        }
        else
        {
            d2 = 2 * d - db2 * x - b2;
            y -= 1;
            if (d2 < 0)
            {
                x += 1;
                d = d + db2 * x - da2 * y + a2 + b2;
            }
            else
                d = d - da2 * y + a2;
        }
    }
}

void lib_ellipse(int &xc, int &yc, int &a, int &b, QPainter &painter)
{
    QPoint center = QPoint(xc, yc);
    painter.drawEllipse(center, a, b);
}



void draw_circles(int &xc, int &yc, int &r_start, int &r_end, int &step, QPainter &painter, void (*draw_circle)(int &, int&, int &, QPainter &))
{
    for (int r = r_start; r <= r_end; r += step)
    {
        draw_circle(xc, yc, r, painter);
    }
}

void draw_ellipses(int &xc, int &yc, int &a_start, int &a_end, int &step, int &b_start, QPainter &painter, void (*draw_ellipse)(int &, int&, int &, int &, QPainter &))
{
    for (int a = a_start, b = b_start; a <= a_end; a += step, b += step)
    {
        draw_ellipse(xc, yc, a, b, painter);
    }
}
