#include "fileio.h"
#include "Print.h"
#include "Scan.h"
#include "Calculation.h"
#include "ui_fileio.h"
#include <fstream>
#include<QFileDialog>
#include<iostream>
#include<cstdio>
using namespace std;

fileio::fileio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fileio)
{
    ui->setupUi(this);

    connect(ui->inTool,SIGNAL(clicked()),this,SLOT(openFileInView()));
    connect(ui->outTool,SIGNAL(clicked()),this,SLOT(openFileOutView()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(ioRun()));
//    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(exec()));
}

fileio::~fileio()
{
    delete ui;
}

void fileio::openFileInView()
{
    fileInName =QFileDialog::getOpenFileName(this,
                    tr("open file"), "", tr("Allfile(*.*)"));
    ui->inShow->setText(fileInName);
}

void fileio::openFileOutView()
{
    QString fileOutName = QFileDialog::getSaveFileName(this,
            tr("Open Config"),
            "",
            tr(""));

    ui->outShow->setText(fileOutName);
}

void fileio::ioRun()
{

    string in = fileInName.toStdString();
    string out = fileOutName.toStdString();
    if(fileInName.length()!=0&&fileOutName.length()!=0)
    {
        Scan scan;
        freopen(in.c_str(),"r",stdin);
        freopen(out.c_str(),"w",stdout);
        string s;
        while(cin>>s)
        {
            queue<string> q = scan.ToStringQueue(s);
            Calculation calculation(q);
            calculation.trans(q);
            cout<<calculation.calcu()<<endl;
         }
     }
    this->exec();
}
