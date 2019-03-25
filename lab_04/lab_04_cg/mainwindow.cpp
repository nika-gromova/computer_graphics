#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

#include "algorithms.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Лабораторная работа №4");

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
    ui->canon_radioButton->setChecked(true);

    my_scene = new QPixmap(570, 570);
    my_scene->fill(QColor("transparent"));
    painter = new QPainter(my_scene);
    painter->setPen(Qt::black);
    ui->plot_widget->setVisible(false);
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
    ui->plot_widget->setVisible(false);
}

void MainWindow::on_draw_circle_button_clicked()
{
    bool ok_1 = true, ok_2 = true, ok_3 = true;
    QString xc_str = ui->x_circle_edit->text();
    QString yc_str = ui->y_circle_edit->text();
    QString r_str = ui->r_circle_edit->text();
    int xc, yc, r;
    xc = xc_str.toInt(&ok_1);
    yc = yc_str.toInt(&ok_2);
    r = r_str.toInt(&ok_3);
    if (!ok_1 || !ok_2 || !ok_3)
         QMessageBox::warning(this, "Неправильный ввод", "Должны быть введены только целые числа!");
    else
    {
        if (r < 0)
            QMessageBox::warning(this, "Неправильный ввод", "Должно быть введено только положительное значения радиуса!");
        else
        {
            if (r == 0)
            {
                QMessageBox::information(this, "Точка", "Радиус равен нулю, будет нарисована точка!");
                painter->drawPoint(xc, yc);
            }
            else
            {
                check_color();
                if (ui->canon_radioButton->isChecked())
                    canon_circle(xc, yc, r, *painter);
                if (ui->param_radioButton->isChecked())
                {
                    param_circle(xc, yc, r, *painter);
                }
                if (ui->bre_radioButton->isChecked())
                {
                    bre_circle(xc, yc, r, *painter);
                }
                if (ui->midpoint_radioButton->isChecked())
                {
                    ok_2 = true;
                }
                if (ui->lib_radioButton->isChecked())
                    lib_circle(xc, yc, r, *painter);

            }
            ui->draw_label->setPixmap(*my_scene);
        }
    }
}

void MainWindow::on_draw_ellipse_button_clicked()
{
    bool ok_1 = true, ok_2 = true, ok_3 = true, ok_4 = true;
    QString xc_str = ui->x_ellipse_edit->text();
    QString yc_str = ui->y_ellipse_edit->text();
    QString a_str = ui->a_ellipse_edit->text();
    QString b_str = ui->b_ellipse_edit->text();
    int xc, yc, a, b;
    xc = xc_str.toInt(&ok_1);
    yc = yc_str.toInt(&ok_2);
    a = a_str.toInt(&ok_3);
    b = b_str.toInt(&ok_4);
    if (!ok_1 || !ok_2 || !ok_3 || !ok_4)
         QMessageBox::warning(this, "Неправильный ввод", "Должны быть введены только целые числа!");
    else
    {
        if (a < 0 || b < 0)
            QMessageBox::warning(this, "Неправильный ввод", "Должны быть введены только положительные значения полуосей!");
        else
        {
            if (a == 0 && b == 0)
            {
                QMessageBox::information(this, "Точка", "Полуоси равны нулю, будет нарисована точка!");
                painter->drawPoint(xc, yc);
            }
            else
            {
                check_color();
                if (ui->canon_radioButton->isChecked())
                    canon_ellipse(xc, yc, a, b, *painter);
                if (ui->param_radioButton->isChecked())
                {
                    param_ellipse(xc, yc, a, b, *painter);
                }
                if (ui->bre_radioButton->isChecked())
                {
                    bre_ellipse(xc, yc, a, b, *painter);
                }
                if (ui->midpoint_radioButton->isChecked())
                {
                    ok_2 = true;
                }
                if (ui->lib_radioButton->isChecked())
                    lib_ellipse(xc, yc, a, b, *painter);

            }
            ui->draw_label->setPixmap(*my_scene);
        }
    }
}

void MainWindow::on_draw_circles_Button_clicked()
{
    bool ok_1 = true, ok_2 = true, ok_3 = true, ok_4 = true, ok_5 = true;
    QString xc_str = ui->x_center_circle_edit->text();
    QString yc_str = ui->y_center_circle_edit->text();
    QString r_start_str = ui->start_r_edit->text();
    QString r_end_str = ui->end_r_edit->text();
    QString step_str = ui->step_r_edit->text();
    int xc, yc, r_start, r_end, step;
    xc = xc_str.toInt(&ok_1);
    yc = yc_str.toInt(&ok_2);
    r_start = r_start_str.toInt(&ok_3);
    r_end = r_end_str.toInt(&ok_4);
    step = step_str.toInt(&ok_5);
    if (!ok_1 || !ok_2 || !ok_3 || !ok_4 || !ok_5)
         QMessageBox::warning(this, "Неправильный ввод", "Должны быть введены только целые числа!");
    else
    {
        if (step == 0 || step < 0)
            QMessageBox::information(this, "Неправильный ввод", "Введите не нулевой, положительный шаг!");
        else if (r_start < 0 || r_end < 0 || r_end < r_start)
            QMessageBox::information(this, "Неправильный ввод", "Введите положительные значения радиусов и в соответствующих полях ввода!");
        else if (r_start == 0 && r_end == 0)
        {
            QMessageBox::information(this, "Точка", "Начальный и конечный радиусы равны нулю, будет нарисована точка!");
            painter->drawPoint(xc, yc);
        }
        else
        {
            check_color();
            if (ui->canon_radioButton->isChecked())
                draw_circles(xc, yc, r_start, r_end, step, *painter, canon_circle);
            if (ui->param_radioButton->isChecked())
                draw_circles(xc, yc, r_start, r_end, step, *painter, param_circle);
            if (ui->bre_radioButton->isChecked())
                draw_circles(xc, yc, r_start, r_end, step, *painter, bre_circle);
            if (ui->midpoint_radioButton->isChecked())
            {
                ok_2 = true;
            }
            if (ui->lib_radioButton->isChecked())
                draw_circles(xc, yc, r_start, r_end, step, *painter, lib_circle);
        }
        ui->draw_label->setPixmap(*my_scene);
    }
}

void MainWindow::on_draw_ellipses_Button_clicked()
{
    bool ok_1 = true, ok_2 = true, ok_3 = true, ok_4 = true, ok_5 = true, ok_6 = true, ok_7 = true;
    int xc = ui->x_center_ellipse_edit->text().toInt(&ok_1);
    int yc = ui->y_center_ellipse_edit->text().toInt(&ok_2);
    int a_start = ui->a_start_edit->text().toInt(&ok_3);
    int b_start = ui->b_start_edit->text().toInt(&ok_4);
    int a_end = ui->a_end_edit->text().toInt(&ok_5);
    int b_end = ui->b_end_edit->text().toInt(&ok_6);
    int step = ui->step_ab_edit->text().toInt(&ok_7);
    if (!(ok_1 && ok_2 && ok_3 && ok_4 && ok_5 && ok_6 && ok_7))
        QMessageBox::warning(this, "Неправильный ввод", "Должны быть введены только целые числа!");
    else
    {
        if (step == 0 || step < 0)
            QMessageBox::information(this, "Неправильный ввод", "Введите не нулевой, положительный шаг!");
        else if (a_start < 0 || b_start < 0 || a_end < 0 || b_end < 0 || a_start > a_end || b_start > b_end)
            QMessageBox::information(this, "Неправильный ввод", "Введите положительные значения полуосей и в соответствующих полях ввода!");
        else if (a_start == b_start && a_end == a_start && a_end == b_end && a_start == 0)
        {
            QMessageBox::information(this, "Точка", "Начальные и конечные полуоси равны нулю, будет нарисована точка!");
            painter->drawPoint(xc, yc);
        }
        else
        {
            check_color();
            check_color();
            if (ui->canon_radioButton->isChecked())
                draw_ellipses(xc, yc, a_start, a_end, step, b_start, *painter, canon_ellipse);
            if (ui->param_radioButton->isChecked())
                draw_ellipses(xc, yc, a_start, a_end, step, b_start, *painter, param_ellipse);
            if (ui->bre_radioButton->isChecked())
                draw_ellipses(xc, yc, a_start, a_end, step, b_start, *painter, bre_ellipse);
            if (ui->midpoint_radioButton->isChecked())
            {
                ok_2 = true;
            }
            if (ui->lib_radioButton->isChecked())
                draw_ellipses(xc, yc, a_start, a_end, step, b_start, *painter, lib_ellipse);
        }
        ui->draw_label->setPixmap(*my_scene);
    }
}
