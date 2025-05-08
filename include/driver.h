#ifndef DRIVER_H
#define DRIVER_H

#include "person.h"
#include "vehicle.h"
#include "location.h"
#include <string>
#include <ostream>

class Driver : public Person
{
private:
    std::string licenseNumber;
    Vehicle *vehicle;
    bool available;

public:
    Driver(std::string name, Location *loc, std::string license);
    ~Driver();
    std::string getName();
    void setLicenseNumber(std::string license);
    std::string getLicenseNumber();
    bool isAvailable() const;
    void setAvailable(bool);
    std::string getName() const;
    friend std::ostream &operator<<(std::ostream &os, Driver &driver);
};

#endif // DRIVER_H
