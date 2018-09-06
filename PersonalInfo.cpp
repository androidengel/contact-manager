/*
Advanced C++:	Course Project - Contact Manager
Programmer:		Andrew Engel
Date:			10/23/2017
Filename:		PersonalInfo.cpp
Purpose:		To maintain all personal data/functionality of a contact
Input:			int, string
Output:			int, string
Exceptions:		Throws invalid arguments from setter methods
*/

#include "stdafx.h"
#include "PersonalInfo.h"


PersonalInfo::PersonalInfo()
{
}

string PersonalInfo::getFirstName() const
{
	return firstName;
}

string PersonalInfo::getLastName() const
{
	return lastName;
}

string PersonalInfo::getTelephone() const
{
	string formattedPhone = telephone;
	formattedPhone.insert(3, "-");
	formattedPhone.insert(7, "-");
	return formattedPhone;
}

string PersonalInfo::getEmail() const
{
	return email;
}

int PersonalInfo::getAge() const
{
	return age;
}

void PersonalInfo::setFirstName(const string& firstName)
{
	if (firstName.length() > 0)
		this->firstName = firstName;
	else
		throw invalid_argument("No first name entered.");
}

void PersonalInfo::setLastName(const string& lastName)
{
	if (lastName.length() > 0)
		this->lastName = lastName;
	else
		throw invalid_argument("No last name entered.");
}

void PersonalInfo::setTelephone(string telephone)
{
	for (size_t i{ 0 }; i < telephone.length(); ++i)	//removes hyphens and spaces
	{
		if (telephone[i] == '-' || telephone[i] == ' ' || telephone[i] == '(' || telephone[i] == ')')
		{
			telephone.erase(i, 1);
			--i;		//re-check same subscript
		}
	}

	if (telephone.length() == 10)		//check length after removing extra characters
		this->telephone = telephone;
	else
		throw invalid_argument("Invalid phone number format.");
}

void PersonalInfo::setEmail(const string& email)
{
	int atSymbol = email.find("@");
	int period = email.length() - 3;
	if (atSymbol != string::npos && email[period] != '.')	//@ is found and period is placed at 4th position before end of address
		this->email = email;
	else
		throw invalid_argument("Invalid email address.");
}

void PersonalInfo::setAge(int age)
{
	if (age > 0)
		this->age = age;
	else
		throw invalid_argument("Age cannot be less than 1.");
}
