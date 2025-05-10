#include "../include/driver.h"
#include "../include/person.h"
#include <iostream>
using namespace std;

Driver::Driver(std::string name, Location *loc, std::string license)
{
    this->licenseNumber = license;
    this->available = true;
    this->name = name;
    this->currentLocation = new Location();
    *this->currentLocation = *loc;
}
Driver::~Driver()
{
    delete currentLocation;
}
std::string Driver::getName()
{
    return this->name;
}
// settler and getters
void Driver::setLicenseNumber(std::string license)
{
    this->licenseNumber = license;
}
std::string Driver::getLicenseNumber()
{
    return this->licenseNumber;
}
void Driver::setAvailable(bool status)
{
    available = status;
}
//
bool Driver::isAvailable() const
{
    return available;
}

std::ostream &operator<<(std::ostream &os, Driver &d)
{
    /* "Name: " << d.getName() << */
    os << d.getName() << ", " << d.getLicenseNumber() << ", " << d.isAvailable();
    return os;
}