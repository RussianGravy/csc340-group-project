#pragma once

#include "person.h"
#include "vehicle.h"
#include "location.h"
#include <string>
#include <ostream>

class Driver : public Person
{
public:
    Driver() = default;
    Driver(std::string name, std::string license);
    ~Driver();
    std::string getName() const;
    void setLicenseNumber(std::string license);
    std::string getLicenseNumber() const;
    bool isAvailable() const;
    void setAvailable(bool);
    
    // set vehicle information assigned to the driver
    void set_vehicle(const Vehicle& p_vehicle);

    // adds new location queue'd up to the driver
    void add_location(const Location& p_location);

   friend std::ostream &operator<<(std::ostream &os, const Driver &driver);
   friend std::istream& operator>>(std::istream& ins, Driver& p_driver);
 private:
    std::string licenseNumber;
    Vehicle vehicle;
    bool available;
    std::vector<Location> locations;

};

