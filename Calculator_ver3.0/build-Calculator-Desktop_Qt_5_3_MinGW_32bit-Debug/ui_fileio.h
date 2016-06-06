/********************************************************************************
** Form generated from reading UI file 'fileio.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEIO_H
#define UI_FILEIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fileio
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QFrame *line;
    QToolButton *outTool;
    QPushButton *pushButton;
    QLabel *inText;
    QLineEdit *outShow;
    QLineEdit *inShow;
    QToolButton *inTool;
    QLabel *outText;
    QLabel *outFile;

    void setupUi(QDialog *fileio)
    {
        if (fileio->objectName().isEmpty())
            fileio->setObjectName(QStringLiteral("fileio"));
        fileio->resize(400, 300);
        gridLayoutWidget = new QWidget(fileio);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 381, 281));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        line = new QFrame(gridLayoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 2, 0, 1, 2);

        outTool = new QToolButton(gridLayoutWidget);
        outTool->setObjectName(QStringLiteral("outTool"));

        gridLayout->addWidget(outTool, 4, 1, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 6, 0, 1, 2);

        inText = new QLabel(gridLayoutWidget);
        inText->setObjectName(QStringLiteral("inText"));

        gridLayout->addWidget(inText, 0, 0, 1, 1);

        outShow = new QLineEdit(gridLayoutWidget);
        outShow->setObjectName(QStringLiteral("outShow"));

        gridLayout->addWidget(outShow, 4, 0, 1, 1);

        inShow = new QLineEdit(gridLayoutWidget);
        inShow->setObjectName(QStringLiteral("inShow"));

        gridLayout->addWidget(inShow, 1, 0, 1, 1);

        inTool = new QToolButton(gridLayoutWidget);
        inTool->setObjectName(QStringLiteral("inTool"));

        gridLayout->addWidget(inTool, 1, 1, 1, 1);

        outText = new QLabel(gridLayoutWidget);
        outText->setObjectName(QStringLiteral("outText"));

        gridLayout->addWidget(outText, 3, 0, 1, 1);

        outFile = new QLabel(gridLayoutWidget);
        outFile->setObjectName(QStringLiteral("outFile"));

        gridLayout->addWidget(outFile, 5, 0, 1, 1);


        retranslateUi(fileio);

        QMetaObject::connectSlotsByName(fileio);
    } // setupUi

    void retranslateUi(QDialog *fileio)
    {
        fileio->setWindowTitle(QApplication::translate("fileio", "Dialog", 0));
        outTool->setText(QApplication::translate("fileio", "...", 0));
        pushButton->setText(QApplication::translate("fileio", "OK", 0));
        inText->setText(QApplication::translate("fileio", "\350\257\273\345\205\245\346\226\207\344\273\266\357\274\232", 0));
        inTool->setText(QApplication::translate("fileio", "...", 0));
        outText->setText(QApplication::translate("fileio", "\350\276\223\345\207\272\345\210\260\346\226\207\344\273\266\357\274\232", 0));
        outFile->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class fileio: public Ui_fileio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEIO_H
