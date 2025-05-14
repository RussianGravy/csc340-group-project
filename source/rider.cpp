#include "rider.h"

Rider::Rider(std::string id, std::string name)
{
    this->id = id;
    this->name = name;
    // Aaron Note -- Memory leak here. No need to allocate unecessarily to the heap, just assign pointer to member variable
    /* this->currentLocation = loc; */
    // Aaron Note -- Redundant assignment of pointer variable
    //*this->currentLocation = *loc;
}
Rider::~Rider()
{
    /* delete currentLocation; */
}
void Rider::set_start_location(const Location &p_start)
{
    start = p_start;
}

void Rider::set_destination_location(const Location &p_destination)
{
    destination = p_destination;
}

std::istream &operator>>(std::istream &ins, Rider &p_rider)
{
    std::string name = "";
    std::cout << "Enter Name: ";
    ins >> name;
    p_rider.setName(name);
    return ins;
}