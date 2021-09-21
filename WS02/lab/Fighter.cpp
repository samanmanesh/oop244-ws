// ===================================================================================
//  Workshop: #2
//  Part: 1 (Lab) 
// ===================================================================================
//  Student Name  : Mohammadhossein Sobhanmanesh
//  Student ID    : 116523200
//  Student Email : msobhanmanesh@myseneca.ca
//  Date          : 2020-09-21
//  Course Section: OOP244-NAA
// ===================================================================================
// I have done all the coding by myself and only copied the code that my professor 
// provided to complete my workshops and assignments.
// ===================================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Fighter.h" 
usding namespace std;
using namespace sdds;

namespace sdds {

	void fighter(char* name) {

		cout << "Enter Fighter Name: ";
		cin >> *name;
	}
	
	void fighter(int& power) {
		cout << "Enter Fighter Power: ";
		cin >> power;
	}

	void display(const Fighter& myFighter) {

		cout << "Name: "myFighter.name ", Power: "myFighter.power << endl;

	}

	void display(const Competition& mycompetition) {	
		int i;

		for ( i = 0; i < mycompetition.numfighters; i++)
		{
			display(mycompetition.fighters[i]);
		}

	}

	void addFighter(Competition& myCompetition) {
		int size = myCompetition.numfighters
			myCompetition.fighters = new Fighter[size+1];

	}
}