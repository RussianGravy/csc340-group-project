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
    std::cout << "~ Before request: ~" << endl;
    drivers.print();
    if (!requests.empty())
    {
        std::cout << "we should be assiging a driver y'all..." << endl;
        Request *nextReq = requests.front();
        assignDriver(*nextReq);
    }
    std::cout << " ~ After assigning request to driver: ~" << endl;
    drivers.print();
}
System::~System()
{
    for (list<Driver *>::Node *current = drivers.get_head(); current; current = current->next)
    {
        delete current->data;
    }
    while (!requests.empty())
    {
        delete requests.front();
        requests.pop();
    }
}
// returns 1 if no available driver, 0 if otherwise successful
int System::assignDriver(Request &request)
{
    Driver *closestDriver = nullptr;
    double distanceToClosestDriver;
    std::cout << "closest driver: " << closestDriver << endl;
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
                    std::cout << *closestDriver << endl;
                }
            }
            else
            {
                closestDriver = current->data;
                distanceToClosestDriver = current->data->getCurrentLocation()->distanceTo(*request.getPickUp());
                std::cout << *closestDriver << endl;
            }
        }
    }
    std::cout << "closest driver: " << closestDriver << endl;
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
void System::addRequest(Request *request)
{
    requests.push(request);
}
void System::addDriver(Driver *driver)
{
    drivers.push_back(driver);
}