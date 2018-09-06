/*
Advanced C++:	Course Project - Contact Manager
Programmer:		Andrew Engel
Date:			10/23/2017
Filename:		Employer.cpp
Purpose:		To maintain employer data/functionality for each contact
Input:			int, string
Output:			int, string
Exceptions:		Throws invalid arguments from setter methods
*/

#include "stdafx.h"
#include "Employer.h"


Employer::Employer()
{
}

int Employer::getEmployeeID() const
{
	return employeeID;
}

string Employer::getTitle() const
{
	return title;
}

string Employer::getManager() const
{
	return manager;
}

void Employer::setEmployeeID(int ID)
{
	if (ID > 0)
		employeeID = ID;
	else
		throw invalid_argument("Employee ID cannot be less than 1.");
}

void Employer::setTitle(const string& title)
{
	if (title.length() > 0)
		this->title = title;
	else
		throw invalid_argument("Title cannot be blank.");
}

void Employer::setManager(const string& manager)
{
	if (manager.length() > 0)
		this->manager = manager;
	else
		throw invalid_argument("Manager cannot be blank.");
}
