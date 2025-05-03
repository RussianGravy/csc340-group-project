#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <cmath>

class Location {
private:
    double latitude;
    double longitude;
    std::string address;

public:

    double distanceTo(const Location& other) const;
    std::string getAddress() const;
};

#endif // LOCATION_H
