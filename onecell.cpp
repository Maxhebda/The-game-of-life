#include "onecell.h"

OneCell::OneCell()
{
    state = 0; //dead
}

unsigned short int OneCell::get()
{
    return state;
}

void OneCell::set(unsigned short int state)
{
    this->state = state;
}
