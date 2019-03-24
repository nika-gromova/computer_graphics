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
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLineEdit *x_start_edit;
    QLabel *label_6;
    QLineEdit *y_start_edit;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *x_end_edit;
    QLabel *label_4;
    QLineEdit *y_end_edit;
    QPushButton *draw_line_button;
    QWidget *tab_2;
    QLabel *label_9;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_7;
    QPushButton *draw_sun_Button;
    QPushButton *compare_time_Button;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_10;
    QLineEdit *x_center_edit;
    QLabel *label_12;
    QLineEdit *y_center_edit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_11;
    QLineEdit *line_length_edit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_13;
    QLineEdit *step_edit;
    QLabel *draw_label;
    QPushButton *pushButton;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *dda_radioButton;
    QRadioButton *bre_double_radioButton;
    QRadioButton *bre_integer_radioButton;
    QRadioButton *bre_stairs_radioButton;
    QRadioButton *lib_radioButton;
    QRadioButton *wu_radioButton;
    QWidget *layoutWidget4;
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
        MainWindow->resize(950, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(590, 10, 351, 201));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 331, 141));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font1;
        font1.setPointSize(10);
        label_5->setFont(font1);

        horizontalLayout->addWidget(label_5);

        x_start_edit = new QLineEdit(layoutWidget);
        x_start_edit->setObjectName(QStringLiteral("x_start_edit"));

        horizontalLayout->addWidget(x_start_edit);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        horizontalLayout->addWidget(label_6);

        y_start_edit = new QLineEdit(layoutWidget);
        y_start_edit->setObjectName(QStringLiteral("y_start_edit"));

        horizontalLayout->addWidget(y_start_edit);


        verticalLayout->addLayout(horizontalLayout);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        horizontalLayout_2->addWidget(label_3);

        x_end_edit = new QLineEdit(layoutWidget);
        x_end_edit->setObjectName(QStringLiteral("x_end_edit"));

        horizontalLayout_2->addWidget(x_end_edit);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        horizontalLayout_2->addWidget(label_4);

        y_end_edit = new QLineEdit(layoutWidget);
        y_end_edit->setObjectName(QStringLiteral("y_end_edit"));

        horizontalLayout_2->addWidget(y_end_edit);


        verticalLayout->addLayout(horizontalLayout_2);

        draw_line_button = new QPushButton(layoutWidget);
        draw_line_button->setObjectName(QStringLiteral("draw_line_button"));

        verticalLayout->addWidget(draw_line_button);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 10, 199, 16));
        label_9->setFont(font1);
        layoutWidget1 = new QWidget(tab_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 110, 92, 54));
        verticalLayout_7 = new QVBoxLayout(layoutWidget1);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        draw_sun_Button = new QPushButton(layoutWidget1);
        draw_sun_Button->setObjectName(QStringLiteral("draw_sun_Button"));

        verticalLayout_7->addWidget(draw_sun_Button);

        compare_time_Button = new QPushButton(layoutWidget1);
        compare_time_Button->setObjectName(QStringLiteral("compare_time_Button"));

        verticalLayout_7->addWidget(compare_time_Button);

        layoutWidget2 = new QWidget(tab_2);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 30, 187, 80));
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
        label_10->setFont(font1);

        horizontalLayout_6->addWidget(label_10);

        x_center_edit = new QLineEdit(layoutWidget2);
        x_center_edit->setObjectName(QStringLiteral("x_center_edit"));

        horizontalLayout_6->addWidget(x_center_edit);

        label_12 = new QLabel(layoutWidget2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font1);

        horizontalLayout_6->addWidget(label_12);

        y_center_edit = new QLineEdit(layoutWidget2);
        y_center_edit->setObjectName(QStringLiteral("y_center_edit"));

        horizontalLayout_6->addWidget(y_center_edit);


        verticalLayout_6->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_11 = new QLabel(layoutWidget2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font1);

        horizontalLayout_7->addWidget(label_11);

        line_length_edit = new QLineEdit(layoutWidget2);
        line_length_edit->setObjectName(QStringLiteral("line_length_edit"));

        horizontalLayout_7->addWidget(line_length_edit);


        verticalLayout_6->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_13 = new QLabel(layoutWidget2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font1);

        horizontalLayout_8->addWidget(label_13);

        step_edit = new QLineEdit(layoutWidget2);
        step_edit->setObjectName(QStringLiteral("step_edit"));

        horizontalLayout_8->addWidget(step_edit);


        verticalLayout_6->addLayout(horizontalLayout_8);

        tabWidget->addTab(tab_2, QString());
        draw_label = new QLabel(centralWidget);
        draw_label->setObjectName(QStringLiteral("draw_label"));
        draw_label->setGeometry(QRect(10, 10, 570, 570));
        draw_label->setStyleSheet(QStringLiteral("background: white"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(590, 560, 75, 23));
        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(590, 240, 333, 161));
        verticalLayout_3 = new QVBoxLayout(layoutWidget3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget3);
        label_7->setObjectName(QStringLiteral("label_7"));
        QFont font2;
        font2.setPointSize(12);
        label_7->setFont(font2);

        verticalLayout_3->addWidget(label_7);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        dda_radioButton = new QRadioButton(layoutWidget3);
        dda_radioButton->setObjectName(QStringLiteral("dda_radioButton"));

        verticalLayout_2->addWidget(dda_radioButton);

        bre_double_radioButton = new QRadioButton(layoutWidget3);
        bre_double_radioButton->setObjectName(QStringLiteral("bre_double_radioButton"));

        verticalLayout_2->addWidget(bre_double_radioButton);

        bre_integer_radioButton = new QRadioButton(layoutWidget3);
        bre_integer_radioButton->setObjectName(QStringLiteral("bre_integer_radioButton"));

        verticalLayout_2->addWidget(bre_integer_radioButton);

        bre_stairs_radioButton = new QRadioButton(layoutWidget3);
        bre_stairs_radioButton->setObjectName(QStringLiteral("bre_stairs_radioButton"));

        verticalLayout_2->addWidget(bre_stairs_radioButton);

        lib_radioButton = new QRadioButton(layoutWidget3);
        lib_radioButton->setObjectName(QStringLiteral("lib_radioButton"));

        verticalLayout_2->addWidget(lib_radioButton);

        wu_radioButton = new QRadioButton(layoutWidget3);
        wu_radioButton->setObjectName(QStringLiteral("wu_radioButton"));

        verticalLayout_2->addWidget(wu_radioButton);


        verticalLayout_3->addLayout(verticalLayout_2);

        layoutWidget4 = new QWidget(centralWidget);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(590, 400, 201, 81));
        verticalLayout_5 = new QVBoxLayout(layoutWidget4);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font2);

        verticalLayout_5->addWidget(label_8);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_14 = new QLabel(layoutWidget4);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font1);

        horizontalLayout_3->addWidget(label_14);

        comboBox_bg = new QComboBox(layoutWidget4);
        comboBox_bg->setObjectName(QStringLiteral("comboBox_bg"));

        horizontalLayout_3->addWidget(comboBox_bg);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_15 = new QLabel(layoutWidget4);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font1);

        horizontalLayout_4->addWidget(label_15);

        comboBox_line = new QComboBox(layoutWidget4);
        comboBox_line->setObjectName(QStringLiteral("comboBox_line"));

        horizontalLayout_4->addWidget(comboBox_line);


        verticalLayout_4->addLayout(horizontalLayout_4);


        verticalLayout_5->addLayout(verticalLayout_4);

        plot_widget = new QCustomPlot(centralWidget);
        plot_widget->setObjectName(QStringLiteral("plot_widget"));
        plot_widget->setGeometry(QRect(10, 10, 571, 571));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\275\320\260\321\207\320\260\320\273\320\276 \320\276\321\202\321\200\320\265\320\267\320\272\320\260", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "x:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "y:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\272\320\276\320\275\320\265\321\206  \320\276\321\202\321\200\320\265\320\267\320\272\320\260", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "x:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "y:", nullptr));
        draw_line_button->setText(QApplication::translate("MainWindow", "\320\277\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\277\320\276\321\201\321\202\321\200\320\276\320\265\320\275\320\270\320\265 \320\276\321\202\321\200\320\265\320\267\320\272\320\276\320\262", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\321\206\320\265\320\275\321\202\321\200:", nullptr));
        draw_sun_Button->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214", nullptr));
        compare_time_Button->setText(QApplication::translate("MainWindow", "\320\241\321\200\320\260\320\262\320\275\320\270\321\202\321\214 \320\262\321\200\320\265\320\274\321\217", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "x:", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "y:", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "\320\264\320\273\320\270\320\275\320\260 \320\273\321\203\321\207\320\260:", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\321\210\320\260\320\263 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \321\203\320\263\320\273\320\260:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\321\201\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265 \321\205\320\260\321\200\320\260\320\272\321\202\320\265\321\200\320\270\321\201\321\202\320\270\320\272", nullptr));
        draw_label->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\320\262\321\213\320\261\320\276\321\200 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274\320\260:", nullptr));
        dda_radioButton->setText(QApplication::translate("MainWindow", "1. \320\246\320\224\320\220", nullptr));
        bre_double_radioButton->setText(QApplication::translate("MainWindow", "2. \320\221\321\200\320\265\320\267\320\265\320\275\321\205\320\265\320\274\320\260 \321\201 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\274\320\270 \321\207\320\270\321\201\320\273\320\260\320\274\320\270", nullptr));
        bre_integer_radioButton->setText(QApplication::translate("MainWindow", "3. \320\221\321\200\320\265\320\267\320\265\320\275\321\205\320\265\320\274\320\260 \321\201 \321\206\320\265\320\273\321\213\320\274\320\270 \321\207\320\270\321\201\320\273\320\260\320\274\320\270", nullptr));
        bre_stairs_radioButton->setText(QApplication::translate("MainWindow", "4. \320\221\321\200\320\265\320\267\320\265\320\275\321\205\320\265\320\274\320\260 \321\201 \321\203\321\201\321\202\321\200\320\260\320\275\320\265\320\275\320\270\320\265\320\274 \321\201\321\202\321\203\320\277\320\265\320\275\321\207\320\260\321\202\320\276\321\201\321\202\320\270", nullptr));
        lib_radioButton->setText(QApplication::translate("MainWindow", "5. \320\221\320\270\320\261\320\273\320\270\320\276\321\202\320\265\321\207\320\275\321\213\320\271 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274", nullptr));
        wu_radioButton->setText(QApplication::translate("MainWindow", "6. \320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\222\321\203", nullptr));
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
