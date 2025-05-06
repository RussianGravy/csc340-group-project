#include "../include/request.h"
using namespace std;

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
