#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QVariant"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&timer,SIGNAL(timeout()),this, SLOT(step()));
    timer.setInterval(20);
//    timer.setSingleShot(false);
    Board myBoard;
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    loadComboItems();
}

void MainWindow::loadComboItems()
{
    for (unsigned short int a=0 ; a<myObjects.oCounter ; a++)
    {
        ui->comboBox->addItem(myObjects.oname(a));
    }
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
            else
            {
                rect = scene->addRect(1+j*5,1+i*5, 3, 3, QPen(Qt::white), QBrush(Qt::white));
            }
        }
    }
}

void MainWindow::clearBoard()
{
    rect = scene->addRect(0, 0, 500, 500, QPen(Qt::white), QBrush(Qt::white));
    scene->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()          // generate life
{
    ui->spinBox->setEnabled(0);
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
    ui->comboBox->setEnabled(1);
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
    ui->comboBox->setEnabled(0);
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
    ui->comboBox->setEnabled(1);
    timer.stop();
}

void MainWindow::step()
{
    myBoard.analyze();
    showBoard();
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    myBoard.clearBoard();
    unsigned short int nr = myObjects.onr(arg1);
    myBoard.loadObject((100-myObjects.oy(nr))/2, (100-myObjects.ox(nr))/2, myObjects.oy(nr), myObjects.ox(nr), myObjects.oarray(nr));

    showBoard();
    ui->spinBox->setEnabled(1);
    ui->pushButton->setEnabled(1);
    ui->pushButton_2->setEnabled(1);
    ui->pushButton_3->setEnabled(1);
    ui->pushButton_5->setEnabled(1);
    ui->pushButton_4->setEnabled(0);
}
