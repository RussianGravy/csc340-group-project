#include "include/person.h"
#include "include/location.h"


#include <string>

using namespace std;

string Person::getId() const { return id; }
string Person::getName() const { return name; }
string Person::getPhone() const { return phone; }
double Person::getRating() const { return rating; }
int Person::getTotalRatings() const { return totalRatings; }



void Person::setId(const string& newId) { 
    id = newId; 
}

void Person::setName(const string& newName) { 
    name = newName; 
}

void Person::setPhone(const string& newPhone) { 
    phone = newPhone; 
}



