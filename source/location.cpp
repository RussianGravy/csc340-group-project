#include "../include/location.h"
#include <cmath>
#include <iostream>
#include "read.h"

Location::Location() {}
Location::Location(double lat, double longg, std::string addy)
{
    this->latitude = lat;
    this->longitude = longg;
    this->address = addy;
}
// calcualting the dstance and should return the pytha theorem
// could do it with one line of code but will look hella weird
//(x2 - x1) squared + (y2 -y1)squared, then you square root everything to get distance
double Location::distanceTo(const Location &other) const
{
    double dx = other.latitude - latitude;
    double dy = other.longitude - longitude;
    return sqrt(dx * dx + dy * dy);
}

std::string Location::getAddress() const
{
    return address;
}

std::ostream& operator<<(std::ostream& outs, const Location& p_location) {
    outs << "Latitude = " << p_location.latitude << '\n'
         << "Longitude = " << p_location.longitude << '\n'
         << "Address = " << p_location.address;
    return outs;
}

std::istream& operator>>(std::istream& ins, Location& p_location) {
    p_location.latitude = read(ins);
    p_location.longitude = read(ins);
    p_location.address = readline(ins);
    return ins;
}
