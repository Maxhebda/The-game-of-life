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
    unsigned int getPopulationCounter();
    unsigned int getCycleCounter();
    unsigned short int mostNeigbors(QVector<unsigned short int>);
    QVector<unsigned short int> neighbors(unsigned short int i, unsigned short int j);
    void loadObject(unsigned short int i, unsigned short int j, unsigned short int y, unsigned short x, unsigned short int *);  //x,y - size object

private:
    OneCell cell[100][100];
    unsigned int populationCounter;
    unsigned int cycleCounter;
};

#endif // BOARD_H
