#include "my_paintwidget.h"
#include <stdio.h>
#include <dos.h>
#include <windows.h>
#define EPS 1e-10

my_paintwidget::my_paintwidget(QWidget *parent) : QWidget(parent)
{
    int image_height = Y_max;
    int image_width = X_max;
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
    my_image.fill(color_bg);
    draw_point();
    draw_bound();
    draw_ellipses();
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
    if (first_pixel)
    {
        QPainter painter(&my_image);
        painter.setPen(color_fill);
        painter.drawPoint(f_pixel);
    }
}

void my_paintwidget::draw_ellipse(ellipse_type &el, QPainter &painter)
{
    painter.drawEllipse(el.center, el.a, el.b);
}

void my_paintwidget::draw_ellipses()
{
    QPainter painter(&my_image);
    QPen pen(color_bound);
    painter.setPen(pen);
    for (int i = 0; i < ellipses.size(); i++)
        draw_ellipse(ellipses[i], painter);
}

void my_paintwidget::find_new_pixel(QStack<QPoint> &st, int x, int y, int xr)
{
    if (y <= Y_min || y >= Y_max)
        return;
    bool flag = false;
    QColor tmp_color;
    QPoint tmp_pix;
    int tmp_x;
    while (x <= xr)
    {
        flag = false;
        tmp_color = my_image.pixelColor(x, y);
        while (x < X_max  && x <= xr && tmp_color != color_bound && tmp_color != color_fill)
        {
            if (!flag)
                flag = true;
            x += 1;
            tmp_color = my_image.pixelColor(x, y);
        }
        if (flag)
        {
            tmp_color = my_image.pixelColor(x, y);
            if (x == xr && tmp_color != color_bound && tmp_color != color_fill)
                tmp_pix.setX(x);
            else
                tmp_pix.setX(x - 1);
            tmp_pix.setY(y);
            st.push(tmp_pix);
            flag = false;
        }
        tmp_x = x;
        tmp_color = my_image.pixelColor(x, y);
        while (x < X_max && x < xr && (tmp_color == color_bound || tmp_color == color_fill))
        {
            x += 1;
            tmp_color = my_image.pixelColor(x, y);
        }
        if (x == tmp_x)
            x += 1;
    }
}

void my_paintwidget::fill_polygon_(QPainter &painter, bool slow)
{
    QPoint tmp_pix;
    int tmp_x;
    int x, y;
    int x_r, x_l;

    painter.setPen(color_fill);
    QStack <QPoint> pixel_stack;
    pixel_stack.push(f_pixel);
    while (!pixel_stack.isEmpty())
    {
        tmp_pix = pixel_stack.pop();
        x = tmp_pix.x();
        y = tmp_pix.y();
        painter.drawPoint(tmp_pix);
        tmp_x = x;
        x += 1;
        while (x < X_max && my_image.pixelColor(x, y) != color_bound)
        {
            painter.drawPoint(x, y);
            x += 1;
        }
        x_r = x - 1;
        x = tmp_x;
        x -= 1;
        while (x > X_min && my_image.pixelColor(x, y) != color_bound)
        {
            painter.drawPoint(x, y);
            x -= 1;
        }
        x_l = x + 1;
        find_new_pixel(pixel_stack, x_l, y + 1, x_r);
        find_new_pixel(pixel_stack, x_l, y - 1, x_r);
        if (slow)
        {
            Sleep(DELAY_TIME);
            repaint();
        }
    }
}

void my_paintwidget::set_color_bound(QColor &color)
{
    color_bound = color;
    //paint_on_image();
}

void my_paintwidget::set_color_fill(QColor &color)
{
    color_fill = color;
    //paint_on_image();
}

void my_paintwidget::set_color_bg(QColor &color)
{
    color_bg = color;
    //paint_on_image();
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

void my_paintwidget::add_new_point(QPoint &point)
{
    first_point = true;
    f_point = point;

    draw_point();
    //paint_on_image();
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
    draw_bound();
    //paint_on_image();
}

void my_paintwidget::add_first_pixel(QPoint &point)
{
    first_pixel = true;
    f_pixel = point;
    draw_point();
    //paint_on_image();
}

void my_paintwidget::add_new_ellipse(ellipse_type ellipse)
{
    ellipses.append(ellipse);
    draw_ellipses();
    //paint_on_image();
}

void my_paintwidget::clear()
{
    edges.clear();
    ellipses.clear();
    f_pixel.setX(-1);
    f_pixel.setY(-1);
    f_point.setX(-1);
    f_point.setY(-1);
    first_point = true;
    first_pixel = false;
    paint_on_image();
}

void my_paintwidget::update_all()
{
    paint_on_image();
}

void my_paintwidget::fill_polygon(bool slow)
{
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
