/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_20;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLineEdit *x_circle_edit;
    QLabel *label_6;
    QLineEdit *y_circle_edit;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *r_circle_edit;
    QPushButton *draw_circle_button;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_21;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_16;
    QLineEdit *x_ellipse_edit;
    QLabel *label_17;
    QLineEdit *y_ellipse_edit;
    QLabel *label_18;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_19;
    QLineEdit *a_ellipse_edit;
    QLabel *label_22;
    QLineEdit *b_ellipse_edit;
    QPushButton *draw_ellipse_button;
    QFrame *line;
    QWidget *tab_2;
    QLabel *label_9;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_7;
    QPushButton *draw_circles_Button;
    QPushButton *compare_time_circle_Button;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_10;
    QLineEdit *x_center_circle_edit;
    QLabel *label_12;
    QLineEdit *y_center_circle_edit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_11;
    QLineEdit *start_r_edit;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_23;
    QLineEdit *end_r_edit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_13;
    QLineEdit *step_r_edit;
    QWidget *tab_3;
    QLabel *label_24;
    QWidget *layoutWidget_7;
    QVBoxLayout *verticalLayout_10;
    QPushButton *draw_ellipses_Button;
    QPushButton *compare_time_ellipse_Button;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_25;
    QLineEdit *x_center_ellipse_edit;
    QLabel *label_26;
    QLineEdit *y_center_ellipse_edit;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_27;
    QLabel *label_30;
    QLineEdit *a_start_edit;
    QLabel *label_31;
    QLineEdit *b_start_edit;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_28;
    QLineEdit *n_ellipses_Edit;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_29;
    QLineEdit *step_ab_edit;
    QLabel *draw_label;
    QPushButton *pushButton;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *canon_radioButton;
    QRadioButton *param_radioButton;
    QRadioButton *bre_radioButton;
    QRadioButton *midpoint_radioButton;
    QRadioButton *lib_radioButton;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_14;
    QComboBox *comboBox_bg;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_15;
    QComboBox *comboBox_line;
    QCustomPlot *plot_widget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1049, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(590, 10, 401, 231));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 10, 161, 191));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_20 = new QLabel(layoutWidget);
        label_20->setObjectName(QStringLiteral("label_20"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label_20->setFont(font);

        verticalLayout->addWidget(label_20);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font2;
        font2.setPointSize(10);
        label_5->setFont(font2);

        horizontalLayout->addWidget(label_5);

        x_circle_edit = new QLineEdit(layoutWidget);
        x_circle_edit->setObjectName(QStringLiteral("x_circle_edit"));

        horizontalLayout->addWidget(x_circle_edit);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font2);

        horizontalLayout->addWidget(label_6);

        y_circle_edit = new QLineEdit(layoutWidget);
        y_circle_edit->setObjectName(QStringLiteral("y_circle_edit"));

        horizontalLayout->addWidget(y_circle_edit);


        verticalLayout->addLayout(horizontalLayout);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font2);

        horizontalLayout_2->addWidget(label_3);

        r_circle_edit = new QLineEdit(layoutWidget);
        r_circle_edit->setObjectName(QStringLiteral("r_circle_edit"));

        horizontalLayout_2->addWidget(r_circle_edit);


        verticalLayout->addLayout(horizontalLayout_2);

        draw_circle_button = new QPushButton(layoutWidget);
        draw_circle_button->setObjectName(QStringLiteral("draw_circle_button"));

        verticalLayout->addWidget(draw_circle_button);

        layoutWidget_2 = new QWidget(tab);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(210, 10, 152, 191));
        verticalLayout_8 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_21 = new QLabel(layoutWidget_2);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font);

        verticalLayout_8->addWidget(label_21);

        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_16 = new QLabel(layoutWidget_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font2);

        horizontalLayout_5->addWidget(label_16);

        x_ellipse_edit = new QLineEdit(layoutWidget_2);
        x_ellipse_edit->setObjectName(QStringLiteral("x_ellipse_edit"));

        horizontalLayout_5->addWidget(x_ellipse_edit);

        label_17 = new QLabel(layoutWidget_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font2);

        horizontalLayout_5->addWidget(label_17);

        y_ellipse_edit = new QLineEdit(layoutWidget_2);
        y_ellipse_edit->setObjectName(QStringLiteral("y_ellipse_edit"));

        horizontalLayout_5->addWidget(y_ellipse_edit);


        verticalLayout_8->addLayout(horizontalLayout_5);

        label_18 = new QLabel(layoutWidget_2);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setFont(font1);
        label_18->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_18);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_19 = new QLabel(layoutWidget_2);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font2);

        horizontalLayout_9->addWidget(label_19);

        a_ellipse_edit = new QLineEdit(layoutWidget_2);
        a_ellipse_edit->setObjectName(QStringLiteral("a_ellipse_edit"));

        horizontalLayout_9->addWidget(a_ellipse_edit);

        label_22 = new QLabel(layoutWidget_2);
        label_22->setObjectName(QStringLiteral("label_22"));

        horizontalLayout_9->addWidget(label_22);

        b_ellipse_edit = new QLineEdit(layoutWidget_2);
        b_ellipse_edit->setObjectName(QStringLiteral("b_ellipse_edit"));

        horizontalLayout_9->addWidget(b_ellipse_edit);


        verticalLayout_8->addLayout(horizontalLayout_9);

        draw_ellipse_button = new QPushButton(layoutWidget_2);
        draw_ellipse_button->setObjectName(QStringLiteral("draw_ellipse_button"));

        verticalLayout_8->addWidget(draw_ellipse_button);

        line = new QFrame(tab);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(190, 10, 20, 191));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 10, 199, 16));
        label_9->setFont(font2);
        layoutWidget1 = new QWidget(tab_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 150, 94, 54));
        verticalLayout_7 = new QVBoxLayout(layoutWidget1);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        draw_circles_Button = new QPushButton(layoutWidget1);
        draw_circles_Button->setObjectName(QStringLiteral("draw_circles_Button"));

        verticalLayout_7->addWidget(draw_circles_Button);

        compare_time_circle_Button = new QPushButton(layoutWidget1);
        compare_time_circle_Button->setObjectName(QStringLiteral("compare_time_circle_Button"));

        verticalLayout_7->addWidget(compare_time_circle_Button);

        layoutWidget2 = new QWidget(tab_2);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 30, 221, 111));
        verticalLayout_6 = new QVBoxLayout(layoutWidget2);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_10 = new QLabel(layoutWidget2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font2);

        horizontalLayout_6->addWidget(label_10);

        x_center_circle_edit = new QLineEdit(layoutWidget2);
        x_center_circle_edit->setObjectName(QStringLiteral("x_center_circle_edit"));

        horizontalLayout_6->addWidget(x_center_circle_edit);

        label_12 = new QLabel(layoutWidget2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font2);

        horizontalLayout_6->addWidget(label_12);

        y_center_circle_edit = new QLineEdit(layoutWidget2);
        y_center_circle_edit->setObjectName(QStringLiteral("y_center_circle_edit"));

        horizontalLayout_6->addWidget(y_center_circle_edit);


        verticalLayout_6->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_11 = new QLabel(layoutWidget2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font2);

        horizontalLayout_7->addWidget(label_11);

        start_r_edit = new QLineEdit(layoutWidget2);
        start_r_edit->setObjectName(QStringLiteral("start_r_edit"));

        horizontalLayout_7->addWidget(start_r_edit);


        verticalLayout_6->addLayout(horizontalLayout_7);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_23 = new QLabel(layoutWidget2);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setFont(font2);

        horizontalLayout_10->addWidget(label_23);

        end_r_edit = new QLineEdit(layoutWidget2);
        end_r_edit->setObjectName(QStringLiteral("end_r_edit"));

        horizontalLayout_10->addWidget(end_r_edit);


        verticalLayout_6->addLayout(horizontalLayout_10);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_13 = new QLabel(layoutWidget2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font2);

        horizontalLayout_8->addWidget(label_13);

        step_r_edit = new QLineEdit(layoutWidget2);
        step_r_edit->setObjectName(QStringLiteral("step_r_edit"));

        horizontalLayout_8->addWidget(step_r_edit);


        verticalLayout_6->addLayout(horizontalLayout_8);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_24 = new QLabel(tab_3);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(10, 10, 199, 16));
        label_24->setFont(font2);
        layoutWidget_7 = new QWidget(tab_3);
        layoutWidget_7->setObjectName(QStringLiteral("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(10, 150, 94, 54));
        verticalLayout_10 = new QVBoxLayout(layoutWidget_7);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        draw_ellipses_Button = new QPushButton(layoutWidget_7);
        draw_ellipses_Button->setObjectName(QStringLiteral("draw_ellipses_Button"));

        verticalLayout_10->addWidget(draw_ellipses_Button);

        compare_time_ellipse_Button = new QPushButton(layoutWidget_7);
        compare_time_ellipse_Button->setObjectName(QStringLiteral("compare_time_ellipse_Button"));

        verticalLayout_10->addWidget(compare_time_ellipse_Button);

        layoutWidget3 = new QWidget(tab_3);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 30, 301, 111));
        verticalLayout_9 = new QVBoxLayout(layoutWidget3);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_25 = new QLabel(layoutWidget3);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setFont(font2);

        horizontalLayout_11->addWidget(label_25);

        x_center_ellipse_edit = new QLineEdit(layoutWidget3);
        x_center_ellipse_edit->setObjectName(QStringLiteral("x_center_ellipse_edit"));

        horizontalLayout_11->addWidget(x_center_ellipse_edit);

        label_26 = new QLabel(layoutWidget3);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setFont(font2);

        horizontalLayout_11->addWidget(label_26);

        y_center_ellipse_edit = new QLineEdit(layoutWidget3);
        y_center_ellipse_edit->setObjectName(QStringLiteral("y_center_ellipse_edit"));

        horizontalLayout_11->addWidget(y_center_ellipse_edit);


        verticalLayout_9->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_27 = new QLabel(layoutWidget3);
        label_27->setObjectName(QStringLiteral("label_27"));

        horizontalLayout_12->addWidget(label_27);

        label_30 = new QLabel(layoutWidget3);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setFont(font2);

        horizontalLayout_12->addWidget(label_30);

        a_start_edit = new QLineEdit(layoutWidget3);
        a_start_edit->setObjectName(QStringLiteral("a_start_edit"));

        horizontalLayout_12->addWidget(a_start_edit);

        label_31 = new QLabel(layoutWidget3);
        label_31->setObjectName(QStringLiteral("label_31"));

        horizontalLayout_12->addWidget(label_31);

        b_start_edit = new QLineEdit(layoutWidget3);
        b_start_edit->setObjectName(QStringLiteral("b_start_edit"));

        horizontalLayout_12->addWidget(b_start_edit);


        verticalLayout_9->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_28 = new QLabel(layoutWidget3);
        label_28->setObjectName(QStringLiteral("label_28"));

        horizontalLayout_13->addWidget(label_28);

        n_ellipses_Edit = new QLineEdit(layoutWidget3);
        n_ellipses_Edit->setObjectName(QStringLiteral("n_ellipses_Edit"));

        horizontalLayout_13->addWidget(n_ellipses_Edit);


        verticalLayout_9->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_29 = new QLabel(layoutWidget3);
        label_29->setObjectName(QStringLiteral("label_29"));

        horizontalLayout_14->addWidget(label_29);

        step_ab_edit = new QLineEdit(layoutWidget3);
        step_ab_edit->setObjectName(QStringLiteral("step_ab_edit"));

        horizontalLayout_14->addWidget(step_ab_edit);


        verticalLayout_9->addLayout(horizontalLayout_14);

        tabWidget->addTab(tab_3, QString());
        draw_label = new QLabel(centralWidget);
        draw_label->setObjectName(QStringLiteral("draw_label"));
        draw_label->setGeometry(QRect(10, 10, 570, 570));
        draw_label->setStyleSheet(QStringLiteral("background: white"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(590, 560, 75, 23));
        layoutWidget4 = new QWidget(centralWidget);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(590, 240, 333, 161));
        verticalLayout_3 = new QVBoxLayout(layoutWidget4);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget4);
        label_7->setObjectName(QStringLiteral("label_7"));
        QFont font3;
        font3.setPointSize(12);
        label_7->setFont(font3);

        verticalLayout_3->addWidget(label_7);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        canon_radioButton = new QRadioButton(layoutWidget4);
        canon_radioButton->setObjectName(QStringLiteral("canon_radioButton"));

        verticalLayout_2->addWidget(canon_radioButton);

        param_radioButton = new QRadioButton(layoutWidget4);
        param_radioButton->setObjectName(QStringLiteral("param_radioButton"));

        verticalLayout_2->addWidget(param_radioButton);

        bre_radioButton = new QRadioButton(layoutWidget4);
        bre_radioButton->setObjectName(QStringLiteral("bre_radioButton"));

        verticalLayout_2->addWidget(bre_radioButton);

        midpoint_radioButton = new QRadioButton(layoutWidget4);
        midpoint_radioButton->setObjectName(QStringLiteral("midpoint_radioButton"));

        verticalLayout_2->addWidget(midpoint_radioButton);

        lib_radioButton = new QRadioButton(layoutWidget4);
        lib_radioButton->setObjectName(QStringLiteral("lib_radioButton"));

        verticalLayout_2->addWidget(lib_radioButton);


        verticalLayout_3->addLayout(verticalLayout_2);

        layoutWidget5 = new QWidget(centralWidget);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(590, 400, 201, 81));
        verticalLayout_5 = new QVBoxLayout(layoutWidget5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget5);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font3);

        verticalLayout_5->addWidget(label_8);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_14 = new QLabel(layoutWidget5);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font2);

        horizontalLayout_3->addWidget(label_14);

        comboBox_bg = new QComboBox(layoutWidget5);
        comboBox_bg->setObjectName(QStringLiteral("comboBox_bg"));

        horizontalLayout_3->addWidget(comboBox_bg);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_15 = new QLabel(layoutWidget5);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font2);

        horizontalLayout_4->addWidget(label_15);

        comboBox_line = new QComboBox(layoutWidget5);
        comboBox_line->setObjectName(QStringLiteral("comboBox_line"));

        horizontalLayout_4->addWidget(comboBox_line);


        verticalLayout_4->addLayout(horizontalLayout_4);


        verticalLayout_5->addLayout(verticalLayout_4);

        plot_widget = new QCustomPlot(centralWidget);
        plot_widget->setObjectName(QStringLiteral("plot_widget"));
        plot_widget->setGeometry(QRect(10, 10, 570, 570));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "\320\276\320\272\321\200\321\203\320\266\320\275\320\276\321\201\321\202\321\214:", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \321\206\320\265\320\275\321\202\321\200\320\260", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "x:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "y:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\321\200\320\260\320\264\320\270\321\203\321\201", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "R:", nullptr));
        draw_circle_button->setText(QApplication::translate("MainWindow", "\320\277\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "\321\215\320\273\320\273\320\270\320\277\321\201:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \321\206\320\265\320\275\321\202\321\200\320\260", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "x:", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "y:", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "\320\277\320\276\320\273\321\203\320\276\321\201\320\270:", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "a:", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "b:", nullptr));
        draw_ellipse_button->setText(QApplication::translate("MainWindow", "\320\277\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\277\320\276\321\201\321\202\321\200\320\276\320\265\320\275\320\270\320\265 \320\272\321\200\320\270\320\262\321\213\321\205", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\321\206\320\265\320\275\321\202\321\200:", nullptr));
        draw_circles_Button->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214", nullptr));
        compare_time_circle_Button->setText(QApplication::translate("MainWindow", "\320\241\321\200\320\260\320\262\320\275\320\270\321\202\321\214 \320\262\321\200\320\265\320\274\321\217", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "x:", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "y:", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "\320\275\320\260\321\207\320\260\320\273\321\214\320\275\321\213\320\271 \321\200\320\260\320\264\320\270\321\203\321\201:", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "\320\272\320\276\320\275\320\265\321\207\320\275\321\213\320\271 \321\200\320\260\320\264\320\270\321\203\321\201:", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\321\210\320\260\320\263 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\321\201\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265 (\320\276\320\272\321\200\321\203\320\266\320\275\320\276\321\201\321\202\321\214)", nullptr));
        label_24->setText(QApplication::translate("MainWindow", "\321\206\320\265\320\275\321\202\321\200:", nullptr));
        draw_ellipses_Button->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214", nullptr));
        compare_time_ellipse_Button->setText(QApplication::translate("MainWindow", "\320\241\321\200\320\260\320\262\320\275\320\270\321\202\321\214 \320\262\321\200\320\265\320\274\321\217", nullptr));
        label_25->setText(QApplication::translate("MainWindow", "x:", nullptr));
        label_26->setText(QApplication::translate("MainWindow", "y:", nullptr));
        label_27->setText(QApplication::translate("MainWindow", "\320\275\320\260\321\207\320\260\320\273\321\214\320\275\321\213\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217:", nullptr));
        label_30->setText(QApplication::translate("MainWindow", "a:", nullptr));
        label_31->setText(QApplication::translate("MainWindow", "b:", nullptr));
        label_28->setText(QApplication::translate("MainWindow", "\320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\215\320\273\320\273\320\270\320\277\321\201\320\276\320\262:", nullptr));
        label_29->setText(QApplication::translate("MainWindow", "\321\210\320\260\320\263 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\321\201\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265(\321\215\320\273\320\273\320\270\320\277\321\201)", nullptr));
        draw_label->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\320\262\321\213\320\261\320\276\321\200 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274\320\260:", nullptr));
        canon_radioButton->setText(QApplication::translate("MainWindow", "1. \320\232\320\260\320\275\320\276\320\275\320\270\321\207\320\265\321\201\320\272\320\276\320\265 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265", nullptr));
        param_radioButton->setText(QApplication::translate("MainWindow", "2. \320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\270\321\207\320\265\321\201\320\272\320\276\320\265 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265", nullptr));
        bre_radioButton->setText(QApplication::translate("MainWindow", "3. \320\221\321\200\320\265\320\267\320\265\320\275\321\205\320\265\320\274\320\260", nullptr));
        midpoint_radioButton->setText(QApplication::translate("MainWindow", "4. \320\241\321\200\320\265\320\264\320\275\320\265\320\271 \321\202\320\276\321\207\320\272\320\270", nullptr));
        lib_radioButton->setText(QApplication::translate("MainWindow", "5. \320\221\320\270\320\261\320\273\320\270\320\276\321\202\320\265\321\207\320\275\321\213\320\271 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\320\262\321\213\320\261\320\276\321\200 \321\206\320\262\320\265\321\202\320\260:", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\321\206\320\262\320\265\321\202 \321\204\320\276\320\275\320\260:", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "\321\206\320\262\320\265\321\202 \320\273\320\270\320\275\320\270\320\271:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
