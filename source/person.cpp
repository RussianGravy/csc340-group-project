#include "person.h"

// Default constructor
Person::Person() : id(""), name(""), phone(""), rating(0.0), totalRatings(0) {}

// Parameterized constructor
Person::Person(const std::string& id, const std::string& name, const std::string& phone)
    : id(id), name(name), phone(phone), rating(0.0), totalRatings(0) {}

// Getters and Setters
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
    return rating;
}

void Person::addRating(int newRating) {
    if (newRating < 0 || newRating > 5) return; // Validate rating
    rating = ((rating * totalRatings) + newRating) / (totalRatings + 1);
    ++totalRatings;
}

// toString method for file I/O
std::string Person::toString() const {
    return id + "," + name + "," + phone + "," + std::to_string(rating);
}
