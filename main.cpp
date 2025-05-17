#include "system.h"
#include "system_test.h"

void print_initial_menu();

int main()
{
    Test *test = new Test();
    System *system = new System();
    // starting the program
    bool choiceMade = false;
    while (!choiceMade)
    {
        print_initial_menu();
        int userSelection = 0;
        std::cin >> userSelection;
        if (userSelection == 1)
        {
            system->start();
            choiceMade = true;
        }
        else if (userSelection == 2)
        {
            test->start();
            choiceMade = true;
        }
        else
        {
            cout << "Please make a valid selection\n";
        }
    }
    // end the program and clean up memory
    delete system;
    delete test;
    return 0;
}

void print_initial_menu()
{
    std::cout << "---------------------------------------------\n";
    std::cout << "Uber mimic - Aaron, Johnny, Valentino, Luis\n";
    std::cout << "---------------------------------------------\n";
    std::cout << "(1) Main Program\n";
    std::cout << "(2) Unit Tests\n";
    std::cout << "---------------------------------------------\n";
}