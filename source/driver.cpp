#include "driver.h"
#include <sstream>

// Default constructor
Driver::Driver()
    : Person(), licenseNumber(""), vehicle(), currentLocation(), available(true) {}

// Parameterized constructor
Driver::Driver(const std::string& id, const std::string& name, const std::string& phone,
               const std::string& licenseNumber, const Vehicle& vehicle, const Location& location)
    : Person(id, name, phone), licenseNumber(licenseNumber), vehicle(vehicle), currentLocation(location), available(true) {}

// Getters and Setters
std::string Driver::getLicenseNumber() const {
    return licenseNumber;
}

void Driver::setLicenseNumber(const std::string& license) {
    this->licenseNumber = license;
}

Vehicle Driver::getVehicle() const {
    return vehicle;
}

void Driver::setVehicle(const Vehicle& vehicle) {
    this->vehicle = vehicle;
}

Location Driver::getCurrentLocation() const {
    return currentLocation;
}

void Driver::setCurrentLocation(const Location& location) {
    this->currentLocation = location;
}

bool Driver::isAvailable() const {
    return available;
}

void Driver::setAvailable(bool available) {
    this->available = available;
}

// Implement abstract method
std::string Driver::getRole() const {
    return "Driver";
}

// toString for file I/O
std::string Driver::toString() const {
    std::ostringstream oss;
    oss << Person::toString() << "," << licenseNumber << ","
        << vehicle.toString() << "," << currentLocation.toString() << ","
        << (available ? "1" : "0");
    return oss.str();
}

// fromString to parse a Driver object from a string
Driver Driver::fromString(const std::string& str) {
    std::istringstream iss(str);
    std::string token;

    std::string id, name, phone, license, vehicleStr, locationStr;
    double rating;
    int totalRatings;
    bool available;

    // Parse basic Person attributes
    std::getline(iss, id, ',');
    std::getline(iss, name, ',');
    std::getline(iss, phone, ',');
    std::getline(iss, token, ',');
    rating = std::stod(token);

    std::getline(iss, license, ',');
    
    std::getline(iss, token, ',');  // Assuming vehicle.toString() is a single comma-free token
    vehicleStr = token;

    std::getline(iss, token, ',');  // Assuming location.toString() is a single comma-free token
    locationStr = token;

    std::getline(iss, token, ',');
    available = (token == "1");

    Vehicle vehicle = Vehicle::fromString(vehicleStr);
    Location location = Location::fromString(locationStr);

    Driver driver(id, name, phone, license, vehicle, location);
    driver.setAvailable(available);
    return driver;
}
