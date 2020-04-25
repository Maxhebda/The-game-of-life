#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
//    rect = scene->addRect(0,0,50,67);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
    rect = scene->addRect(0, 0, 500, 500, QPen(Qt::white), QBrush(Qt::white));

    QBrush blueCell(Qt::blue);
    QPen bluePen(Qt::blue);
    for (int i=0;i<100;i++)
    {
        for (int j=0;j<100;j++)
        {
            if (rand()%100<ui->spinBox->value())
            {
                rect = scene->addRect(1+i*5, 1+j*5, 3, 3, bluePen, blueCell);
            }
        }
    }
}

