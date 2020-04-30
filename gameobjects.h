#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H
#include <QString>

class GameObjects
{
public:
    GameObjects();
    unsigned short int * oarray(unsigned short int);
    unsigned short int oy(unsigned short int);
    unsigned short int ox(unsigned short int);
    QString oname(unsigned short int);
    unsigned short int onr(QString);
    unsigned short int oCounter;
};

#endif // GAMEOBJECTS_H
