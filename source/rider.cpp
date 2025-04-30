// #include "rider.h"
// #include <sstream>
// #include <vector>

// // Default constructor
// Rider::Rider() : Person() {}

// // Parameterized constructor
// Rider::Rider(const std::string& id, const std::string& name, const std::string& phone,
//        const std::string& paymentMethod, const Location& home, const Location& work)
//     : Person(id, name, phone), paymentMethod(paymentMethod), homeAddress(home), workAddress(work) {}

// // Getters and setters
// std::string Rider::getPaymentMethod() const {
//     return paymentMethod;
// }

// void Rider::setPaymentMethod(const std::string& method) {
//     paymentMethod = method;
// }

// Location Rider::getHomeAddress() const {
//     return homeAddress;
// }

// void Rider::setHomeAddress(const Location& location) {
//     homeAddress = location;
// }

// Location Rider::getWorkAddress() const {
//     return workAddress;
// }

// void Rider::setWorkAddress(const Location& location) {
//     workAddress = location;
// }

// // Implementation of abstract method
// std::string Rider::getRole() const {
//     return "Rider";
// }

// // For file I/O
// std::string Rider::toString() const {
//     std::stringstream ss;
//     ss << Person::toString() << "," << paymentMethod << ","
//        << homeAddress.toString() << "," << workAddress.toString();
//     return ss.str();
// }

// Rider Rider::fromString(const std::string& str) {
//     std::stringstream ss(str);
//     std::string item;
//     std::vector<std::string> tokens;
    
//     while (std::getline(ss, item, ',')) {
//         tokens.push_back(item);
//     }
    
//     // Parse Person data
//     std::string id = tokens[0];
//     std::string name = tokens[1];
//     std::string phone = tokens[2];
//     double rating = std::stod(tokens[3]);
//     int totalRatings = std::stoi(tokens[4]);
    
//     // Parse Rider-specific data
//     std::string paymentMethod = tokens[5];
    
//     // Parse home address
//     double homeLat = std::stod(tokens[6]);
//     double homeLon = std::stod(tokens[7]);
//     std::string homeAddr = tokens[8];
//     Location home(homeLat, homeLon, homeAddr);
    
//     // Parse work address
//     double workLat = std::stod(tokens[9]);
//     double workLon = std::stod(tokens[10]);
//     std::string workAddr = tokens[11];
//     Location work(workLat, workLon, workAddr);
    
//     Rider rider(id, name, phone, paymentMethod, home, work);
    
//     // Set rating manually since it's derived
//     for (int i = 0; i < totalRatings; i++) {
//         rider.addRating(rating / totalRatings);
//     }
    
//     return rider;
// }
