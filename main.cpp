#include <iostream>

#include "addressType.h"
#include "extPersonType.h"


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

    std::string fname = "bob";
    std::string lname = "bonzo";
    std::string street = "123 Street";
    std::string city = "Buffalo";
    std::string state = "New York";
    int zip = 12345;

    extPersonType person = extPersonType(fname, lname, 12, 5, 1989,
        street, city, state, zip);
    person.print();
    person.printBirthDate();
    std::cout << person.getAddress() << std::endl;
    extPersonType person2 = extPersonType();
    person2.print();
    person2.printBirthDate();
    std::cout << person2.getAddress() << std::endl;
    return 0;
}