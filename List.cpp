/*
 * List.cpp
 *
 * Class Description: A test driver to test the List class.
 *
 * Author: Michael Song
 * Date: September 24, 2022
 */

#include <iostream>
#include <string>

#include "List.h"

// Description: Factor all code that destroy or remove all elements from the List into
//              this method. Then call it from whichever method needs this functionality.
void List::clear() {
    delete[] elements;
    elements = NULL;
    elementCount = 0;
}

// Default constructor
List::List() {
    elements = new Member[CAPACITY];
}

// Destructor
// Description: Destruct a List object, releasing heap-allocated memory.
List::~List() {
    clear();
}

// Description: Returns the total number of elements currently stored in List.
unsigned int List::getElementCount() const {
    return elementCount;
}

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.
// Postcondition: newElement inserted in its proper place in List
//                and elementCount has been incremented.
bool List::insert(Member& newElement) {
    if (elementCount >= CAPACITY) {
        return false;
    }

    int index = 0;
    for (unsigned int i = 0; i < elementCount; i++) {
        if (newElement.getPhone() < elements[i].getPhone()) {
            index = i + 1;
        }
    }

    for (int i = elementCount; i > index; i--) {
        elements[i] = elements[i - 1];
    }

    elements[index] = newElement;
    elementCount++;
    return true;
}

// Description: Remove an element.
// Postcondition: toBeRemoved is removed (leaving no gap in the data structure of List)
//                and elementCount has been decremented.
bool List::remove(Member& toBeRemoved) {
    if (elementCount == 0) {
        return false;
    }

    bool found = false;
    int index = 0;
    for (unsigned int i = 0; i < elementCount; i++) {
        if (toBeRemoved.getPhone() == elements[i].getPhone()) {
            index = i;
            found = true;
        }
    }

    if (found == false) {
        return false;
    }

    for (unsigned int i = index; i < elementCount; i++) {
        elements[i] = elements[i + 1];
    }

    elementCount--;
    return true;
}

// Description: Remove all elements.
// Postcondition: List is back to the state it was right after being constructed.
void List::removeAll() {
    clear();
}

// Description: Search for target element.
//              Returns a pointer to the element if found, otherwise, returns NULL.
Member* List::search(Member& target) {
    if (elementCount == 0) {
        return NULL;
    }

    bool found = false;
    int index = 0;
    for (unsigned int i = 0; i < elementCount; i++) {
        if (target.getPhone() == elements[i].getPhone()) {
            index = i;
            found = true;
        }
    }

    if (found == false) {
        return NULL;
    } else {
        return &elements[index];
    }
}

// Description: Prints all elements stored in List by descending order of search key.
// Time Efficiency: O(n)
void List::printList() {
    for (unsigned int i = 0; i < elementCount; i++) {
        cout << elements[i].getName() << ", " << elements[i].getPhone() << ", "
                << elements[i].getEmail() << ", " << elements[i].getCreditCard()
                << endl;
    }
}
