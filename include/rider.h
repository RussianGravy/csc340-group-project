#ifndef RIDER_H
#define RIDER_H

#include "person.h"
#include "location.h"
#include <string>

class Rider : public Person
{
private:
    std::string paymentMethod;

public:
    Rider(std::string id, std::string name, Location *loc);
    ~Rider();
};

#endif // RIDER_H
