#include "driver.h"
#include <sstream>
#include <vector>

// Default constructor
Driver::Driver() : Person(), available(false) {}

// Parameterized constructor
Driver::Driver(const std::string& id, const std::string& name, const std::string& phone,
              const std::string& licenseNumber, const Vehicle& vehicle, const Location& location)
    : Person(id, name, phone), licenseNumber(licenseNumber), 
      vehicle(vehicle), currentLocation(location), available(true) {}

// Getters and setters
std::string Driver::getLicenseNumber() const {
    return licenseNumber;
}

void Driver::setLicenseNumber(const std::string& license) {
    licenseNumber = license;
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
    currentLocation = location;
}

bool Driver::isAvailable() const {
    return available;
}

void Driver::setAvailable(bool available) {
    this->available = available;
}

// Implementation of abstract method
std::string Driver::getRole() const {
    return "Driver";
}

// For file I/O
std::string Driver::toString() const {
    std::stringstream ss;
    ss << Person::toString() << "," << licenseNumber << "," 
       << vehicle.toString() << "," << currentLocation.toString() << "," << (available ? "1" : "0");
    return ss.str();
}

Driver Driver::fromString(const std::string& str) {
    std::stringstream ss(str);
    std::string item;
    std::vector<std::string> tokens;
    
    while (std::getline(ss, item, ',')) {
        tokens.push_back(item);
    }
    
    if (tokens.size() < 13) { // Minimum expected tokens
        return Driver(); // Return default driver if format is incorrect
    }
    
    // Parse Person data
    std::string id = tokens[0];
    std::string name = tokens[1];
    std::string phone = tokens[2];
    double rating = std::stod(tokens[3]);
    int totalRatings = std::stoi(tokens[4]);
    
    // Parse Driver-specific data
    std::string licenseNumber = tokens[5];
    
    // Parse Vehicle data
    std::string licensePlate = tokens[6];
    std::string make = tokens[7];
    std::string model = tokens[8];
    std::string color = tokens[9];
    int year = std::stoi(tokens[10]);
    int capacity = std::stoi(tokens[11]);
    Vehicle vehicle(licensePlate, make, model, color, year,
