//
// Created by cpelton on 2/24/25.
// personType original definition from D.S. Malik
// Class definition written in his book, Data Structures Using C++, pages 36-38
// Extensions to the class made by Chauncey Pelton.

#ifndef EXTPERSONTYPE_H
#define EXTPERSONTYPE_H
#include <iostream>
#include <ostream>
#include <string>

#include "dateType.h"
#include "addressType.h"

class extPersonType {
public:
    void print() const {
        std::cout << firstName << " " << lastName << std::endl;
    }

    void setName(std::string first, std::string last) {
        firstName = first;
        lastName = last;
    }

    std::string getFirstName() const {
        return firstName;
    }

    std::string getLastName() const {
        return lastName;
    }

    void printBirthDate() const {
        birthDate.printDate();
    }

    addressType getAddress() const {
        return address;
    }

    // Default Constructor
    extPersonType() {
        firstName = "--";
        lastName = "--";
        birthDate = dateType();
        address = addressType();
    }

    // Constructor with parameters
    extPersonType(std::string first, std::string last, int month, int day, int year,
        std::string street, std::string city, std::string state, int zip) {
        firstName = first;
        lastName = last;
        birthDate.setDate(month, day, year);
        address = addressType(street, city, state, zip);
    }

private:
    std::string firstName;
    std::string lastName;
    dateType birthDate;
    addressType address;
};
#endif //EXTPERSONTYPE_H
