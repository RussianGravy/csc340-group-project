#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
protected:
    std::string id;
    std::string name;
    std::string phone;
    double rating;
    int totalRatings;

public:
    // Constructors
    Person();
    Person(const std::string& id, const std::string& name, const std::string& phone);
    virtual ~Person() = default;
    
    // Getters and setters
    std::string getId() const;
    void setId(const std::string& id);
    
    std::string getName() const;
    void setName(const std::string& name);
    
    std::string getPhone() const;
    void setPhone(const std::string& phone);
    
    double getRating() const;
    void addRating(int rating);
    
    // Pure virtual method to make this an abstract class
    virtual std::string getRole() const = 0;
    
    // For file I/O
    virtual std::string toString() const;
};

#endif // PERSON_H
