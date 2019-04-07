#include "my_paintwidget.h"
#include <stdio.h>
#include <dos.h>
#include <windows.h>
#define EPS 1e-10

my_paintwidget::my_paintwidget(QWidget *parent) : QWidget(parent)
{
    int image_height = 600;
    int image_width = 640;
    my_image = QImage(image_width, image_height, QImage::Format_RGB32);
    my_image.fill(color_bg);
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

void my_paintwidget::draw_line_bre(QPoint &start, QPoint &end, QPainter &painter, QColor &color)
{
    QPen pen(color);
    pen.setWidth(2);;
    painter.setPen(pen);
    int x_start = start.x(), y_start = start.y();
    int x_end = end.x(), y_end = end.y();
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

void my_paintwidget::paint_on_image()
{
    calc_min_max();
    my_image.fill(color_bg);
    draw_point();
    draw_bound();
    this->repaint();
}

void my_paintwidget::draw_edge(edge_type &e, QPainter &painter)
{
    draw_line_bre(e.start, e.end, painter, color_bound);
}

void my_paintwidget::draw_bound()
{
    QPainter painter(&my_image);
    for (int i = 0; i < edges.size(); i++)
        draw_edge(edges[i], painter);
}

void my_paintwidget::draw_point()
{
    if (first_point)
    {
        QPainter painter(&my_image);
        painter.setPen(color_bound);
        painter.drawPoint(f_point);
    }
}

void my_paintwidget::draw_sep()
{
    QPainter painter(&my_image);
    QPoint p1(sep_pos_x, min_p.y() - 10);
    QPoint p2(sep_pos_x, max_p.y() + 10);
    draw_line_bre(p1, p2, painter, color_sep);
}

void my_paintwidget::calc_min_max()
{
    if (edges.size() == 0)
        return;
    int x_max = edges[0].start.x(), x_min = edges[0].start.x();
    int y_max = edges[0].start.y(), y_min = edges[0].start.y();
    for (int i = 0; i < edges.size(); i++)
    {
        if (x_max < edges[i].start.x())
            x_max = edges[i].start.x();
        if (x_max < edges[i].end.x())
            x_max = edges[i].end.x();
        if (x_min > edges[i].start.x())
            x_min = edges[i].start.x();
        if (x_min > edges[i].end.x())
            x_min = edges[i].end.x();
        if (y_max < edges[i].end.y())
            y_max = edges[i].end.y();
        if (y_min > edges[i].start.y())
            y_min = edges[i].start.y();
    }
    sep_pos_x = (x_max + x_min) * 0.5;
    max_p.setX(x_max);
    max_p.setY(y_max);
    min_p.setX(x_min);
    min_p.setY(y_min);
}

void my_paintwidget::color_pixel(int x, int y, QPainter &painter)
{
    QColor color = my_image.pixelColor(x, y);
    if (color == color_fill)
        painter.setPen(color_bg);
    else
        painter.setPen(color_fill);
    painter.drawPoint(x, y);
}

void my_paintwidget::fill_polygon_(QPainter &painter, bool slow)
{
    int tmp_start;
    int sep;
    for (int i = 0; i < edges.size(); i++)
    {
        int x_start = edges[i].start.x(), y_start = edges[i].start.y();
        int x_end = edges[i].end.x(), y_end = edges[i].end.y();
        bool xl = x_start < sep_pos_x;
        bool xr = x_end < sep_pos_x;

        if (xl && xr)
        {
            for (int y = y_start; y < y_end; y++)
            {
                //tmp_start = find_x(i, y);
                for (int x = tmp_start; x < sep_pos_x; x++)
                {
                    color_pixel(x, y, painter);
                }
                if (slow)
                {
                    Sleep(DELAY_TIME);
                    repaint();
                }
            }
        }
        else if (!xl && !xr)
        {
            for (int y = y_start; y < y_end; y++)
            {
                //tmp_start = find_x(i, y);
                for (int x = tmp_start; x > sep_pos_x; x--)
                {
                    color_pixel(x, y, painter);
                }
                if (slow)
                {
                    Sleep(DELAY_TIME);
                    repaint();
                }
            }
        }
        else if (xl && !xr)
        {
            sep = find_y(i, sep_pos_x);
            for (int y = y_start; y < sep; y++)
            {
                //tmp_start = find_x(i, y);
                for (int x = tmp_start; x < sep_pos_x; x++)
                    color_pixel(x, y, painter);
                if (slow)
                {
                    Sleep(DELAY_TIME);
                    repaint();
                }
            }
            for (int y = sep; y < y_end; y++)
            {
                //tmp_start = find_x(i, y);
                for (int x = tmp_start; x > sep_pos_x; x--)
                    color_pixel(x, y, painter);
                if (slow)
                {
                    Sleep(DELAY_TIME);
                    repaint();
                }
            }
        }
        else
        {
            sep = find_y(i, sep_pos_x);
            for (int y = y_start; y < sep; y++)
            {
                //tmp_start = find_x(i, y);
                for (int x = tmp_start; x > sep_pos_x; x--)
                    color_pixel(x, y, painter);
                if (slow)
                {
                    Sleep(DELAY_TIME);
                    repaint();
                }
            }
            for (int y = sep; y < y_end; y++)
            {
                //tmp_start = find_x(i, y);
                for (int x = tmp_start; x < sep_pos_x; x++)
                    color_pixel(x, y, painter);
                if (slow)
                {
                    Sleep(DELAY_TIME);
                    repaint();
                }
            }
        }
    }
}

void my_paintwidget::set_color_bound(QColor &color)
{
    color_bound = color;
    paint_on_image();
}

void my_paintwidget::set_color_fill(QColor &color)
{
    color_fill = color;
    paint_on_image();
}

void my_paintwidget::set_color_bg(QColor &color)
{
    color_bg = color;
    paint_on_image();
}

void my_paintwidget::set_color_sep(QColor &color)
{
    color_sep = color;
    paint_on_image();
}

QColor my_paintwidget::get_color_bound()
{
    return color_bound;
}

QColor my_paintwidget::get_color_fill()
{
    return color_fill;
}

QColor my_paintwidget::get_color_bg()
{
    return color_bg;
}

QColor my_paintwidget::get_color_sep()
{
    return color_sep;
}

void my_paintwidget::add_new_point(QPoint &point)
{
    first_point = true;
    f_point = point;
    paint_on_image();
}

void my_paintwidget::add_new_edge(edge_type edge)
{
    first_point = false;
    // start.y < end.y
    if (edge.start.y() > edge.end.y())
    {
        QPoint tmp = edge.start;
        edge.start = edge.end;
        edge.end = tmp;
    }
    edges.append(edge);
    paint_on_image();
}

void my_paintwidget::clear()
{
    edges.clear();
    max_p.setX(-1);
    max_p.setY(-1);
    min_p.setX(-1);
    min_p.setY(-1);
    f_point.setX(-1);
    f_point.setY(-1);
    first_point = true;
    paint_on_image();
}

void my_paintwidget::fill_polygon(bool slow)
{
    /*for (int i = 0; i < edges.size(); i++)
        printf("(%d; %d) - (%d; %d)\n", edges[i].start.x(), edges[i].start.y(), edges[i].end.x(), edges[i].end.y());*/
    paint_on_image();
    draw_sep();
    QPainter painter(&my_image);
    fill_polygon_(painter, slow);
    painter.end();
    this->repaint();
}

void my_paintwidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(0, 0, my_image);
}


