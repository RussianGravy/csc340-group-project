#include "../include/driver.h"
#include <iostream>
#include "read.h"
using namespace std;

Driver::Driver(std::string name, std::string license)
{
    this->licenseNumber = license;
    this->available = true;
    this->name = name;
}
Driver::~Driver()
{
}

std::string Driver::getName() const
{
    return this->name;
}

// settler and getters
void Driver::setLicenseNumber(std::string license)
{
    this->licenseNumber = license;
}
std::string Driver::getLicenseNumber() const
{
    return this->licenseNumber;
}
void Driver::setAvailable(bool status)
{
    available = status;
}

Location Driver::getCurrentLocation()
{
    return *(this->locations.end() - 1);
}

void Driver::add_location(const Location &p_location)
{
    locations.push_back(p_location);
}
void Driver::add_location(const int latitude, const int longitude, const std::string address)
{
    Location temp(latitude, longitude, address);
    this->add_location(temp);
}

void Driver::set_vehicle(const Vehicle &p_vehicle)
{
    vehicle = p_vehicle;
}

//
bool Driver::isAvailable() const
{
    return available;
}

std::ostream &operator<<(std::ostream &os, const Driver &d)
{
    os << "\n------[Driver: " << d.getName() << "]-------\n";
    os << "License: " << d.getLicenseNumber() << " | isAvailable: " << (d.isAvailable() ? "true" : "false") << '\n';
    Assignment temp = d.getAssignment(); // Aaron, I know how this looks
    os << temp;
    os << "\n------Locations-------\n";
    for (const Location &loc : d.locations)
    {
        os << loc << '\n';
    }
    return os;
}

std::istream &operator>>(std::istream &ins, Driver &p_driver)
{

    cout << "Enter Name: ";
    std::string name = read(ins);
    cout << "Enter License: ";
    std::string license = read(ins);

    p_driver.setName(name);
    p_driver.setLicenseNumber(license);
    // give them random location
    p_driver.add_location(read<Location>(""));
    return ins;
}

Assignment Driver::getAssignment() const
{
    return this->assignment;
}
void Driver::setAssignment(Assignment &assignment)
{
    this->assignment = assignment;
}

void Driver::setAssignment(Rider &rider, Location &pickUp, Location &dropOff)
{
    Assignment temp(rider, pickUp, dropOff);
    this->assignment = temp;
}