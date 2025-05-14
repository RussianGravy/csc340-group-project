#include "system.h"
#include "location.h"
#include "read.h"

/*
    We should have a set list of locations and only pass those in.
*/

int main()
{
    // T_E_S_T_I_N_G
    System *system = new System();
    // making locations
    Location sfstate = Location(2, 4, "SF State");
    Location embarcadaero = Location(1, 1, "Embarcadero");
    Location baybridge = Location(1, 2, "Bay Bridge");
    Location mcdonalds = Location(1, 1, "McDonalds");
    Location home = Location(2, 2, "Home");
    std::vector<Location> locations = {sfstate, embarcadaero, baybridge, mcdonalds, home};

    // adding drivers
    Driver driver1 = Driver("Driver_Bob", "8YHH264");
    driver1.add_location(sfstate);
    Driver driver2 = Driver("Driver_Alex", "123ABC!");
    driver2.add_location(embarcadaero);
    Driver driver3 = Driver("Driver_Alice", "155HJ66");
    driver3.add_location(baybridge);

    system->addDriver(driver1);
    system->addDriver(driver2);
    system->addDriver(driver3);
    // adding a request

    // Aaron Note -- When you allocate it memory leaks here because your allocating your rider to the heap
    // Aaron Note -- You might want to do this a bit differently because this also causes a memory leak.
    /* Rider *testRider = new Rider("C1238895", "Rider_James", mcdonalds); */
    /* system->addRequest(new Request(testRider, mcdonalds, home)); */

    // Driver test_driver = read<Driver>("");
    // cout << test_driver << '\n';
    // starting the program
    system->start();
    // end the program and clean up memory
    delete system;
    return 0;
}
