#include "../include/system.h"
#include "read.h"

/*
 * Main Program Loop
 * If (Request queue has any Requests && any Drivers are available)
 *   pop the next request in queue and create Assignment for closest Driver
 *
 * progress each Driver through its Assignement (LinkedList?)
*/

void print_menu() {
    cout << "------------------------------\n";
    cout << "1. Add Driver\n"
         << "2. Add Rider\n"
         << "3. Load Drivers From File\n"
         << "4. Load Riders From File\n"
         << "Press 0 to quit\n";
    cout << "------------------------------\n";
}

// starts system's main loop
void System::start()
{
    // just testing
    std::cout << "~ Before request: ~" << endl;
    /* drivers.print(); */
    if (!requests.empty())
    {
        Request nextReq = requests.front();
        assignDriver(nextReq);
    }

    
    while(true){
        print_menu();

        int x = read("");
        if(x == 0){
            break;
        }

        if(x == 1) {
            cout << "Adding a driver!\n";
        }
        else if(x == 2) {
            cout << "Adding a Rider\n";
        }
        else if(x == 3) {
            cout << "Loading Driver from File\n";
        }
        else if(x == 4) {
            cout << "Loading Rider from File\n";
        }

    }
    

    std::cout << " ~ After assigning request to driver: ~" << endl;
    drivers.print();
}
System::~System()
{
    /* for (list<Driver *>::Node *current = drivers.get_head(); current; current = current->next) */
    /* { */
    /*     delete current->data; */
    /* } */
    while (!requests.empty())
    {
        /* delete requests.front(); */
        requests.pop();
    }
}
// returns 1 if no available driver, 0 if otherwise successful
int System::assignDriver(const Request &request)
{
    Driver *closestDriver = nullptr;
    double distanceToClosestDriver;
    for (list<Driver>::Node *current = drivers.get_head(); current; current = current->next)
    {
        if (current->data.isAvailable())
        {
            if (closestDriver)
            {
                double distanceToCurrent = current->data.getCurrentLocation().distanceTo(*request.getPickUp());
                if (distanceToCurrent < distanceToClosestDriver)
                {
                    closestDriver = &current->data;
                    distanceToClosestDriver = distanceToCurrent;
                }
            }
            else
            {
                closestDriver = &current->data;
                distanceToClosestDriver = current->data.getCurrentLocation().distanceTo(*request.getPickUp());
            }
        }
    }
    if (closestDriver)
    {
        closestDriver->setAvailable(false);
        requests.pop();
        return 0;
    }
    else
    {
        return 1;
    }
}
void System::addRequest(const Request& request)
{
    requests.push(request);
}
void System::addDriver(const Driver& driver)
{
    drivers.push_back(driver);
}
