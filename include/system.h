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
    vector<Driver> *drivers;
    queue<Request> *requests;

public:
    void start();                       // starts system's main loop
    int assignDriver(Request &request); // returns 1 if no available driver, 0 if otherwise successful
    void addRequest(Request &request);  // API that adds new request to queue
}

#endif