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
    // cant do a setter and gettr for currentlcation becouse its a pointer
    //dont know if yall want to change that or keep it like that
    std::string getId() const;
    std::string getName() const;
    std::string getPhone() const;
    double getRating() const;
    int getTotalRatings() const;
    Location getLocation() const;

    

    void setId(const std::string &newId);
    void setName(const std::string &newName);
    void setPhone(const std::string &newPhone);
    void updateRating(double newRating);
    void setLocation(const Location& loc);

};

#endif // PERSON_H
