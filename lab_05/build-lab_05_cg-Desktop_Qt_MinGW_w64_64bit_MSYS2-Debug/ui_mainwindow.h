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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_5;
    QFrame *line_3;
    QFrame *line_4;
    QWidget *draw_widget;
    QFrame *line_6;
    QLabel *label_7;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_6;
    QVBoxLayout *verticalLayout;
    QWidget *w_color_bound;
    QWidget *w_color_bg;
    QWidget *w_color_fill;
    QWidget *w_color_sep;
    QVBoxLayout *verticalLayout_2;
    QPushButton *button_color_bound;
    QPushButton *button_color_bg;
    QPushButton *button_color_fill;
    QPushButton *button_color_sep;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *button_fill;
    QPushButton *button_fill_slow;
    QPushButton *button_clear;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(950, 620);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(660, 10, 131, 31));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(660, 220, 261, 71));
        QFont font1;
        font1.setPointSize(12);
        label_5->setFont(font1);
        label_5->setTextFormat(Qt::AutoText);
        label_5->setScaledContents(false);
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_5->setWordWrap(true);
        label_5->setMargin(-1);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(660, 210, 281, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(660, 280, 281, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        draw_widget = new QWidget(centralWidget);
        draw_widget->setObjectName(QStringLiteral("draw_widget"));
        draw_widget->setGeometry(QRect(10, 10, 640, 600));
        line_6 = new QFrame(centralWidget);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setGeometry(QRect(660, 360, 281, 16));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(660, 300, 261, 71));
        label_7->setFont(font1);
        label_7->setTextFormat(Qt::AutoText);
        label_7->setScaledContents(false);
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_7->setWordWrap(true);
        label_7->setMargin(-1);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(660, 50, 281, 114));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        verticalLayout_3->addWidget(label_2);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        verticalLayout_3->addWidget(label_4);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        verticalLayout_3->addWidget(label_3);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        verticalLayout_3->addWidget(label_6);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        w_color_bound = new QWidget(widget);
        w_color_bound->setObjectName(QStringLiteral("w_color_bound"));
        w_color_bound->setAutoFillBackground(true);

        verticalLayout->addWidget(w_color_bound);

        w_color_bg = new QWidget(widget);
        w_color_bg->setObjectName(QStringLiteral("w_color_bg"));
        w_color_bg->setAutoFillBackground(true);

        verticalLayout->addWidget(w_color_bg);

        w_color_fill = new QWidget(widget);
        w_color_fill->setObjectName(QStringLiteral("w_color_fill"));
        w_color_fill->setAutoFillBackground(true);

        verticalLayout->addWidget(w_color_fill);

        w_color_sep = new QWidget(widget);
        w_color_sep->setObjectName(QStringLiteral("w_color_sep"));
        w_color_sep->setAutoFillBackground(true);

        verticalLayout->addWidget(w_color_sep);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        button_color_bound = new QPushButton(widget);
        button_color_bound->setObjectName(QStringLiteral("button_color_bound"));
        button_color_bound->setAutoFillBackground(true);
        button_color_bound->setStyleSheet(QStringLiteral(""));

        verticalLayout_2->addWidget(button_color_bound);

        button_color_bg = new QPushButton(widget);
        button_color_bg->setObjectName(QStringLiteral("button_color_bg"));
        button_color_bg->setAutoFillBackground(true);
        button_color_bg->setStyleSheet(QStringLiteral(""));

        verticalLayout_2->addWidget(button_color_bg);

        button_color_fill = new QPushButton(widget);
        button_color_fill->setObjectName(QStringLiteral("button_color_fill"));
        button_color_fill->setAutoFillBackground(true);
        button_color_fill->setStyleSheet(QStringLiteral(""));

        verticalLayout_2->addWidget(button_color_fill);

        button_color_sep = new QPushButton(widget);
        button_color_sep->setObjectName(QStringLiteral("button_color_sep"));
        button_color_sep->setAutoFillBackground(true);
        button_color_sep->setStyleSheet(QStringLiteral(""));

        verticalLayout_2->addWidget(button_color_sep);


        horizontalLayout->addLayout(verticalLayout_2);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(660, 170, 285, 25));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        button_fill = new QPushButton(widget1);
        button_fill->setObjectName(QStringLiteral("button_fill"));

        horizontalLayout_2->addWidget(button_fill);

        button_fill_slow = new QPushButton(widget1);
        button_fill_slow->setObjectName(QStringLiteral("button_fill_slow"));

        horizontalLayout_2->addWidget(button_fill_slow);

        button_clear = new QPushButton(widget1);
        button_clear->setObjectName(QStringLiteral("button_clear"));

        horizontalLayout_2->addWidget(button_clear);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \321\206\320\262\320\265\321\202\320\260:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\225\321\201\320\273\320\270 \320\262\321\213 \321\205\320\276\321\202\320\270\321\202\320\265 \320\275\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214 \320\277\321\200\321\217\320\274\321\203\321\216 \320\263\320\276\321\200\320\270\320\267\320\276\320\275\321\202\320\260\320\273\321\214\320\275\321\203\321\216 \320\270\320\273\320\270 \320\262\320\265\321\200\321\202\320\270\320\272\320\260\320\273\321\214\320\275\321\203\321\216 \320\273\320\270\320\275\320\270\321\216, \320\267\320\260\320\266\320\274\320\270\321\202\320\265 \320\272\320\273\320\260\320\262\320\270\321\210\321\203 shift", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\320\225\321\201\320\273\320\270 \320\262\321\213 \321\205\320\276\321\202\320\270\321\202\320\265 \320\267\320\260\320\274\320\272\320\275\321\203\321\202\321\214 \320\263\321\200\320\260\320\275\320\270\321\206\321\203 \320\274\320\275\320\276\320\263\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272\320\260, \320\275\320\260\320\266\320\274\320\270\321\202\320\265 \320\277\321\200\320\260\320\262\321\203\321\216 \320\272\320\275\320\276\320\277\320\272\321\203 \320\274\321\213\321\210\320\270", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\321\206\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\321\206\320\262\320\265\321\202 \321\204\320\276\320\275\320\260:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\321\206\320\262\320\265\321\202 \320\267\320\260\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\321\206\320\262\320\265\321\202 \320\277\320\265\321\200\320\265\320\263\320\276\321\200\320\276\320\264\320\272\320\270:", nullptr));
        button_color_bound->setText(QApplication::translate("MainWindow", "\320\270\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        button_color_bg->setText(QApplication::translate("MainWindow", "\320\270\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        button_color_fill->setText(QApplication::translate("MainWindow", "\320\270\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        button_color_sep->setText(QApplication::translate("MainWindow", "\320\270\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        button_fill->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\320\260\321\201\320\270\321\202\321\214", nullptr));
        button_fill_slow->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\320\260\321\201\320\270\321\202\321\214 (\320\274\320\265\320\264\320\273\320\265\320\275\320\275\320\276)", nullptr));
        button_clear->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
