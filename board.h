#ifndef BOARD_H
#define BOARD_H

#include "onecell.h"
#include <QVector>

class Board
{
public:
    Board();
    Board(Board &);
    void set(unsigned short int i, unsigned short int j, unsigned short int state);
    unsigned short int get(unsigned short int i, unsigned short j);
    void clearBoard();
    void generateNewBoard(unsigned short int percent);
    void analyze();
    unsigned short int mostNeigbors(QVector<unsigned short int>);
    QVector<unsigned short int> neighbors(unsigned short int i, unsigned short int j);
private:
    OneCell cell[100][100];
};

#endif // BOARD_H
