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
    populationCounter=0;
    cycleCounter=0;
}

void Board::generateNewBoard(unsigned short percent)
{
    clearBoard();
    for(unsigned short int i=0; i<100; i++)
    {
        for(unsigned short int j=0; j<100; j++)
        {
            if (rand()%100 < percent)
            {
                set(i,j,rand()%4+1);
                populationCounter++;
            }
        }
    }
}

void Board::analyze()
{
    OneCell temp[100][100];
    // ------------ analyzing the temp board and updating the original board
    for(unsigned short int i=0; i<100; i++)
    {
        for(unsigned short int j=0; j<100; j++)
        {
            if (get(i,j)==0)
            {
                //birth
                if (neighbors(i,j).size()==3)    //if he has exactly three neighbors then birth.
                {
                    temp[i][j].set(mostNeigbors(neighbors(i,j)));
                }
            }
            else
            {
                //dead
                if (neighbors(i,j).size()!=2 && neighbors(i,j).size()!=3) //if he has 2 or 3 he is alive
                {                                                       //if it is less than 2 and more than 3 it dies
                    temp[i][j].set(0);
                }
                else
                {
                    temp[i][j].set(get(i,j));
                }
            }
        }
    }

    // ------------ copy temp to original

    populationCounter=0;
    for(unsigned short int i=0; i<100; i++)
    {
        for(unsigned short int j=0; j<100; j++)
        {
            set(i,j,temp[i][j].get());
            if (get(i,j)) populationCounter++;
        }
    }
    cycleCounter++;
}

QVector<unsigned short int> Board::neighbors(unsigned short int i, unsigned short int j)
{
    QVector<unsigned short int> temp;
    temp.clear();

    //find 8 neigbors  - only life neigbors (status>0)
    if (i>0 && j>0) if (get(i-1,j-1)) temp.push_back(get(i-1,j-1));
    if (i>0)        if (get(i-1,j)) temp.push_back(get(i-1,j));
    if (i>0 && j<99)if (get(i-1,j+1)) temp.push_back(get(i-1,j+1));

    if (j>0)        if (get(i,j-1)) temp.push_back(get(i,j-1));
    if (j<99)       if (get(i,j+1)) temp.push_back(get(i,j+1));

    if (i<99&& j>0) if (get(i+1,j-1)) temp.push_back(get(i+1,j-1));
    if (i<99)       if (get(i+1,j)) temp.push_back(get(i+1,j));
    if (i<99&& j<99)if (get(i+1,j+1)) temp.push_back(get(i+1,j+1));
    return temp;
}

unsigned short int Board::mostNeigbors(QVector<unsigned short int> n)
{
    unsigned short int temp[5] = {0};
    for (auto iter=n.begin();iter!=n.end();iter++)
    {
        temp[*iter]++;
    }
    unsigned short int maxN=temp[1];
    unsigned short int maxL=1;              //predominat color
    unsigned short int minL=1;              //other color
    for (unsigned short int i=2;i<5;i++)
    {
        if (maxN<temp[i])
        {
            maxN=temp[i];
            maxL=i;
        }
        if (temp[i]==0)
            minL = i;           //other color that doesn't exist
    }
    if (maxN == 1)
        return minL;
    else
        return maxL;
}

unsigned int Board::getPopulationCounter()
{
    return populationCounter;
}

unsigned int Board::getCycleCounter()
{
    return cycleCounter;
}
