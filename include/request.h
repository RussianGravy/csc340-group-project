#pragma once
#include "location.h"
#include "rider.h"

class Request
{
public:
    Request(Rider *rider, Location *pickUp, Location *dropOff);
    ~Request();
    Rider *getRider();
    Location *getPickUp() const;
 private:
    Rider *rider;
    Location *pickUp;
    Location *dropOff;
   Location *getDropOff() const;
};

