#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "transform.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    k_group = new QGraphicsItemGroup();
    scene->addItem(k_group);

    k_face = new face();
    k_group->addToGroup(k_face);

    k_eyes = new eyes();
    k_group->addToGroup(k_eyes);

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
        move_pic(k_face, k_eyes, dx, dy);
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
            move_pic(k_face, k_eyes, (-1) * tmp[1], (-1) * tmp[2]);
            scene->update();
        }
    }
}

void MainWindow::on_initial_clicked()
{
    while (!previous_changes.isEmpty())
        previous_changes.pop();
    delete_items(k_group);
    scene->clear();
    k_group = new QGraphicsItemGroup();
    scene->addItem(k_group);

    k_face = new face();
    k_group->addToGroup(k_face);

    k_eyes = new eyes();
    k_group->addToGroup(k_eyes);
}
