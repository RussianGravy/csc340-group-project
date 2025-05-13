#pragma once
#include "location.h"
#include <string>

class Person
{
public:
    // getters
    std::string getID();
    virtual std::string getName();
    std::string getPhone();
    double getRating();
    int getTotalRatings();
    Location getCurrentLocation() const;
    // setters
    void setID(std::string id);
    void setName(std::string name);
    void setPhone(std::string phone);
    void addRating(double rating); // calculates an average using old rating and the rating argument
    void setCurrentLocation(const Location& p_location);
 protected:
    std::string id;
    std::string name;
    std::string phone;
    double rating;
    int totalRatings;
    Location currentLocation;
};

