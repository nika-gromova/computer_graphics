#ifndef MY_PAINTWIDGET_H
#define MY_PAINTWIDGET_H

#include <QWidget>
#include <QColor>
#include <QPainter>
#include <math.h>

#define SEP_X 320
#define DELAY_TIME 50

struct edge_type
{
    QPoint start;
    QPoint end;
};


class my_paintwidget : public QWidget
{
    Q_OBJECT
private:
    QColor color_bound = QColor(Qt::black);
    QColor color_fill = QColor(Qt::green);
    QColor color_bg = QColor(Qt::white);
    QColor color_sep = QColor(Qt::darkGreen);
    int sep_pos_x = SEP_X;
    QPoint min_p;
    QPoint max_p;
    QVector <edge_type> edges;
    QImage my_image;
    QPoint f_point;
    bool first_point;


    void paint_on_image(void);
    void draw_edge(edge_type &e, QPainter &painter);
    void draw_bound(void);
    void draw_point(void);
    void draw_sep(void);
    void calc_min_max(void);
    void fill_polygon_(QPainter &painter, bool slow);
    void draw_line_bre(QPoint &start, QPoint &end, QPainter &painter, QColor &color);
    void color_pixel(int x, int y, QPainter &painter);

public:
    explicit my_paintwidget(QWidget *parent = nullptr);

    void set_color_bound(QColor &color);
    void set_color_fill(QColor &color);
    void set_color_bg(QColor &color);
    void set_color_sep(QColor &color);

    QColor get_color_bound(void);
    QColor get_color_fill(void);
    QColor get_color_bg(void);
    QColor get_color_sep(void);

    void add_new_point(QPoint &point);
    void add_new_edge(edge_type edge);

    void clear(void);

    void fill_polygon(bool slow);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // MY_PAINTWIDGET_H
