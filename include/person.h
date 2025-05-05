#ifndef PERSON_H
#define PERSON_H
#include "include/location.h"


#include <string>

class Person
{
protected:
    std::string id;
    std::string name;
    std::string phone;
    double rating;
    int totalRatings;
    Location *currentLocation;

public:
    // getters
    std::string getID();
    std::string getName();
    std::string getPhone();
    double getRating();
    int getTotalRatings();
    Location *getCurrentLocation();
    // setters
    void setID(std::string id);
    void setName(std::string name);
    void setPhone(std::string phone);
    void addRating(double rating); // calculates an average using old rating and the rating argument
    void setCurrentLocation(Location* location);
};

#endif // PERSON_H
