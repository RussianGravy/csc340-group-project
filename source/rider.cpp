#include "rider.h"

Rider::Rider(std::string id, std::string name, Location *loc)
{
    this->id = id;
    this->name = name;
	// Aaron Note -- Memory leak here. No need to allocate unecessarily to the heap, just assign pointer to member variable
    this->currentLocation = loc;
	// Aaron Note -- Redundant assignment of pointer variable
    //*this->currentLocation = *loc;
}
Rider::~Rider()
{
    delete currentLocation;
}
