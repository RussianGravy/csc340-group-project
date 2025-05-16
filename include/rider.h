#pragma once
#include "person.h"
#include "location.h"
#include <string>

class Rider : public Person
{
public:
    Rider() = default;
    Rider(std::string id, std::string name);
    void set_start_location(const Location &p_start);
    void set_destination_location(const Location &p_destination);
    ~Rider();
    Location get_start_location() const;
    Location get_destination_location() const;

    std::string getName() const override;
    friend std::ostream &operator<<(std::ostream &os, const Rider &rider);
    friend std::istream &operator>>(std::istream &ins, Rider &p_rider);

private:
    std::string paymentMethod;
    Location start;
    Location destination;
};
