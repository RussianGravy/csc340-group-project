#pragma once
#include <istream>
#include <string>

class Location
{
public:
    Location();
    Location(double lat, double longg, std::string addy);
    ~Location() {}
    double distanceTo(const Location &other) const;
   std::string getAddress() const;
   friend std::ostream& operator<<(std::ostream& outs, const Location& p_location);
   friend std::istream& operator>>(std::istream& outs, Location& p_location);
 private:
    double latitude;
    double longitude;
    std::string address;
};

