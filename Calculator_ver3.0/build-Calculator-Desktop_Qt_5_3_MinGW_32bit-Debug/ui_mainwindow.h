/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QPushButton *btnBackSpace;
    QPushButton *btnDivision;
    QPushButton *btnMultiplication;
    QPushButton *btnSubtraction;
    QPushButton *btnPoint;
    QPushButton *btnEqual;
    QPushButton *btnNum0;
    QPushButton *btnAddition;
    QPushButton *btnRightBracket;
    QPushButton *btnNum4;
    QPushButton *btnNum7;
    QPushButton *btnNum3;
    QPushButton *btnNum6;
    QPushButton *btnNum9;
    QPushButton *btnNum2;
    QPushButton *btnNum1;
    QPushButton *btnLeftBracket;
    QPushButton *btnNum8;
    QPushButton *btnNum5;
    QPushButton *btnClear;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(260, 365);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(250, 300));
        centralWidget->setMaximumSize(QSize(250, 340));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 50, 245, 241));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        btnBackSpace = new QPushButton(gridLayoutWidget);
        btnBackSpace->setObjectName(QStringLiteral("btnBackSpace"));
        btnBackSpace->setMaximumSize(QSize(50, 50));
        btnBackSpace->setLayoutDirection(Qt::LeftToRight);

        gridLayout_2->addWidget(btnBackSpace, 1, 3, 1, 1);

        btnDivision = new QPushButton(gridLayoutWidget);
        btnDivision->setObjectName(QStringLiteral("btnDivision"));
        btnDivision->setMaximumSize(QSize(50, 50));

        gridLayout_2->addWidget(btnDivision, 2, 3, 1, 1);

        btnMultiplication = new QPushButton(gridLayoutWidget);
        btnMultiplication->setObjectName(QStringLiteral("btnMultiplication"));
        btnMultiplication->setMaximumSize(QSize(50, 50));

        gridLayout_2->addWidget(btnMultiplication, 3, 3, 1, 1);

        btnSubtraction = new QPushButton(gridLayoutWidget);
        btnSubtraction->setObjectName(QStringLiteral("btnSubtraction"));
        btnSubtraction->setMaximumSize(QSize(50, 50));

        gridLayout_2->addWidget(btnSubtraction, 4, 3, 1, 1);

        btnPoint = new QPushButton(gridLayoutWidget);
        btnPoint->setObjectName(QStringLiteral("btnPoint"));
        btnPoint->setMaximumSize(QSize(50, 50));

        gridLayout_2->addWidget(btnPoint, 5, 1, 1, 1);

        btnEqual = new QPushButton(gridLayoutWidget);
        btnEqual->setObjectName(QStringLiteral("btnEqual"));
        btnEqual->setMaximumSize(QSize(50, 50));

        gridLayout_2->addWidget(btnEqual, 5, 2, 1, 1);

        btnNum0 = new QPushButton(gridLayoutWidget);
        btnNum0->setObjectName(QStringLiteral("btnNum0"));
        btnNum0->setMaximumSize(QSize(50, 50));

        gridLayout_2->addWidget(btnNum0, 5, 0, 1, 1);

        btnAddition = new QPushButton(gridLayoutWidget);
        btnAddition->setObjectName(QStringLiteral("btnAddition"));
        btnAddition->setMaximumSize(QSize(50, 50));

        gridLayout_2->addWidget(btnAddition, 5, 3, 1, 1);

        btnRightBracket = new QPushButton(gridLayoutWidget);
        btnRightBracket->setObjectName(QStringLiteral("btnRightBracket"));
        btnRightBracket->setMaximumSize(QSize(50, 50));

        gridLayout_2->addWidget(btnRightBracket, 1, 1, 1, 1);

        btnNum4 = new QPushButton(gridLayoutWidget);
        btnNum4->setObjectName(QStringLiteral("btnNum4"));
        btnNum4->setMaximumSize(QSize(50, 50));

        gridLayout_2->addWidget(btnNum4, 3, 0, 1, 1);

        btnNum7 = new QPushButton(gridLayoutWidget);
        btnNum7->setObjectName(QStringLiteral("btnNum7"));
        btnNum7->setMaximumSize(QSize(50, 50));

        gridLayout_2->addWidget(btnNum7, 2, 0, 1, 1);

        btnNum3 = new QPushButton(gridLayoutWidget);
        btnNum3->setObjectName(QStringLiteral("btnNum3"));
        btnNum3->setMaximumSize(QSize(50, 50));

        gridLayout_2->addWidget(btnNum3, 4, 2, 1, 1);

        btnNum6 = new QPushButton(gridLayoutWidget);
        btnNum6->setObjectName(QStringLiteral("btnNum6"));
        btnNum6->setMaximumSize(QSize(50, 50));

        gridLayout_2->addWidget(btnNum6, 3, 2, 1, 1);

        btnNum9 = new QPushButton(gridLayoutWidget);
        btnNum9->setObjectName(QStringLiteral("btnNum9"));
        btnNum9->setMaximumSize(QSize(50, 50));

        gridLayout_2->addWidget(btnNum9, 2, 2, 1, 1);

        btnNum2 = new QPushButton(gridLayoutWidget);
        btnNum2->setObjectName(QStringLiteral("btnNum2"));
        btnNum2->setMaximumSize(QSize(50, 50));

        gridLayout_2->addWidget(btnNum2, 4, 1, 1, 1);

        btnNum1 = new QPushButton(gridLayoutWidget);
        btnNum1->setObjectName(QStringLiteral("btnNum1"));
        btnNum1->setMaximumSize(QSize(50, 50));

        gridLayout_2->addWidget(btnNum1, 4, 0, 1, 1);

        btnLeftBracket = new QPushButton(gridLayoutWidget);
        btnLeftBracket->setObjectName(QStringLiteral("btnLeftBracket"));
        btnLeftBracket->setMaximumSize(QSize(50, 50));

        gridLayout_2->addWidget(btnLeftBracket, 1, 0, 1, 1);

        btnNum8 = new QPushButton(gridLayoutWidget);
        btnNum8->setObjectName(QStringLiteral("btnNum8"));
        btnNum8->setMaximumSize(QSize(50, 50));

        gridLayout_2->addWidget(btnNum8, 2, 1, 1, 1);

        btnNum5 = new QPushButton(gridLayoutWidget);
        btnNum5->setObjectName(QStringLiteral("btnNum5"));
        btnNum5->setMaximumSize(QSize(50, 50));

        gridLayout_2->addWidget(btnNum5, 3, 1, 1, 1);

        btnClear = new QPushButton(gridLayoutWidget);
        btnClear->setObjectName(QStringLiteral("btnClear"));
        btnClear->setMaximumSize(QSize(50, 50));

        gridLayout_2->addWidget(btnClear, 1, 2, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 10, 241, 41));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Caslon Pro Bold"));
        font.setPointSize(19);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 260, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\350\256\241\347\256\227\345\231\250", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About...", 0));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\344\270\200\344\270\252\347\225\214\351\235\242\344\270\215\345\244\252\347\276\216\350\247\202\347\204\266\350\200\214\350\277\207\347\250\213\350\211\260\350\276\233\347\232\204\350\256\241\347\256\227\345\231\250_(:\320\267\343\202\235\342\210\240)_</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        btnBackSpace->setText(QApplication::translate("MainWindow", "\342\206\220", 0));
        btnDivision->setText(QApplication::translate("MainWindow", "\303\267", 0));
        btnMultiplication->setText(QApplication::translate("MainWindow", "\303\227", 0));
        btnSubtraction->setText(QApplication::translate("MainWindow", "\357\274\215", 0));
        btnPoint->setText(QApplication::translate("MainWindow", ".", 0));
        btnEqual->setText(QApplication::translate("MainWindow", "\357\274\235", 0));
        btnNum0->setText(QApplication::translate("MainWindow", "0", 0));
        btnAddition->setText(QApplication::translate("MainWindow", "\357\274\213", 0));
        btnRightBracket->setText(QApplication::translate("MainWindow", ")", 0));
        btnNum4->setText(QApplication::translate("MainWindow", "4", 0));
        btnNum7->setText(QApplication::translate("MainWindow", "7", 0));
        btnNum3->setText(QApplication::translate("MainWindow", "3", 0));
        btnNum6->setText(QApplication::translate("MainWindow", "6", 0));
        btnNum9->setText(QApplication::translate("MainWindow", "9", 0));
        btnNum2->setText(QApplication::translate("MainWindow", "2", 0));
        btnNum1->setText(QApplication::translate("MainWindow", "1", 0));
        btnLeftBracket->setText(QApplication::translate("MainWindow", "(", 0));
        btnNum8->setText(QApplication::translate("MainWindow", "8", 0));
        btnNum5->setText(QApplication::translate("MainWindow", "5", 0));
        btnClear->setText(QApplication::translate("MainWindow", "C", 0));
        label->setText(QApplication::translate("MainWindow", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
