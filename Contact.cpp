/*
Advanced C++:	Course Project - Contact Manager
Programmer:		Andrew Engel
Date:			10/23/2017
Filename:		Contact.cpp
Purpose:		To maintain personal and employer data/functionality for each contact
Input:			int, string
Output:			int, string
Exceptions:		None
*/

#include "stdafx.h"
#include "Contact.h"
#include "PersonalInfo.h"
#include "Employer.h"
#include <string>

Contact::Contact()
{
}

string Contact::getFirstName() const
{
	return personalInfo.getFirstName();
}

string Contact::getLastName() const
{
	return personalInfo.getLastName();
}

string Contact::getFullName() const
{
	string fullName = personalInfo.getFirstName() + " " + personalInfo.getLastName();
	return fullName;
}

string Contact::getTelephone() const
{
	return personalInfo.getTelephone();
}

string Contact::getEmail() const
{
	return personalInfo.getEmail();
}

string Contact::getTitle() const
{
	return employer.getTitle();
}

string Contact::getManager() const
{
	return employer.getManager();
}

int Contact::getEmployeeID() const
{
	return employer.getEmployeeID();
}

int Contact::getAge() const
{
	return personalInfo.getAge();
}

void Contact::setEmployeeID(int ID)
{
	employer.setEmployeeID(ID);
}

void Contact::setFirstName(const string& firstName)
{
	personalInfo.setFirstName(firstName);
}

void Contact::setLastName(const string& lastName)
{
	personalInfo.setLastName(lastName);
}

void Contact::setTelephone(string telephone)
{
	personalInfo.setTelephone(telephone);
}

void Contact::setEmail(const string& email)
{
	personalInfo.setEmail(email);
}

void Contact::setTitle(const string& title)
{
	employer.setTitle(title);
}

void Contact::setManager(const string& manager)
{
	employer.setManager(manager);
}

void Contact::setAge(int age)
{
	personalInfo.setAge(age);
}
