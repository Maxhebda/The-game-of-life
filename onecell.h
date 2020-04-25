#ifndef ONECELL_H
#define ONECELL_H


class OneCell
{
public:
    OneCell();
    void set(unsigned short int);
    unsigned short int get();
private:
    unsigned short int state;                       //0 white (dead), 1 red, 2 blue, 3 yellow, 4 green
};

#endif // ONECELL_H
