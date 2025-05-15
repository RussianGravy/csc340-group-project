#pragma once

#include "assignment.h"
#include "person.h"
#include "vehicle.h"
#include "location.h"
#include <string>
#include <vector>
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

  // returns the last location in locations
  Location getCurrentLocation();

  // set vehicle information assigned to the driver
  void set_vehicle(const Vehicle &p_vehicle);

  // adds new location queue'd up to the driver
  void add_location(const Location &p_location);
  void add_location(const int latitude, const int longitude, const std::string address);

  friend std::ostream &operator<<(std::ostream &os, const Driver &driver);
  friend std::istream &operator>>(std::istream &ins, Driver &p_driver);

  Assignment getAssignment() const;
  void setAssignment(Assignment &assignment);
  void setAssignment(Rider &rider, Location &pickUp, Location &dropOff);

private:
  std::string licenseNumber;
  Vehicle vehicle;
  bool available;
  std::vector<Location> locations;
  Assignment assignment;
};
