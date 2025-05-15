#include "../include/request.h"
using namespace std;

Request::Request(Rider *rider, Location *pickUp, Location *dropOff)
{
    this->rider = rider;
    // Aaron Note -- Memory leak also from here because you are essentially allocating to the heap
    // Aaron Note -- Did not need to allocate and simpler to just assign the variables directly to the member variables
    this->pickUp = pickUp;
    this->dropOff = dropOff;
    //*this->pickUp = *pickUp;
    //*this->dropOff = *dropOff;
}
Request::~Request()
{
    delete rider;
    delete pickUp;
    delete dropOff;
}
// not sure how we doing the requist so i just set up pick up
Rider *Request::getRider() const
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
