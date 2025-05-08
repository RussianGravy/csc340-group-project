#include "../include/system.h"
/*
 * Main Program Loop
 * If (Request queue has any Requests && any Drivers are available)
 *   pop the next request in queue and create Assignment for closest Driver
 *
 * progress each Driver through its Assignement (LinkedList?)
 */

// starts system's main loop
void System::start()
{
    // just testing
    drivers.print();
    if (requests.size() > 0)
    {
        Request *nextReq = requests.front();
    }
    drivers.print();
}
System::~System()
{
    for (list<Driver *>::Node *current = drivers.get_head(); current; current = current->next)
    {
        delete current->data;
    }
}
// returns 1 if no available driver, 0 if otherwise successful
int System::assignDriver(Request &request)
{
    Driver *closestDriver = nullptr;
    double distanceToClosestDriver;
    for (list<Driver *>::Node *current = drivers.get_head(); current; current = current->next)
    {
        if (current->data->isAvailable())
        {
            if (closestDriver)
            {
                double distanceToCurrent = current->data->getCurrentLocation()->distanceTo(*request.getPickUp());
                if (distanceToCurrent < distanceToClosestDriver)
                {
                    closestDriver = current->data;
                    distanceToClosestDriver = distanceToCurrent;
                }
            }
            else
            {
                closestDriver = current->data;
                distanceToClosestDriver = current->data->getCurrentLocation()->distanceTo(*request.getPickUp());
            }
        }
    }
    if (closestDriver)
    {
        closestDriver->setAvailable(false);
        return 0;
    }
    else
    {
        return 1;
    }
}
void System::addRequest(Request *request)
{
    requests.push(request);
}
void System::addDriver(Driver *driver)
{
    drivers.push_back(driver);
}