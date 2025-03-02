//
// Created by cpelton on 3/1/25.
//
// linkedList.h original definition from D.S. Malik
// Class definition written in his book, Data Structures Using C++, pages 279 onward
// Any extensions or extras added to this header file are made by Chauncey Pelton.

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

// Define the node structure first. (p. 279-280)
template <class Type>
struct nodeType {
    Type info;
    nodeType<Type> *link;
};


// Define the iterator class second. (p. 280-282)
template <class Type>
class linkedListIterator {
public:
    // Default constructor
    linkedListIterator() {
        current = NULL;
    }

    // Constructor with a parameter
    linkedListIterator(nodeType<Type> *ptr) {
        current = ptr;
    }

    // Function to overload the dereferencing operator *.
    Type operator*() {
        return current->info;
    }

    // Function to overload the preincrement operator.
    linkedListIterator<Type> operator++() {
        current = current->link;
        return *this;
    }

    // Overload the equality operator.
    bool operator==(const linkedListIterator<Type> &right) const {
        return current == right.current;
    }

    // Overload the not equal operator.
    bool operator!=(const linkedListIterator<Type> &right) const {
        return current != right.current;
    }

private:
    nodeType<Type> *current; // a pointer to point to the current node in the linked list.
};


// Define the linkedList class third. (p. 282-292)
template <class Type>
class linkedListType {
public:
    // Overload the assignment operator.
    const linkedListType<Type>& operator=(const linkedListType<Type> &otherList) {
        if (this != &otherList) { // This check will avoid self-copying
            copyList(otherList);
        }
        return *this;
    }

    // Initialize the list to an empty state.
    void initializeList() {
        destroyList();  // if the list has any nodes, delete them
    }

    // Function to determine whether the list is empty
    bool isEmptyList() const {
        return (first == NULL);
    }

    // Function to output the data contained in each node.
    void print() const {
        nodeType<Type> *current = first;  // make a temporary pointer to travel through the list

        current = first;
        while (current != NULL) {
            std::cout << current->info << " ";
            current = current->link;
        }
    }

    // Function to return the number of nodes in the list.
    int length() const {
        return count;
    }

    // Function to delete all the nodes from the list.
    void destroyList() {
        nodeType<Type> *temp;   // pointer to deallocate the memory occupied by the node
        while (first != NULL) { // while there are nodes in the list
            temp = first;       // set temp to the current node
            first = first->link;// advance first to next node
            delete temp;        // deallocate the memory occupied by temp.
        }

        last = NULL;
        count = 0;
    }

    // Function to return the first element of the list.
    Type front() const {
        assert(first != NULL);
        return first->info;
    }

    // Function to return the first node of the list.
    nodeType<Type> *getFirst() const {
        return first;
    }

    // Function to return the last element of the list.
    Type back() const {
        assert(last != NULL);
        return last->info;
    }

    // Function to determine wheather searchItem is in the list.
    virtual bool search(const Type& searchItem) const = 0;

    // Function to insert newItem at the beginning of the list.
    virtual void insertFirst(const Type& newItem) = 0;

    // Function to insert newItem at th end of the list.
    virtual void insertLast(const Type& newItem) = 0;

    // Function to delete deleteItem from the list.
    virtual void deleteNode(const Type& deleteItem) = 0;

    // Function to return an iterator at the beginning of the linked list.
    linkedListIterator<Type> begin() {
        linkedListIterator<Type> temp(first);
        return temp;
    }

    // Function to return an iterator one element past the last element of the linked list.
    linkedListIterator<Type> end() {
        linkedListIterator<Type> temp(NULL);
        return temp;
    }

    // Default constructor
    linkedListType() {
        first = NULL;
        last = NULL;
        count = 0;
    }

    // Copy constructor
    linkedListType(const linkedListType<Type> &otherList) {
        first = NULL;
        copyList(otherList);
    }

    // Destructor
    ~linkedListType() {
        destroyList();
    }

protected:
    int count; // variable to store the number of elements in the list

    nodeType<Type> *first; // pointer to the first node of the list
    nodeType<Type> *last; // pointer to the last node of the list

private:
    // Function to make a copy of otherList.
    void copyList(const linkedListType<Type> &otherList) {
        nodeType<Type> *newNode;  // pointer to create a new node
        nodeType<Type> *current;  // pointer to traverse the list

        if (first != NULL) {
            destroyList();
        }

        if (otherList.first == NULL) {
            first = NULL;
            last = NULL;
            count = 0;
        }
        else {
            current = otherList.first;
            count = otherList.count;

            // Copy the first node
            first = new nodeType<Type>;
            first->info = current->info;
            first->link = NULL;
            last = first;
            current = current->link;

            // Copy the remaining list
            while (current != NULL) {
                newNode = new nodeType<Type>;
                newNode->info = current->info;
                newNode->link = NULL;
                last->link = newNode;
                last = newNode;
                current = current->link;
            }
        }
    }
};


#endif //LINKEDLIST_H
