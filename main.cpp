#include "list.h"
#include "system.h"
#include "driver.h"
#include "location.h"
#include "request.h"
#include "rider.h"
#include "vehicle.h"
#include "person.h"
#include "assignment.h"
#include "controller.h"

/*
    We should have a set list of locations and only pass those in.
*/

int main()
{
    // T_E_S_T_I_N_G
    System *system = new System();
    // adding drivers
    system->addDriver(new Driver("Driver_Bob", new Location(1, 2, "SF State"), "8YHH264"));
    system->addDriver(new Driver("Driver_Alex", new Location(3, 3, "Embarcadero"), "123ABC!"));
    system->addDriver(new Driver("Driver_Alice", new Location(1, 1, "Bay Bridge"), "155HJ66"));
    // adding a request
    Location *pickUp = new Location(1, 1, "McDonalds");
    Location *dropOff = new Location(2, 2, "Home");
    Rider *testRider = new Rider("C1238895", "Rider_James", pickUp);
    system->addRequest(new Request(testRider, pickUp, dropOff));
    // starting the program
    system->start();
    delete system;
    return 0;
}