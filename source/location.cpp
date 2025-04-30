#include "location.h"
#include <sstream>
#include <cmath>

// Default constructor
Location::Location() : latitude(0.0), longitude(0.0), address("") {}

// Parameterized constructor
Location::Location(double lat, double lon, const std::string& addr)
    : latitude(lat), longitude(lon), address(addr) {}

// Getters and setters
double Location::getLatitude() const {
    return latitude;
}

void Location::setLatitude(double lat) {
    latitude = lat;
}

double Location::getLongitude() const {
    return longitude;
}

void Location::setLongitude(double lon) {
    longitude = lon;
}

std::string Location::getAddress() const {
    return address;
}

void Location::setAddress(const std::string& addr) {
    address = addr;
}

// Calculate distance using the Haversine formula
double Location::distanceTo(const Location& other) const {
    const double EARTH_RADIUS_KM = 6371.0;

    double lat1_rad = latitude * M_PI / 180.0;
    double lon1_rad = longitude * M_PI / 180.0;
    double lat2_rad = other.latitude * M_PI / 180.0;
    double lon2_rad = other.longitude * M_PI / 180.0;

    double dlat = lat2_rad - lat1_rad;
    double dlon = lon2_rad - lon1_rad;

    double a = std::sin(dlat / 2) * std::sin(dlat / 2) +
               std::cos(lat1_rad) * std::cos(lat2_rad) *
               std::sin(dlon / 2) * std::sin(dlon / 2);

    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    return EARTH_RADIUS_KM * c;
}

// Convert Location to string for file I/O
std::string Location::toString() const {
    std::ostringstream oss;
    oss << latitude << ";" << longitude << ";" << address;
    return oss.str();
}

// Parse Location from string
Location Location::fromString(const std::string& str) {
    std::istringstream iss(str);
    std::string latStr, lonStr, addr;

    std::getline(iss, latStr, ';');
    std::getline(iss, lonStr, ';');
    std::getline(iss, addr);

    double lat = std::stod(latStr);
    double lon = std::stod(lonStr);

    return Location(lat, lon, addr);
}
