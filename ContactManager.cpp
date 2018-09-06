/*
Advanced C++:	Course Project - Contact Manager
Programmer:		Andrew Engel
Date:			10/23/2017
Filename:		ContactManager.cpp
Purpose:		To handle all manipulation/access of a collection of contact objects
Input:			int, string
Output:			int, string, bool
Exceptions:		None
*/

#include "stdafx.h"
#include "ContactManager.h"
#include "Contact.h"
#include <sstream>
#include <string>
#include <iomanip>


ContactManager::ContactManager()
{
}

Contact& ContactManager::getContact(int ID)		//private function overloaded for setters
{
	if (contacts.empty())
		throw invalid_argument("No records found.");
	else
	{
		for (size_t i{ 0 }; i < contacts.size(); ++i)
		{
			if (contacts[i].getEmployeeID() == ID)
				return contacts[i];
		}
	}
	//if no contact was returned
	throw invalid_argument("Record not found.");
}

Contact ContactManager::getContact(int ID) const	//private function overloaded for getters
{
	if (contacts.empty())
		throw invalid_argument("No records found.");
	else
	{
		for (size_t i{ 0 }; i < contacts.size(); ++i)
		{
			if (contacts[i].getEmployeeID() == ID)
				return contacts[i];
		}
	}
	//if no contact was returned
	throw invalid_argument("Record not found.");
}

int ContactManager::addContact()		//creates new Contact object and returns an ID as an int
{
	Contact newContact;
	int ID;
	if (contacts.empty())
	{
		ID = 1;
		newContact.setEmployeeID(ID);
	}
	else
	{
		ID = (contacts.back().getEmployeeID() + 1);		//set ID one # higher than last ID in list
		newContact.setEmployeeID(ID);
	}
	contacts.push_back(newContact);		//add contact to vector
	return ID;
}

string ContactManager::getFirstName(int ID) const
{
	return getContact(ID).getFirstName();
}

string ContactManager::getLastName(int ID) const
{
	return getContact(ID).getLastName();
}

string ContactManager::getTelephone(int ID) const
{
	return getContact(ID).getTelephone();
}

string ContactManager::getEmail(int ID) const
{
	return getContact(ID).getEmail();
}

string ContactManager::getTitle(int ID) const
{
	return getContact(ID).getTitle();
}

string ContactManager::getManager(int ID) const
{
	return getContact(ID).getManager();
}

int ContactManager::getAge(int ID) const
{
	return getContact(ID).getAge();
}

bool ContactManager::deleteContact(int ID)
{
	bool deleted = false;
	if (contacts.empty())
		throw invalid_argument("No contacts available to delete.");
	else
	{
		for (size_t i{ 0 }; i < contacts.size(); ++i)
		{
			if (contacts[i].getEmployeeID() == ID)
			{
				contacts.erase(contacts.begin() + i);
				deleted = true;
			}

		}
	}
	return deleted;
}

bool ContactManager::isExistingContact(int ID)
{
	bool found = false;
	if (contacts.empty())
		return found;
	else
		for (Contact contact : contacts)
		{
			if (contact.getEmployeeID() == ID)
			{
				found = true;
				return found;
			}
		}

	return found;		//if contact not found
}

bool ContactManager::isContactListEmpty()
{
	if (contacts.empty())
		return true;
	else
		return false;
}

void ContactManager::setEmployeeID(int ID)
{
	contacts.back().setEmployeeID(ID);
}

void ContactManager::setFirstName(int ID, const string& firstName)
{
	getContact(ID).setFirstName(firstName);
}

void ContactManager::setLastName(int ID, const string& lastName)
{
	getContact(ID).setLastName(lastName);
}

void ContactManager::setTelephone(int ID, string telephone)
{
	getContact(ID).setTelephone(telephone);
}

void ContactManager::setEmail(int ID, const string& email)
{
	getContact(ID).setEmail(email);
}

void ContactManager::setAge(int ID, int age)
{
	getContact(ID).setAge(age);
}

void ContactManager::setTitle(int ID, const string& title)
{
	getContact(ID).setTitle(title);
}

void ContactManager::setManager(int ID, const string& manager)
{
	getContact(ID).setManager(manager);
}

string ContactManager::displayAllContacts()
{
	ostringstream output;
	if (contacts.empty())
		throw invalid_argument("No contacts to display.");
	else
	{
		//column headings
		output << "ID\t" << right << "Name" << setw(20) << "Phone"
			<< setw(16) << "Email" << setw(25) << "Age"
			<< setw(8) << "Title" << setw(17) << "Manager" << endl;
		//contact data
		for (size_t i{ 0 }; i < contacts.size(); ++i)
		{
			output << setw(5) << setfill('0') << right << contacts[i].getEmployeeID()
				<< "\t" << setfill(' ') << left
				<< setw(19) << contacts[i].getFullName()
				<< setw(16) << contacts[i].getTelephone() << setw(27) << contacts[i].getEmail()
				<< setw(6) << contacts[i].getAge() << setw(15) << contacts[i].getTitle()
				<< contacts[i].getManager() << endl;
		}
	}
	return output.str();	
}

string ContactManager::displaySingleRecord(int ID) const
{
	ostringstream output;
	Contact record = getContact(ID);

	output << "Employee ID: " << right << setfill('0') << setw(5) << record.getEmployeeID() << endl;
	output << "Name: " << record.getFirstName() << " " << record.getLastName() << endl;
	output << "Phone number: " << record.getTelephone() << endl;
	output << "Email address: " << record.getEmail() << endl;
	output << "Age: " << record.getAge() << endl;
	output << "Title: " << record.getTitle() << endl;
	output << "Manager: " << record.getManager();

	return output.str();
}
