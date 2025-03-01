//
// Created by cpelton on 3/1/25.
//
// linkedList.h original definition from D.S. Malik
// Class definition written in his book, Data Structures Using C++, pages 279 onward
// Any extensions or extras added to this header file are made by Chauncey Pelton.

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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


// Define the linkedList class third. (p. 282-...)
template <class Type>
class linkedListType {
public:
    // Overload the assignment operator.
    const linkedListType<Type>& operator=(const linkedListType<Type> &right);

    // Initialize the list to an empty state.
    void initializeList();

    // Function to determine whether the list is empty
    bool isEmptyList() const;

    // Function to output the data contained in each node.
    void print() const;

    // Function to return the number of nodes in the list.
    int length() const;

    // Function to delete all the nodes from the list.
    void destroyList();

    // Function to return the first element of the list.
    Type front() const;

    // Function to return the last element of the list.
    Type back() const;

    // Function to determine wheather searchItem is in the list.
    virtual bool search(const Type& searchItem) const = 0;

    // Function to insert newItem at the beginning of the list.
    virtual void insertFirst(const Type& newItem) = 0;

    // Function to insert newItem at th end of the list.
    virtual void insertLast(const Type& newItem) = 0;

    // Function to delete deleteItem from the list.
    virtual void deleteNode(const Type& deleteItem) = 0;

    // Function to return an iterator at the beginning of the linked list.
    linkedListIterator<Type> begin();

    // Function to return an iterator one element past the last element of the linked list.
    linkedListIterator<Type> end();

    // Default constructor
    linkedListType();

    // Copy constructor
    linkedListType(const linkedListType<Type> &otherList);

    // Destructor
    ~linkedListType();

protected:
    int count; // variable to store the number of elements in the list

    nodeType<Type> *first; // pointer to the first node of the list
    noteType<Type> *last; // pointer to the last node of the list

private:
    // Function to make a copy of otherList.
    void copyList(const linkedListType<Type> &otherList);
};


#endif //LINKEDLIST_H
