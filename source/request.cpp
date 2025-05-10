#include "../include/request.h"
using namespace std;

Request::Request(Rider *rider, Location *pickUp, Location *dropOff)
{
    this->rider = rider;
    this->pickUp = new Location();
    this->dropOff = new Location();
    *this->pickUp = *pickUp;
    *this->dropOff = *dropOff;
}
Request::~Request()
{
    delete rider;
    delete pickUp;
    delete dropOff;
}
// not sure how we doing the requist so i just set up pick up
Rider *Request::getRider()
{
    return this->rider;
}
Location *Request::getPickUp() const
{
    return this->pickUp;
}
Location *Request::getDropOff() const
{
    return this->dropOff;
}
