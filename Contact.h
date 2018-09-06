#pragma once
/*
Advanced C++:	Course Project - Contact Manager
Programmer:		Andrew Engel
Date:			10/23/2017
Filename:		Contact.h
Purpose:		To provide a class definition for Contact.cpp
Input:			int, string
Output:			int, string
Exceptions:		None
*/

#include <string>
#include "PersonalInfo.h"
#include "Employer.h"

using namespace std;

class Contact
{
private:
	Employer employer;
	PersonalInfo personalInfo;

public:
	Contact();
	//purpose:	constructor; initializes Contact object
	//input:	none
	//output:	none
	string getFirstName() const;
	//purpose:	returns contact's first name
	//input:	none
	//output:	const string
	string getLastName() const;
	//purpose:	returns contact's last name
	//input:	none
	//output:	const string
	string getFullName() const;
	//purpose:	combines and returns contact's first and last name
	//input:	none
	//output:	const string
	string getTelephone() const;
	//purpose:	returns contact's telephone number
	//input:	none
	//output:	const string
	string getEmail() const;
	//purpose:	returns contact's email address
	//input:	none
	//output:	const string
	string getTitle() const;
	//purpose:	returns contact's title
	//input:	none
	//output:	const string
	string getManager() const;
	//purpose:	returns contact's manager
	//input:	none
	//output:	const string
	int getEmployeeID() const;
	//purpose:	returns contact's employee ID
	//input:	none
	//output:	const int
	int getAge() const;
	//purpose:	returns contact's age
	//input:	none
	//output:	const int
	void setEmployeeID(int);
	//purpose:	sets contact's employee ID
	//input:	int
	//output:	void
	void setFirstName(const string&);
	//purpose:	sets contact's first name
	//input:	const string reference
	//output:	void
	void setLastName(const string&);
	//purpose:	sets contact's last name
	//input:	const string reference
	//output:	void
	void setTelephone(string);
	//purpose:	sets contact's telephone number
	//input:	string
	//output:	void
	void setEmail(const string&);
	//purpose:	sets contact's email address
	//input:	const string reference
	//output:	void
	void setTitle(const string&);
	//purpose:	sets contact's title
	//input:	const string reference
	//output:	void
	void setManager(const string&);
	//purpose:	sets contact's manager
	//input:	const string reference
	//output:	void
	void setAge(int);
	//purpose:	sets contact's age
	//input:	int
	//output:	void
};

