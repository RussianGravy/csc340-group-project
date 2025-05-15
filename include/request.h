#pragma once
#include "location.h"
#include "rider.h"

class Request
{
public:
   Request(Rider *rider, Location *pickUp, Location *dropOff);
   ~Request();
   Rider *getRider() const;
   Location *getPickUp() const;
   Location *getDropOff() const;

private:
   Rider *rider;
   Location *pickUp;
   Location *dropOff;
};
