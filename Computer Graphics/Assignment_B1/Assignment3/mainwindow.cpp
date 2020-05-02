#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"math.h"
QImage img(700,700,QImage :: Format_RGB888);

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

void MainWindow::ddaSolid(int x1, int y1, int x2, int y2)
{
    float dx=x2-x1;
    float dy=y2-y1;
    float len;
    if(abs(dx)>= abs(dy))
        len=abs(dx);
    else
        len=abs(dy);

    float xinc,yinc;

    xinc=dx/len;
    yinc=dy/len;

   float  x=x1;
   float y=y1;

   int i=0;
   while(i<=len)
   {
      img.setPixel(x,y,qRgb(255,i,255-i));
      ui->label->setPixmap(QPixmap::fromImage(img));
        x=x+xinc;
        y=y+yinc;
        i++;
   }
}

void MainWindow::ddaDashed(int x1, int y1, int x2, int y2)
{
    float dx=x2-x1;
    float dy=y2-y1;
    float len;
    if(abs(dx)>= abs(dy))
        len=abs(dx);
    else
        len=abs(dy);

    float xinc,yinc;

    xinc=dx/len;
    yinc=dy/len;

   float  x=x1;
   float y=y1;
    int j=0;
   int i=0;
   while(i<=len)
   {
       if(j<5)

       {
      img.setPixel(x,y,qRgb(255,i,255-i));
      ui->label->setPixmap(QPixmap::fromImage(img));
       }
      x=x+xinc;
      y=y+yinc;
       i++;
       j++;
       j=j%10;
   }
}

void MainWindow::ddaDotted(int x1, int y1, int x2, int y2)
{
    float dx=x2-x1;
    float dy=y2-y1;
    float len;
    if(abs(dx)>= abs(dy))
        len=abs(dx);
    else
        len=abs(dy);

    float xinc,yinc;

    xinc=dx/len;
    yinc=dy/len;

   float  x=x1;
   float y=y1;

   int i=0;
   while(i<=len)
   {
       if(i%5==0)
       {
      img.setPixel(x,y,qRgb(255,i,255-i));
      ui->label->setPixmap(QPixmap::fromImage(img));
       }
        x=x+xinc;
        y=y+yinc;
        i++;

   }
}

void MainWindow::ddaDash_Dot(int x1, int y1, int x2, int y2)
{
    float dx=x2-x1;
    float dy=y2-y1;
    float len;
    if(abs(dx)>= abs(dy))
        len=abs(dx);
    else
        len=abs(dy);

    float xinc,yinc;

    xinc=dx/len;
    yinc=dy/len;

   float  x=x1;
   float y=y1;
    int j=0;
   int i=0;
   while(i<=len)
   {
       if(j<=10)
       {
      img.setPixel(x,y,qRgb(255,i,255-i));
      ui->label->setPixmap(QPixmap::fromImage(img));
       }
       if(j==15)
       {
         img.setPixel(x,y,qRgb(255,i,255-i));
         ui->label->setPixmap(QPixmap::fromImage(img));
       }
        x=x+xinc;
        y=y+yinc;
        i++;
        j++;
        j=j%20;
   }
}

void MainWindow::ddaThick(int x1, int y1, int x2, int y2,int w)
{

    float dy2=(y2-y1)*(y2-y1);
    float dx2=(x2-x1)*(x2-x1);
    int absx=abs(x2-x1);
    int absy=abs(y2-y1);
    float num=sqrt(dy2+dx2);
    float wy,wx;
        if((y2-y1)<(x2-x1))
        {
            wy=(w-1)/2;
            wy=wy*(num/absx);
            for(int i=0;i<wy;i++)
            {
            ddaSolid(x1,y1+i,x2,y2+i);
            ddaSolid(x1,y1-i,x2,y2-i);
            }
        }
        else
        {
            wx=(w-1)/2;
            wx=wx*(num/absy);
            for(int i=0;i<wx;i++)
            {
                ddaSolid(x1+i,y1,x2+i,y2);
                ddaSolid(x1-i,y1,x2-i,y2);
            }

        }

}
void MainWindow::on_pushButton_4_clicked()
{
    int x1,y1,x2,y2;

    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();

    ddaSolid(x1,y1,x2,y2);
ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::on_pushButton_clicked()
{
    int x1,y1,x2,y2;

    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();

    ddaDashed(x1,y1,x2,y2);
ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_2_clicked()
{
    int x1,y1,x2,y2;

    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();

    ddaDotted(x1,y1,x2,y2);
ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_3_clicked()
{
    int x1,y1,x2,y2;

    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();

    ddaDash_Dot(x1,y1,x2,y2);
ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_5_clicked()
{
    int x1,y1,x2,y2,w;

    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    w=ui->textEdit_5->toPlainText().toInt();
    ddaThick(x1,y1,x2,y2,w);
ui->label->setPixmap(QPixmap::fromImage(img));

}
