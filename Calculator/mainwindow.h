#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *);

private:
    Ui::MainWindow *ui;
    QLabel *bar;
    QString inputStr;
    bool isEmpty;

public slots:
    void showMessage(const QString & message, int timeOut);
    void openDialog();
    void openFileio();

    void clear();
    void backSpaceClicked();
    void input();
    void displayNumber();
    void decimalPointClicked();
    void equalClicked();


};

#endif // MAINWINDOW_H
