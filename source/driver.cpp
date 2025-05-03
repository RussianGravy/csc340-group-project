#include "include/driver.h"
using namespace std;


Driver::Driver(std::string name, Location* loc, std::string license){
    this->licenseNumber = license;
    this->available = true;
    this->name = name;
    this->currentLocation = loc;
}

//settler and getters

void Driver::setAvailable(bool status) {
     available = status; 
}
//
bool Driver::isAvailable() const { 
    return available; 
}    
Location* Driver::getLocation() const { 
    return currentLocation; 
}

//inhertor of person class
std::string Driver::getName() const { 
    return name; 
}