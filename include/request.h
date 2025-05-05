#ifndef REQUEST_H
#define REQUEST_H

#include "location.h"
#include "rider.h"

class Request
{
private:
    Rider *rider;
    Location *pickUp;
    Location *dropOff;

public:
    Location* getPickUp() const;
    Location* getDropOff() const;
};

#endif