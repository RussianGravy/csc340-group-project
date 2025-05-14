#include "system.h"

/*
    We should have a set list of locations and only pass those in.
*/

int main()
{
    System *system = new System();
    // starting the program
    system->start();
    // end the program and clean up memory
    delete system;
    return 0;
}