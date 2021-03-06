#include "gameobjects.h"

struct MyData
{
    QString name;
    unsigned short int * wsk;
    unsigned short int x;
    unsigned short int y;
};
MyData myObject[21];

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

unsigned short int oDiehard[]= {0,0,0,0,0,0,4,0,
                                1,1,0,0,0,0,0,0,
                                0,1,0,0,0,3,3,3};

unsigned short int oAcorn[]=   {0,3,0,0,0,0,0,
                                0,0,0,3,0,0,0,
                                3,3,0,0,4,4,4};

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

unsigned short int oGligerGun1[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,2,0,0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,3,3,
                                  0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,3,3,
                                  3,3,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                  3,3,0,0,0,0,0,0,0,0,1,0,0,0,2,0,1,1,0,0,0,0,2,0,2,0,0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

unsigned short int oGligerGun2[]={1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                  1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,4,4,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,4,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,4,0,0,1,1,
                                  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,4,0,0,0,1,1,
                                  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0};


unsigned short int oRoad[]={1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            1,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,4,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,4,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,4,0,3,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,2,0,3,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,2,0,3,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,2,0,3,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,3,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,3,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1};

unsigned short int oFigure2[]= {1,1,1,0,1,
                                1,0,0,0,0,
                                0,0,0,3,3,
                                0,3,3,0,3,
                                3,0,3,0,3};

unsigned short int oFigure8[]= {1,1,1,0,0,0,
                                1,1,1,0,0,0,
                                1,1,1,0,0,0,
                                0,0,0,4,4,4,
                                0,0,0,4,4,4,
                                0,0,0,4,4,4};

unsigned short int oOctagon[]= {0,1,1,1,1,0,
                                1,0,4,4,0,1,
                                1,4,0,0,4,1,
                                1,4,0,0,4,1,
                                1,0,4,4,0,1,
                                0,1,1,1,1,0};

unsigned short int oMold[]=    {0,3,3,0,0,
                                3,0,0,1,0,
                                3,0,3,0,0,
                                0,1,0,4,4,
                                0,0,1,4,4,
                                0,0,0,4,4};

unsigned short int oLine[]= {1,1,1,1,1,1,1,1,0,2,2,2,2,2,0,0,0,3,3,3,0,0,0,0,0,0,2,2,2,2,2,2,2,0,1,1,1,1,1};

unsigned short int oSparkcoil[]= {1,1,0,0,0,0,1,1,
                                  2,0,1,0,0,3,0,2,
                                  0,0,1,0,0,3,0,0,
                                  2,0,1,0,0,3,0,2,
                                  1,1,0,0,0,0,1,1};

unsigned short int oBeeshuttle[]={0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                  3,3,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,3,3,
                                  3,3,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,3,3,
                                  0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0};

unsigned short int oDacota123[]={1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

                                 0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                 2,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                 0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                 2,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                 0,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

                                 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

                               0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               3,3,3,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

unsigned short int oDacota1[]={1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

unsigned short int oDacota2[]={0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               3,3,3,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

unsigned short int oDacota3[]={0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               2,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               2,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                               0,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};



//-----------------------------------------------------------------------------
GameObjects::GameObjects()
{
    unsigned short int nr=0;


    myObject[nr].x=7;
    myObject[nr].y=3;
    myObject[nr].name="Acorn";
    myObject[nr].wsk=oAcorn;
    nr++;

    myObject[nr].x=22;
    myObject[nr].y=7;
    myObject[nr].name="Bee shuttle";
    myObject[nr].wsk=oBeeshuttle;
    nr++;

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

    myObject[nr].x=65;
    myObject[nr].y=4;
    myObject[nr].name="Dacota 1";
    myObject[nr].wsk=oDacota1;
    nr++;

    myObject[nr].x=65;
    myObject[nr].y=4;
    myObject[nr].name="Dacota 2";
    myObject[nr].wsk=oDacota2;
    nr++;

    myObject[nr].x=65;
    myObject[nr].y=5;
    myObject[nr].name="Dacota 3";
    myObject[nr].wsk=oDacota3;
    nr++;

    myObject[nr].x=65;
    myObject[nr].y=25;
    myObject[nr].name="Dacota 123";
    myObject[nr].wsk=oDacota123;
    nr++;

    myObject[nr].x=8;
    myObject[nr].y=3;
    myObject[nr].name="Diehard";
    myObject[nr].wsk=oDiehard;
    nr++;

    myObject[nr].x=5;
    myObject[nr].y=5;
    myObject[nr].name="Figure 2";
    myObject[nr].wsk=oFigure2;
    nr++;

    myObject[nr].x=6;
    myObject[nr].y=6;
    myObject[nr].name="Figure 8";
    myObject[nr].wsk=oFigure8;
    nr++;

    myObject[nr].x=36;
    myObject[nr].y=9;
    myObject[nr].name="Glider Gun 1";
    myObject[nr].wsk=oGligerGun1;
    nr++;

    myObject[nr].x=33;
    myObject[nr].y=21;
    myObject[nr].name="Glider Gun 2";
    myObject[nr].wsk=oGligerGun2;
    nr++;

    myObject[nr].x=5;
    myObject[nr].y=6;
    myObject[nr].name="Mold";
    myObject[nr].wsk=oMold;
    nr++;

    myObject[nr].x=39;
    myObject[nr].y=1;
    myObject[nr].name="Line";
    myObject[nr].wsk=oLine;
    nr++;

    myObject[nr].x=6;
    myObject[nr].y=6;
    myObject[nr].name="Octagon";
    myObject[nr].wsk=oOctagon;
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

    myObject[nr].x=20;
    myObject[nr].y=20;
    myObject[nr].name="Road";
    myObject[nr].wsk=oRoad;
    nr++;

    myObject[nr].x=8;
    myObject[nr].y=5;
    myObject[nr].name="Spark coil";
    myObject[nr].wsk=oSparkcoil;
    nr++;

    myObject[nr].x=13;
    myObject[nr].y=13;
    myObject[nr].name="Toad";
    myObject[nr].wsk=oToad;
    nr++;

    oCounter=nr;
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
