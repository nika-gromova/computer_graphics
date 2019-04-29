#include "my_paintwidget.h"

my_paintwidget::my_paintwidget(QWidget *parent) : QWidget(parent)
{
    my_image = QImage(X_max, Y_max, QImage::Format_RGB32);
    my_image.fill(color_bg);
    first_point_seg = true;
}

segment_type my_paintwidget::get_edge(int index)
{
    return cut_params[index];
}

double distance(QPoint &p1, QPoint &p2)
{
    return sqrt((p2.x() - p1.x()) * (p2.x() - p1.x()) + (p2.y() - p1.y()) * (p2.y() - p1.y()));
}

double distance_to_point(QPoint &p1, QPoint &p2, QPoint &p)
{
    double p1p2 = distance(p1, p2);
    double p1p = distance(p1, p);
    double p2p = distance(p2, p);
    if (p1p2 + p1p < p2p)
        return p1p;
    if (p1p2 + p2p < p1p)
        return p2p;
    int dx = p2.x() - p1.x();
    int dy = p2.y() - p1.y();
    double d = fabs((p.y() - p1.y()) * dx - (p.x() - p1.x()) * dy) / p1p2;
    return d;
}

int my_paintwidget::find_closest(QPoint &p)
{
    double min_distance = distance_to_point(cut_params[0].p1, cut_params[0].p2, p);
    int min_index = 0;
    double tmp;
    for (int i = 0; i < cut_params.size(); i++)
    {
        tmp = distance_to_point(cut_params[i].p1, cut_params[i].p2, p);
        if (tmp < min_distance)
        {
            min_distance = tmp;
            min_index = i;
        }
    }
    return min_index;
}

void my_paintwidget::draw_point()
{
    QPainter painter(&my_image);
    if (first_point_seg)
    {
        painter.setPen(color_segments);
        painter.drawPoint(f_point_seg);
    }
    if (first_point_cut)
    {
        painter.setPen(color_cut);
        painter.drawPoint(f_point_cut);
    }
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

void my_paintwidget::draw_cut()
{
    if (cut_params.empty())
        return;
    QPen pen(color_cut);
    draw_lines(cut_params, &my_image, pen);
}

void my_paintwidget::draw_result()
{
    QPen pen(color_result);
    draw_lines(result, &my_image, pen);
}

void my_paintwidget::draw_image()
{
    my_image.fill(color_bg);
    draw_segments();
    draw_result();
    draw_cut();
}

void vector_mult(vector_type &a, vector_type &b, vector_type &res)
{
    res.x = a.y * b.z - a.z * b.y;
    res.y = a.z * b.x - a.x * b.z;
    res.z = a.x * b.y - a.y * b.x;
}

bool my_paintwidget::is_convex()
{
    vector_type a = vector_type(cut_params[0]);
    vector_type b;
    vector_type mult_res;
    int sign = 0;
    for (int i = 1; i < cut_params.size(); i++)
    {
        b = vector_type(cut_params[i]);
        vector_mult(a, b, mult_res);
        if (sign == 0)
            sign = SIGN(mult_res.z);
        if (mult_res.z && sign != SIGN(mult_res.z))
        {
            direction = 0;
            return false;
        }
        a = b;
    }
    direction = sign;
    return true;
}

void my_paintwidget::cut_result()
{
    calculate_results();
    draw_result();
}

void my_paintwidget::calculate_normals()
{
    vector_type tmp;
    for (int i = 0; i < cut_params.size(); i++)
    {
        tmp = vector_type(cut_params[i]);
        if (direction == 1)
            normals.push_back(vector_type(-tmp.y, tmp.x));
        else
            normals.push_back(vector_type(tmp.y, -tmp.x));
    }
}

void my_paintwidget::calculate_one(const segment_type seg)
{

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
    first_point_seg = false;
    segments.append(segment);
    draw_segments();
}

void my_paintwidget::add_point_seg(QPoint p)
{
    f_point_seg = p;
    first_point_seg = true;
    draw_point();
}

void my_paintwidget::add_cut_seg(segment_type p)
{
    first_point_cut = false;
    cut_params.push_back(p);
    draw_cut();
}

void my_paintwidget::add_point_cut(QPoint p)
{
    f_point_cut = p;
    first_point_cut = true;
    draw_point();
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

void my_paintwidget::clear_cutter()
{
    cut_params.clear();
    draw_image();
}

bool my_paintwidget::cutter_is_empty()
{
    return (cut_params.isEmpty());
}

void my_paintwidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(0, 0, my_image);
}
