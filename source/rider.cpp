#include "rider.h"

Rider::Rider(std::string id, std::string name, Location *loc)
{
    this->id = id;
    this->name = name;
    this->currentLocation = loc;
}
Rider::~Rider()
{
    delete currentLocation;
}