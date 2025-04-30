#include "person.h"
#include <sstream>

// Default constructor
Person::Person() : rating(0.0), totalRatings(0) {}

// Parameterized constructor
Person::Person(const std::string& id, const std::string& name, const std::string& phone)
    : id(id), name(name), phone(phone), rating(0.0), totalRatings(0) {}

// Getters and setters
std::string Person::getId() const {
    return id;
}

void Person::setId(const std::string& id) {
    this->id = id;
}

std::string Person::getName() const {
    return name;
}

void Person::setName(const std::string& name) {
    this->name = name;
}

std::string Person::getPhone() const {
    return phone;
}

void Person::setPhone(const std::string& phone) {
    this->phone = phone;
}

double Person::getRating() const {
    if (totalRatings == 0) {
        return 0.0;
    }
    return rating / totalRatings;
}

void Person::addRating(int rating) {
    if (rating >= 1 && rating <= 5) {
        this->rating += rating;
        totalRatings++;
    }
}

// For file I/O
std::string Person::toString() const {
    std::stringstream ss;
    ss << id << "," << name << "," << phone << "," << rating << "," << totalRatings;
    return ss.str();
}
