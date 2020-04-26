#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QVariant"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&timer,SIGNAL(timeout()),this, SLOT(step()));
    timer.setInterval(50);
//    timer.setSingleShot(false);
    Board myBoard;
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

void MainWindow::showBoard()
{
    clearBoard();
    ui->label_2->setText(QVariant(myBoard.getPopulationCounter()).toString());
    ui->label_5->setText(QVariant(myBoard.getCycleCounter()).toString());
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


void MainWindow::on_pushButton_3_clicked()          // generate life
{
    ui->pushButton->setEnabled(1);
    ui->pushButton_3->setEnabled(0);
    ui->pushButton_2->setEnabled(1);
    ui->pushButton_5->setEnabled(1);
    myBoard.generateNewBoard(ui->spinBox->value());
    showBoard();
}


void MainWindow::on_pushButton_clicked()            // reset
{
    ui->pushButton_2->setEnabled(0);
    ui->pushButton->setEnabled(0);
    ui->pushButton_5->setEnabled(0);
    ui->pushButton_4->setEnabled(0);
    ui->pushButton_3->setEnabled(1);
    myBoard.clearBoard();
    showBoard();
}

void MainWindow::on_pushButton_2_clicked()          // next cycle
{
    myBoard.analyze();
    showBoard();
}

void MainWindow::on_pushButton_5_clicked()          // start
{
    ui->spinBox->setEnabled(0);
    ui->pushButton->setEnabled(0);
    ui->pushButton_2->setEnabled(0);
    ui->pushButton_3->setEnabled(0);
    ui->pushButton_5->setEnabled(0);
    ui->pushButton_4->setEnabled(1);
    timer.start();
}

void MainWindow::on_pushButton_4_clicked()          //stop
{
    ui->spinBox->setEnabled(1);
    ui->pushButton->setEnabled(1);
    ui->pushButton_2->setEnabled(1);
    ui->pushButton_3->setEnabled(1);
    ui->pushButton_5->setEnabled(1);
    ui->pushButton_4->setEnabled(0);
    timer.stop();
}

void MainWindow::step()
{
    myBoard.analyze();
    showBoard();
}
