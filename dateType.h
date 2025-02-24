//
// Created by cpelton on 2/24/25.
//
// dateType original definition from D.S. Malik
// Class definition written in his book, Data Structures Using C++, pages 80-82

#ifndef DATETYPE_H
#define DATETYPE_H
#include <iostream>
#include <ostream>

class dateType {
public:
    void setDate(int month, int day, int year) {
        dMonth = month;
        dDay = day;
        dYear = year;
    }

    int getDay() const {
        return dDay;
    }

    int getMonth() const {
        return dMonth;
    }

    int getYear() const {
        return dYear;
    }

    void printDate() const {
        std::cout << dMonth << "-" << dDay << "-" << dYear << std::endl;
    }

    // Default constructor
    dateType(int month = 1, int day = 1, int year = 1900) {
        setDate(month, day, year);
    }

private:
    int dMonth;
    int dDay;
    int dYear;
};
#endif //DATETYPE_H
