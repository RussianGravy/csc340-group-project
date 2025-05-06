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
    // implement main loop from above
    drivers.print();
}
// System::System()
// {
//     drivers = new list();
//     requests = new queue();
// }
// returns 1 if no available driver, 0 if otherwise successful
int System::assignDriver(list<Driver *> drivers, Request &request)
{
    return 1;
}
void System::addRequest(std::queue<Request *> &requests, Request &request)
{
    requests.push(&request);
}
void System::addDriver(Driver *driver)
{
    drivers.push_back(driver);
}
double System::getDistance(Location &loc1, Location &loc2)
{
    // implement pythagoreon theorem and return distance
    return 0.0;
}