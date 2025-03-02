#include <iostream>
#include <fstream>

#include "addressType.h"
#include "extPersonType.h"
#include "orderedListType.h"
#include "personListType.h"

// Overloading the << operator to help with printing out addresses.
std::ostream& operator<<(std::ostream& osObject, const addressType& address) {
    osObject << address.streetAddress << std::endl;
    osObject << std::right << std::setw(14) << " " << address.city << ", " << address.state << std::endl;
    osObject << std::right << std::setw(14) << " " << address.zipCode << std::endl;
    return osObject;
}

std::ostream& operator<<(std::ostream& osObject, const extPersonType& personObject) {
    personObject.print();
    return osObject;
}

void createContactList(std::ifstream& infile, orderedListType<extPersonType>& addressBook);

void displayMenu();

// Begin main program
int main() {
    personListType addressBook;
    int choice;
    int month;
    std::string lastName;

    std::ifstream infile("contactData.txt");
    if (!infile) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    createContactList(infile, addressBook);
    infile.close();

    displayMenu();
    std::cin >> choice;
    std::cout << std::endl;

    while (choice != 0) {
        switch (choice) {
            case 1:
                std::cout << "Enter the last name: ";
                std::cin >> lastName;
                std::cout << std::endl;
                if (addressBook.personSearch(lastName)) {
                    addressBook.printAddressInfo(lastName);
                }
                else {
                    std::cerr << "    No such name." << std::endl;
                }
                break;
            case 2:
                std::cout << "Enter a number between 1 and 12 to search by month: ";
                std::cin >> month;
                std::cout << std::endl;
                if (addressBook.printBdayByMonth(month)) {
                    break;
                }
                else {
                    std::cerr << "    No contacts have birthdays in that month." << std::endl;
                }
                break;
            case 3:

            default:
                std::cout << "    Invalid choice" << std::endl; break;
        }
        std::cout << std::endl;
        displayMenu();
        std::cin >> choice;
        std::cout << std::endl;
    }
    std::cout << "Goodbye!" << std::endl;

    // for (const auto& person : addressBook) {
    //     person.print();
    // }
    // int num = addressBook.length();
    // std::cout << num << std::endl;
    return 0;
}

void createContactList(std::ifstream& infile, orderedListType<extPersonType>& addressBook) {
    std::string fname, lname, street, city, state, email, relationship, phone;
    int day, month, year, zip;

    extPersonType tempPerson;

    while (infile >> fname >> lname >> day >> month >> year) {
        infile.ignore(); // This will ignore the space before a quote

        if (infile.peek() == '"') {
            infile.get(); // Consume the opening quote
            std::getline(infile, street, '"'); // Read until the closing quote
            infile.ignore(); // This will ignore the space after the closing quote if needed.
        }
        else {
            infile >> street;
        }

        if (!(infile >> city >> state >> zip >> relationship >> phone >> email)) {
            std::cerr << "Error reading data. Skipping entry.\n";
            continue; // This will skip the current iteration if the reading failed
        }

        // // Printing out to help with debugging.
        // std::cout << "Inserting: " << fname << lname << day << month << year << street;
        // std::cout << city << state << zip << relationship << phone << email << std::endl;

        tempPerson.setPersonInfo(fname, lname, day, month, year, street, city, state,
            zip, relationship, phone, email);
        addressBook.insert(tempPerson);
    }
}

void displayMenu() {
    std::cout << "############### Simple Address Book ###############\n";
    std::cout << "Choose from the options listed below.\n";
    std::cout << "    1. Search for a contact by last name.\n";
    std::cout << "    2. Search for contacts by birth month.\n";
    std::cout << "    3. Search for contact birthdays in date range.\n";
    std::cout << "Enter the number that corresponds to your choice: ";
}
