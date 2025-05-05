#include "../include/person.h"
#include "../include/location.h"

// getters
std::string Person::getID()
{
    return this->id;
}

std::string Person::getName()
{
    return this->name;
}

std::string Person::getPhone()
{
    return this->phone;
}

double Person::getRating()
{
    return this->rating;
}
int Person::getTotalRatings()
{
    return this->totalRatings;
}

Location *Person::getCurrentLocation()
{
    return this->currentLocation;
}

// setters
void Person::setID(std::string id)
{
    this->id = id;
}
void Person::setName(std::string name)
{
    this->name = name;
}

void Person::setPhone(std::string phone)
{
    this->phone = phone;
}

// calculates an average using old rating and the rating argument
void Person::addRating(double rating)
{
    this->rating += rating;
    this->rating /= this->totalRatings;
    this->totalRatings += 1;
}

void Person::setCurrentLocation(Location *location)
{
    // copies members without copying pointer.
    *this->currentLocation = *location;
}