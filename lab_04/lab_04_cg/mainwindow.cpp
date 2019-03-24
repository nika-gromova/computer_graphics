#include "mainwindow.h"
#include "ui_mainwindow.h"

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
