#include "mainwindow.h"
#include "ui_mainwindow.h"
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
    int xc,yc,r;
    xc=ui->textEdit->toPlainText().toInt();\
    yc=ui->textEdit_2->toPlainText().toInt();
    r=ui->textEdit_3->toPlainText().toInt();

    BCircle(xc,yc,r);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::BCircle(int xc, int yc, int r)
{
    int x=0,y=r;
    int p;
    p=3-(2*r);

    while(x<=y)
    {
        img.setPixel(xc+x,yc+y,qRgb(0,255,0));
        img.setPixel(xc-x,yc+y,qRgb(0,255,0));
        img.setPixel(xc+x,yc-y,qRgb(0,255,0));
        img.setPixel(xc-x,yc-y,qRgb(0,255,0));

        img.setPixel(xc+y,yc+x,qRgb(0,255,0));
        img.setPixel(xc-y,yc+x,qRgb(0,255,0));
        img.setPixel(xc+y,yc-x,qRgb(0,255,0));
        img.setPixel(xc-y,yc-x,qRgb(0,255,0));
        if(p<0)
        {
            p=p+(4*x)+6;
        }
        else
        {
            p=p+4*(x-y)+10;
            y=y-1;
        }
        x=x+1;
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    int xc,yc,r;
    xc=ui->textEdit->toPlainText().toInt();\
    yc=ui->textEdit_2->toPlainText().toInt();
    r=ui->textEdit_3->toPlainText().toInt();

    DDACircle(xc,yc,r);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::DDACircle(int xc, int yc, int r)
{
    float x1=r, y1=0;
    float sx=x1,sy=y1;

    float e=1.0/r;
    float x2,y2;
    do
    {
        x2=x1+(e*y1);
        y2=y1-(e*x2);
        img.setPixel(xc+x2,yc-y2,qRgb(255,0,0));
        x1=x2;
        y1=y2;
    }while((y1-sy)<e  || (sx-x1)>e);
}

void MainWindow::on_pushButton_3_clicked()
{
    int xc,yc,r;
    xc=ui->textEdit->toPlainText().toInt();\
    yc=ui->textEdit_2->toPlainText().toInt();
    r=ui->textEdit_3->toPlainText().toInt();

    float x1=xc;
    float y1=yc-r;

    float x2=xc-(0.8666*r);
    float y2=yc+(r/2);

    float x3=xc+(0.8666*r);
    float y3=yc+(r/2);

    DDA(x1,y1,x2,y2);
    DDA(x2,y2,x3,y3);
    DDA(x3,y3,x1,y1);

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
         img.setPixel(x,y,qRgb(0,0,255));
         ui->label->setPixmap(QPixmap::fromImage(img));
         x=x+xinc;
         y=y+yinc;
         i++;
     }
}

void MainWindow::on_pushButton_4_clicked()
{
    BCircle(200,200,100);

    DDACircle(200,200,50);

    DDA(200,100,113.34,250);
    DDA(113.34,250,286.66,250);
    DDA(286.66,250,200,100);
}
