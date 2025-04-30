#include "location.h"
#include <sstream>

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

// Calculate distance between two locations using Haversine formula (in kilometers)
double Location::distanceTo(const Location& other) const {
    const double R = 6371.0; // Earth radius in kilometers
    
    double lat1 = latitude * M_PI / 180.0;
    double lon1 = longitude * M_PI / 180.0;
    double lat2 = other.latitude * M_PI / 180.0;
    double lon2 = other.longitude * M_PI / 180.0;
    
    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;
    
    double a = sin(dLat/2) * sin(dLat/2) + 
               cos(lat1) * cos(lat2) * 
               sin(dLon/2) * sin(dLon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    
    return R * c;
}

// For file I/O
std::string Location::toString() const {
    std::stringstream ss;
    ss << latitude << "," << longitude << "," << address;
    return ss.str();
}

Location Location::fromString(const std::string& str) {
    std::stringstream ss(str);
    std::string item;
    double lat, lon;
    std::string addr;
    
    std::getline(ss, item, ',');
    lat = std::stod(item);
    
    std::getline(ss, item, ',');
    lon = std::stod(item);
    
    std::getline(ss, addr);
    
    return Location(lat, lon, addr);
}
