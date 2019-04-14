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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *draw_widget;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *button_color_bound;
    QPushButton *button_color_bg;
    QPushButton *button_color_fill;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_5;
    QWidget *w_color_bound;
    QWidget *w_color_bg;
    QWidget *w_color_fill;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *button_fill;
    QPushButton *button_clear;
    QVBoxLayout *verticalLayout_6;
    QPushButton *button_fill_slow;
    QPushButton *button_clear_fill;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QLabel *label_7;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *button_inp_point;
    QPushButton *button_close_p;
    QWidget *widget;
    QVBoxLayout *verticalLayout_7;
    QRadioButton *radioButton_point;
    QRadioButton *radioButton_pixel;
    QRadioButton *radioButton_ellipse;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *x_edit;
    QLabel *label_8;
    QLineEdit *y_edit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_10;
    QLineEdit *edit_circle_a;
    QLabel *label_11;
    QLineEdit *edit_circle_b;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(950, 620);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        draw_widget = new QWidget(centralWidget);
        draw_widget->setObjectName(QStringLiteral("draw_widget"));
        draw_widget->setGeometry(QRect(10, 10, 640, 600));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(660, 0, 281, 121));
        QFont font;
        font.setPointSize(12);
        groupBox->setFont(font);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(200, 30, 77, 81));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        button_color_bound = new QPushButton(layoutWidget);
        button_color_bound->setObjectName(QStringLiteral("button_color_bound"));
        QFont font1;
        font1.setFamily(QStringLiteral("Alef"));
        font1.setPointSize(10);
        button_color_bound->setFont(font1);
        button_color_bound->setAutoFillBackground(true);
        button_color_bound->setStyleSheet(QStringLiteral(""));

        verticalLayout_2->addWidget(button_color_bound);

        button_color_bg = new QPushButton(layoutWidget);
        button_color_bg->setObjectName(QStringLiteral("button_color_bg"));
        button_color_bg->setFont(font1);
        button_color_bg->setAutoFillBackground(true);
        button_color_bg->setStyleSheet(QStringLiteral(""));

        verticalLayout_2->addWidget(button_color_bg);

        button_color_fill = new QPushButton(layoutWidget);
        button_color_fill->setObjectName(QStringLiteral("button_color_fill"));
        button_color_fill->setFont(font1);
        button_color_fill->setAutoFillBackground(true);
        button_color_fill->setStyleSheet(QStringLiteral(""));

        verticalLayout_2->addWidget(button_color_fill);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 30, 131, 81));
        verticalLayout_4 = new QVBoxLayout(layoutWidget1);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font2;
        font2.setFamily(QStringLiteral("Alef"));
        font2.setPointSize(11);
        label_2->setFont(font2);

        verticalLayout_4->addWidget(label_2);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font2);

        verticalLayout_4->addWidget(label_4);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font2);

        verticalLayout_4->addWidget(label_3);

        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(140, 30, 51, 81));
        verticalLayout_5 = new QVBoxLayout(layoutWidget2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        w_color_bound = new QWidget(layoutWidget2);
        w_color_bound->setObjectName(QStringLiteral("w_color_bound"));
        w_color_bound->setAutoFillBackground(true);

        verticalLayout_5->addWidget(w_color_bound);

        w_color_bg = new QWidget(layoutWidget2);
        w_color_bg->setObjectName(QStringLiteral("w_color_bg"));
        w_color_bg->setAutoFillBackground(true);

        verticalLayout_5->addWidget(w_color_bg);

        w_color_fill = new QWidget(layoutWidget2);
        w_color_fill->setObjectName(QStringLiteral("w_color_fill"));
        w_color_fill->setAutoFillBackground(true);

        verticalLayout_5->addWidget(w_color_fill);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(660, 320, 281, 111));
        groupBox_3->setFont(font);
        layoutWidget3 = new QWidget(groupBox_3);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 30, 261, 71));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        button_fill = new QPushButton(layoutWidget3);
        button_fill->setObjectName(QStringLiteral("button_fill"));
        QFont font3;
        font3.setPointSize(10);
        button_fill->setFont(font3);

        verticalLayout_3->addWidget(button_fill);

        button_clear = new QPushButton(layoutWidget3);
        button_clear->setObjectName(QStringLiteral("button_clear"));
        button_clear->setFont(font3);

        verticalLayout_3->addWidget(button_clear);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        button_fill_slow = new QPushButton(layoutWidget3);
        button_fill_slow->setObjectName(QStringLiteral("button_fill_slow"));
        button_fill_slow->setFont(font3);

        verticalLayout_6->addWidget(button_fill_slow);

        button_clear_fill = new QPushButton(layoutWidget3);
        button_clear_fill->setObjectName(QStringLiteral("button_clear_fill"));
        button_clear_fill->setFont(font3);

        verticalLayout_6->addWidget(button_clear_fill);


        horizontalLayout_2->addLayout(verticalLayout_6);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(660, 450, 281, 161));
        groupBox_4->setFont(font3);
        layoutWidget4 = new QWidget(groupBox_4);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 30, 261, 121));
        verticalLayout = new QVBoxLayout(layoutWidget4);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget4);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font4;
        font4.setPointSize(11);
        label_5->setFont(font4);
        label_5->setTextFormat(Qt::AutoText);
        label_5->setScaledContents(false);
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_5->setWordWrap(true);
        label_5->setMargin(1);
        label_5->setIndent(0);

        verticalLayout->addWidget(label_5);

        label_7 = new QLabel(layoutWidget4);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font4);
        label_7->setTextFormat(Qt::AutoText);
        label_7->setScaledContents(false);
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_7->setWordWrap(true);
        label_7->setMargin(1);
        label_7->setIndent(0);

        verticalLayout->addWidget(label_7);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(660, 120, 281, 201));
        groupBox_2->setFont(font);
        layoutWidget5 = new QWidget(groupBox_2);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(10, 160, 261, 31));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        button_inp_point = new QPushButton(layoutWidget5);
        button_inp_point->setObjectName(QStringLiteral("button_inp_point"));
        button_inp_point->setFont(font3);

        horizontalLayout_3->addWidget(button_inp_point);

        button_close_p = new QPushButton(layoutWidget5);
        button_close_p->setObjectName(QStringLiteral("button_close_p"));
        button_close_p->setFont(font3);

        horizontalLayout_3->addWidget(button_close_p);

        widget = new QWidget(groupBox_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 30, 261, 71));
        verticalLayout_7 = new QVBoxLayout(widget);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        radioButton_point = new QRadioButton(widget);
        radioButton_point->setObjectName(QStringLiteral("radioButton_point"));
        radioButton_point->setFont(font3);

        verticalLayout_7->addWidget(radioButton_point);

        radioButton_pixel = new QRadioButton(widget);
        radioButton_pixel->setObjectName(QStringLiteral("radioButton_pixel"));
        radioButton_pixel->setFont(font3);

        verticalLayout_7->addWidget(radioButton_pixel);

        radioButton_ellipse = new QRadioButton(widget);
        radioButton_ellipse->setObjectName(QStringLiteral("radioButton_ellipse"));
        radioButton_ellipse->setFont(font3);

        verticalLayout_7->addWidget(radioButton_ellipse);

        widget1 = new QWidget(groupBox_2);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 100, 261, 56));
        verticalLayout_9 = new QVBoxLayout(widget1);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget1);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        x_edit = new QLineEdit(widget1);
        x_edit->setObjectName(QStringLiteral("x_edit"));
        x_edit->setFont(font3);

        horizontalLayout->addWidget(x_edit);

        label_8 = new QLabel(widget1);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        horizontalLayout->addWidget(label_8);

        y_edit = new QLineEdit(widget1);
        y_edit->setObjectName(QStringLiteral("y_edit"));
        y_edit->setFont(font3);

        horizontalLayout->addWidget(y_edit);


        verticalLayout_9->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_10 = new QLabel(widget1);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);

        horizontalLayout_5->addWidget(label_10);

        edit_circle_a = new QLineEdit(widget1);
        edit_circle_a->setObjectName(QStringLiteral("edit_circle_a"));
        edit_circle_a->setFont(font3);

        horizontalLayout_5->addWidget(edit_circle_a);

        label_11 = new QLabel(widget1);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);

        horizontalLayout_5->addWidget(label_11);

        edit_circle_b = new QLineEdit(widget1);
        edit_circle_b->setObjectName(QStringLiteral("edit_circle_b"));
        edit_circle_b->setFont(font3);

        horizontalLayout_5->addWidget(edit_circle_b);


        verticalLayout_9->addLayout(horizontalLayout_5);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \321\206\320\262\320\265\321\202\320\260", nullptr));
        button_color_bound->setText(QApplication::translate("MainWindow", "\320\270\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        button_color_bg->setText(QApplication::translate("MainWindow", "\320\270\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        button_color_fill->setText(QApplication::translate("MainWindow", "\320\270\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\321\206\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\321\206\320\262\320\265\321\202 \321\204\320\276\320\275\320\260:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\321\206\320\262\320\265\321\202 \320\267\320\260\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217:", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\227\320\260\320\277\320\276\320\273\320\275\320\265\320\275\320\270\320\265", nullptr));
        button_fill->setText(QApplication::translate("MainWindow", "\320\267\320\260\320\272\321\200\320\260\321\201\320\270\321\202\321\214", nullptr));
        button_clear->setText(QApplication::translate("MainWindow", "\320\276\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\262\321\201\320\265", nullptr));
        button_fill_slow->setText(QApplication::translate("MainWindow", "\320\267\320\260\320\272\321\200\320\260\321\201\320\270\321\202\321\214 (\320\274\320\265\320\264\320\273\320\265\320\275\320\275\320\276)", nullptr));
        button_clear_fill->setText(QApplication::translate("MainWindow", "\320\276\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\267\320\260\320\277\320\276\320\273\320\275\320\265\320\275\320\270\320\265", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\225\321\201\320\273\320\270 \320\262\321\213 \321\205\320\276\321\202\320\270\321\202\320\265 \320\275\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214 \320\277\321\200\321\217\320\274\321\203\321\216 \320\263\320\276\321\200\320\270\320\267\320\276\320\275\321\202\320\260\320\273\321\214\320\275\321\203\321\216 \320\270\320\273\320\270 \320\262\320\265\321\200\321\202\320\270\320\272\320\260\320\273\321\214\320\275\321\203\321\216 \320\273\320\270\320\275\320\270\321\216, \320\267\320\260\320\266\320\274\320\270\321\202\320\265 \320\272\320\273\320\260\320\262\320\270\321\210\321\203 shift", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\320\225\321\201\320\273\320\270 \320\262\321\213 \321\205\320\276\321\202\320\270\321\202\320\265 \320\267\320\260\320\274\320\272\320\275\321\203\321\202\321\214 \320\263\321\200\320\260\320\275\320\270\321\206\321\203 \320\274\320\275\320\276\320\263\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272\320\260, \320\275\320\260\320\266\320\274\320\270\321\202\320\265 \320\277\321\200\320\260\320\262\321\203\321\216 \320\272\320\275\320\276\320\277\320\272\321\203 \320\274\321\213\321\210\320\270", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264 \321\202\320\276\321\207\320\272\320\270", nullptr));
        button_inp_point->setText(QApplication::translate("MainWindow", "\320\262\320\262\320\265\321\201\321\202\320\270", nullptr));
        button_close_p->setText(QApplication::translate("MainWindow", "\320\267\320\260\320\274\320\272\320\275\321\203\321\202\321\214", nullptr));
        radioButton_point->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264 \320\262\320\265\321\200\321\210\320\270\320\275\321\213", nullptr));
        radioButton_pixel->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264 \320\267\320\260\321\202\321\200\320\260\320\262\320\276\321\207\320\275\320\276\320\263\320\276 \320\277\320\270\320\272\321\201\320\265\320\273\321\217", nullptr));
        radioButton_ellipse->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264 \321\215\320\273\320\273\320\270\320\277\321\201\320\260", nullptr));
        label->setText(QApplication::translate("MainWindow", "x:", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "y:", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "a:", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "b:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
