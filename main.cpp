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
#include "read.h"

/*
    We should have a set list of locations and only pass those in.
*/

int main()
{
    // T_E_S_T_I_N_G
    System *system = new System();
    // making locations
    Location *sfstate = new Location(2, 4, "SF State");
    Location *embarcadaero = new Location(1, 1, "Embarcadero");
    Location *baybridge = new Location(1, 2, "Bay Bridge");
    Location *mcdonalds = new Location(1, 1, "McDonalds");
    Location *home = new Location(2, 2, "Home");
    Location *locations[] = {sfstate, embarcadaero, baybridge, mcdonalds, home};
    // adding drivers
    system->addDriver(new Driver("Driver_Bob", sfstate, "8YHH264"));
    system->addDriver(new Driver("Driver_Alex", embarcadaero, "123ABC!"));
    system->addDriver(new Driver("Driver_Alice", baybridge, "155HJ66"));
    // adding a request
    
	// Aaron Note -- When you allocate it memory leaks here because your allocating your rider to the heap
	// Aaron Note -- You might want to do this a bit differently because this also causes a memory leak.
	//Rider *testRider = new Rider("C1238895", "Rider_James", mcdonalds);
    //system->addRequest(new Request(testRider, mcdonalds, home));
    

	// starting the program
    system->start();
    // end the program and clean up memory
    delete system;
    for (Location *loc : locations)
    {
        delete loc;
    }

    cout << "Read Input Example\n";
    while(true) {
        char ch = read("Enter a number: ");
        cout << "char = " << ch << '\n';

        if(ch == 'q') break;
    }
    return 0;
}
