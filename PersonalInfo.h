#pragma once
/*
Advanced C++:	Course Project - Contact Manager
Programmer:		Andrew Engel
Date:			10/23/2017
Filename:		PersonalInfo.h
Purpose:		To provide a class definition for PersonalInfo.cpp
Input:			int, string
Output:			int, string
Exceptions:		Throws invalid arguments from setter methods
*/

#include <string>

using namespace std;

class PersonalInfo
{
private:
	string firstName;
	string lastName;
	string telephone;
	string email;
	int age;

public:
	PersonalInfo();
	//purpose:	constructor; initializes PersonalInfo object
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
	string getTelephone() const;
	//purpose:	returns contact's telephone number
	//input:	none
	//output:	const string
	string getEmail() const;
	//purpose:	returns contact's email address
	//input:	none
	//output:	const string
	int getAge() const;
	//purpose:	returns contact's age
	//input:	none
	//output:	const int;
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
	void setAge(int);
	//purpose:	sets contact's age
	//input:	int
	//output:	void
};

