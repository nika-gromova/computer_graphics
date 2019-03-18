#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPixmap>

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
    void on_draw_line_button_clicked();

    void on_pushButton_clicked();

    void on_draw_sun_Button_clicked();

    void on_compare_time_Button_clicked();

private:
    Ui::MainWindow *ui;
    QPixmap *my_scene;
    QPainter *painter;

    void check_color(void);
};

#endif // MAINWINDOW_H
