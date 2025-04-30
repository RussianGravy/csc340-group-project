#ifndef DRIVER_H
#define DRIVER_H

#include "person.h"
#include "vehicle.h"
#include "location.h"
#include <string>

class Driver : public Person {
private:
    std::string licenseNumber;
    Vehicle vehicle;
    Location currentLocation;
    bool available;
    
public:
    // Constructors
    Driver();
    Driver(const std::string& id, const std::string& name, const std::string& phone,
           const std::string& licenseNumber, const Vehicle& vehicle, const Location& location);
    
    // Getters and setters
    std::string getLicenseNumber() const;
    void setLicenseNumber(const std::string& license);
    
    Vehicle getVehicle() const;
    void setVehicle(const Vehicle& vehicle);
    
    Location getCurrentLocation() const;
    void setCurrentLocation(const Location& location);
    
    bool isAvailable() const;
    void setAvailable(bool available);
    
    // Implementation of abstract method
    std::string getRole() const override;
    
    // For file I/O
    std::string toString() const override;
    static Driver fromString(const std::string& str);
};

#endif // DRIVER_H
