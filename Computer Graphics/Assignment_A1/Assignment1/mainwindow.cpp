#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
QImage img(500,500,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int x1,x2,y1,y2;
    x1=ui->textEdit->toPlainText().toInt();\
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();

    DDA(x1,y1,x2,y2);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::DDA(int x1, int y1, int x2, int y2)
{
     float dx,dy;
     dx=x2-x1;
     dy=y2-y1;
     float len;
     if(abs(dx) >= abs(dy))
     {
         len=abs(dx);
     }
     else
     {
         len=abs(dy);
     }
     float xinc,yinc;
     xinc=dx/len;
     yinc=dy/len;
     float x=x1;
     float y=y1;
     int i=0;
     while(i<=len)
     {
         img.setPixel(x,y,qRgb(255,0,0));
         ui->label->setPixmap(QPixmap::fromImage(img));
         x=x+xinc;
         y=y+yinc;
         i++;
     }
}

void MainWindow::on_pushButton_2_clicked()
{
    int x1,x2,y1,y2;
    x1=ui->textEdit->toPlainText().toInt();\
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();

    Bresenham(x1,y1,x2,y2);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

int MainWindow::Sign(int a,int b)
{
    int c=a-b;
    if(c<0)
        return -1;
    else if(c>0)
        return 1;
    else
        return 0;
}

void MainWindow::Bresenham(int x1, int y1, int x2, int y2)
{
    float dx=abs(x2-x1);
    float dy=abs(y2-y1);
    float x=x1;
    float y=y1;
    float p;
    int i=0;
    if(dx >= dy)
    {
        p=(2*dy)-dx;
        while(i<=dx)
        {
            img.setPixel(x,y,qRgb(255,255,255));
            if(p<0)
                p=p+(2*dy);
            else
            {
                p=p + 2*(dy-dx);
                y=y+1*Sign(y2,y1);
            }
            x=x+1 * Sign(x2,x1);
            i++;
        }
    }
    else
    {
        p=(2*dx)-dy;
        while(i<=dy)
        {
            img.setPixel(x,y,qRgb(255,255,255));
            if(p<0)
                p=p+(2*dx);
            else
            {
                p=p+2*(dx-dy);
                x=x+1 * Sign(x2,x1);
            }
            y=y+1 * Sign(y2,y1);
            i++;
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    DDA(50,50,50,350);
    DDA(50,50,350,50);
    DDA(50,350,350,350);
    DDA(350,50,350,350);

    Bresenham(200,50,50,200);
    Bresenham(50,200,200,350);
    Bresenham(200,350,350,200);
    Bresenham(350,200,200,50);

    DDA(125,125,125,275);
    DDA(125,275,275,275);
    DDA(275,275,275,125);
    DDA(275,125,125,125);
}
