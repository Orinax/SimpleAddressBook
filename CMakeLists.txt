cmake_minimum_required(VERSION 3.30)
project(SimpleAddressBook)

set(CMAKE_CXX_STANDARD 20)

add_executable(SimpleAddressBook main.cpp
        addressType.h
        extPersonType.h
        dateType.h
        linkedList.h
        orderedListType.h
        personListType.h)
