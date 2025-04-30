#ifndef RIDER_H
#define RIDER_H

#include "person.h"
#include "location.h"
#include <string>

class Rider : public Person {
private:
    std::string paymentMethod;
    Location homeAddress;
    Location workAddress;
    
public:
    // Constructors
    Rider();
    Rider(const std::string& id, const std::string& name, const std::string& phone,
          const std::string& paymentMethod, const Location& home, const Location& work);
    
    // Getters and setters
    std::string getPaymentMethod() const;
    void setPaymentMethod(const std::string& method);
    
    Location getHomeAddress() const;
    void setHomeAddress(const Location& location);
    
    Location getWorkAddress() const;
    void setWorkAddress(const Location& location);
    
    // Implementation of abstract method
    std::string getRole() const override;
    
    // For file I/O
    std::string toString() const override;
    static Rider fromString(const std::string& str);
};

#endif // RIDER_H
