#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_pushButton_clicked();

    void on_draw_circle_button_clicked();

    void on_draw_ellipse_button_clicked();

    void on_draw_circles_Button_clicked();

    void on_draw_ellipses_Button_clicked();

private:
    Ui::MainWindow *ui;
    QPixmap *my_scene;
    QPainter *painter;

    void check_color(void);
};

#endif // MAINWINDOW_H
