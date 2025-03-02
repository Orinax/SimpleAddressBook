#include <iostream>
#include <fstream>

#include "addressType.h"
#include "extPersonType.h"
#include "orderedListType.h"

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

void getContactInfo(std::ifstream& infile, orderedListType<extPersonType>& addressBook);


int main() {

    std::ifstream infile("contactData.txt");

    if (!infile) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    orderedListType<extPersonType> addressBook;

    getContactInfo(infile, addressBook);

    // getContactInfo(infile, tempPerson);
    infile.close();

    for (const auto& person : addressBook) {
        person.print();
    }
    int num = addressBook.length();
    std::cout << num << std::endl;
    // tempPerson.print();

    // Default Class Construction
    // std::cout << "\nDefault Person\n";
    // extPersonType person2 = extPersonType();
    // person2.print();



    // std::cout << "**********" << std::endl;
    //
    // orderedListType<int> list1, list2;
    // int num;
    //
    // std::cout << "Line 7: Enter numbers ending with -999." << std::endl;
    // std::cin >> num;
    //
    // while (num != -999) {
    //     list1.insert(num);
    //     std::cin >> num;
    // }
    //
    // std::cout << std::endl;
    // std::cout << "Line 15: list1: ";
    // list1.print();
    // std::cout << std::endl;
    //
    // list2 = list1;
    //
    // std::cout << "Line 19: list2: ";
    // list2.print();
    // std::cout << std::endl;
    //
    // std::cout << "Line 22: Enter the number to be deleted: ";
    // std::cin >> num;
    // std::cout << std::endl;
    //
    // list2.deleteNode(num);
    // std::cout << "Line 26: After deleting " << num << ", list2: " << std::endl;
    // list2.print();
    // std::cout << std::endl;
    //
    return 0;
}

void getContactInfo(std::ifstream& infile, orderedListType<extPersonType>& addressBook) {
    std::string fname, lname, street, city, state, email, relationship;
    int day, month, year, zip, phone;

    extPersonType tempPerson;

    while (infile) {
        infile >> fname >> lname >> day >> month >> year;

        infile.ignore(); // This will ignore the space before a quote
        if (infile.peek() == '"') {
            infile.get();
            std::getline(infile, street, '"');;
        }
        else {
            infile >> street;
        }
        infile >> city >> state >> zip >> relationship >> phone >> email;

        std::cout << "Inserting: " << fname << lname << day << month << year << street;
        std::cout << city << state << zip << relationship << phone << email;
        tempPerson.setPersonInfo(fname, lname, day, month, year, street, city, state,
            zip, relationship, phone, email);
        addressBook.insert(tempPerson);
        std::cout << tempPerson.getFirstName() << "Inserted" << std::endl;
    }
}
