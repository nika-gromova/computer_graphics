/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *rotate_pushButton;
    QPushButton *move_pushButton;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_12;
    QLineEdit *rotate_angle_edit;
    QLabel *label_4;
    QSpacerItem *verticalSpacer_2;
    QPushButton *scale_pushButton;
    QLabel *label_2;
    QLabel *scale_label;
    QLabel *rotate_label;
    QLabel *move_label;
    QHBoxLayout *horizontalLayout;
    QLabel *move_dx_label;
    QLineEdit *move_dx_edit;
    QLabel *move_dy_label;
    QLineEdit *move_dy_edit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *scale_xc_edit;
    QLabel *label;
    QLineEdit *scale_yc_edit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_kx;
    QLineEdit *scale_kx_edit;
    QLabel *label_ky;
    QLineEdit *scale_ky_edit;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *back_pushButton;
    QPushButton *initial;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(813, 628);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setEnabled(true);
        graphicsView->setGeometry(QRect(10, 10, 551, 551));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(571, 0, 215, 381));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        rotate_pushButton = new QPushButton(layoutWidget);
        rotate_pushButton->setObjectName(QStringLiteral("rotate_pushButton"));

        horizontalLayout_5->addWidget(rotate_pushButton);


        gridLayout->addLayout(horizontalLayout_5, 14, 0, 1, 1);

        move_pushButton = new QPushButton(layoutWidget);
        move_pushButton->setObjectName(QStringLiteral("move_pushButton"));

        gridLayout->addWidget(move_pushButton, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_4->addWidget(label_12);

        rotate_angle_edit = new QLineEdit(layoutWidget);
        rotate_angle_edit->setObjectName(QStringLiteral("rotate_angle_edit"));

        horizontalLayout_4->addWidget(rotate_angle_edit);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);


        gridLayout->addLayout(horizontalLayout_4, 13, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 9, 0, 1, 1);

        scale_pushButton = new QPushButton(layoutWidget);
        scale_pushButton->setObjectName(QStringLiteral("scale_pushButton"));

        gridLayout->addWidget(scale_pushButton, 8, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 11, 0, 1, 1);

        scale_label = new QLabel(layoutWidget);
        scale_label->setObjectName(QStringLiteral("scale_label"));
        QFont font;
        font.setPointSize(14);
        scale_label->setFont(font);

        gridLayout->addWidget(scale_label, 5, 0, 1, 1);

        rotate_label = new QLabel(layoutWidget);
        rotate_label->setObjectName(QStringLiteral("rotate_label"));
        rotate_label->setFont(font);

        gridLayout->addWidget(rotate_label, 10, 0, 1, 1);

        move_label = new QLabel(layoutWidget);
        move_label->setObjectName(QStringLiteral("move_label"));
        move_label->setFont(font);

        gridLayout->addWidget(move_label, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        move_dx_label = new QLabel(layoutWidget);
        move_dx_label->setObjectName(QStringLiteral("move_dx_label"));
        QFont font1;
        font1.setPointSize(10);
        move_dx_label->setFont(font1);

        horizontalLayout->addWidget(move_dx_label);

        move_dx_edit = new QLineEdit(layoutWidget);
        move_dx_edit->setObjectName(QStringLiteral("move_dx_edit"));
        move_dx_edit->setAutoFillBackground(false);

        horizontalLayout->addWidget(move_dx_edit);

        move_dy_label = new QLabel(layoutWidget);
        move_dy_label->setObjectName(QStringLiteral("move_dy_label"));
        move_dy_label->setFont(font1);

        horizontalLayout->addWidget(move_dy_label);

        move_dy_edit = new QLineEdit(layoutWidget);
        move_dy_edit->setObjectName(QStringLiteral("move_dy_edit"));

        horizontalLayout->addWidget(move_dy_edit);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        horizontalLayout_2->addWidget(label_5);

        scale_xc_edit = new QLineEdit(layoutWidget);
        scale_xc_edit->setObjectName(QStringLiteral("scale_xc_edit"));

        horizontalLayout_2->addWidget(scale_xc_edit);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        horizontalLayout_2->addWidget(label);

        scale_yc_edit = new QLineEdit(layoutWidget);
        scale_yc_edit->setObjectName(QStringLiteral("scale_yc_edit"));

        horizontalLayout_2->addWidget(scale_yc_edit);


        gridLayout->addLayout(horizontalLayout_2, 6, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_kx = new QLabel(layoutWidget);
        label_kx->setObjectName(QStringLiteral("label_kx"));
        label_kx->setFont(font1);

        horizontalLayout_3->addWidget(label_kx);

        scale_kx_edit = new QLineEdit(layoutWidget);
        scale_kx_edit->setObjectName(QStringLiteral("scale_kx_edit"));

        horizontalLayout_3->addWidget(scale_kx_edit);

        label_ky = new QLabel(layoutWidget);
        label_ky->setObjectName(QStringLiteral("label_ky"));
        label_ky->setFont(font1);

        horizontalLayout_3->addWidget(label_ky);

        scale_ky_edit = new QLineEdit(layoutWidget);
        scale_ky_edit->setObjectName(QStringLiteral("scale_ky_edit"));

        horizontalLayout_3->addWidget(scale_ky_edit);


        gridLayout->addLayout(horizontalLayout_3, 7, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 12, 0, 1, 1);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(570, 530, 239, 25));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        back_pushButton = new QPushButton(layoutWidget1);
        back_pushButton->setObjectName(QStringLiteral("back_pushButton"));

        horizontalLayout_6->addWidget(back_pushButton);

        initial = new QPushButton(layoutWidget1);
        initial->setObjectName(QStringLiteral("initial"));

        horizontalLayout_6->addWidget(initial);

        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_6->addWidget(pushButton);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 813, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        rotate_pushButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", Q_NULLPTR));
        move_pushButton->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\265\321\201\321\202\320\270", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "\321\203\320\263\320\276\320\273:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "(\320\263\321\200\320\260\320\264\321\203\321\201\321\213)", Q_NULLPTR));
        scale_pushButton->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\321\206\320\265\320\275\321\202\321\200 \320\277\320\276\320\262\320\276\321\200\320\276\321\202\320\260  (xc, yc) ", Q_NULLPTR));
        scale_label->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", Q_NULLPTR));
        rotate_label->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", Q_NULLPTR));
        move_label->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\276\321\201", Q_NULLPTR));
        move_dx_label->setText(QApplication::translate("MainWindow", "dx:", Q_NULLPTR));
        move_dx_edit->setInputMask(QString());
        move_dx_edit->setText(QString());
        move_dy_label->setText(QApplication::translate("MainWindow", "dy:", Q_NULLPTR));
        move_dy_edit->setInputMask(QString());
        label_5->setText(QApplication::translate("MainWindow", "xc:", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "yc:", Q_NULLPTR));
        label_kx->setText(QApplication::translate("MainWindow", "kx:", Q_NULLPTR));
        label_ky->setText(QApplication::translate("MainWindow", "ky:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\320\267\320\260\320\264\320\260\320\265\321\202\321\201\321\217 \320\262 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\260\321\205 \320\274\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", Q_NULLPTR));
        back_pushButton->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", Q_NULLPTR));
        initial->setText(QApplication::translate("MainWindow", "\320\230\321\201\321\205\320\276\320\264\320\275\320\276\320\265", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
