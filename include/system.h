/*
    Implement binary search tree to sort requests by closest distance to available driver.
*/
#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <queue>
#include "list.h"
#include "driver.h"
#include "rider.h"
#include "request.h"

/*
 * Main Program Loop
 * If (Request queue has any Requests && any Drivers are available)
 *   pop the next request in queue and create Assignment for closest Driver
 *
 * progress each Driver through its Assignement (LinkedList?)
 */

class System
{
private:
    list<Driver *> drivers;
    std::queue<Request *> requests;

public:
    System() = default;
    ~System() = default;
    void start();                                                       // starts system's main loop
    int assignDriver(list<Driver *> drivers, Request &request);         // returns 1 if no available driver, 0 if otherwise successful
    void addRequest(std::queue<Request *> &requests, Request &request); // API that adds new request to queue
    void addDriver(Driver *driver);
    double getDistance(Location &loc1, Location &loc2); // gives the distance between two locations using pythagorean theorem
};

#endif