#include "my_paintwidget.h"

my_paintwidget::my_paintwidget(QWidget *parent) : QWidget(parent)
{
    my_image = QImage(X_max, Y_max, QImage::Format_RGB32);
    my_image.fill(color_bg);
}

void draw_lines(QVector<segment_type> &arr, QImage *img, QPen &pen)
{
    QPainter painter(img);
    painter.setPen(pen);
    for (int i = 0; i < arr.size(); i++)
        painter.drawLine(arr[i].p1, arr[i].p2);
}

void my_paintwidget::draw_segments()
{
    QPen pen(color_segments);
    draw_lines(segments, &my_image, pen);
}

void my_paintwidget::draw_result()
{
    QPen pen(color_result);
    pen.setWidth(2);
    draw_lines(result, &my_image, pen);
}

void my_paintwidget::draw_cut()
{
    if (cut_params.empty())
        return;
    QPainter painter(&my_image);
    painter.setPen(color_cut);
    QRect r(QPoint(cut_params[0], cut_params[3]), QPoint(cut_params[1], cut_params[2]));
    painter.drawRect(r);
}

void my_paintwidget::draw_image()
{
    my_image.fill(color_bg);
    draw_segments();
    draw_result();
    draw_cut();
}

void calculate_dot_code(const QPoint &p, dot_code &T, const QVector<int> &cut, char &sum)
{
    T[0] = (p.x() < cut[0]) ? 1 : 0;
    T[1] = (p.x() > cut[1]) ? 1 : 0;
    T[2] = (p.y() > cut[2]) ? 1 : 0; // экранная система координат
    T[3] = (p.y() < cut[3]) ? 1 : 0;
    sum = 0;
    for (int i = 0; i < 4; i++)
        sum += T[i];
}

void calculate_prod(const dot_code &T1, const dot_code &T2, char &prod)
{
    prod = 0;
    for (int i = 0; i < 4; i++)
        prod += T1[i] * T2[i];
}

void my_paintwidget::calculate_one(const segment_type seg)
{
    int rc  = WORK;

    QPoint P1 = seg.p1, P2 = seg.p2;
    QPoint Pm;
    QPoint resP1, resP2;
    QPoint temp_p;
    QPoint remember;

    dot_code TP1, TP2;
    char sum1, sum2;
    char prod;

    int count = 1;
    while (rc == WORK && count < 4)
    {
        calculate_dot_code(P1, TP1, cut_params, sum1);
        calculate_dot_code(P2, TP2, cut_params, sum2);
        rc = (sum1 == 0 && sum2 == 0) ? DRAW : WORK;
        if (rc == WORK)
        {
            calculate_prod(TP1, TP2, prod);
            rc = (prod != 0) ? END_P : WORK;
        }
        if (rc == WORK)
        {
            temp_p = P1;
            if (count > 2)
            {
                calculate_prod(TP1, TP2, prod);
                rc = (prod != 0) ? END_P : DRAW;
            }
            if (rc == WORK)
            {
                if (sum2 != 0)
                {
                    while (abs(P1.x() - P2.x()) > eps || abs(P1.y() - P2.y()) > eps)
                    {
                        Pm.setX((P1.x() + P2.x()) / 2);
                        Pm.setY((P1.y() + P2.y()) / 2);
                        remember = P1;
                        P1 = Pm;
                        calculate_dot_code(P1, TP1, cut_params, sum1);
                        calculate_prod(TP1, TP2, prod);
                        if (prod != 0)
                        {
                            P1 = remember;
                            P2 = Pm;
                        }
                    }
                    P1 = P2;
                    P2 = temp_p;
                    count += 1;
                }
                else
                {
                    P1 = P2;
                    P2 = temp_p;
                    count += 1;
                }
            }
        }
    }
    if (rc == DRAW)
    {
        resP1 = P1;
        resP2 = P2;
        segment_type new_seg {resP1, resP2};
        result.append(new_seg);
    }
}

void my_paintwidget::calculate_results()
{
    for (int i = 0; i < segments.size(); i++)
    {
        calculate_one(segments[i]);
    }
}


void my_paintwidget::add_segment(segment_type segment)
{
    segments.append(segment);
    draw_segments();
}

void my_paintwidget::set_cut(int &xl, int &xr, int &yb, int &yt)
{
    cut_params.clear();
    cut_params << xl << xr << yb << yt;
    draw_image();
}

void my_paintwidget::set_eps(double &e)
{
    eps = e;
}

void my_paintwidget::clear_all()
{
    segments.clear();
    cut_params.clear();
    result.clear();
    draw_image();
}

void my_paintwidget::clear_segments()
{
    segments.clear();
    result.clear();
    draw_image();
}


void my_paintwidget::cut_result()
{
    calculate_results();
    draw_result();
}

void my_paintwidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(0, 0, my_image);
}

