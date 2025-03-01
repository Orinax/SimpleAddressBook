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
    void setDate(int day, int month, int year) {
        dDay = day;
        dMonth = month;
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
        std::cout << dDay << "-" << dMonth << "-" << dYear << std::endl;
    }

    // Default constructor
    dateType(int day = 1, int month = 1, int year = 1900) {
        setDate(day, month, year);
    }

private:
    int dDay;
    int dMonth;
    int dYear;
};
#endif //DATETYPE_H
