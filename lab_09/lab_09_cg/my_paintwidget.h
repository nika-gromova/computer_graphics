#ifndef MY_PAINTWIDGET_H
#define MY_PAINTWIDGET_H

#include <QWidget>
#include <QVector>
#include <QImage>
#include <QPainter>
#include <QRect>
#include <math.h>

#define X_max 690
#define X_min 0
#define Y_max 590
#define Y_min 0

#define WORK -5
#define EXIT -10

#define SIGN(x) ((x) > 0) ? 1 : (((x) < 0) ? -1 : 0)

struct segment_type
{
    QPoint p1;
    QPoint p2;
    segment_type() {}
    segment_type(QPoint t1, QPoint t2)
    {
        p1 = t1;
        p2 = t2;
    }
};

struct vector_type
{
    int x;
    int y;
    int z;
    vector_type() {}
    vector_type(int tx, int ty, int tz = 0)
    {
        x = tx;
        y = ty;
        z = tz;
    }
    vector_type(QPoint p2, QPoint p1)
    {
        x = p2.x() - p1.x();
        y = p2.y() - p1.y();
        z = 0;
    }
    vector_type(segment_type seg)
    {
        x = seg.p2.x() - seg.p1.x();
        y = seg.p2.y() - seg.p1.y();
        z = 0;
    }
};

class my_paintwidget : public QWidget
{
    Q_OBJECT

private:
    QColor color_bg = QColor(Qt::white);
    QColor color_poly = QColor(Qt::red);
    QColor color_cut = QColor(Qt::blue);
    QColor color_result = QColor(Qt::black);

    QVector<QPoint> cut_params;    
    QVector<QPoint> poly;
    QVector<QPoint> result;

    bool first_point_poly;
    QPoint f_point_poly;

    bool first_point_cut;
    QPoint f_point_cut;

    int direction;

    QImage my_image;

    void draw_point();
    void draw_poly();
    void draw_cut();
    void draw_result();
    void draw_image();

    void calculate_results();

    bool is_crossing(QPoint &seg_b, QPoint &seg_e, int &index);
    int is_visible(QPoint &p, int &index);

public:
    explicit my_paintwidget(QWidget *parent = nullptr);

    segment_type get_edge(int index);
    void add_point_poly(QPoint p);
    void add_point_cut(QPoint p);
    int find_closest(QPoint &p);
    void clear_all();
    void clear_poly();
    void clear_cutter();
    bool cutter_is_empty();
    bool is_convex();
    void cut_result();

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // MY_PAINTWIDGET_H
