/*
 * FitStudioReg.cpp - Assignment 1
 *
 * Class Description: Fitness Studio Registration System
 *
 * Author: Michael Song
 * Date: September 24, 2022
 */

#include <cctype>
#include <iostream>
#include <string>

#include "List.h"
#include "Member.h"

using std::cout;

void add(List* arr) {
    string ph;
    cout << "Please enter the phone number of the member you are adding: ";
    cin >> ph;

    Member m = Member(ph);
    if (arr->search(m) == NULL) {
        string n;
        cout << "Please enter the name of the member you are adding: ";
        getline(cin >> ws, n);

        string e;
        cout << "Please enter the email address of the member you are adding: ";
        cin >> e;

        string cc;
        cout
                << "Please enter the credit card number of the member you are adding: ";
        getline(cin >> ws, cc);

        Member m = Member(n, ph, e, cc);
        arr->insert(m);
        cout << "Success!" << endl;
    } else {
        cout << ph << " already exists in the system." << endl;
    }
}

void remove(List* arr) {
    string ph;
    cout << "Please enter the phone number of the member you are removing: ";
    cin >> ph;

    Member m = Member(ph);
    if (arr->search(m) != NULL) {
        arr->remove(m);
    } else {
        cout << ph << " does not exist in the system." << endl;
    }
}

void search(List* arr) {
    string ph;
    cout << "Please enter the phone number of the member you are searching: ";
    cin >> ph;
    Member m = Member(ph);
    if (arr->search(m) == NULL) {
        cout << ph << " does not exist in the system." << endl;
    } else {
        cout << "Member Details: " << arr->search(m)->getName() << ", "
                << arr->search(m)->getPhone() << ", "
                << arr->search(m)->getEmail() << ", "
                << arr->search(m)->getCreditCard() << endl;
    }
}

void modify(List* arr) {
    string ph;
    cout << "Please enter the phone number of the member you are modifying: ";
    cin >> ph;
    Member m = Member(ph);
    if (arr->search(m) == NULL) {
        cout << ph << " does not exist in the system." << endl;
    } else {
        cout << "Current member Details: " << arr->search(m)->getName() << ", "
                << arr->search(m)->getPhone() << ", "
                << arr->search(m)->getEmail() << ", "
                << arr->search(m)->getCreditCard() << endl;
        arr->remove(m);
        add(arr);
    }
}

void print(List* arr) {
    arr->printList();
}

int main() {
    // Variables declaration
    List* Members = new List();
    bool done = false;
    char input = 0;

    // Keep going until the user exits
    while (not done) {
        // Print menu to stdout
        cout << endl << "----Welcome to the Fitness Studio Registration System!"
                << endl;
        cout << endl << "Enter ..." << endl << endl;
        cout << "a -> to add a new member" << endl;
        cout << "r -> to remove a member" << endl;
        cout << "s -> to search for a member" << endl;
        cout << "m -> to modify the record of a member" << endl;
        cout << "p -> to print all members" << endl;
        cout << "x -> to exit\n" << endl;

        cout << "Your choice: ";
        cin >> input;
        cout << endl;
        input = tolower(input);
        switch (input) {
            case 'a':
                add(Members);
                break;
            case 'r':
                remove(Members);
                break;
            case 's':
                search(Members);
                break;
            case 'm':
                modify(Members);
                break;
            case 'p':
                print(Members);
                break;
            case 'x':
                cout << "\n----Bye!\n" << endl;
                done = true;
                break;
            default:
                cout << "Not sure what you mean! Please, try again!" << endl;
        }
    }

    delete Members;
    Members = NULL;

    return 0;
}
