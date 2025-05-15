#include "assignment.h"
/*

Assignment();
Assignment(Rider passenger, Location dropOff, Location pickUp); // assignment ID is randomly generated
~Assignment();

std::string getAssignmentID();
int calculateTimeToDestination(Location currentLocation); // getter and setter
Location getPickUp();
Location getDropOff();
*/

Assignment::Assignment(Rider passenger, Location dropOff, Location pickUp)
{
    this->passenger = passenger;
    this->dropOff = dropOff;
    this->pickUp = pickUp;
    // maker random 4-digit assignmentID
    this->assignmentID = "";
    for (int i = 1; i <= 4; i++)
    {
        int digit = random();
        assignmentID += digit;
    }
}

Assignment::~Assignment() {}

std::string Assignment::getAssignmentID()
{
    return this->assignmentID;
}
Location Assignment::getPickUp()
{
    return this->pickUp;
}
Location Assignment::getDropOff()
{
    return this->dropOff;
}

std::ostream &operator<<(std::ostream &os, Assignment &assignment)
{
    // Assignment: 'pickUp' -> 'dropOff'
    os << "Assignment: " << "'" << assignment.getPickUp().getAddress() << "'" << " -> '" << assignment.getDropOff().getAddress() << "'" << std::endl;
    return os;
}
