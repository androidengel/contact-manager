#pragma once
/*
Advanced C++:	Course Project - Contact Manager
Programmer:		Andrew Engel
Date:			10/23/2017
Filename:		Menu.h
Purpose:		To provide a class definition for Menu.cpp
Input:			int, char
Output:			char
Exceptions:		invalid_argument, ios::failure, istream::failbit
*/

#include "ContactManager.h"

class Menu
{
private:
	char menuSelection;
	ContactManager contactManager;
	void getUpdateSubMenu(int);
	//purpose:	private helper method to launch Update Contact sub menu
	//input:	int (ID)
	//output:	void

public:
	Menu();
	//purpose:	constructor; initializes Menu object
	//input:	none
	//output:	none
	char getMenuSelection() const;
	//purpose:	return user's menu selection
	//input:	none
	//output:	const char
	void setMenuSelection(char);
	//purpose:	set MenuSelection data member that user input
	//input:	char
	//output:	void
	void displayEmptyListMessage() const;
	//purpose:	displays message to user indicating no contacts have been added to the ContactManager vector
	//input:	none
	//output:	void
	void displayAllContacts();
	//purpose:	displays pre-formatted string of contacts to console
	//input:	none
	//output:	void
	void displaySingleRecord(int);
	//purpose:	displays pre-formatted string of single contact to console
	//input:	int (ID)
	//output:	void
	void displayWelcomeMessage();
	//purpose:	displays welcome message for when application first runs
	//input:	none
	//output:	void
	void displayMainMenu();
	//purpose:	displays main menu options to console
	//input:	none
	//output:	void
	void displayInvalidMessage();
	//purpose:	displays message that user's input was invalid
	//input:	none
	//output:	void
	void launchAddMenu();
	//purpose:	launches menu for adding a new contact
	//input:	none
	//output:	void
	void launchUpdateMenu();
	//purpose:	launches menu for updating an existing contact
	//input:	none
	//output:	void
	void launchDeleteMenu();
	//purpose:	launches menu for deleting an existing contact
	//input:	none
	//output:	void
	void launchSearchMenu();
	//purpose:	launches menu to search for an existing contact
	//input:	none
	//output:	void
	void setFirstNameMenu(int);
	//purpose:	launches menu to obtain and set contact's first name
	//input:	int (ID)
	//output:	void
	void setLastNameMenu(int);
	//purpose:	launches menu to obtain and set contact's last name
	//input:	int (ID)
	//output:	void
	void setTelephoneMenu(int);
	//purpose:	launches menu to obtain and set contact's telephone number
	//input:	int (ID)
	//output:	void
	void setEmailMenu(int);
	//purpose:	launches menu to obtain and set contact's email address
	//input:	int (ID)
	//output:	void
	void setAgeMenu(int);
	//purpose:	launches menu to obtain and set contact's age
	//input:	int (ID)
	//output:	void
	void setTitleMenu(int);
	//purpose:	launches menu to obtain and set contact's title
	//input:	int (ID)
	//output:	void
	void setManagerMenu(int);
	//purpose:	launches menu to obtain and set contact's manager
	//input:	int (ID)
	//output:	void
};

