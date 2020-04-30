#include "gameobjects.h"

struct MyData
{
    QString name;
    unsigned short int * wsk;
    unsigned short int x;
    unsigned short int y;
};
MyData myObject[10];

//-----------------------------------------------------------------------------
unsigned short int oBlinker[]={0,1,0,
                               0,1,0,
                               0,1,0};

unsigned short int oClock[]={0,0,1,0,
                             1,3,0,0,
                             0,0,3,1,
                             0,1,0,0};

unsigned short int oOnly5cell[]={0,1,1,
                                 4,3,0,
                                 0,2,0};

unsigned short int oToad[]= {0,0,1,1,1,0,0,0,2,2,2,0,0,
                             0,0,0,0,0,0,0,0,0,0,0,0,0,
                             1,0,0,0,0,1,0,2,0,0,0,0,2,
                             1,0,0,0,0,1,0,2,0,0,0,0,2,
                             1,0,0,0,0,1,0,2,0,0,0,0,2,
                             0,0,1,1,1,0,0,0,2,2,2,0,0,
                             0,0,0,0,0,0,0,0,0,0,0,0,0,
                             0,0,3,3,3,0,0,0,4,4,4,0,0,
                             3,0,0,0,0,3,0,4,0,0,0,0,4,
                             3,0,0,0,0,3,0,4,0,0,0,0,4,
                             3,0,0,0,0,3,0,4,0,0,0,0,4,
                             0,0,0,0,0,0,0,0,0,0,0,0,0,
                             0,0,3,3,3,0,0,0,4,4,4,0,0};

unsigned short int oPentadecathlon[]= {0,0,4,0,0,0,0,4,0,0,
                                       2,1,0,1,1,3,3,0,3,2,
                                       0,0,4,0,0,0,0,4,0,0};
//-----------------------------------------------------------------------------
GameObjects::GameObjects()
{
    oCounter=5;
    unsigned short int nr=0;

    myObject[nr].x=3;
    myObject[nr].y=3;
    myObject[nr].name="Blinker";
    myObject[nr].wsk=oBlinker;
    nr++;

    myObject[nr].x=4;
    myObject[nr].y=4;
    myObject[nr].name="Clock";
    myObject[nr].wsk=oClock;
    nr++;

    myObject[nr].x=3;
    myObject[nr].y=3;
    myObject[nr].name="Only 5 cell";
    myObject[nr].wsk=oOnly5cell;
    nr++;

    myObject[nr].x=10;
    myObject[nr].y=3;
    myObject[nr].name="Pentadecathlon";
    myObject[nr].wsk=oPentadecathlon;
    nr++;

    myObject[nr].x=13;
    myObject[nr].y=13;
    myObject[nr].name="Toad";
    myObject[nr].wsk=oToad;
    nr++;
}

unsigned short int GameObjects::ox(unsigned short int nr)
{
    return myObject[nr].x;
}

unsigned short int * GameObjects::oarray(unsigned short int nr)
{
    return myObject[nr].wsk;
}

unsigned short int GameObjects::oy(unsigned short int nr)
{
    return myObject[nr].y;
}

QString GameObjects::oname(unsigned short int nr)
{
    return myObject[nr].name;
}

unsigned short int GameObjects::onr(QString name)
{
    for (unsigned short int nr=0 ; nr< oCounter ; nr++)
    {
        if (oname(nr)==name) return nr;
    }
    return 0;
}
