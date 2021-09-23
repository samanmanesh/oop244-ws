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
#include <cstring>
#include "Fighter.h" 
using namespace std;
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

		cout << "Name: " << myFighter.name <<", Power: " << myFighter.power << endl;

	}

	void display(const Competition& mycompetition) {	
		int i;

		for ( i = 0; i < mycompetition.numfighters; i++)
		{
			display(mycompetition.fighters[i]);
		}

	}

	void addFighter(Competition& myCompetition) {
		int prevSize = myCompetition.numfighters;
		int newSize = prevSize + 1;
		
		Fighter* newFighter = nullptr;
		newFighter = new Fighter[newSize];

		
			for (int i = 0; i < newSize; i++)
			{
				//newFighter[i].name = myCompetition.fighters[i].name;
				/*for (int j = 0; j < MAX_NAME+1; j++)
				{
					newFighter[i].name[j] = myCompetition.fighters[i].name[j];
				}*/

				strcpy(newFighter[i].name, myCompetition.fighters[i].name);
				newFighter[i].power = myCompetition.fighters[i].power;
			};
				
			cout << "Enter the information of the new fighter:" << endl;
			fighter(newFighter[newSize].name);
			fighter(newFighter[newSize].power);

			delete[] myCompetition.fighters;
			myCompetition.fighters = nullptr;

			myCompetition.fighters = newFighter;
			myCompetition.numfighters++;

	}
}