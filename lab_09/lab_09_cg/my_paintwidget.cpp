#include "my_paintwidget.h"
#include "math_module.h"

my_paintwidget::my_paintwidget(QWidget *parent) : QWidget(parent)
{
    my_image = QImage(X_max, Y_max, QImage::Format_RGB32);
    my_image.fill(color_bg);
    first_point_poly = true;
    first_point_cut = true;
}

// ------------------------------------------------------------drawing----------------------------------------------------------------

void my_paintwidget::draw_point()
{
    QPainter painter(&my_image);
    if (!first_point_poly)
    {
        painter.setPen(color_poly);
        painter.drawPoint(f_point_poly);
    }
    if (!first_point_cut)
    {
        painter.setPen(color_cut);
        painter.drawPoint(f_point_cut);
    }
}

void draw_polygon(QVector<QPoint> &arr, QImage *img, QPen &pen)
{
    QPainter painter(img);
    painter.setPen(pen);
    painter.drawPolygon(QPolygon(arr));
}

void my_paintwidget::draw_poly()
{
    if (poly.empty())
        return;
    QPen pen(color_poly);
    draw_polygon(poly, &my_image, pen);
}

void my_paintwidget::draw_cut()
{
    if (cut_params.empty())
        return;
    QPen pen(color_cut);
    draw_polygon(cut_params, &my_image, pen);
}

void my_paintwidget::draw_result()
{
    if (result.empty())
        return;
    QPen pen(color_result);
    pen.setWidth(2);
    draw_polygon(result, &my_image, pen);
}

void my_paintwidget::draw_image()
{
    my_image.fill(color_bg);
    draw_cut();
    draw_poly();
    draw_result();
}

// ------------------------------------------------calculating results of cutting-----------------------------------------------------


void copy_arr(QVector<QPoint> &dst, const QVector<QPoint> &src)
{
    dst.clear();
    for (int i = 0; i < src.size(); i++)
        dst.append(QPoint(src[i].x(), src[i].y()));
}

int my_paintwidget::is_visible(QPoint &p, int &index)
{
    vector_type fs(p, cut_params[index]);
    vector_type ci(cut_params[index + 1], cut_params[index]);
    vector_type res;
    if (direction == -1)
        vector_mult(fs, ci, res);
    else
        vector_mult(ci, fs, res);
    return SIGN(res.z);
}

bool my_paintwidget::is_crossing(QPoint &seg_b, QPoint &seg_e, int &index)
{
    int visibility1 = is_visible(seg_b, index);
    int visibility2 = is_visible(seg_e, index);
    if ((visibility1 > 0 && visibility2 < 0) || (visibility1 < 0 && visibility2 > 0))
        return true;
    return false;
}

QPoint calculate_crossing_point(QPoint &P1, QPoint &P2, QPoint &Q1, QPoint &Q2)
{
    double A1 = P2.x() - P1.x();
    double B1 = -(Q2.x() - Q1.x());
    double C1 = Q1.x() - P1.x();
    double A2 = P2.y() - P1.y();
    double B2 = -(Q2.y() - Q1.y());
    double C2 = Q1.y() - P1.y();
    double det = A1 * B2 - B1 * A2;
    double t = (C1 * B2 - B1 * C2) / det;
    return calculate_P(P1, P2, t);
}

void my_paintwidget::calculate_results()
{
    poly.removeLast();
    copy_arr(result, poly);
    QVector<QPoint> B;
    QPoint Aj;
    QPoint F;
    QPoint S;
    QPoint I;
    bool crossing;
    int rc = WORK;
    for (int i = 0; i < cut_params.size() - 1 && rc == WORK; i++)
    {
        B.clear();
        for (int j = 0; j < result.size(); j++)
        {
            Aj = result[j];
            if (j == 0)
                F = Aj;
            else
            {
                crossing = is_crossing(S, Aj, i);
                if (crossing)
                {
                    I = calculate_crossing_point(S, Aj, cut_params[i], cut_params[i + 1]);
                    B.append(I);
                }
            }
            S = Aj;
            if (is_visible(S, i) >= 0)
                B.append(S);
        }
        if (B.size() == 0)
            rc = EXIT;
        else
        {
            crossing = is_crossing(S, F, i);
            if (crossing)
            {
                I = calculate_crossing_point(S, F, cut_params[i], cut_params[i + 1]);
                B.append(I);
            }
            copy_arr(result, B);
        }
    }
}

// ---------------------------------------------------------------public--------------------------------------------------------------

void my_paintwidget::add_point_poly(QPoint p)
{
    if (first_point_poly)
    {
        first_point_poly = false;
        f_point_poly = p;
        draw_point();
    }
    else
    {
        QPainter painter(&my_image);
        painter.setPen(color_poly);
        painter.drawLine(poly.last(), p);
    }
    poly.append(p);
}

void my_paintwidget::add_point_cut(QPoint p)
{
    if (first_point_cut)
    {
        first_point_cut = false;
        f_point_cut = p;
        draw_point();
    }
    else
    {
        QPainter painter(&my_image);
        painter.setPen(color_cut);
        painter.drawLine(cut_params.last(), p);
    }
    cut_params.append(p);
}

void my_paintwidget::cut_result()
{
    calculate_results();
    draw_result();
}

void my_paintwidget::clear_all()
{
    poly.clear();
    cut_params.clear();
    result.clear();
    draw_image();
    first_point_cut = true;
    first_point_poly = true;
}

void my_paintwidget::clear_poly()
{
    poly.clear();
    result.clear();
    draw_image();
    first_point_poly = true;
}

void my_paintwidget::clear_cutter()
{
    cut_params.clear();
    result.clear();
    draw_image();
    first_point_cut = true;
}

bool my_paintwidget::cutter_is_empty()
{
    return (cut_params.isEmpty());
}

segment_type my_paintwidget::get_edge(int index) // ??
{
    return segment_type(cut_params[index], cut_params[index + 1]);
}

int my_paintwidget::find_closest(QPoint &p)
{
    if (cut_params.size() < 2)
        return 0;
    double min_distance = distance_to_point(cut_params[0], cut_params[1], p);
    int min_index = 0;
    double tmp;
    for (int i = 1; i < cut_params.size() - 1; i++)
    {
        tmp = distance_to_point(cut_params[i], cut_params[i + 1], p);
        if (tmp < min_distance)
        {
            min_distance = tmp;
            min_index = i;
        }
    }
    return min_index;
}

// -------------------------------------------------check if the polygon (cutter) is convex-------------------------------------------

bool my_paintwidget::is_convex()
{
    if (cut_params.size() < 3)
    {
        direction = 0;
        return false;
    }
    vector_type a = vector_type(cut_params[1], cut_params[0]);
    vector_type b;
    vector_type mult_res;
    int sign = 0;
    for (int i = 1; i < cut_params.size() - 1; i++)
    {
        b = vector_type(cut_params[i + 1], cut_params[i]);
        vector_mult(a, b, mult_res);
        if (sign == 0)
            sign = SIGN(mult_res.z);
        int tmp = SIGN(mult_res.z);
        if ((sign != tmp) && mult_res.z)
        {
            direction = 0;
            return false;
        }
        a = b;
    }
    direction = sign;
    return true;
}

void my_paintwidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(0, 0, my_image);
}
