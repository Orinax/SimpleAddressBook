//
// Created by cpelton on 3/1/25.
//
// orderedListType.h original definition from D.S. Malik
// Class definition written in his book, Data Structures Using C++, pages 300-309.
// Any extensions or extras added to this header file are made by Chauncey Pelton.

#ifndef ORDEREDLISTTYPE_H
#define ORDEREDLISTTYPE_H
#include <iostream>

#include "linkedList.h"

template <class Type>
class orderedListType: public linkedListType<Type> {
public:
    // // Function to print
    // void printA() const {
    //     nodeType<Type> *current;
    //     current = this->first;
    //     while (current != NULL) {
    //         current->info.print();
    //         current = current->link;
    //     }
    // }

    // Function to determine whether searchItem is in the list.
    bool search(const Type& searchItem) const {
        bool found = false;
        nodeType<Type> *current; // Temporary pointer to travel through the list
        current = this->first;  // Start searching from the first node

        while (current != NULL && !found) {
            if (current->info >= searchItem) {
                found = true;
            }
            else {
                current = current->link;
            }
        }
        if (found) {
            found = (current->info == searchItem);
        }
        return found;
    }

    // Function to insert newItem in the list.
    void insert(const Type& newItem) {
        nodeType<Type> *current; // This pointer will travel the list
        nodeType<Type> *trailCurrent = NULL; // This points to just before current
        nodeType<Type> *newNode; // This pointer is used to create a new node

        bool found = false;

        newNode = new nodeType<Type>;
        newNode->info = newItem; // The newItem gets stored in the new node here
        newNode->link = NULL; // Set the link field of the node to be NULL for now

        if (this->first == NULL) {  // Case 1, an empty list
            this->first = newNode;
            this->last = newNode;
            this->count++;
        }
        else {
            current = this->first;
            found = false;

            while (current != NULL && !found) { // search through the list
                if (current->info >= newItem) {
                    found = true;
                }
                else {
                    trailCurrent = current;
                    current = current->link;
                }
            }
            if (current == this->first) {  // Case 2, insert at the beginning
                newNode->link = this->first;
                this->first = newNode;
                this->count++;
            }
            else {  // Case 3, insert in the middle or end
                trailCurrent->link = newNode;
                newNode->link = current;

                if (current == NULL) { // For inserting at the end
                    this->last = newNode;
                }
                this->count++;
            }
        }
    }

    // Function to insert newItem at teh beginning of the list.
    void insertFirst(const Type& newItem) {
        insert(newItem);
    }

    // Function to insert newItem at the end of the list.
    void insertLast(const Type& newItem) {
        insert(newItem);
    }

    // Function to delete deleteItem from the list.
    void deleteNode(const Type& deleteItem) {
        nodeType<Type> *current;  // The pointer that will travel through the list
        nodeType<Type> *trailCurrent; // The pointer that is just befor current
        bool found;

        if (this->first == NULL) { // Case 1
            std::cout << "Cannot delete from an empty list." << std::endl;
        }
        else {
            current = this->first;
            found = false;

            while (current != NULL && !found) {
                if (current->info >= deleteItem) {
                    found = true;
                }
                else {
                    trailCurrent = current;
                    current = current->link;
                }
            }

            if (current == NULL) {  // Case 4
                std::cout << "The item to be delete is not in the list." << std::endl;
            }
            else {
                if (current->info == deleteItem) {
                    if (this->first == current) {
                        // Case 2
                        this->first = this->first->link;

                        if (this->first == NULL) {
                            this->last = NULL;
                        }
                        delete current;
                    }
                    else {
                        trailCurrent->link = current->link;

                        if (current == this->last) {
                            this->last = trailCurrent;
                        }
                        delete current;
                    }
                    this->count--;
                }
                else {
                    std::cout << "The item to delete is not in the list." << std::endl;
                }
            }
        }
    }
};
#endif //ORDEREDLISTTYPE_H
