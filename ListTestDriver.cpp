/*
 * ListTestDriver.cpp
 *
 * Class Description: A test driver to test the List class.
 *
 * Author: Michael Song
 * Date: September 24, 2022
 */

#include <cctype>
#include <iostream>
#include <string>

#include "List.h"
#include "Member.h"

using namespace std;

void testPart1(List* Members) {
    cout << "Testing insert():" << endl;
    Member m1 = Member("Xiao Wong", "778-123-1234", "xw123@coldmail.com",
            "9876 5432 1234 5678");     // valid format
    Member m2 = Member("Arwinder Singh", "604-231-4548", "meow@telthem.com",
            "2375 8765 9843 1208");     // valid format
    Member m3 = Member("Marie Lower", "778-778-7788", "marie@somewhere.ca",
            "5674 7890 2345 1276");     // valid format
    Member m4 = Member("Louis Pace", "604-853-1423", "louis@nowhere.com",
            "1234 5678 9098 7654");     // valid format
    Members->insert(m1);
    Members->insert(m2);
    Members->insert(m3);
    Members->insert(m4);
    Members->printList();
    cout << endl;

    cout << "Testing getElementCount():" << endl;
    cout << "Current element count is: " << Members->getElementCount() << endl;
    cout << endl;

    cout << "Testing insert() with wrong format:" << endl;
    Member m5 = Member("John Doe", "1233451212", "no@nothing.com",
            "7439 4743 2953 0901");     // wrong format
    Members->insert(m5);
    Members->printList();
    cout << endl;
}

void testPart2(List* Members) {
    cout << "Testing search():" << endl;
    Member m6 = Member("", "778-778-7788", "", "");     // member exists
    Member m7 = Member("", "176-346-9900", "", "");     // member does not exist
    if (Members->search(m6) == NULL) {
        cout << m6.getPhone() << " does not exist in the system." << endl;
    } else {
        cout << "Member Details: " << Members->search(m6)->getName() << ", "
                << Members->search(m6)->getPhone() << ", "
                << Members->search(m6)->getEmail() << ", "
                << Members->search(m6)->getCreditCard() << endl;
    }
    if (Members->search(m7) == NULL) {
        cout << m7.getPhone() << " does not exist in the system." << endl;
    } else {
        cout << "Member Details: " << Members->search(m7)->getName() << ", "
                << Members->search(m7)->getPhone() << ", "
                << Members->search(m7)->getEmail() << ", "
                << Members->search(m7)->getCreditCard() << endl;
    }
    cout << endl;

    cout << "Testing remove():" << endl;
    Member m8 = Member("", "604-231-4548", "", "");     // member exists
    Member m9 = Member("", "940-033-1212", "", "");     // member does not exist
    Members->remove(m8);
    Members->remove(m9);
    Members->printList();
    cout << endl;

    cout << "Testing removeAll():" << endl;
    Members->removeAll();
    cout << "Calling search() with empty array:" << endl;
    if (Members->search(m6) == NULL) {
        cout << m6.getPhone() << " does not exist in the system." << endl;
    } else {
        cout << "Member Details: " << Members->search(m6)->getName() << ", "
                << Members->search(m6)->getPhone() << ", "
                << Members->search(m6)->getEmail() << ", "
                << Members->search(m6)->getCreditCard() << endl;
    }
    cout << endl;

    cout << "Calling remove() with an empty array: " << endl;
    Members->remove(m8);
    Members->printList();
}

int main() {
    List* Members = new List();

    testPart1(Members);
    testPart2(Members);

    delete Members;
    Members = NULL;

    return 0;
}
