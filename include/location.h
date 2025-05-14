#pragma once
#include <string>

class Location
{
public:
  Location();
  Location(double lat, double longg, std::string addy);
  ~Location() {}
  double distanceTo(const Location &other) const;
  std::string getAddress() const;
  void setAddress(std::string addy);
  void setLongitude(double longitude);
  void setLatitude(double latitude);
  friend std::ostream &operator<<(std::ostream &outs, const Location &p_location);
  friend std::istream &operator>>(std::istream &ins, Location &p_location);

private:
  double latitude;
  double longitude;
  std::string address;
};
