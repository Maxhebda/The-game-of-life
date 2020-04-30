#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "board.h"
#include "QTimer"
#include "gameobjects.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showBoard();
    void clearBoard();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void step();

    void on_comboBox_activated(const QString &arg1);

protected:
    Ui::MainWindow *ui;

private:
    QGraphicsScene *scene;
    QGraphicsRectItem *rect;
    Board myBoard;
    QTimer timer;
    GameObjects myObjects;
    void loadComboItems();
};
#endif // MAINWINDOW_H
