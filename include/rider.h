#pragma once
#include "person.h"
#include "location.h"
#include <iostream>
#include <string>

class Rider : public Person
{
public:
    Rider(std::string id, std::string name);
    ~Rider();
    void set_start_location(const Location &p_start);
    void set_destination_location(const Location &p_destination);
    friend std::istream &operator>>(std::istream &ins, Rider &p_rider);

private:
    std::string paymentMethod;
    Location start;
    Location destination;
};
