#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QVector>
#include <QStack>

#include "face.h"
#include "eyes.h"
#include "pic.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_move_pushButton_clicked();

    void on_back_pushButton_clicked();

    void on_initial_clicked();

    void on_scale_pushButton_clicked();

    void on_rotate_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsItemGroup *k_group;
    face *k_face;
    eyes *k_eyes;
    pic *k_pic;

    QStack <QVector<double>> previous_changes;

    void delete_items(QGraphicsItemGroup *group);

};

#endif // MAINWINDOW_H
