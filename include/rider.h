#pragma once
#include "person.h"
#include "location.h"
#include <string>

class Rider : public Person
{
public:
    Rider(std::string id, std::string name);
    void set_start_location(const Location& p_start);
    void set_destination_location(const Location& p_destination);
    ~Rider();

 private:
    std::string paymentMethod;
    Location start;
    Location destination;
};

