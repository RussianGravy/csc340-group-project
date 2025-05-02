#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include "location.h"
#include "rider.h"

class Assignment
{
private:
    std::string assignmentID;
    int timeToDestination;
    Rider *passenger;
    Location *pickUp;
    Location *dropOff;

public:
};

#endif