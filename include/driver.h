#ifndef DRIVER_H
#define DRIVER_H

#include "person.h"
#include "vehicle.h"
#include "location.h"
#include <string>

class Driver : public Person {
private:
    std::string licenseNumber;
    Vehicle *vehicle;
    bool available;
    
public:
    Driver(std::string name, Location* loc, std::string license);
    
    bool isAvailable() const;
    void setAvailable(bool);
    Location* getLocation() const;
    string getName() const;
};

#endif // DRIVER_H
