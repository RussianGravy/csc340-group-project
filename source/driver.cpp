#include "../include/driver.h"
#include "../include/person.h"
using namespace std;

Driver::Driver(std::string name, Location *loc, std::string license)
{
    this->licenseNumber = license;
    this->available = true;
    this->name = name;
    this->currentLocation = loc;
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
    os << "Name: " << d.getName() << ", License: " << d.getLicenseNumber() << ", isAvailable(1 for True, 0 for False): " << d.isAvailable();
    return os;
}