#include "board.h"
#include <cstdlib>
#include <ctime>

Board::Board()
{
    srand(time(NULL));
    clearBoard();
}

void Board::set(unsigned short i, unsigned short j, unsigned short state)
{
    cell[i][j].set(state);
}

unsigned short int Board::get(unsigned short i, unsigned short j)
{
    return cell[i][j].get();
}

void Board::clearBoard()
{
    for(unsigned short int i=0; i<100; i++)
    {
        for(unsigned short int j=0; j<100; j++)
        {
            set(i,j,0);
        }
    }
}

void Board::generateNewBoard(unsigned short percent)
{
    clearBoard();
    for(unsigned short int i=0; i<100; i++)
    {
        for(unsigned short int j=0; j<100; j++)
        {
            if (rand()%100 < percent)
            set(i,j,1);
        }
    }
}
