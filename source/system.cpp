#include "include/system.h"
#include "include/driver.h"
#include "include/request.h"
#include <iostream>
#include <cmath>

using namespace std;


System::System() {
    drivers = new vector<Driver>();
    requests = new queue<Request>();
}

void System::addRequest(Request& request) {
    requests->push(request);
}

int System::assignDriver(Request& request) {
    if (drivers->empty()) {
        return 1;  // no drivers available
    }

    Driver* closestDriver = nullptr;
    double minDistance = -1;

    for (Driver& driver : *drivers) {
        if (driver.isAvailable()) {
            double distance = driver.getLocation()->distanceTo(*request.getPickUp());
            if (minDistance == -1 || distance < minDistance) {
                minDistance = distance;
                closestDriver = &driver;
            }
        }
    }

    if (closestDriver) {
        closestDriver->setAvailable(false);  // driver is now assigned
        cout << "Assigned driver " << closestDriver->getName() << " to the request.\n";
        return 0;  // Success
    }

    return 1; 
}

void System::start() {
    while (!requests->empty()) {
        Request& request = requests->front();
        assignDriver(request);
        requests->pop();
    }
}