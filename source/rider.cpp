#include "rider.h"
#include <sstream>

// Default constructor
Rider::Rider()
    : Person(), paymentMethod(""), homeAddress(), workAddress() {}

// Parameterized constructor
Rider::Rider(const std::string& id, const std::string& name, const std::string& phone,
             const std::string& paymentMethod, const Location& home, const Location& work)
    : Person(id, name, phone), paymentMethod(paymentMethod), homeAddress(home), workAddress(work) {}

// Getters and setters
std::string Rider::getPaymentMethod() const {
    return paymentMethod;
}

void Rider::setPaymentMethod(const std::string& method) {
    this->paymentMethod = method;
}

Location Rider::getHomeAddress() const {
    return homeAddress;
}

void Rider::setHomeAddress(const Location& location) {
    this->homeAddress = location;
}

Location Rider::getWorkAddress() const {
    return workAddress;
}

void Rider::setWorkAddress(const Location& location) {
    this->workAddress = location;
}

// Abstract method implementation
std::string Rider::getRole() const {
    return "Rider";
}

// For file I/O
std::string Rider::toString() const {
    std::ostringstream oss;
    oss << Person::toString() << ","
        << paymentMethod << ","
        << homeAddress.toString() << ","
        << workAddress.toString();
    return oss.str();
}

// Create a Rider from a string
Rider Rider::fromString(const std::string& str) {
    std::istringstream iss(str);
    std::string token;

    std::string id, name, phone, method, homeStr, workStr;
    double rating;

    std::getline(iss, id, ',');
    std::getline(iss, name, ',');
    std::getline(iss, phone, ',');
    std::getline(iss, token, ',');
    rating = std::stod(token);
    
    std::getline(iss, method, ',');
    std::getline(iss, token, ','); // home location string
    homeStr = token;
    std::getline(iss, token, ','); // work location string
    workStr = token;

    Location home = Location::fromString(homeStr);
    Location work = Location::fromString(workStr);

    Rider rider(id, name, phone, method, home, work);
    return rider;
}
