#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "transform.h"
#include <stdio.h>
#include <QMessageBox>

#define EPS 1e-10

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, 540, 540);

    k_group = new QGraphicsItemGroup();
    scene->addItem(k_group);

    k_pic = new pic();
    k_group->addToGroup(k_pic);

    k_pic_reserve = new pic();
    null_scale = false;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_move_pushButton_clicked()
{
    bool ok_1, ok_2;
    QString dx_str = ui->move_dx_edit->text();
    QString dy_str = ui->move_dy_edit->text();
    double dx = dx_str.toDouble(&ok_1);
    double dy = dy_str.toDouble(&ok_2);
    if (ok_1 != true || ok_2 != true)
        QMessageBox::warning(this, "Неправильный ввод", "Должны быть введены только вещественные числа!");
    else
    {
        previous_changes.push({1, dx, dy});
        move_pic(k_pic, dx, dy);
        scene->update();
    }
}

void MainWindow::on_scale_pushButton_clicked()
{
    bool ok_1 = true, ok_2 = true, ok_3 = true, ok_4 = true;
    bool flag_xc = false, flag_yc = false;
    QString x_str = ui->scale_xc_edit->text();
    QString y_str = ui->scale_yc_edit->text();
    double xc;
    double yc;
    double kx;
    double ky;
    static bool info = true;
    static bool null_scale = false;
    if (x_str.isEmpty())
    {
        xc = 270;//0.0;
        flag_xc = true;
    }
    else
        xc = x_str.toDouble(&ok_1);
    if (y_str.isEmpty())
    {
        yc = 270;//0.0;
        flag_yc = true;
    }
    else
        yc = y_str.toDouble(&ok_2);
    x_str = ui->scale_kx_edit->text();
    y_str = ui->scale_ky_edit->text();
    kx = x_str.toDouble(&ok_3);
    ky = y_str.toDouble(&ok_4);
    if (ok_1 != true || ok_2 != true || ok_3 != true || ok_4 != true)
        QMessageBox::warning(this, "Неправильный ввод", "Должны быть введены только вещественные числа или ничего(для центра масштабирования!");
    else
    {
        if (flag_xc && flag_yc)
        {
            if (info)
            {
                QMessageBox::information(this, "Не указан центр поворота", "Масштабирование будет производиться относительно центра области рисования.");
                info = false;
            }
        }
        else if (flag_xc)
        {
            info = true;
            xc = 0.0;
        }
        else if (flag_yc)
        {
            info = true;
            yc = 0.0;
        }
        else
            info = false;
        if (fabs(kx) <= EPS || fabs(ky) <= EPS)
        {
            QMessageBox::information(this, "Масштабирование с нулевым(и) коэффициентом", "Изображение выродится в точку или в прямую.");
            previous_changes.push({4});
            if (null_scale == false)
            {
                copy_pic(k_pic_reserve, k_pic);
                null_scale = true;
            }
        }
        else
            previous_changes.push({2, xc, yc, kx, ky});
        scale_pic(k_pic, xc, yc, kx, ky);
        scene->update();
    }
}

void MainWindow::on_rotate_pushButton_clicked()
{
    bool ok_1 = true, ok_2 = true, ok_3 = true;
    bool flag_xc = false, flag_yc = false;
    QString x_str = ui->scale_xc_edit->text();
    QString y_str = ui->scale_yc_edit->text();
    double xc;
    double yc;
    double degrees;
    static bool info = true;
    if (x_str.isEmpty())
    {
        xc = 270;//0.0;
        flag_xc = true;
    }
    else
        xc = x_str.toDouble(&ok_1);
    if (y_str.isEmpty())
    {
        yc = 270;//0.0;
        flag_yc = true;
    }
    else
        yc = y_str.toDouble(&ok_2);
    x_str = ui->rotate_angle_edit->text();
    degrees = x_str.toDouble(&ok_3);
    if (ok_1 != true || ok_2 != true || ok_3 != true)
        QMessageBox::warning(this, "Неправильный ввод", "Должны быть введены только вещественные числа или ничего(для центра поворота)!");
    else
    {
        if (flag_xc && flag_yc)
        {
            if (info)
            {
                QMessageBox::information(this, "Не указан центр поворота", "Поворот будет производиться относительно центра области рисования.");
                info = false;
            }
        }
        else if (flag_xc)
        {
            info = true;
            xc = 0.0;
        }
        else if (flag_yc)
        {
            info = true;
            yc = 0.0;
        }
        else
            info = true;
        printf("%.3lf %.3lf\n", xc, yc);
        previous_changes.push({3, xc, yc, degrees});
        rotate_pic(k_pic, xc, yc, degrees);
        scene->update();
    }
}

void MainWindow::delete_items(QGraphicsItemGroup *group)
{
    foreach (QGraphicsItem *item, scene->items(group->boundingRect()))
    {
        if (item->group() == group)
            delete item;
    }
}

void MainWindow::on_back_pushButton_clicked()
{
    if (previous_changes.isEmpty())
        QMessageBox::warning(this, "Назад", "Назад больше вернуться нельзя)");
    else
    {
        QVector<double> tmp = previous_changes.pop();
        if (tmp[0] == 1)
        {
            move_pic(k_pic, (-1) * tmp[1], (-1) * tmp[2]);
            scene->update();
        }
        else if (tmp[0] == 2)
        {
            scale_pic(k_pic, tmp[1], tmp[2], 1 / tmp[3], 1 / tmp[4]);
            scene->update();
        }
        else if (tmp[0] == 3)
        {
            rotate_pic(k_pic, tmp[1], tmp[2], (-1) * tmp[3]);
            scene->update();
        }
        else if (tmp[0] == 4)
        {
            copy_pic(k_pic, k_pic_reserve);
            null_scale = false;
            scene->update();
        }
        else if (tmp[0] == 5)
        {
            copy_pic(k_pic, k_pic_reserve);
            scene->update();
        }
    }
}

void MainWindow::on_initial_clicked()
{
    copy_pic(k_pic_reserve, k_pic);
    previous_changes.push({5});
    /*while (!previous_changes.isEmpty())
        previous_changes.pop();*/

    scene->clear();
    scene->update();

    k_group = new QGraphicsItemGroup();
    scene->addItem(k_group);

    k_pic = new pic();
    k_group->addToGroup(k_pic);
}
