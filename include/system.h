/*
    Implement binary search tree to sort requests by closest distance to available driver.
*/
#pragma once
#include <queue>
#include "../template/list.tpp"
#include "driver.h"
#include "request.h"
#include "rider.h" 

/*
 * Main Program Loop
 * If (Request queue has any Requests && any Drivers are available)
 *   pop the next request in queue and create Assignment for closest Driver
 *
 * progress each Driver through its Assignement (LinkedList?)
 */

class System
{
public:
    System() = default;
    ~System();
    void start();                                               // starts system's main loop
    int assignDriver(const Request &request); // returns 1 if no available driver, 0 if otherwise successful
    void addRequest(const Request& request);                          // API that adds new request to queue
    void addDriver(const Driver& driver);

    void addRider(const Rider& rider);

    int availableDriversCount() const;

    //getter for the rider
    const list<Rider>& getRiders() const;
    
 private:
    list<Driver> drivers;
    list<Rider> riders;
    std::queue<Request> requests;

};
