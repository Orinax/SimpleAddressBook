//
// Created by cpelton on 3/2/25.
//

#ifndef PERSONLISTTYPE_H
#define PERSONLISTTYPE_H
#include <string>
#include "orderedListType.h"
#include "extPersonType.h"

class personListType: public orderedListType<extPersonType> {
public:
    // Function to search the list to see if a person is in the list
    bool personSearch(std::string lastName) const {
        bool found = false;
        nodeType<extPersonType> *location;

        searchPersonList(lastName, found, location);
        return found;
    }

    // // Function to remove a person from the list
    // void personRemove(extPersonType person);
    //
    // // Function to add a person to the list
    // void personAdd(extPersonType person);

    // Function to print address for a person in the list
    void printAddressInfo(std::string lastName) {
        nodeType<extPersonType> *current;
        current = first;
        while (current != NULL) {
            if (current->info.checkLastName(lastName)) {
                current->info.print();
            }
            current = current->link;
        }
    }

    // Function to print people and their birthdays by month
    bool printBdayByMonth(int month) {
        bool canPrint = false;
        nodeType<extPersonType> *current;
        current = first;
        while (current != NULL) {
            if (current->info.getBirthDate().getMonth() == month) {
                std::cout << "    " << current->info.getFirstName() << " " << current->info.getLastName();
                std::cout << " has the birth month: " << month << std::endl;
                canPrint = true;
            }
            current = current->link;
        }
        return canPrint;
    }

    // Function to print people who have birthdays between specified dates
    void printBdayByRange(dateType startDate, dateType endDate) {
        nodeType<extPersonType> *current;
        current = first;
        while (current != NULL) {
            std::cout << "The contacts who have birthdays between ";
            std::cout << startDate.getDay() << "-" << startDate.getMonth() << startDate.getYear() << " and ";
            std::cout << endDate.getDay() << "-" << endDate.getMonth() << endDate.getYear() << ".";
            if (current->info.getBirthDate() >= startDate && current->info.getBirthDate() <= endDate) {
                std::cout << current->info.getFirstName() << " " << current->info.getLastName();
                std::cout << " has a birthday on ";
                current->info.printBirthDate();
            }
        }
    }

    // Function to print people based on their relationships
    void relationshipPrint(std::string relationship) {
        nodeType<extPersonType> *current;
        current = first;
        while (current != NULL) {
            std::cout << "The contacts with relationship status [" << relationship << "]" << "are:" << std::endl;
            if (current->info.getRelationshipString() == relationship) {
                std::cout << current->info.getFirstName() << " " << current->info.getLastName();
            }
        }
    }

    // Function to print names of all people between two last names
    void printLastNameByRange(std::string lastNameA, std::string lastNameB) {
        nodeType<extPersonType> *current;
        current = first;
        while (current != NULL) {
            if (current->info.getLastName() >= lastNameA && current->info.getLastName() <= lastNameB) {
                std::cout << current->info.getFirstName() << " " << current->info.getLastName();
            }
        }
    }

private:
    // Function to search the person list and point to the node for found person
    void searchPersonList(const std::string& lastName, bool& found, nodeType<extPersonType>* &current) const {
        found = false;
        current = first;

        while (current != NULL && !found) {
            if (current->info.checkLastName(lastName)) {
                found = true;
            }
            else {
                current = current->link;
            }
        }
    }
};

#endif //PERSONLISTTYPE_H
