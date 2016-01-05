//***********************************************************
//* 2DMomentumEquations.cpp Created By Kian Gorgichuk	      *
//* Copyright (c) 2015 Kian Gorgichuk. All rights reserved. *
//***********************************************************

#include <iostream>
#include <string>
#include <stdlib.h>
#include "2DMomentumEquations.h"
#include "Vector.cpp"

using namespace std;

double getVelocity(const char* when, const char* object);
double getDirection(const char* when, const char* object);
double getMass(const char* object);

void beforeFuse()
{	
	//Get User Values
	double bfmass = getMass("A");
	double bfvelocity = getVelocity("", "A");
	double bfdirection = getDirection("", "A");
	cout << endl;
	
	double afmass = getMass("A & B after collision");
	double afvelocity = getVelocity("", "A & B after collision");
	double afdirection = getDirection("", "A & B after collision");
	cout << endl;
	
	//Exception Handling - Mass cannot be Zero
	if((bfmass == 0) || afmass == 0)
	{
		cout << "ERROR: Mass Cannot Be Zero!" << endl;
		exit(0);
	}
	
	//Create A Before and After Vector Using User Data - Use Vector Subtraction to Compute
	Vector* fused = new Vector((afmass * afvelocity), afdirection);
	Vector* knownbf = new Vector((bfmass * bfvelocity), bfdirection + 180);
	
	Vector* answer = new Vector();
	
	*answer = *fused + *knownbf;
	cout << "The Initial Trajectory of Object B is: " << (answer->getMagnitude()) /  (afmass - bfmass) << " m/s [" << answer->getDirectionDeg() << "]." << endl;
	
	//Clean Up
	delete fused;
	delete knownbf;
	delete answer;
	
}

void afterFuse()
{
		
	//Get User Values
	double massA = getMass("A");
	double velocityA = getVelocity("", "A");
	double directionA = getDirection("", "A");
	cout << endl;
	
	double massB = getMass("B");
	double velocityB = getVelocity("", "B");
	double directionB = getDirection("", "B");
	cout << endl;
	
	//Exception Handling - Mass cannot equal zero
	if((massA == 0) || massB == 0)
	{
		cout << "ERROR: Mass Cannot Be Zero!" << endl;
		exit(EXIT_FAILURE);
	}
	
	//Process User Data into Initial Vectors Then Add 
	Vector *A = new Vector((massA * velocityA), directionA);
	Vector *B = new Vector((massB * velocityB), directionB);
	Vector *answer = new Vector();
	*answer = *A + *B;
	
	//Print out result
	cout << "The Resultant Trajectory of the Two Fused Objects is: " << (answer->getMagnitude()) / (massA + massB) << " m/s [" << answer->getDirectionDeg() << "]." << endl;
	
	//Clean Up
	delete A;
	delete B;
	delete answer;
}

void beforeSep()
{
	//Get User Values
	double massA = getMass("A");
	double velocityA = getVelocity("Initial ", "A");
	double directionA = getDirection("Initial ", "A");
	cout << endl;
	
	double velocityA_ = getVelocity("Post Collision ", "A");
	double directionA_ = getDirection("Post Collision ", "A");
	cout << endl;
	
	double massB = getMass("B");
	double velocityB_ = getVelocity("Post Collision ", "B");
	double directionB_ = getDirection("Post Collision ", "B");
	cout << endl;
	
	//Exception Handling - Mass Cannot Equal Zero
	if((massA == 0) || massB == 0)
	{
		cout << "ERROR: Mass Cannot Be Zero!" << endl;
		exit(0);
	}
	
	//Determine Total Momentum
	Vector *A_ = new Vector((massA * velocityA_), directionA_);
	Vector *B_ = new Vector((massB * velocityB_), directionB_);
	Vector *total = new Vector();
	*total = *A_ + *B_;
	
	//Determine Missing Vector
	Vector *answer = new Vector();
	Vector *A = new Vector((massA * velocityA), directionA + 180);
	
	*answer = *total + *A;
	
	//Print Out Answer
	cout << "The Initial Trajectory of Object B is: " << (answer->getMagnitude()) / massB << " m/s [" << answer->getDirectionDeg() << "]." << endl;
	
	//Clean Up
	delete A;
	delete A_;
	delete B_;
	delete total;
	delete answer;
}

void afterSep()
{
	//Get User Values
	double massA = getMass("A");
	double velocityA = getVelocity("Initial ", "A");
	double directionA = getDirection("Initial ", "A");
	cout << endl;
	
	double massB = getMass("B");
	double velocityB = getVelocity("Initial ", "B");
	double directionB = getDirection("Initial ", "B");
	cout << endl;
	
	double velocityA_ = getVelocity("Post Collision ", "A");
	double directionA_ = getDirection("Post Collision ", "A");
	cout << endl;
	
	//Exception Handling - Mass cannot be Zero
	if((massA == 0) || massB == 0)
	{
		cout << "ERROR: Mass Cannot Be Zero!" << endl;
		exit(0);
	}
	
	//Determine Total Momentum
	Vector *A = new Vector((massA * velocityA), directionA);
	Vector *B = new Vector((massB * velocityB), directionB);
	Vector *total = new Vector();
	*total = *A + *B;
	
	//Determine Missing Trajectory
	Vector *answer = new Vector();
	Vector *A_ = new Vector((massA * velocityA_), directionA_ + 180);
	
	*answer = *total + *A_;
	
	//Print out answer
	cout << "The Post Collision Trajectory of Object B is: " << (answer->getMagnitude()) / massB << " m/s [" << answer->getDirectionDeg() << "]." << endl;
	
	//Clean Up
	delete A;
	delete B;
	delete A_;
	delete total;
	delete answer;
}

//Helper functions to get user input:
double getDirection(const char* when, const char* object)
{
	string userInput;
	cout << "Please enter the " << when << "Direction for Object " << object <<" in degrees: ";
	cin >> userInput;
	
	return strtod(userInput.c_str(), NULL);
}

double getVelocity(const char* when, const char* object)
{
	string userInput;
	cout << "Please enter the " << when << "Velocity for Object " << object <<" in meters per second: ";
	cin >> userInput;
	
	return strtod(userInput.c_str(), NULL);
}

double getMass(const char* object)
{
	string userInput;
	cout << "Please enter the Mass for Object " << object << " in kilograms: ";
	cin >> userInput;
	
	return strtod(userInput.c_str(), NULL);
}