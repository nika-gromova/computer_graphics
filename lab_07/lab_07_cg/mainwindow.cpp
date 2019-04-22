#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myscene = new my_paintwidget(ui->draw_widget);
    myscene->setMinimumSize(X_max, Y_max);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_segment_pushButton_clicked()
{
    bool ok_1 = true, ok_2 = true, ok_3 = true, ok_4 = true;
    int x1 = ui->x_start_edit->text().toInt(&ok_1);
    int y1 = ui->y_start_edit->text().toInt(&ok_2);
    int x2 = ui->x_end_edit->text().toInt(&ok_3);
    int y2 = ui->y_end_edit->text().toInt(&ok_4);
    if (!ok_1 || !ok_2 || !ok_3 || !ok_4)
        QMessageBox::warning(this, "Ошибка ввода", "Вводите, пожалуйста, только целые числа.");
    else
    {
        segment_type elem {QPoint(x1, y1), QPoint(x2, y2)};
        myscene->add_segment(elem);
        myscene->repaint();
    }
}

void MainWindow::on_add_cut_pushButton_clicked()
{
    bool ok_1 = true, ok_2 = true, ok_3 = true, ok_4 = true;
    int xl = ui->x_left_edit->text().toInt(&ok_1);
    int yt = ui->y_top_edit->text().toInt(&ok_2);
    int xr = ui->x_right_edit->text().toInt(&ok_3);
    int yb = ui->y_bottom_edit->text().toInt(&ok_4);
    if (!ok_1 || !ok_2 || !ok_3 || !ok_4)
        QMessageBox::warning(this, "Ошибка ввода", "Вводите, пожалуйста, только целые числа для координат.");
    else
    {
        ok_1 = true;
        double eps = ui->eps_edit->text().toDouble(&ok_1);
        if (!ok_1 || eps < 2)
            QMessageBox::warning(this, "Ошибка ввода", "Вводите, пожалуйста, квадрат точности в виде вещественного числа не меньшего 2.");
        else
        {
            myscene->set_cut(xl, xr, yb, yt);
            myscene->set_eps(eps);
            myscene->repaint();
        }
    }
}

void MainWindow::on_clear_segments_pushButton_clicked()
{
    myscene->clear_segments();
    myscene->repaint();
}

void MainWindow::on_clear_all_pushButton_clicked()
{
    myscene->clear_all();
    myscene->repaint();
}

void MainWindow::on_cut_pushButton_clicked()
{
    myscene->cut_result();
    myscene->repaint();
}

void MainWindow::on_pushButton_clicked()
{
    int xl = 150, xr = 450, yb = 440, yt = 140;
    double eps = 2.0;
    myscene->set_cut(xl, xr, yb, yt);
    myscene->set_eps(eps);
    myscene->repaint();
}
