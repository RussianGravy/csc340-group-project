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
};

#endif // RIDER_H
