/*
Advanced C++:	Course Project - Contact Manager
Programmer:		Andrew Engel
Date:			10/23/2017
Filename:		Menu.cpp
Purpose:		A class to handle screen output for the contact manager program
Input:			int, char
Output:			char
Exceptions:		invalid_argument, ios::failure, istream::failbit
*/

#include "stdafx.h"
#include "Menu.h"
#include <iostream>
#include <string>

using namespace std;

Menu::Menu()
{
}

char Menu::getMenuSelection() const
{
	return menuSelection;
}

void Menu::displayEmptyListMessage() const
{
	cout << "No records in list. ";
}

void Menu::setMenuSelection(char selection)
{
	menuSelection = tolower(selection);
}

void Menu::getUpdateSubMenu(int ID)		//private helper method to launchUpdateMenu()
{
	char selection = ' ';
	cout << "Select which information to update:\n"
		<< "1. First name\n" << "2. Last name\n"
		<< "3. Phone number\n" << "4. Email Address\n"
		<< "5. Age\n" << "6. Title\n" << "7. Manager\n" 
		<< "Q. Return to main menu" << endl;

	cin >> selection;		//get user's input
	cin.exceptions(istream::failbit);
	try
	{
		switch (tolower(selection))
		{
		case '1':
			setFirstNameMenu(ID);
			cout << "First name updated!" << endl;
			break;
		case '2':
			setLastNameMenu(ID);
			cout << "Last name updated!" << endl;
			break;
		case '3':
			setTelephoneMenu(ID);
			cout << "Phone number updated!" << endl;
			break;
		case '4':
			setEmailMenu(ID);
			cout << "Emaill address updated!" << endl;
			break;
		case '5':
			setAgeMenu(ID);
			cout << "Age updated!" << endl;
			break;
		case '6':
			setTitleMenu(ID);
			cout << "Title updated!" << endl;
			break;
		case '7':
			setManagerMenu(ID);
			cout << "Manager updated!" << endl;
			break;
		case 'q':
			break;
		default:
			cout << "Invalid entry. Returning to main menu." << endl;
			break;
		}
	}
	catch (ios::failure)
	{
		cout << "Age cannot contain letters. Returning to main menu." << endl;
		cin.clear();
		cin.ignore();
		return;
	}
	
}	//end getUpdateSubMenu() function

void Menu::displayAllContacts()
{
	cout << contactManager.displayAllContacts() << endl;
}

void Menu::displaySingleRecord(int ID)
{
	cout << contactManager.displaySingleRecord(ID) << endl;
}

void Menu::displayWelcomeMessage()
{
	cout << "Welcome to the Contact Manager Application!" << endl;
}

void Menu::displayMainMenu()	//displays menu and calls setMenuSelection()
{
	char selection = ' ';
	cout << "\nPlease select on of the following options:\n"
		<< "1. Add a contact\n"
		<< "2. Update a contact\n"
		<< "3. Delete a contact\n"
		<< "4. Search for a contact\n"
		<< "5. Display all contacts\n"
		<< "Q. Quit" << endl;

	cin >> selection;

	setMenuSelection(selection);
}

void Menu::displayInvalidMessage()
{
	cout << "Invalid Entry." << endl;
}

void Menu::launchAddMenu()
{
	bool userAdded = false;
	int menuSequence = 1;

	int ID = contactManager.addContact();
	cin.exceptions(istream::failbit);
	while (!userAdded)
	{
		try
		{
			switch (menuSequence)
			{
			case 1:
				setFirstNameMenu(ID);
				menuSequence = 2;
				break;
			case 2:
				setLastNameMenu(ID);
				menuSequence = 3;
				break;
			case 3:
				setTelephoneMenu(ID);
				menuSequence = 4;
				break;
			case 4:
				setEmailMenu(ID);
				menuSequence = 5;
				break;
			case 5:
				setAgeMenu(ID);
				menuSequence = 6;
				break;
			case 6:
				setTitleMenu(ID);
				menuSequence = 7;
				break;
			case 7:
				setManagerMenu(ID);
				userAdded = true;
				break;
			default:
				break;
			}
		}
		catch (invalid_argument& ex)
		{
			cout << ex.what() << endl;
		}
		catch(ios::failure)
		{ 
			cout << "This field cannot contain letters." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}

	cout << "Contact Added!\n";
}

void Menu::launchUpdateMenu()
{
	//check if list is empty
	if (contactManager.isContactListEmpty())
	{
		displayEmptyListMessage();
		return;
	}

	//if not empty, get ID from user
	int ID = 0;
	cin.exceptions(istream::failbit);		//enable istream exceptions
	try
	{
		cout << "Please enter an employee ID: ";
		cin >> ID;
	}
	catch (ios::failure)
	{
		cout << "IDs cannot contain letters. Returning to main menu." << endl;
		cin.clear();
		cin.ignore();
		return;
	}

	//find ID in list
	if (contactManager.isExistingContact(ID))
	{
		cout << "Contact found!" << endl;
		getUpdateSubMenu(ID);
	}
	else
		throw invalid_argument("Contact record not found.");
}

void Menu::launchDeleteMenu()
{
	//check if list is empty
	if (contactManager.isContactListEmpty())
	{
		displayEmptyListMessage();
		return;
	}

	//if not empty, get ID from user
	int ID = 0;
	char decision = ' ';	//confirm delete variable

	cin.exceptions(istream::failbit);
	try
	{
		cout << "Enter an employee ID: ";
		cin >> ID;
	}
	catch (ios::failure)
	{
		cout << "IDs cannot contain letters. Returning to main menu." << endl;
		cin.clear();
		cin.ignore();
		return;
	}
	
	//find user with supplied ID
	if (contactManager.isExistingContact(ID))
	{
		//if contact found, have user confirm deletion
		cout << "Are you sure you want to delete "
			<< contactManager.getFirstName(ID) << " "
			<< contactManager.getLastName(ID) << "?"
			<< " Y or N: ";
		cin >> decision;

		if (tolower(decision) == 'y')
		{
			if (contactManager.deleteContact(ID))
				cout << "Contact deleted." << endl;
			else
				throw invalid_argument("Contact not deleted.");
		}
		else		//if any other character is entered
			cout << "Delete request aborted." << endl;
	}
	else
		cout << "Contact not found." << endl;
}

void Menu::launchSearchMenu()
{
	//check if list is empty
	if (contactManager.isContactListEmpty())
	{
		displayEmptyListMessage();
		return;
	}

	//if list not empty, get ID from user
	int ID = 0;
	cin.exceptions(istream::failbit);
	try
	{
		cout << "Please enter an employee ID: ";
		cin >> ID;
	}
	catch (ios::failure)
	{
		cout << "IDs cannot contain letters. Returning to main menu." << endl;
		cin.clear();
		cin.ignore();
		return;
	}
	

	if (contactManager.isExistingContact(ID))
		displaySingleRecord(ID);
	else
		throw invalid_argument("Record not found.");
}

void Menu::setFirstNameMenu(int ID)
{
	string name = " ";

	cout << "Enter a first name: ";
	cin >> name;

	contactManager.setFirstName(ID, name);
}

void Menu::setLastNameMenu(int ID)
{
	string name = " ";

	cout << "Enter a last name: ";
	cin >> name;

	contactManager.setLastName(ID, name);
}

void Menu::setTelephoneMenu(int ID)
{
	string phone = " ";

	cout << "Enter a phone number: ";
	cin >> phone;

	contactManager.setTelephone(ID, phone);
}

void Menu::setEmailMenu(int ID)
{
	string email = " ";

	cout << "Enter an email address: ";
	cin >> email;

	contactManager.setEmail(ID, email);
}

void Menu::setAgeMenu(int ID)
{
	int age = 0;
	cout << "Enter an age: ";
	cin >> age;
	contactManager.setAge(ID, age);
}

void Menu::setTitleMenu(int ID)
{
	string title = " ";

	cout << "Enter a title: ";
	cin >> title;

	contactManager.setTitle(ID, title);
}

void Menu::setManagerMenu(int ID)
{
	string manager;

	cout << "Enter a manager: ";
	cin >> manager;
	
	contactManager.setManager(ID, manager);
}
