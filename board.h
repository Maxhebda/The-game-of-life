#ifndef BOARD_H
#define BOARD_H

#include "onecell.h"

class Board
{
public:
    Board();
    void set(unsigned short int i, unsigned short int j, unsigned short int state);
    unsigned short int get(unsigned short int i, unsigned short j);
    void clearBoard();
    void generateNewBoard(unsigned short int percent);

private:
    OneCell cell[100][100];
};

#endif // BOARD_H
