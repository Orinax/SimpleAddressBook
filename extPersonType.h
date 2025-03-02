//
// Created by cpelton on 2/24/25.
// personType original definition from D.S. Malik
// Class definition written in his book, Data Structures Using C++, pages 36-38
// Extensions to the class made by Chauncey Pelton.

#ifndef EXTPERSONTYPE_H
#define EXTPERSONTYPE_H
#include <iostream>
#include <iomanip>
#include <ostream>
#include <string>

#include "dateType.h"
#include "addressType.h"

class extPersonType {
public:
    const extPersonType& operator=(const extPersonType& otherPerson) {
        if (this != &otherPerson) {
            copyPerson(otherPerson);
        }
        return *this;
    }

    bool operator==(const extPersonType& other) const {
        return (this->firstName == other.firstName) &&
            (this->lastName == other.lastName) &&
                (this->birthDate.getYear() == other.birthDate.getYear()) &&
                    (this->birthDate.getMonth() == other.birthDate.getMonth()) &&
                        (this->birthDate.getDay() == other.birthDate.getDay());
    }

    bool operator>=(const extPersonType& other) const {
        return (this->lastName >= other.lastName);
    }

    friend std::ostream& operator<<(std::ostream& osObject, const extPersonType& personObject);

    void print() const {
        std::cout << "############### Contact Info ###############" << std::endl;
        std::cout << std::right << std::setw(14) << "Name: " << firstName << " " << lastName << std::endl;
        std::cout << std::right << std::setw(14) << "Telephone: " << telephone << std::endl;
        std::cout << std::right << std::setw(14) << "Email: " << emailAddress << std::endl;
        std::cout << std::right << std::setw(14) << "Birthday: ";
        birthDate.printDate();
        std::cout << "Relationship: " << getRelationshipString() << std::endl;
        std::cout << std::right << std::setw(14) << "Address: " << address << std::endl;
    }

    void setPersonInfo(std::string fname, std::string lname, int day, int month, int year,
        std::string street, std::string city, std::string state, int zip, std::string relationship,
        std::string phone, std::string email) {
        setName(fname, lname);
        birthDate.setDate(day, month, year);
        setAddress(street, city, state, zip);
        setRelationship(relationship);
        setPhoneNumber(phone);
        setEmail(email);
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

    bool checkLastName(std::string last) const {
        if (lastName == last) {
            return true;
        }
        return false;
    }

    dateType getBirthDate() const {
        return birthDate;
    }

    void printBirthDate() const {
        birthDate.printDate();
    }

    void setAddress(std::string street, std::string city, std::string state, int zip) {
        address = addressType(street, city, state, zip);
    }

    addressType getAddress() const {
        return address;
    }

    void setPhoneNumber(const std::string number) {
        telephone = number;
    }

    std::string getPhoneNumber() const {
        return telephone;
    }

    void setEmail(std::string email) {
        emailAddress = email;
    }

    std::string getEmail() const {
        return emailAddress;
    }

    enum class Relationship {Family_Member, Friend, Business_Associate, Academic_Associate, Acquaintance};

    void setRelationship(Relationship newRelationship) {
        relationshipType = newRelationship;
    }

    // Set the relationship with a string input
    bool setRelationship(const std::string &relationshipString) {
        if (relationshipString == "Family_Member") relationshipType = Relationship::Family_Member;
        else if (relationshipString == "Friend") relationshipType = Relationship::Friend;
        else if (relationshipString == "Business_Associate") relationshipType = Relationship::Business_Associate;
        else if (relationshipString == "Academic_Associate") relationshipType = Relationship::Academic_Associate;
        else if (relationshipString == "Acquaintance") relationshipType =Relationship::Acquaintance;
        else return false;

        return true;
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

    // Copy one extPersonType object to another
    void copyPerson(const extPersonType &other) {
        firstName = other.firstName;
        lastName = other.lastName;
        birthDate = other.birthDate;
        address = other.address;
        relationshipType = other.relationshipType;
        telephone = other.telephone;
        emailAddress = other.emailAddress;
    }

    // Default Constructor
    extPersonType() {
        firstName = "";
        lastName = "";
        birthDate = dateType();
        address = addressType();
        relationshipType = Relationship::Acquaintance;
        telephone = "";
        emailAddress = "";
    }

    // Constructor with parameters
    extPersonType(std::string first, std::string last, int day, int month, int year,
        std::string street, std::string city, std::string state, int zip, std::string relationship,
        std::string phone, std::string email) {
        firstName = first;
        lastName = last;
        birthDate.setDate(day, month, year);
        address = addressType(street, city, state, zip);
        setRelationship(relationship);
        telephone = phone;
        emailAddress = email;
    }

    // Copy Constructor
    extPersonType(const extPersonType &otherPerson) {
        copyPerson(otherPerson);
    }

private:
    std::string firstName;
    std::string lastName;
    dateType birthDate;
    addressType address;
    Relationship relationshipType;
    std::string telephone;
    std::string emailAddress;
};
#endif //EXTPERSONTYPE_H
