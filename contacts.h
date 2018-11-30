/* -------------------------------------------
Name: Harkaran Panesar
	Student number : 159875178
	Email : hpanesar2@myseneca.ca
	Section : B
----------------------------------------------
Assignment 2
Milestone 4
---------------------------------------------- */
// ----------------------------------------------------------------------------
// DO NOT remove the below 2 lines.
// The below two lines is needed to ensure only one copy
// of this header file is included when compiling the project.
// (it is referred to as "safeguarding")
// You will learn about this in C++ (OOP244/BTP200)
// For now, simply leave this code in!
#ifndef CONTACTS_H_
#define CONTACTS_H_
// ----------------------------------------------------------------------------

/* -------------------------------------------
Name: Josh Moscoe
Student number: 135873172
Email: jmoscoe@myseneca.ca
Section: SPP
Date: March 26 2018
----------------------------------------------
Assignment: 2
Milestone:  3
---------------------------------------------- */


//------------------------------------------------------
// Structure Types
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        structures here...                       |
// +-------------------------------------------------+

// Structure type Name declaration

struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};

struct Address {
	int streetNumber;
	char street[41];
	int apartmentNumber;
	char postalCode[8];
	char city[41];
};

struct Numbers {
	char cell[11];
	char home[11];
	char business[11];

};

struct Contact {
	struct Name name;
	struct Address address;
	struct Numbers numbers;
};





//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

void getName(struct Name *);

void getAddress(struct Address *);

void getNumbers(struct Numbers *);

void getContact(struct Contact *);



// ----------------------------------------------------------------------------
// DO NOT remove the below line (closing of the "safeguard" condition)
#endif // !CONTACTS_H_
