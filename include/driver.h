#ifndef DRIVER_H
#define DRIVER_H

#include "person.h"
#include "vehicle.h"
#include "location.h"
#include <string>

class Driver : public Person {
private:
    std::string licenseNumber;
    Vehicle vehicle;
    bool available;
    
public:
};

#endif // DRIVER_H
