#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include "location.h"
#include "rider.h"

class Assignment
{
private:
    std::string assignmentID;
    int timeToDestination;
    Rider passenger;
    Location pickUp;
    Location dropOff;

public:
    // constructors
    Assignment() = default;
    Assignment(Rider passenger, Location dropOff, Location pickUp); // assignment ID is randomly generated
    ~Assignment();
    //  getters and setters
    std::string getAssignmentID();
    int calculateTimeToDestination(Location currentLocation); // getter and setter
    Location getPickUp();
    Location getDropOff();
    // overloads
    friend std::ostream &operator<<(std::ostream &os, Assignment &assignment);
};

#endif