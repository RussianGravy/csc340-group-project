#include "../include/location.h"
#include <cmath>
#include <iostream>
using namespace std;

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