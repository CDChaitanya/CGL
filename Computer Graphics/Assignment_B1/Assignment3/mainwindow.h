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
    ~MainWindow();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    void ddaSolid(int x1,int y1, int x2, int y2);
    void ddaDashed(int x1,int y1, int x2, int y2);
    void ddaDotted(int x1,int y1, int x2, int y2);
    void ddaDash_Dot(int x1,int y1, int x2, int y2);
    void ddaThick(int x1,int y1, int x2, int y2,int w);
};

#endif // MAINWINDOW_H
