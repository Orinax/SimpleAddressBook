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
void saveContactListToFile(const std::string& filename, const orderedListType<extPersonType>& addressBook);
void displayMainMenu();
void displayRelationshipMenu();

// Begin main program
int main() {
    personListType addressBook;
    extPersonType newContact;
    int choice, day, month, year, zip;
    std::string firstName, lastNameA, lastNameB;
    std::string street, city, state, relationship, phone, email;
    std::string reFamily = "Family_Member";
    std::string reFriend = "Friend";
    std::string reBusiness = "Business_Associate";
    std::string reAcademic = "Academic_Associate";
    std::string reAcquaintance = "Acquaintance";
    dateType dateA, dateB;
    bool valid = false;

    std::ifstream infile("contactData.txt");
    const std::string outfile("contactData.txt");

    if (!infile) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    createContactList(infile, addressBook);
    infile.close();

    displayMainMenu();
    std::cin >> choice;
    std::cout << std::endl;

    while (choice != 0) {
        switch (choice) {
            case 1:
                std::cout << "Enter the last name: ";
                std::cin >> lastNameA;
                std::cout << std::endl;
                if (addressBook.personSearch(lastNameA)) {
                    addressBook.printAddressInfo(lastNameA);
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
                std::cerr << "    No contacts have birthdays in that month." << std::endl;
                break;
            case 3:
                std::cout << "Enter a start date in format: d m yyyy: ";
                std::cin >> day >> month >> year;
                dateA.setDate(day, month, year);
                std::cout << "Enter an end date in format: d m yyyy: ";
                std::cin >> day >> month >> year;
                std::cout << std::endl;
                dateB.setDate(day, month, year);
                if (addressBook.printBdayByRange(dateA, dateB)) {
                    break;
                }
                std::cerr << "    No contacts with birthdays in that range." << std::endl;
                break;
            case 4:
                std::cout << "Please choose a relationship type. ";
                displayRelationshipMenu();
                std::cin >> choice;
                switch (choice) {
                    case 1: if (addressBook.relationshipPrint(reFamily)) {break;}
                        std::cout << "\n    No such relationships found." << std::endl; break;
                    case 2: if (addressBook.relationshipPrint(reFriend)) {break;}
                        std::cout << "\n    No such relationships found." << std::endl; break;
                    case 3: if (addressBook.relationshipPrint(reBusiness)) {break;}
                        std::cout << "\n    No such relationships found." << std::endl; break;
                    case 4: if (addressBook.relationshipPrint(reAcademic)) {break;}
                        std::cout << "\n    No such relationships found." << std::endl; break;
                    case 5: if (addressBook.relationshipPrint(reAcquaintance)) {break;}
                        std::cout << "\n    No such relationships found." << std::endl; break;
                    default: std::cerr << "\n    No such relationship." << std::endl; break;
                }
                break;
            case 5:
                std::cout << "Enter a last name to start searching from: ";
                std::cin >> lastNameA;
                std::cout << "Enter a last name to stop searching at: ";
                std::cin >> lastNameB;
                std::cout << std::endl;
                if (addressBook.printLastNameByRange(lastNameA, lastNameB)) {
                    break;
                }
                std::cout << "\n    No contacts found." << std::endl;
                break;
            case 6:
                std::cout << "Enter the new contact's first name: ";
                std::cin >> firstName;
                std::cout << "Enter the new contact's last name: ";
                std::cin >> lastNameA;
                std::cout << "Enter the new contact's birthday (d m yyyy): ";
                std::cin >> day >> month >> year;
                std::cin.ignore();
                std::cout << "Enter the new contact's street address: ";
                std::getline(std::cin, street);
                std::cout << "Enter the new contact's city: ";
                std::cin >> city;
                std::cout << "Enter the new contact's state: ";
                std::cin >> state;
                std::cout << "Enter the new contact's zip code: ";
                std::cin >> zip;
                std::cout << "Please choose a relationship type for the new contact: \n";
                while (valid == false) {
                    displayRelationshipMenu();
                    std::cin >> choice;
                    switch (choice) {
                        case 1: relationship = reFamily; valid = true; break;
                        case 2: relationship = reFriend; valid = true; break;
                        case 3: relationship = reBusiness; valid = true; break;
                        case 4: relationship = reAcademic; valid = true; break;
                        case 5: relationship = reAcquaintance; valid = true; break;
                        default: std::cerr << "\n    Invalid choice." << std::endl; break;
                    }
                }
                std::cout << "Please enter the new contact's phone number: ";
                std::cin >> phone;
                std::cout << "Please enter the new contact's email address: ";
                std::cin >> email;
                newContact.setPersonInfo(firstName, lastNameA, day, month, year,
                    street, city, state, zip, relationship, phone, email);
                addressBook.insert(newContact);
                std::cout << "\n    New contact created for " << firstName << " " << lastNameA << std::endl;
                break;
            case 7:
                std::cout << "Please enter the first and last name of the contact to delete: ";
                std::cin >> firstName >> lastNameA;
                if (addressBook.personRemove(firstName, lastNameA)) {
                    break;
                }
                std::cout << "\n    No such contact found." << std::endl; break;
            case 8:
                saveContactListToFile(outfile, addressBook); break;
            default:
                std::cout << "    Invalid choice" << std::endl; break;
        }
        std::cout << std::endl;
        displayMainMenu();
        std::cin >> choice;
        std::cout << std::endl;
    }
    std::cout << "    Goodbye!\n" << std::endl;

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

void saveContactListToFile(const std::string& filename, const orderedListType<extPersonType>& addressBook) {
    std::ofstream outfile(filename);

    if (!outfile) {
        std::cerr << "Error opening file.\n";
        return;
    }
    nodeType<extPersonType> *current = addressBook.getFirst();
    while (current != NULL) {
        extPersonType tempPerson = current->info;
        outfile << tempPerson.getFirstName() << " " << tempPerson.getLastName() << " "
        << tempPerson.getBirthDate().getDay() << " " << tempPerson.getBirthDate().getMonth() << " "
        << tempPerson.getBirthDate().getYear() << " \"" << tempPerson.getAddress().getStreetAddress() << "\" "
        << tempPerson.getAddress().getCity() << " " << tempPerson.getAddress().getState() << " "
        << tempPerson.getAddress().getZipCode() << " " << tempPerson.getRelationshipString() << " "
        << tempPerson.getPhoneNumber() << " " << tempPerson.getEmail() << " \n";

        current = current->link;
    }
    outfile.close();
    std::cout << "    List saved to " << filename << std::endl;
}

void displayMainMenu() {
    std::cout << "############### Simple Address Book ###############\n";
    std::cout << "Choose from the options listed below.\n";
    std::cout << "    1. Search for a contact by last name.\n";
    std::cout << "    2. Search for contacts by birth month.\n";
    std::cout << "    3. Search for contact birthdays in date range.\n";
    std::cout << "    4. Search for contacts based on relationship.\n";
    std::cout << "    5. Search for contacts between two last names.\n";
    std::cout << "    6. Add a new contact.\n";
    std::cout << "    7. Delete a contact.\n";
    std::cout << "    8. Save.\n";
    std::cout << "Enter the number that corresponds to your choice: ";
}

void displayRelationshipMenu() {
    std::cout << "Possible relationship types are: \n";
    std::cout << "    1. Family_Member\n";
    std::cout << "    2. Friend\n";
    std::cout << "    3. Business_Associate\n";
    std::cout << "    4. Academic_Associate\n";
    std::cout << "    5. Acquaintance\n";
    std::cout << "Enter the number that corresponds to your choice: ";
}

