/* -------------------------------------------
Name: Harkaran Panesar
	Student number : 159875178
	Email : hpanesar2@myseneca.ca
	Section : B
----------------------------------------------
Assignment 2
Milestone 4
---------------------------------------------- */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>


// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"

#define MAXCONTACTS 5 
//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        function definitions below...            |
// +-------------------------------------------------+

void clearKeyboard(void)
{
	char getchar = 0;
	while (getchar != '\n'){// empty execution code block on purpose
		scanf("%c", &getchar);
	}
}


void pause(void) {

	printf("(Press Enter to continue)");
	clearKeyboard();

}


int getInt(void)
{
	int num;
	char newline = 0;
	do
	{
		scanf("%d%c", &num, &newline);
		if (newline != '\n') {
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			clearKeyboard();
		}
	} while (newline != '\n');
	return num;
}

int getIntInRange(int min, int max)
{
	int value;
	int f = 0;
	while (f == 0)
	{
		value = getInt();
		if (value < min || value > max) {
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		}
		else
		{
			f = 1;
		}
	}
	return value;

}


int yes(void)
{
	char value, check;
	while (1) {
		scanf(" %c", &value);
		scanf("%c", &check);
		if ((value == 'N' || value == 'n') && check == '\n') {
			return 0;
		}
		else if ((value == 'Y' || value == 'y') && check == '\n') {
			return 1;
		}
		else {
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			clearKeyboard();
			continue;
			yes();


		}
	}

}


int menu(void) {
	int chosen;
	char check;


	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\nSelect an option:> ");

	chosen = getIntInRange(0, 6);

	return chosen;
}


void ContactManagerSystem(void) {
	struct Contact cn[MAXCONTACTS] = { { { "Rick",{ '\0' },"Grimes" } ,{ 11,"Trailer Park",0, "A7A 2J2", "King City" } ,{ "4161112222", "4162223333", "4163334444" } } ,
	{ { "Maggie","R.", "Greene" } ,{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" } ,{ "9051112222", "9052223333", "9053334444" } } ,
	{ { "Morgan", "A.", "Jones" } ,{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" } ,{ "7051112222", "7052223333", "7053334444" } } ,
	{ { "Sasha",{ '\0' }, "Williams" },{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },{ "9052223333", "9052223333", "9054445555" } }, };
	int option = 00 , feature;
	do {
		feature = menu();
		printf("\n");
		if (feature == 1) {
			displayContacts(cn, MAXCONTACTS);
			pause();
		}
		else if (feature == 2) {
			addContact(cn, MAXCONTACTS);
			pause();
		}
		else if (feature == 3) {
			updateContact(cn, MAXCONTACTS);
			pause();
		}
		else if (feature == 4) {
			deleteContact(cn, MAXCONTACTS);
			pause();
		}
		else if (feature == 5) {
			searchContacts(cn, MAXCONTACTS);
			pause();
		}
		else if (feature == 6) {
			sortContacts(cn, MAXCONTACTS);
			pause();
		}
		else if (feature == 0) {
			printf("Exit the program? (Y)es/(N)o: ");
			option = yes();

			if (option == 1)
				printf("\nContact Management System: terminated\n");
		}
		printf("\n");
	} while (option == 0);
}


// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10 chars entered)
void getTenDigitPhone(char telNum[])
{
	int needInput = 0, i;

	while (needInput == 0) {
		scanf("%10s", telNum);
		clearKeyboard();
		int check = 0;

		// (String Length Function: validate entry of 10 characters)
		if (strlen(telNum) == 10)
		{
			for (i = 0; i < 10; i++)
			{

				if (telNum[i] >= '0' && telNum[i] <= '9') {

					check++;

				}

			}

			if (check == 10)
			{
				needInput = 1;
			}

			else {
				printf("Enter a 10-digit phone number: ");
			}
		}
		else
		{
			printf("Enter a 10-digit phone number: ");

		}
	}
}
// findContactIndex:
int findContactIndex(const struct Contact cn[], int size, const char cellNum[])
{
	int i = 0;
	int result = -1;
	for (i = 0; i < size; i++) {
		if (strcmp(cn[i].numbers.cell, cellNum) == 0)
			result = i;
	}
	return result;
}

// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int x) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", x);
}

// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact *cn) {
	if ((*cn).name.middleInitial[0] == '\0')
		printf("%s %s\n", (*cn).name.firstName, (*cn).name.lastName);
	else
		printf("%s %s %s\n", (*cn).name.firstName, (*cn).name.middleInitial, (*cn).name.lastName);
	printf("    C: %-10s   H: %-10s   B: %-10s\n", (*cn).numbers.cell, (*cn).numbers.home, (*cn).numbers.business);
	if ((*cn).address.apartmentNumber > 0)
		printf("       %d %s, Apt# %d, %s, %s\n", (*cn).address.streetNumber, (*cn).address.street, (*cn).address.apartmentNumber, (*cn).address.city, (*cn).address.postalCode);
	else
		printf("       %d %s, %s, %s\n", (*cn).address.streetNumber, (*cn).address.street, (*cn).address.city, (*cn).address.postalCode);
}

// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact cn[], int size) {
	int i, counter = 0;
	displayContactHeader();
	for (i = 0; i < size; i++) {
		if (strlen(cn[i].numbers.cell) > 0) {
			displayContact(&cn[i]);
			counter++;
		}
	}
	displayContactFooter(counter);
}

// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact cn[], int size) {
	char cellNum[11];
	int index;
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNum);
	index = findContactIndex(cn, size, cellNum);
	if (index != -1) {
		printf("\n");
		displayContact(&cn[index]);
		printf("\n");
	}
	else
		printf("*** Contact NOT FOUND ***\n\n");
}

// addContact:
// Put empty function definition below:
void addContact(struct Contact cn[], int size) {
	int i = 0;
	int conNum = -1;
	for (i = 0; i < size; i++) {
		if (strlen(cn[i].numbers.cell) == 0)
			conNum = i;
	}
	if (conNum != -1) {
		getContact(&cn[conNum]);
		printf("--- New contact added! ---\n\n");
	}
	else
		printf("*** ERROR: The contact list is full! ***\n\n");
}


// updateContact:
// Put empty function definition below:
void updateContact(struct Contact cn[], int size) {
	int edit, choice;
	char cellNum[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNum);
	edit = findContactIndex(cn, size, cellNum);
	if (edit == -1)
		printf("*** Contact NOT FOUND ***\n\n");
	else {
		printf("\nContact found:\n");
		displayContact(&cn[edit]);
		printf("\nDo you want to update the name? (y or n): ");
		choice = yes();
		if (choice == 1)
			getName(&cn[edit].name);

		printf("Do you want to update the address? (y or n): ");
		choice = yes();
		if (choice == 1)
			getAddress(&cn[edit].address);

		printf("Do you want to update the numbers? (y or n): ");
		choice = yes();
		if (choice == 1)
			getNumbers(&cn[edit].numbers);
		printf("--- Contact Updated! ---\n\n");
	}
}

// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact cn[], int size) {
	char cellNum[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNum);
	int rm = findContactIndex(cn, size, cellNum);
	if (rm == -1)
		printf("*** Contact NOT FOUND ***\n");
	else {
		printf("\nContact found: \n");
		displayContact(&cn[rm]);
		printf("\nCONFIRM: Delete this contact? (y or n): ");
		int delete = yes();
		if (delete == 1) {
			*cn[rm].numbers.cell = '\0';
			*cn[rm].numbers.home = '\0';
			printf("--- Contact deleted! ---\n\n");
		}
		else
		{
			printf("\n");
		}
	}
}

// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact cn[], int size) {
	int i, j, m, test = 0;
	char temp[11];
	for (i = 0; i < size; i++) {
		m = i;
		for (j = 1 + i; j < size; j++) {
			
			if (strcmp(cn[j].numbers.cell, cn[m].numbers.cell) < 0) {
				m = j;
				
			}
			test = strcmp(cn[j].numbers.cell, cn[m].numbers.cell);
		}
		if (m != i) {
			strcpy(temp, cn[i].numbers.cell);
			strcpy(cn[i].numbers.cell, cn[m].numbers.cell);
			strcpy(&cn[m].numbers.cell[m], temp);
		}
		
	}
	printf("--- Contacts sorted! ---\n\n");
}


