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
    // Constructors
    Location();
    Location(double lat, double lon, const std::string& addr);
    
    // Getters and setters
    double getLatitude() const;
    void setLatitude(double lat);
    
    double getLongitude() const;
    void setLongitude(double lon);
    
    std::string getAddress() const;
    void setAddress(const std::string& addr);
    
    // Calculate distance between two locations (in kilometers)
    double distanceTo(const Location& other) const;
    
    // For file I/O
    std::string toString() const;
    static Location fromString(const std::string& str);
};

#endif // LOCATION_H
