#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "my_paintwidget.h"

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
    void on_add_segment_pushButton_clicked();

    void on_add_cut_pushButton_clicked();

    void on_clear_segments_pushButton_clicked();

    void on_clear_all_pushButton_clicked();

    void on_cut_pushButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    my_paintwidget *myscene;
};

#endif // MAINWINDOW_H
