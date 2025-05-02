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

class System
{
private:
    vector<Driver> *drivers;
    queue<Request> *requests;

public:
    void start();                      // starts system's main loop
    int assignDriver(Request request); // returns 1 if no available driver, 0 if otherwise successful
}

#endif