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

#include "contacts.h"

#include "contactHelpers.h"


void getName(struct Name *contacts)
{


	printf("Please enter the contact's first name: ");
	scanf(" %[^\n]s", contacts->firstName);
	clearKeyboard();
	printf("Do you want to enter a middle initial(s)? (y or n): ");

	if (yes()) {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]", contacts->middleInitial);
		clearKeyboard();
	}
	else
	{
		*contacts->middleInitial = '\0';
	}

	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]", contacts->lastName);
	clearKeyboard();


}


// getAddress:
void getAddress(struct Address *contacts)
{


	printf("Please enter the contact's street number: ");
	contacts->streetNumber = getInt();

	while (contacts->streetNumber < 0)
	{
		printf("Please enter the contact's street number: ");
		scanf("%d", &contacts->streetNumber);
		clearKeyboard();
	}

	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]", contacts->street);
	clearKeyboard();
	printf("Do you want to enter an apartment number? (y or n): ");

	if (yes()) {
		printf("Please enter the contact's apartment number: ");
		contacts->apartmentNumber = getInt();

	}
	while (contacts->apartmentNumber < 0)
	{
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &contacts->apartmentNumber);
		clearKeyboard();
	}
	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", contacts->postalCode);
	clearKeyboard();

	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]", contacts->city);
	clearKeyboard();
}

void getNumbers(struct Numbers *nums) {


	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(nums->cell);


	printf("Do you want to enter home phone number? (y or n): ");

	if (yes()) {
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(nums->home);
	}
	else 
	{
		*nums->home = '\0';
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	
	if (yes()) {
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(nums->business);
	}
	else
	{
		*nums->business = '\0';
	}

}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// +-------------------------------------------------+
void getContact(struct Contact *contacts)
{
	getName(&contacts->name);
	getAddress(&contacts->address);
	getNumbers(&contacts->numbers);
}