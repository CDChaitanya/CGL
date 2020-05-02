#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
QImage img(401,401,QImage::Format_RGB888);

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
         img.setPixel(x,y,qRgb(0,255,0));
         ui->label->setPixmap(QPixmap::fromImage(img));
         x=x+xinc;
         y=y+yinc;
         i++;
     }
}
void MainWindow::multi(int a[2][3],int t[3][3])
{
    int ans[2][3];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            ans[i][j]=0;
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                ans[i][j]=ans[i][j]+a[i][k]*t[k][j];
            }
        }
    }
    DDA(ans[0][0]+200,ans[0][1]+200,ans[1][0]+200,ans[1][1]+200);
}

void MainWindow::on_pushButton_clicked()
{
    DDA(200,0,200,400);
    DDA(0,200,400,200);
    int x1,x2,y1,y2,tx,ty;
    x1=ui->textEdit->toPlainText().toInt();\
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    tx=ui->textEdit_5->toPlainText().toInt();
    ty=ui->textEdit_6->toPlainText().toInt();

    DDA(x1+200,y1+200,x2+200,y2+200);
    int a[2][3]={x1,y1,1,
                 x2,y2,1};
    int t[3][3]={1,0,0,
                 0,1,0,
                 tx,ty,1};
    multi(a,t);

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_3_clicked()
{
    DDA(200,0,200,400);
    DDA(0,200,400,200);
    int x1,x2,y1,y2,sx,sy;
    x1=ui->textEdit->toPlainText().toInt();\
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    sx=ui->textEdit_5->toPlainText().toInt();
    sy=ui->textEdit_6->toPlainText().toInt();

    DDA(x1+200,y1+200,x2+200,y2+200);
    int a[2][3]={x1,y1,1,
                 x2,y2,1};
    int s[3][3]={sx,0,0,
                 0,sy,0,
                 0,0,1};
    multi(a,s);

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_2_clicked()
{
    DDA(200,0,200,400);
    DDA(0,200,400,200);
    int x1,x2,y1,y2;
    double ang,angle;
    x1=ui->textEdit->toPlainText().toInt();\
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    ang=ui->textEdit_7->toPlainText().toDouble();
    angle=0.017455556*ang;

    DDA(x1+200,y1+200,x2+200,y2+200);
    double a[2][3]={x1,y1,1,
                 x2,y2,1};
    double r[3][3]={cos(angle),sin(angle),0,
                 -sin(angle),cos(angle),0,
                 0,0,1};
    double ans[2][3];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            ans[i][j]=0;
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                ans[i][j]=ans[i][j]+a[i][k]*r[k][j];
            }
        }
    }
    DDA(ans[0][0]+200,ans[0][1]+200,ans[1][0]+200,ans[1][1]+200);

    ui->label->setPixmap(QPixmap::fromImage(img));
}
