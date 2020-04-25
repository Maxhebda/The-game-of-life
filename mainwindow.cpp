#include "mainwindow.h"
#include "ui_mainwindow.h"

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
                rect = scene->addRect(1+i*5, 1+j*5, 3, 3, bluePen, blueCell);
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
}

void MainWindow::on_pushButton_2_clicked()
{
    myBoard.analyze();
    showBoard();
}
