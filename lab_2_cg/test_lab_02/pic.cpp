#include "pic.h"

pic::pic()
{
    face_top_left.setX(225);
    face_top_left.setY(225);
    face_bootom_right.setX(320);
    face_bootom_right.setY(320);

    eye_top_left_1.setX(245);
    eye_top_left_1.setY(255);
    eye_bottom_rigth_1.setX(265);
    eye_bottom_rigth_1.setY(275);
    eye_top_left_2.setX(280);
    eye_top_left_2.setY(255);
    eye_bottom_rigth_2.setX(300);
    eye_bottom_rigth_2.setY(275);

    hair_top_1.setX(255);
    hair_top_1.setY(230);
    hair_top_2.setX(265);
    hair_top_2.setY(230);
    hair_top_3.setX(275);
    hair_top_3.setY(230);
    hair_top_4.setX(285);
    hair_top_4.setY(230);
    hair_bottom_1.setX(240);
    hair_bottom_1.setY(250);
    hair_bottom_2.setX(250);
    hair_bottom_2.setY(250);
    hair_bottom_3.setX(290);
    hair_bottom_3.setY(250);
    hair_bottom_4.setX(300);
    hair_bottom_4.setY(250);

    nose_up.setX(272);
    nose_up.setY(275);
    nose_left.setX(262);
    nose_left.setY(295);
    nose_right.setX(282);
    nose_right.setY(295);

    mounth_left.setX(257);
    mounth_left.setY(300);
    mounth_right.setX(287);
    mounth_right.setY(300);
    mounth_bottom.setX(272);
    mounth_bottom.setY(315);

    pic_points << face_top_left << face_bootom_right << eye_top_left_1 << eye_bottom_rigth_1 << eye_top_left_2 << eye_bottom_rigth_2;
    pic_points << hair_bottom_1 << hair_bottom_2 << hair_bottom_3 << hair_bottom_4 << hair_top_1 << hair_top_2 << hair_top_3 << hair_top_4;
    pic_points << nose_up << nose_left << nose_right << mounth_left << mounth_right << mounth_bottom;

}

QRectF pic::boundingRect() const
{
    return QRectF(face_top_left, face_bootom_right);
}

void pic::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect_face(face_top_left, face_bootom_right);
    QBrush brush(Qt::yellow);
    painter->setPen(Qt::darkYellow);
    painter->setBrush(brush);
    painter->drawEllipse(rect_face);

    QRectF rect_eyes_1(eye_top_left_1, eye_bottom_rigth_1);
    QRectF rect_eyes_2(eye_top_left_2, eye_bottom_rigth_2);
    painter->setPen(Qt::darkGray);
    painter->setBrush(Qt::green);
    painter->drawEllipse(rect_eyes_1);
    painter->drawEllipse(rect_eyes_2);


}
