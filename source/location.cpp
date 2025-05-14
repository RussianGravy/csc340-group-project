#include "../include/location.h"
#include <cmath>
#include <iostream>
using namespace std;

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

string Location::getAddress() const
{
    return address;
}

void Location::setAddress(std::string addy) { this->address = addy; }

void Location::setLongitude(double longitude) { this->longitude = longitude; }

void Location::setLatitude(double latitude) { this->latitude = latitude; }

std::ostream &operator<<(std::ostream &outs, const Location &p_location)
{
    outs << "Latitude = " << p_location.latitude << '\n'
         << "Longitude = " << p_location.longitude << '\n'
         << "Address = " << p_location.address;
    return outs;
}

std::istream &operator>>(std::istream &ins, Location &p_location)
{
    double latitude;
    double longitude;
    std::string address;
    cout << "Enter Address: ";
    ins >> address;
    cout << "Enter Latitude: ";
    ins >> latitude;
    cout << "Enter Longitude: ";
    ins >> longitude;

    p_location.setLatitude(latitude);
    p_location.setLongitude(longitude);
    p_location.setAddress(address);
    return ins;
}