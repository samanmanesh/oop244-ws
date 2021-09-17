// ===================================================================================
//  Workshop: #1
//  Part: 2 (DIY) 
// ===================================================================================
//  Student Name  : Mohammadhossein Sobhanmanesh
//  Student ID    : 116523200
//  Student Email : msobhanmanesh@myseneca.ca
//  Date          : 
//  Course Section: OOP244-NAA
// ===================================================================================
// I have done all the coding by myself and only copied the code that my professor 
// provided to complete my workshops and assignments.
// ===================================================================================

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include"drink.h"
using namespace std;



namespace sdds {
	
	void loadFile(const char* filename, int maxSize, Drink* relatedStruct) {

        int i = 0;

        FILE* fp = fopen(filename, "r");

        if (fp != NULL)
        {
            for (i = 0; i < maxSize; i++)
            {
                fscanf(fp, "%s %d %lf %d[^\n]",
                    &relatedStruct[i].name,
                    &relatedStruct[i].volume,
                    &relatedStruct[i].price,
                    &relatedStruct[i].quantity
                );
            };
            fclose(fp);
            fp = NULL;
        }
        else
        {
            cout << "ERROR: Unable to open file for reading" << endl;
        }


	}

	



}