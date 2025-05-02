#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
protected:
    std::string id;
    std::string name;
    std::string phone;
    double rating;
    int totalRatings;
    Location currentLocation;

public:
};

#endif // PERSON_H
