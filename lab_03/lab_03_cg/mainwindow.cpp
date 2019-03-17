#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <stdio.h>

#include "algorithms.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Лабораторная работа №3");

    ui->comboBox_bg->addItem("белый");
    ui->comboBox_bg->addItem("черный");
    ui->comboBox_bg->addItem("красный");
    ui->comboBox_bg->addItem("зеленый");
    ui->comboBox_bg->addItem("желтый");
    ui->comboBox_bg->addItem("синий");

    ui->comboBox_line->addItem("черный");
    ui->comboBox_line->addItem("белый");
    ui->comboBox_line->addItem("красный");
    ui->comboBox_line->addItem("зеленый");
    ui->comboBox_line->addItem("желтый");
    ui->comboBox_line->addItem("синий");

    ui->dda_radioButton->setChecked(true);


    my_scene = new QPixmap(570, 570);
    my_scene->fill(QColor("transparent"));
    painter = new QPainter(my_scene);
    painter->setPen(Qt::black);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::check_color()
{
    switch (ui->comboBox_bg->currentIndex()) {
    case 1:
        ui->draw_label->setStyleSheet("QLabel { background-color : black; }");
        break;
    case 0:
        ui->draw_label->setStyleSheet("QLabel { background-color : white; }");
        break;
    case 2:
        ui->draw_label->setStyleSheet("QLabel { background-color : red; }");
        break;
    case 3:
        ui->draw_label->setStyleSheet("QLabel { background-color : green; }");
        break;
    case 4:
        ui->draw_label->setStyleSheet("QLabel { background-color : yellow; }");
        break;
    case 5:
        ui->draw_label->setStyleSheet("QLabel { background-color : blue; }");
        break;
    default:
        break;
    }
    switch (ui->comboBox_line->currentIndex()) {
    case 0:
        painter->setPen(QColor(Qt::black));
        break;
    case 1:
        painter->setPen(QColor(Qt::white));
        break;
    case 2:
        painter->setPen(QColor(Qt::red));
        break;
    case 3:
        painter->setPen(QColor(Qt::green));
        break;
    case 4:
        painter->setPen(QColor(Qt::yellow));
        break;
    case 5:
        painter->setPen(QColor(Qt::blue));
        break;
    default:
        break;
    }
}

void MainWindow::on_draw_line_button_clicked()
{
    bool ok_1 = true, ok_2 = true, ok_3 = true, ok_4 = true;
    QString x_s_str = ui->x_start_edit->text();
    QString y_s_str = ui->y_start_edit->text();
    QString x_e_str = ui->x_end_edit->text();
    QString y_e_str = ui->y_end_edit->text();
    int x_start = x_s_str.toInt(&ok_1, 10);
    int y_start = y_s_str.toInt(&ok_2, 10);
    int x_end = x_e_str.toInt(&ok_3, 10);
    int y_end = y_e_str.toInt(&ok_4, 10);

    if (!ok_1 || !ok_2 || !ok_3 || !ok_4)
        QMessageBox::warning(this, "Неправильный ввод", "Должны быть введены только целые числа!");
    else
    {

        if (x_start == x_end && y_start == y_end)
        {
            QMessageBox::information(this, "Точка", "Координаты концов отрезка совпадают, будет нарисована точка!");
            painter->drawPoint(x_start, y_start);
        }
        else
        {
            check_color();
            if (ui->dda_radioButton->isChecked())
            {
                printf("dda\n");
                dda(x_start, y_start, x_end, y_end, *painter);
            }
            if (ui->bre_double_radioButton->isChecked())
            {
                printf("bre_float\n");
                bre_double(x_start, y_start, x_end, y_end, *painter);
            }
            if (ui->bre_integer_radioButton->isChecked())
            {
                printf("bre_int\n");
                bre_int(x_start, y_start, x_end, y_end, *painter);
            }
            if (ui->bre_stairs_radioButton->isChecked())
            {
                printf("bre_stairs\n");
                bre_stairs(x_start, y_start, x_end, y_end, *painter);
            }
            if (ui->lib_radioButton->isChecked())
            {
                printf("lib\n");
                painter->drawLine(x_start, y_start, x_end, y_end);
            }
        }
        ui->draw_label->setPixmap(*my_scene);
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->draw_label->setStyleSheet("QLabel { background-color : white; }");
    delete painter;
    delete my_scene;
    my_scene = new QPixmap(570, 570);
    my_scene->fill(QColor("transparent"));
    painter = new QPainter(my_scene);
    painter->setPen(Qt::black);
    ui->draw_label->setPixmap(*my_scene);
}

void MainWindow::on_draw_sun_Button_clicked()
{
    bool ok_1 = true, ok_2 = true, ok_3 = true, ok_4 = true;
    QString x_c_str = ui->x_center_edit->text();
    QString y_c_str = ui->y_center_edit->text();
    QString radius_str = ui->line_length_edit->text();
    QString step_str = ui->step_edit->text();
    int x_center = x_c_str.toInt(&ok_1, 10);
    int y_center = y_c_str.toInt(&ok_2, 10);
    int radius = radius_str.toInt(&ok_3, 10);
    int step = step_str.toInt(&ok_4, 10);
    if (!ok_1 || !ok_2 || !ok_3 || !ok_4)
        QMessageBox::warning(this, "Неправильный ввод", "Должны быть введены только целые числа!");
    else
    {
        check_color();
        int x_end = x_center + radius;
        int y_end = y_center;
        if (ui->dda_radioButton->isChecked())
            draw_sun(x_center, y_center, x_end, y_end, step, *painter, dda);
        if (ui->bre_double_radioButton->isChecked())
            draw_sun(x_center, y_center, x_end, y_end, step, *painter, bre_double);
        if (ui->bre_integer_radioButton->isChecked())
            draw_sun(x_center, y_center, x_end, y_end, step, *painter, bre_int);
        if (ui->bre_stairs_radioButton->isChecked())
            draw_sun(x_center, y_center, x_end, y_end, step, *painter, bre_stairs);
        if (ui->lib_radioButton->isChecked())
            draw_sun(x_center, y_center, x_end, y_end, step, *painter, decorator);
        ui->draw_label->setPixmap(*my_scene);
    }
}
