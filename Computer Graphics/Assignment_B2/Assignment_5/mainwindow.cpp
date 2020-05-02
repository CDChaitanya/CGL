#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include "QColorDialog"

QColor color;
QImage img(500,500,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    i=0;
    start=true;             // INITIALIZING
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(start)
    {
        int p=ev->pos().x();
        int q=ev->pos().y();
        a[i]=p;
        b[i]=q;
        if(ev->button() == Qt::RightButton)
        {
            DDA(a[i],b[i],a[0],b[0]);
            start=false;
        }
        else
        {
            if(i>0)
            {
                DDA(a[i],b[i],a[i-1],b[i-1]);
            }
        }
        i++;
    }
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
        img.setPixel(x,y,color.rgb());          // slight change
        ui->label->setPixmap(QPixmap::fromImage(img));
        x=x+xinc;
        y=y+yinc;
        i++;
    }
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *ev)
{
    int p=ev->pos().x();
    int q=ev->pos().y();\

    QRgb bg=qRgb(0,0,0);
    seed_fill(p,q,bg);
    ui->label->setPixmap(QPixmap::fromImage(img)); // IMPORTANAT
}

void MainWindow::seed_fill(int p, int q, QRgb bg)
{
    QRgb current = img.pixel(p,q);
    if(bg == current)
    {
        img.setPixel(p,q,color.rgb());  // SINGLE PIXEL

        seed_fill(p+1,q,bg);
        seed_fill(p-1,q,bg);
        seed_fill(p,q+1,bg);
        seed_fill(p,q-1,bg);
    }
}

void MainWindow::on_pushButton_clicked()
{
    color=QColorDialog::getColor();
}

MainWindow::~MainWindow()
{
    delete ui;
}


