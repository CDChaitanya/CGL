#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void mousePressEvent(QMouseEvent *ev);
    void DDA(int,int,int,int);
    void cohen(int,int,int,int);
    int compute(int,int);

    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;

    int inside;
    int left;
    int  right;
    int  bottom;
    int  top;

    int a[20],b[20];
    int i;
    bool start;
    int xmin,xmax,ymin,ymax;
};

#endif // MAINWINDOW_H
