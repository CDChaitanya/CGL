#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include "math.h"
QImage img(400,400,QImage::Format_RGB888);
QImage img1(400,400,QImage::Format_RGB888);
QRgb new_c=qRgb(120,120,125);
QRgb border=qRgb(255,0,0);
QRgb white=qRgb(255,255,255);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRgb val=qRgb(255,255,255);
    bres_line(0,200,400,200,val,0);
    bres_line(200,0,200,400,val,0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QRgb val=qRgb(0,255,255);
    bres_line(-100+200,-100+200,100+200,-100+200,val,0);
     bres_line(-100+200,-50+200,100+200,-50+200,val,0);
      bres_line(-100+200,200,100+200,200,val,0);
       bres_line(-100+200,100+200,100+200,100+200,val,0);
        bres_line(-100+200,50+200,100+200,50+200,val,0);
        bres_line(-100+200,-100+200,-100+200,100+200,val,0);
         bres_line(-50+200,-100+200,-50+200,100+200,val,0);
         bres_line(200,-100+200,200,100+200,val,0);
         bres_line(50+200,-100+200,50+200,100+200,val,0);
         bres_line(100+200,-100+200,100+200,100+200,val,0);

}

void MainWindow::on_pushButton_2_clicked()
{
   bres_line(0,200,400,200,qRgb(255,255,255),1);
    bres_line(200,0,200,400,qRgb(255,255,255),1);
    //...vertical lines
    rotate(-100,100,-100,-100);
    rotate(-50,100,-50,-100);
    rotate(0,100,0,-100);
    rotate(50,100,50,-100);
    rotate(100,100,100,-100);

    //...horizontal lines
    rotate(-100,100,100,100);
    rotate(-100,50,100,50);
    rotate(-100,0,100,0);
    rotate(-100,-50,100,-50);
    rotate(-100,-100,100,-100);

}
int MainWindow::sign(int p)
{
    if(p<0)
        return -1;
    else
        return 1;
}
void MainWindow::bres_line(int x1, int y1, int x2, int y2,QRgb val,int im)
{
    int dx,dy,x,y,dp,i=0;


    dx=abs(x2-x1);
    dy=abs(y2-y1);

    x=x1;
    y=y1;

    if(dx>=dy)
    {
        dp=2*dy-dx;
        i=0;
        while(i<dx)
        {
            if(im==0)
                img.setPixel(x,y,val);
            else
                 img1.setPixel(x,y,val);
            if(dp<0)
                dp+=2*dy;
            else
            {
                dp+=2*dy-2*dx;

                y=y+sign(y2-y1);
            }
            x=x+sign(x2-x1);
            i++;
        }
    }
    else
    {
        dp=2*dx-dy;
        while(i<dy)
        {
            if(im==0)
                img.setPixel(x,y,val);
            else
                 img1.setPixel(x,y,val);
            if(dp<0)
                dp+=(2*dx);
            else
            {
                dp+=(2*dx-2*dy);

                 x=x+sign(x2-x1);
         }
            y=y+sign(y2-y1);
            i++;
        }
    }
    if(im==0)
        img.setPixel(x,y,val);
    else
         img1.setPixel(x,y,val);
    if(im==0)
    ui->label->setPixmap(QPixmap::fromImage(img));
    if(im==1)
          ui->label->setPixmap(QPixmap::fromImage(img1));

}
void MainWindow::mouseDoubleClickEvent(QMouseEvent *ev)
{
    int p,q;
    p=ev->pos().x();
    q=ev->pos().y();
    seed_fill(p,q);
}
void MainWindow::rotate(int x1,int y1,int x2,int y2)
{
    float angle=45;
    angle=angle*3.14/180;
    QRgb val=qRgb(255,0,0);
    int i=1;
    int p[2][3]={{x1,y1,1},{x2,y2,1}};
    float r[3][3]={{cos(angle),-sin(angle),0},{sin(angle),cos(angle),0},{0,0,1}};
    float a[3][3]={0};
                for(int i=0;i<2;i++)
              {
                for(int j=0;j<3;j++)
                {a[i][j]=0;
                    for(int k=0;k<3;k++)
                        a[i][j]+=p[i][k]*r[k][j];
                }
                }
                bres_line(a[0][0]+200,a[0][1]+200,a[1][0]+200,a[1][1]+200,val,i);
}
void MainWindow::seed_fill(int x, int y)
{
    QRgb cur=img1.pixel(x,y);
    if(cur!=border&&cur!=new_c)
    {
        img1.setPixel(x,y,new_c);
        seed_fill(x+1,y);
        seed_fill(x,y+1);
        seed_fill(x-1,y);
        seed_fill(x,y-1);
    }
    ui->label->setPixmap(QPixmap::fromImage(img1));
}
