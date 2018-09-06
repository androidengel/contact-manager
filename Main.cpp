/*
Advanced C++:	Course Project - Contact Manager
Programmer:		Andrew Engel
Date:			10/23/2017
Filename:		Main.cpp
Purpose:		To provide an entry point for the contact manager app
Input:			int, char
Output:			string
Exceptions:		invalid_argument
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Menu.h"

int main()
{
	char menuSelection = ' ';
	Menu menu;

	menu.displayWelcomeMessage();

	while (menuSelection != 'q')
	{
		try
		{
			menu.displayMainMenu();
			menuSelection = menu.getMenuSelection();

			switch (menuSelection)
			{
			case '1':
				menu.launchAddMenu();
				break;
			case '2':
				menu.launchUpdateMenu();
				break;
			case '3':
				menu.launchDeleteMenu();
				break;
			case '4':
				menu.launchSearchMenu();
				break;
			case '5':
				menu.displayAllContacts();
				break;
			case 'q':
				cout << "Goodbye";
				break;
			default:
				menu.displayInvalidMessage();
			}
		}
		catch (const std::invalid_argument& ex)
		{
			cout << ex.what() << endl;
		}
	}
    return 0;
}

