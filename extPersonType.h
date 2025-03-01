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
    enum class Relationship {Family_Member, Friend, Business_Associate, Academic_Associate, Acquaintance};

// private:
//     // Private member of the Relationship class.
//     Relationship relationshipType; // Member variable of type Relationship.

public:
    // Constructor for the Relationship class.
    // explicit extPersonType(Relationship type): relationshipType(type) {}

    void setRelationship(Relationship newRelationship) {
        relationshipType = newRelationship;
    }

    [[nodiscard]] Relationship getRelationship() const {
        return relationshipType;
    }

    // Convert the Relationship type to a string for easy access.
    [[nodiscard]] std::string getRelationshipString() const {
        switch (relationshipType) {
            case Relationship::Family_Member: return "Family_Member";
            case Relationship::Friend: return "Friend";
            case Relationship::Business_Associate: return "Business_Associate";
            case Relationship::Academic_Associate: return "Academic_Associate";
            case Relationship::Acquaintance: return "Acquaintance";
            default: return "Unknown";
        }
    }

    void print() const {
        std::cout << firstName << " " << lastName << std::endl;
        //std::cout << categoryToString(category.)
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



    // [[nodiscard]] Relationship getCategory() const {
    //     return category;
    // }

    // Default Constructor
    extPersonType() {
        firstName = "--";
        lastName = "--";
        birthDate = dateType();
        address = addressType();
        relationshipType = Relationship::Acquaintance;
    }

    // Constructor with parameters
    extPersonType(std::string first, std::string last, int month, int day, int year,
        std::string street, std::string city, std::string state, int zip, Relationship type) {
        firstName = first;
        lastName = last;
        birthDate.setDate(month, day, year);
        address = addressType(street, city, state, zip);
        relationshipType = type;
    }

private:
    std::string firstName;
    std::string lastName;
    dateType birthDate;
    addressType address;
    Relationship relationshipType;
};
#endif //EXTPERSONTYPE_H
