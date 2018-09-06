#pragma once
/*
Advanced C++:	Course Project - Contact Manager
Programmer:		Andrew Engel
Date:			10/23/2017
Filename:		Employer.h
Purpose:		To provide a class definition for Employer.cpp
Input:			int, string
Output:			int, string
Exceptions:		Throws invalid arguments from setter methods
*/

#include <string>

using namespace std;

class Employer
{
private:
	int employeeID;
	string title;
	string manager;

public:
	Employer();
	//purpose:	constructor; initializes Employer object
	//input:	none
	//output:	none
	int getEmployeeID() const;
	//purpose:	returns contact's auto-assigned employee ID
	//input:	none
	//output:	const int
	string getTitle() const;
	//purpose:	return's contact's title
	//input:	none
	//output:	const string
	string getManager() const;
	//purpose:	returns contact's manager
	//input:	none
	//output:	const string
	void setEmployeeID(int);
	//purpose:	sets employee ID, which is not chosen by the user
	//input:	int, variable name ID
	//output:	void
	void setTitle(const string&);
	//purpose:	sets contact's title
	//input:	const string reference
	//output:	void
	void setManager(const string&);
	//purpose:	sets contact's manager
	//input:	const strig reference
	//output:	void
};

