//***********************************************************
//* 2DMomentumSolver.cpp Created By Kian Gorgichuk	      *
//* Copyright (c) 2015 Kian Gorgichuk. All rights reserved. *
//***********************************************************

#include <iostream>
#include <string>
#include <windows.h>
#include "2DMomentumEquations.h"

using namespace std;

//User input helper functions
bool validValue(string str);
bool isYes(string str);

int main()
{
	//Set Command Prompt Size
	system("mode 100,40"); 
	
	//Loop back program in order to do multiple calculations 
	bool exitProgram = false;
	
	do
	{
		system("CLS");

		cout << "**************************************" << endl;
		cout << "*        Welcome to the 2D MCS!      *" << endl;
        cout << "* The 2D Momentum Computation System *" << endl;
		cout << "*      Created By Kian Gorgichuk     *" << endl;
		cout << "*           Version: 1.3.0           *" << endl;
		cout << "**************************************\n" << endl;
		
		string userInputFuse;
		string userInputColl;
		
		//Ask if objects fuse together 
		cout << "After Collision Do the Two Objects Fuse or Link Together (Y/N): ";
		cin >> userInputFuse;
		
		while(!validValue(userInputFuse))
		{
			cout << "After Collision Do the Two Objects Fuse or Link Together (Y/N): ";
			cin >> userInputFuse;
		}
		cout << endl;
		
		//Ask if unknown vector is after collision 
		cout << "Is Unknown Vector After Collision (Y/N): ";
		cin >> userInputColl;
		
		while(!validValue(userInputColl))
		{
			cout << "Is Unknown Vector After Collision (Y/N): ";
			cin >> userInputColl;
		}
		cout << endl;
		
		//Determine which method to use for calculations
		if(isYes(userInputFuse))
		{
			if(isYes(userInputColl))
				afterFuse();
			else
				beforeFuse();
		}
		else 
		{
			if(isYes(userInputColl))
				afterSep();
			else
				beforeSep();
		}
		
		//Ask if user would like to do another calculation
		string userInput;
		cout << "\nWould You Like To Do Another Calculation (Y/N): ";
		cin >> userInput;
		while(!validValue(userInput))
		{
			cout << "Would You Like To Do Another Calculation (Y/N): ";
			cin >> userInput;
		}
		if(isYes(userInput))
			exitProgram = false;
		else
			exitProgram = true;
		
	} while (exitProgram == false);
}

//Determine if user enters a valid value in a yes or no question.
bool validValue(string str)
{
	if(str.compare("Y") == 0)
		return true;
	else if(str.compare("y") == 0)
		return true;
	else if(str.compare("N") == 0)
		return true;
	else if(str.compare("n") == 0)
		return true;
	return false;
}

//Determine if user entered a yes or a no
bool isYes(string str)
{
	if(str.compare("Y") == 0)
		return true;
	else if(str.compare("y") == 0)
		return true;
	
	//All other possible values (as determined by validValue) are 'n' or 'N'
	//Therefore: return false
	return false;
}