#include "../include/rider.h"
#include <iostream>
#include "read.h"

Rider::Rider(std::string id, std::string name)
{
    this->id = id;
    this->name = name;
    // Aaron Note -- Memory leak here. No need to allocate unecessarily to the heap, just assign pointer to member variable
    /* this->currentLocation = loc; */
    // Aaron Note -- Redundant assignment of pointer variable
    //*this->currentLocation = *loc;
    this->rating = 0.0;
    this->totalRatings = 0;
}
Rider::~Rider()
{
}

void Rider::set_start_location(const Location& p_start) {
    start = p_start;
}

void Rider::set_destination_location(const Location &p_destination)
{
    destination = p_destination;
}

std::string Rider::getName() const {
    return name;
}

Location Rider::get_start_location() const {
    return start;
}

Location Rider::get_destination_location() const {
    return destination;
}

std::ostream& operator<<(std::ostream& os, const Rider& rider) {
    os << rider.getName() << " (" << rider.getID() << ")";
    return os;
}

std::istream& operator>>(std::istream& ins, Rider& p_rider) {

    std::cout << "Enter Rider Name: ";
    std::string rider_name = read(ins);
    std::cout << "Enter Rider ID: ";
    std::string rider_id = read(ins);


    p_rider.setName(rider_name);
    p_rider.setID(rider_id);
    return ins;
}
