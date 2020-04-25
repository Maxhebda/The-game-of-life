#include "board.h"
#include <cstdlib>
#include <ctime>
#include <QVector>

Board::Board()
{
    srand(time(NULL));
    clearBoard();
}

Board::Board(Board & b)
{
    for(unsigned short int i=0; i<100; i++)
    {
        for(unsigned short int j=0; j<100; j++)
        {
            set(i,j,b.get(i,j));                        //copy status
        }
    }
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
            set(i,j,0); //all dead
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
            set(i,j,1);                                             //only blue
        }
    }
}

void Board::analyze()
{
    // ------------ copy oryginal board
    OneCell temp[100][100];
    for(unsigned short int i=0; i<100; i++)
    {
        for(unsigned short int j=0; j<100; j++)
        {
            temp[i][j].set(get(i,j));
        }
    }

    // ------------ analyzing the temp board and updating the original board
    QVector <unsigned short int> tempNeighbors;
    for(unsigned short int i=0; i<100; i++)
    {
        for(unsigned short int j=0; j<100; j++)
        {
            tempNeighbors = neighbors(i,j);     //find neighbors
            if (temp[i][j].get()==0)
            {
                //birth

            }
            else
            {
                //dead

            }
        }
    }
}

QVector<unsigned short int> Board::neighbors(unsigned short int i, unsigned short int j)
{
    QVector<unsigned short int> temp;
    temp.clear();

    return temp;
}
