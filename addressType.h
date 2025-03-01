//
// Created by cpelton on 2/24/25.
//

// Define a class, addressType, that can store a street address, city, state, and zip code.
// Use the appropriate functions to print and store the address.
// Also, use constructors to automatically initialize the data members.

#ifndef ADDRESSTYPE_H
#define ADDRESSTYPE_H
#include <string>

class addressType {
public:
    // add all the functions here
    void setStreetAddress(std::string streetAddress) {
        this->streetAddress = streetAddress;
    }

    void setCity(std::string city) {
        this->city = city;
    }

    void setState(std::string state) {
        this->state = state;
    }

    void setZipCode(int zipCode) {
        this->zipCode = zipCode;
    }

    friend std::ostream& operator<<(std::ostream&, const addressType&);

    // Default constructor
    addressType() {
        streetAddress = "--";
        city = "--";
        state = "--";
        zipCode = 0;
    }

    // Constructor with parameters
    addressType(std::string streetAddress, std::string city, std::string state, int zipCode) {
        setStreetAddress(streetAddress);
        setCity(city);
        setState(state);
        setZipCode(zipCode);
    }

private:
    std::string streetAddress;
    std::string city;
    std::string state;
    int zipCode;
};

#endif //ADDRESSTYPE_H
