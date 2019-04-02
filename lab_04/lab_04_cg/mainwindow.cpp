#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <time.h>
#include "algorithms.h"

#define CPU_F 3.5e9

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
    ui->plot_widget->clearGraphs();
    ui->plot_widget->setVisible(false);
}

void MainWindow::on_draw_circle_button_clicked()
{
    bool ok_1 = true, ok_2 = true, ok_3 = true;
    int xc, yc, r;
    xc = ui->x_circle_edit->text().toInt(&ok_1);
    yc = ui->y_circle_edit->text().toInt(&ok_2);
    r = ui->r_circle_edit->text().toInt(&ok_3);
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
                    midpoint_circle(xc, yc, r, *painter);
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
    int xc, yc, a, b;
    xc = ui->x_ellipse_edit->text().toInt(&ok_1);
    yc = ui->y_ellipse_edit->text().toInt(&ok_2);
    a = ui->a_ellipse_edit->text().toInt(&ok_3);
    b = ui->b_ellipse_edit->text().toInt(&ok_4);
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
                    midpoint_ellipse(xc, yc, a, b, *painter);
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
    int xc, yc, r_start, r_end, step;
    xc = ui->x_center_circle_edit->text().toInt(&ok_1);
    yc = ui->y_center_circle_edit->text().toInt(&ok_2);
    r_start = ui->start_r_edit->text().toInt(&ok_3);
    r_end = ui->end_r_edit->text().toInt(&ok_4);
    step = ui->step_r_edit->text().toInt(&ok_5);
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
                draw_circles(xc, yc, r_start, r_end, step, *painter, midpoint_circle);
            if (ui->lib_radioButton->isChecked())
                draw_circles(xc, yc, r_start, r_end, step, *painter, lib_circle);
        }
        ui->draw_label->setPixmap(*my_scene);
    }
}

void MainWindow::on_draw_ellipses_Button_clicked()
{
    bool ok_1 = true, ok_2 = true, ok_3 = true, ok_4 = true, ok_5 = true, ok_6 = true;
    int xc = ui->x_center_ellipse_edit->text().toInt(&ok_1);
    int yc = ui->y_center_ellipse_edit->text().toInt(&ok_2);
    int a_start = ui->a_start_edit->text().toInt(&ok_3);
    int b_start = ui->b_start_edit->text().toInt(&ok_4);
    int n = ui->n_ellipses_Edit->text().toInt(&ok_5);
    int step = ui->step_ab_edit->text().toInt(&ok_6);
    if (!(ok_1 && ok_2 && ok_3 && ok_4 && ok_5 && ok_6))
        QMessageBox::warning(this, "Неправильный ввод", "Должны быть введены только целые числа!");
    else
    {
        if (step == 0 || step < 0)
            QMessageBox::information(this, "Неправильный ввод", "Введите не нулевой, положительный шаг!");
        else if (a_start < 0 || b_start < 0)
            QMessageBox::information(this, "Неправильный ввод", "Введите положительные значения полуосей и в соответствующих полях ввода!");
        else
        {
            check_color();
            if (ui->canon_radioButton->isChecked())
                draw_ellipses(xc, yc, a_start, b_start, step, n, *painter, canon_ellipse);
            if (ui->param_radioButton->isChecked())
                draw_ellipses(xc, yc, a_start, b_start, step, n, *painter, param_ellipse);
            if (ui->bre_radioButton->isChecked())
                draw_ellipses(xc, yc, a_start, b_start, step, n, *painter, bre_ellipse);
            if (ui->midpoint_radioButton->isChecked())
                draw_ellipses(xc, yc, a_start, b_start, step, n, *painter, midpoint_ellipse);
            if (ui->lib_radioButton->isChecked())
                draw_ellipses(xc, yc, a_start, b_start, step, n, *painter, lib_ellipse);
        }
        ui->draw_label->setPixmap(*my_scene);
    }
}

unsigned long long tick(void)
{
    unsigned long long d;
    __asm__ __volatile__ ("rdtsc" : "=A"(d));
    return d;
}

double time_circle(void (*draw_circle)(int &, int&, int &, QPainter &), int &r, QPainter &pen)
{
    unsigned long long t1;
    //clock_t t1;
    double tmp;
    int xc = 0;
    int yc = 0;
    /*t1 = clock();
    for (int i = 0; i < 10; i++)
        draw_circle(xc, yc, r, pen, true);
    t1 = clock() - t1;
    tmp = ((double)t1) / CLOCKS_PER_SEC;
    printf("%lf\n", tmp);
    return tmp / 10;*/

    t1 = tick();
    for (int i = 0; i < 10; i++)
        draw_circle(xc, yc, r, pen);
    t1 = tick() - t1;
    tmp = ((double)t1) / CPU_F;
    printf("%lf\n", tmp);
    return tmp;
}

void MainWindow::on_compare_time_circle_Button_clicked()
{
    QVector <double> radius;
    QVector <QVector<double>> seconds_circle(5);
    for (int i = 1; i <= 600; i += 10)
    {
        radius.append(i);
        (seconds_circle[0]).append(time_circle(canon_circle, i, *painter));
        (seconds_circle[1]).append(time_circle(param_circle, i, *painter));
        (seconds_circle[2]).append(time_circle(bre_circle, i, *painter));
        (seconds_circle[3]).append(time_circle(midpoint_circle, i, *painter));
        (seconds_circle[4]).append(time_circle(lib_circle, i, *painter));
    }

    ui->plot_widget->legend->setFont(QFont("Helvetica", 9));
    QPen pen;
    QStringList lineNames;
    lineNames << "Канонический" << "Параметрический" << "Брезенхема" << "Средней точки" << "Библиотечный";
    for (int i = 0; i < 5; ++i)
    {
      ui->plot_widget->addGraph();
      // красивый градиентный цвет для линий
      pen.setColor(QColor(qSin(i*1+1.2)*80+80, qSin(i*0.3+0)*80+80, qSin(i*0.3+1.5)*80+80));
      pen.setWidth(5);
      ui->plot_widget->graph()->setPen(pen);
      ui->plot_widget->graph()->setName(lineNames.at(i));
      ui->plot_widget->graph()->setLineStyle(QCPGraph::lsLine);
      ui->plot_widget->graph()->setData(radius, seconds_circle[i]);

    }
    ui->plot_widget->graph()->rescaleAxes(true);
    // легенда в левом верхнем углу
    ui->plot_widget->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignLeft | Qt::AlignTop);
    ui->plot_widget->legend->setVisible(true);
    // границы по x и по y
    ui->plot_widget->yAxis->setRange(0,  seconds_circle[1][seconds_circle[1].size() - 1]);
    ui->plot_widget->xAxis->scaleRange(0, 610);

    ui->plot_widget->xAxis->setLabel("Радиус");
    ui->plot_widget->yAxis->setLabel("Время (секунды)");

    ui->plot_widget->xAxis->setTicks(true);
    ui->plot_widget->yAxis->setTicks(true);
    ui->plot_widget->xAxis->setTickLabels(true);
    ui->plot_widget->yAxis->setTickLabels(true);

    ui->plot_widget->replot();
    ui->plot_widget->setVisible(true);
}

double time_ellipse(void (*draw_ellipse)(int &, int&, int &, int &, QPainter &), int &a, int &b, QPainter &pen)
{
    unsigned long long t1;
    double tmp;
    int xc = 0;
    int yc = 0;

    t1 = tick();
    for (int i = 0; i < 10; i++)
        draw_ellipse(xc, yc, a, b, pen);
    t1 = tick() - t1;
    tmp = ((double)t1) / CPU_F;
    return tmp;
}

void MainWindow::on_compare_time_ellipse_Button_clicked()
{
    // доделать для эллипсов график
    return;
}
