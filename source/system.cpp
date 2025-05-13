#include "../include/system.h"
#include "read.h"

/*
 * Main Program Loop
 * If (Request queue has any Requests && any Drivers are available)
 *   pop the next request in queue and create Assignment for closest Driver
 *
 * progress each Driver through its Assignement (LinkedList?)
 */

void print_menu()
{
    cout << "------------------------------\n";
    cout << "1. Add Driver\n"
         << "2. Add Rider\n"
         << "3. Load Drivers From File\n"
         << "4. Load Riders From File\n"
         << "~ App Controls ~\n"
         << "5. Check available drivers // gives number of available drivers\n"
         << "6. New Request // submit new request with pick-up and drop-off location\n"
         << "7. Check Status of Request // gives your place in queue\n"
         << "Press 0 to quit\n";
    cout << "------------------------------\n";
}

// starts system's main loop
void System::start()
{
    while (true)
    {
        print_menu();

        int x = read("");
        if (x == 0)
        {
            break;
        }

        if (x == 1)
        {
            cout << "Adding a driver!\n";
        }
        else if (x == 2)
        {
            cout << "Adding a Rider\n";
        }
        else if (x == 3)
        {
            cout << "Loading Driver from File\n";
        }
        else if (x == 4)
        {
            cout << "Loading Rider from File\n";
        }
        // App User Controls
        else if (x == 5)
        {
            cout << "Giving number of available drivers.\n";
        }
        else if (x == 6)
        {
            cout << "Making a new request for pick up and drop off.\n";
        }
        else if (x == 7)
        {
            cout << "Giving your place in the request queue\n";
        }
    }
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
void System::addRequest(const Request &request)
{
    requests.push(request);
}
void System::addDriver(const Driver &driver)
{
    drivers.push_back(driver);
}
