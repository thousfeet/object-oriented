#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "fileio.h"
#include "Scan.h"
#include "Print.h"
#include "Calculation.h"
#include<QAction>
#include<QMenuBar>
#include<QTimer>
#include<QDialog>
#include<QKeyEvent>
#include<string>
#include<QTextCodec>
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    isEmpty(true)
{
    ui->setupUi(this);
    this->setFixedSize( this->width (),this->height ());

    //菜单栏动作监听
    QAction *newAction = new QAction("About",this);
    newAction->setToolTip("About");
    newAction->setStatusTip("Calculator ver3.0");

    QAction *newAction_2 = new QAction("文件输入",this);
    newAction_2->setToolTip("文件输入");


    QMenu *newMenu = menuBar()->addMenu("关于");
    newMenu->addAction(newAction);

    QMenu *newMenu_2 = menuBar()->addMenu("开始");
    newMenu_2->addAction(newAction_2);

    connect(newAction,SIGNAL(triggered(bool)),this,SLOT(openDialog()));
    connect(newAction_2,SIGNAL(triggered(bool)),this,SLOT(openFileio()));

    //状态栏显示
    bar = new QLabel("bar");
    statusBar()->addWidget(bar,1);
    bar->show();
    showMessage("Welcome...",2000);

    //按钮操作
    connect(ui->btnClear,SIGNAL(clicked(bool)),this,SLOT(clear()));
    connect(ui->btnBackSpace,SIGNAL(clicked(bool)),this,SLOT(backSpaceClicked()));
    connect(ui->btnPoint,SIGNAL(clicked(bool)),this,SLOT(decimalPointClicked()));
    connect(ui->btnEqual,SIGNAL(clicked(bool)),this,SLOT(equalClicked()));

    connect(ui->btnAddition,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->btnSubtraction,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->btnMultiplication,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->btnDivision,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->btnLeftBracket,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->btnRightBracket,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->btnNum0,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->btnNum1,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->btnNum2,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->btnNum3,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->btnNum4,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->btnNum5,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->btnNum6,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->btnNum7,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->btnNum8,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->btnNum9,SIGNAL(clicked(bool)),this,SLOT(input()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::showMessage(const QString &message, int timeOut)
{
    bar->setText(message);
    QTimer *timer = new QTimer;
    timer->singleShot(timeOut,bar,SLOT(clear()));
}

void MainWindow::openDialog()
{
    Dialog dialog;
    dialog.exec();
}

void MainWindow::openFileio()
{
    fileio file;
    file.exec();
}

void MainWindow::clear()
{
    inputStr= "0";
    isEmpty = true;
    displayNumber();
}

void MainWindow::backSpaceClicked()
{
    if(inputStr.length() == 1)
        isEmpty = true;
    else
        inputStr = inputStr.left(inputStr.length()-1);
    displayNumber();
}

void MainWindow::input()
{
    QPushButton *currentButton = qobject_cast<QPushButton *>(this->sender());

    if(currentButton)
    {
        //非清空状态
        if(!isEmpty)
        {
            if(currentButton == ui->btnAddition)
            {
                inputStr.append('+');
            }
            else if(currentButton == ui-> btnSubtraction)
            {
                inputStr.append('-');
            }
            else if(currentButton == ui->btnMultiplication)
            {
                inputStr.append('*');
            }
            else if(currentButton == ui->btnDivision)
            {
                inputStr.append('/');
            }
            else
            {
                inputStr.append(currentButton->text());
            }
        }
        //清空状态
        else
        {
            isEmpty = false;
            if(currentButton == ui->btnAddition)
            {
                inputStr.append('+');
            }
            else if(currentButton == ui-> btnSubtraction)
            {
                inputStr.append('-');
            }
            else if(currentButton == ui->btnMultiplication)
            {
                inputStr.append('*');
            }
            else if(currentButton == ui->btnDivision)
            {
                inputStr.append('/');
            }
            else
            {
                inputStr = currentButton->text();
            }
        }
    }
    displayNumber();
}

void MainWindow::displayNumber()
{
    if(isEmpty)
        ui->label->setText("0");
    else
    {
        QString str="";
        for(int i =0; i <inputStr.length();i++)
        {

            if(inputStr[i] == '*')
            {
                str+="×";
            }
            else if(inputStr[i] == '/')
            {
                str+="÷";
            }
            else
            {
                str.append(inputStr[i]);
            }
        }
        ui->label->setText(str);
    }
}

void MainWindow::decimalPointClicked()
{
    if(isEmpty)
        inputStr+="0.";
    else
        inputStr+=".";

    displayNumber();
}

void MainWindow::equalClicked()
{
    if(!isEmpty)
    {
        string newInput = inputStr.toStdString();

        //计算开始
        Scan scan;
        queue<string> q = scan.ToStringQueue(newInput);
        Calculation calculation(q);
        calculation.trans(q);
        QString outputStr = QString::number(calculation.calcu(),'g',6);
        ui->label->setText(outputStr);

        inputStr = "";
        isEmpty = true;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    isEmpty = false;
    if(e->key()== Qt::Key_0||e->key()== Qt::Key_1||e->key()== Qt::Key_2||e->key()== Qt::Key_3||e->key()== Qt::Key_4||e->key()== Qt::Key_5||
            e->key()== Qt::Key_6||e->key()== Qt::Key_7||e->key()== Qt::Key_8||e->key()== Qt::Key_9||e->key()==Qt::Key_ParenLeft||e->key()==Qt::Key_ParenRight
            ||e->key()==Qt::Key_Plus||e->key()==Qt::Key_Minus||e->key()==Qt::Key_Asterisk||e->key()==Qt::Key_Slash)
    {
        inputStr+=e->text();
        displayNumber();
    }
    else if(e->key() == Qt::Key_Period)
    {
        decimalPointClicked();
    }
    else if(e->key() == Qt::Key_Backspace)
    {
        backSpaceClicked();
    }
    else if(e->key() == Qt::Key_Escape)
    {
        clear();
    }
    else if(e->key() == Qt::Key_Enter ||e->key() == Qt::Key_Return)
    {
        equalClicked();
    }


}
