#ifndef FILEIO_H
#define FILEIO_H

#include <QDialog>

namespace Ui {
class fileio;
}

class fileio : public QDialog
{
    Q_OBJECT

public:
    explicit fileio(QWidget *parent = 0);
    ~fileio();

private:
    Ui::fileio *ui;
    QString fileInName;
    QString fileOutName;

public slots:
    void openFileInView();
    void openFileOutView();
    void ioRun();
};

#endif // FILEIO_H
