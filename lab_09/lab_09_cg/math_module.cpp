#include "math_module.h"
void vector_mult(vector_type &a, vector_type &b, vector_type &res)
{
    res.x = a.y * b.z - a.z * b.y;
    res.y = a.z * b.x - a.x * b.z;
    res.z = a.x * b.y - a.y * b.x;
}

int scalar_mult(vector_type &a, vector_type &b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
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
    if (p1p2 * p1p2 + p1p * p1p < p2p * p2p)
        return p1p;
    if (p1p2 * p1p2 + p2p * p2p < p1p * p1p)
        return p2p;
    int dx = p2.x() - p1.x();
    int dy = p2.y() - p1.y();
    double d = fabs((p.y() - p1.y()) * dx - (p.x() - p1.x()) * dy) / p1p2;
    return d;
}

QPoint calculate_P(const QPoint &p1, const QPoint &p2, double t)
{
    QPoint res;
    res.setX(p1.x() + round((p2.x() - p1.x()) * t));
    res.setY(p1.y() + round((p2.y() - p1.y()) * t));
    return res;
}

double vector_len(vector_type &vect)
{
    return sqrt(vect.x * vect.x + vect.y * vect.y + vect.z * vect.z);
}

QPointF normalize(vector_type &vect)
{
    double len = vector_len(vect);
    if (fabs(len) < EPS)
        return QPoint(0, 0);
    QPointF res;
    res.setX((double)vect.x / len);
    res.setY(double(vect.y) / len);
    return res;
}

double vector_component(vector_type &v1, vector_type &v2)
{
    int scalar = scalar_mult(v1, v2);
    double v2_len = vector_len(v2);
    if (fabs(v2_len) < EPS)
        return 0;
    return (double)scalar / v2_len;
}

QPoint normal_point(QPoint &A, QPoint &B, QPoint &C)
{
    vector_type AB = vector_type(B, A);
    vector_type AC = vector_type(C, A);
    AB.z = 0;
    AC.z = 0;
    double tmp = vector_component(AC, AB);
    QPointF nAB = normalize(AB);
    nAB.setX(nAB.x() * tmp);
    nAB.setY(nAB.y() * tmp);
    return QPoint(fabs(nAB.x() + A.x()), fabs(nAB.y() + A.y()));
}
