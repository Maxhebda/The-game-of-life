#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QVariant"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Board myBoard;
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

void MainWindow::showBoard()
{
    QBrush blueCell(Qt::blue);
    QPen bluePen(Qt::blue);
    clearBoard();
    for(unsigned short int i=0; i<100; i++)
    {
        for(unsigned short int j=0; j<100; j++)
        {
            if (myBoard.get(i,j))
            {
                switch (myBoard.get(i,j)) {
                    case 1 : {
                        rect = scene->addRect(1+j*5,1+i*5, 3, 3, QPen(Qt::blue), QBrush(Qt::blue));
                        break;
                    }
                    case 2 : {
                        rect = scene->addRect(1+j*5,1+i*5, 3, 3, QPen(Qt::red), QBrush(Qt::red));
                        break;
                    }
                    case 3 : {
                        rect = scene->addRect(1+j*5,1+i*5, 3, 3, QPen(Qt::black), QBrush(Qt::black));
                        break;
                    }
                    case 4 : {
                        rect = scene->addRect(1+j*5,1+i*5, 3, 3, QPen(Qt::green), QBrush(Qt::green));
                        break;
                    }
                }
            }
        }
    }
}

void MainWindow::clearBoard()
{
    rect = scene->addRect(0, 0, 500, 500, QPen(Qt::white), QBrush(Qt::white));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
    myBoard.generateNewBoard(ui->spinBox->value());
    showBoard();
}


void MainWindow::on_pushButton_clicked()
{
    clearBoard();
    myBoard.clearBoard();
    myBoard.set(1,0,4);
    myBoard.set(1,1,4);
    myBoard.set(1,2,4);
    myBoard.set(0,1,3);
    myBoard.set(2,1,3);
    ui->label_5->setText( QVariant(myBoard.mostNeigbors( myBoard.neighbors(2,1))).toString());
    showBoard();
}

void MainWindow::on_pushButton_2_clicked()
{
    myBoard.analyze();
    showBoard();
}
