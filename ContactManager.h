#pragma once
/*
Advanced C++:	Course Project - Contact Manager
Programmer:		Andrew Engel
Date:			10/23/2017
Filename:		ContactManager.h
Purpose:		To provide a class definition for ContactManager.cpp
Input:			int, string
Output:			int, string, bool
Exceptions:		None
*/

#include <string>
#include <vector>
#include "Contact.h"

using namespace std;

class ContactManager
{
private:
	vector<Contact> contacts;
	Contact& getContact(int);
	//purpose:	returns contact object as reference
	//input:	int
	//output:	Contact object reference
	Contact getContact(int) const;
	//purpose:	returns contact object as value
	//input:	int (ID)
	//output:	const Contact object
public:
	ContactManager();
	//purpose:	constructor; initializes ContactManager object
	//input:	none
	//output:	none
	int addContact();
	//purpose:	creates new Contact object and returns an employee ID as an int
	//input:	none
	//output:	int
	string getFirstName(int) const;
	//purpose:	returns contact's first name
	//input:	int (employee ID)
	//output:	const string
	string getLastName(int) const;
	//purpose:	returns contact's last name
	//input:	int (employee ID)
	//output:	const string
	string getTelephone(int) const;
	//purpose:	returns contact's telephone number
	//input:	int (employee ID)
	//output:	const string
	string getEmail(int) const;
	//purpose:	returns contact's email address
	//input:	int (employee ID)
	//output:	const string
	string getTitle(int) const;
	//purpose:	returns contact's title
	//input:	int (employee ID)
	//output:	const string
	string getManager(int) const;
	//purpose:	returns contact's manager
	//input:	int (employee ID)
	//output:	const string
	int getAge(int) const;
	//purpose:	returns contact's age
	//input:	int (employee ID)
	//output:	const int
	bool deleteContact(int);
	//purpose:	attempts to delete contact from the vector and confirms its success
	//input:	int (employee ID)
	//output:	bool
	bool isExistingContact(int);
	//purpose:	checks whether an employee ID exists within the Contact vector
	//input:	int (employee ID)
	//output:	bool
	bool isContactListEmpty();
	//purpose:	checks if the Contact vector is empty
	//input:	none
	//output:	bool
	void setEmployeeID(int);
	//purpose:	sets employee ID
	//input:	int (employee ID)
	//output:	void
	void setFirstName(int, const string&);
	//purpose:	sets contact's first name
	//input:	int (employee ID), const string reference (name)
	//output:	void
	void setLastName(int, const string&);
	//purpose:	sets contact's last name
	//input:	int (employee ID), const string reference (name)
	//output:	void
	void setTelephone(int, string);
	//purpose:	sets contact's telephone number
	//input:	int (employee ID), string (phone number)
	//output:	void
	void setEmail(int, const string&);
	//purpose:	sets contact's email address
	//input:	int (employee ID), const string reference (email address)
	//output:	void
	void setAge(int, int);
	//purpose:	sets contact's age
	//input:	int (employee ID), int (age)
	//output:	void
	void setTitle(int, const string&);
	//purpose:	sets contact's title
	//input:	int (employee ID), const string reference (title)
	//output:	void
	void setManager(int, const string&);
	//purpose:	sets contact's manager
	//input:	int (employee ID), const string reference (manager)
	//output:	void
	string displayAllContacts();
	//purpose:	formats and returns all contacts' information
	//input:	none
	//output:	string
	string displaySingleRecord(int) const;
	//purpose:	formats and returns a single contact's information
	//input:	int (employee ID)
	//output:	const string
};

