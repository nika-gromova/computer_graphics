#include "my_paintwidget.h"
#include "math_module.h"

my_paintwidget::my_paintwidget(QWidget *parent) : QWidget(parent)
{
    my_image = QImage(X_max, Y_max, QImage::Format_RGB32);
    my_image.fill(color_bg);
    first_point_seg = true;
}

// ------------------------------------------------------------drawing----------------------------------------------------------------

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
    pen.setWidth(2);
    draw_lines(result, &my_image, pen);
}

void my_paintwidget::draw_image()
{
    my_image.fill(color_bg);
    draw_segments();
    draw_result();
    draw_cut();
}


// -------------------------------------------------normals for each edge of polygon--------------------------------------------------

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

// ------------------------------------------------calculating results of cutting-----------------------------------------------------

void my_paintwidget::calculate_one(const segment_type seg)
{
    int rc = WORK;
    double t_bottom = 0;
    double t_top = 1;
    double t_cur;
    segment_type cur_edge;
    vector_type D = vector_type(seg);
    vector_type W;
    int D_scalar, W_scalar;
    for (int i = 0; i < cut_params.size() && rc == WORK; i++)
    {
        cur_edge = cut_params[i];
        W = vector_type(seg.p1, cur_edge.p1);
        D_scalar = scalar_mult(normals[i], D);
        W_scalar = scalar_mult(W, normals[i]);
        if (D_scalar == 0)
        {
            if (W_scalar < 0)
                rc = EXIT;
        }
        else
        {
            t_cur = -W_scalar / (double)D_scalar;
            if (D_scalar > 0)
            {
                if (t_cur > 1)
                    rc = EXIT;
                else
                    t_bottom = (t_bottom > t_cur) ? t_bottom : t_cur;
            }
            else
            {
                if (t_cur < 0)
                    rc = EXIT;
                else
                    t_top = (t_top < t_cur) ? t_top : t_cur;
            }
        }
    }
    if (rc != EXIT)
    {
        if (t_bottom <= t_top)
        {
            QPoint p1 = calculate_P(seg.p1, seg.p2, t_bottom);
            QPoint p2 = calculate_P(seg.p1, seg.p2, t_top);
            segment_type res = segment_type(p1, p2);
            result.push_back(res);
        }
    }
}

void my_paintwidget::calculate_results()
{
    calculate_normals();
    for (int i = 0; i < segments.size(); i++)
    {
        calculate_one(segments[i]);
    }
}


// ---------------------------------------------------------------public--------------------------------------------------------------

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

void my_paintwidget::cut_result()
{
    calculate_results();
    draw_result();
}

void my_paintwidget::clear_all()
{
    segments.clear();
    cut_params.clear();
    result.clear();
    normals.clear();
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
    normals.clear();
    draw_image();
}

bool my_paintwidget::cutter_is_empty()
{
    return (cut_params.isEmpty());
}

segment_type my_paintwidget::get_edge(int index)
{
    return cut_params[index];
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

// -------------------------------------------------check if the polygon (cutter) is convex-------------------------------------------

bool my_paintwidget::is_convex()
{
    if (cut_params.isEmpty())
    {
        direction = 0;
        return false;
    }
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

void my_paintwidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(0, 0, my_image);
}
