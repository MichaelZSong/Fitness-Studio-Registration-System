# Fitness Studio Registration System

A C++ application that manages member records for a fitness studio. This system allows front desk attendants to efficiently handle member registrations, modifications, removals, and print records in a structured format.

## Features

- Create and store records for new members, including personal and payment details.
- Remove the record of a member who leaves the fitness studio.
- Quickly search for a member's record by relevant details (name, phone, or email).
- Update existing records, such as credit card information or contact details.
- Print the current list of members, sorted in descending order of phone number.

### Data Model

Each member record stores the following:
- Name
- Phone Number
- Email Address
- Credit Card Number

The records are managed using a List ADT, ensuring efficient insertion, removal, and search operations.

## Usage

Use the provided Makefile to compile and run the project

```console
make
```

After compiling, run the program using:

```console
./fsrs
```