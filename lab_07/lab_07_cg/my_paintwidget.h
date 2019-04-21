#ifndef MY_PAINTWIDGET_H
#define MY_PAINTWIDGET_H

#include <QWidget>
#include <QVector>
#include <QImage>
#include <QPainter>
#include <QRect>
#include <math.h>

#define X_max 600
#define X_min 0
#define Y_max 580
#define Y_min 0

#define DRAW  10
#define END_P 20
#define WORK  30

struct segment_type
{
    QPoint p1;
    QPoint p2;
};

typedef char dot_code[4];

class my_paintwidget : public QWidget
{
    Q_OBJECT
private:

    QColor color_bg = QColor(Qt::white);
    QColor color_segments = QColor(Qt::gray);
    QColor color_cut = QColor(Qt::green);
    QColor color_result = QColor(Qt::red);

    QVector<int> cut_params;
    QVector<segment_type> segments;
    QVector<segment_type> result;
    double eps;
    QImage my_image;

    void draw_segments();
    void draw_cut();
    void draw_result();
    void draw_image();
    void calculate_one(const segment_type seg);
    void calculate_results();

public:
    explicit my_paintwidget(QWidget *parent = nullptr);

    void add_segment(segment_type segment);
    void set_cut(int &xl, int &xr, int &yb, int &yt);
    void set_eps(double &e);
    void clear_all();
    void clear_segments();
    void cut_result();

signals:

public slots:
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // MY_PAINTWIDGET_H
