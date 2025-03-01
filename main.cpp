#include <iostream>

#include "addressType.h"
#include "extPersonType.h"

// Overloading the << operator to help with printing out addresses.
std::ostream& operator<<(std::ostream& osObject, const addressType& address) {
    osObject << "Street address: " << address.streetAddress << std::endl;
    osObject << "City: " << address.city << std::endl;
    osObject << "State: " << address.state << std::endl;
    osObject << "Zip code: " << address.zipCode << std::endl;
    return osObject;
}


int main() {
    addressType address;
    std::cout << address << std::endl;

    // Sample variables to help with testing.
    std::string fname = "bob";
    std::string lname = "bonzo";
    std::string street = "123 Street";
    std::string city = "Buffalo";
    std::string state = "New York";
    int zip = 12345;
    int phone = 1234567890;
    std::string email = "demo@email.com";

    // Parameterized Class Construction
    extPersonType person = extPersonType(fname, lname, 12, 5, 1989,
        street, city, state, zip, extPersonType::Relationship::Friend, phone, email);
    person.print();
    person.printBirthDate();
    std::cout << person.getAddress() << "\n" << person.getRelationshipString() << "\n";
    std::cout << person.getPhoneNumber() << "\n" << person.getEmail() << std::endl;

    // Default Class Construction
    std::cout << "\nDefault Person\n";
    extPersonType person2 = extPersonType();
    person2.print();
    person2.printBirthDate();
    std::cout << person2.getAddress() << "\n" << person2.getRelationshipString() << "\n";
    std::cout << person2.getPhoneNumber() << "\n" << person2.getEmail() << "\n";
    return 0;
}