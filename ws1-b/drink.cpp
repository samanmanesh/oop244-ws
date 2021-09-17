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
#include <iomanip>
#include <cstdio>
#include "drink.h"
#include "util.h"
#include "file.h"
using namespace std;



namespace sdds {
    
    const int MAXDRINKS = 5;
    Drink machine[MAXDRINKS];

    
    void loadDrinksFromFile(const char* filename) {

        loadFile(filename, MAXDRINKS, machine);
        
        
        /*int i = 0;
        
        FILE* fp = fopen( filename , "r");
        cout << fp->_Placeholder<< "target of fp" << endl;

        if (fp != NULL)
        {
            for (i = 0; i < MAXDRINKS; i++)
            {
                fscanf(fp, "%s %d %lf %d[^\n]",
                    &machine[i].name,
                    &machine[i].volume,
                    &machine[i].price,
                    &machine[i].quantity
              );
            };
            fclose(fp);
            fp = NULL;
        }
        else
        {
            cout << "ERROR: Unable to open file for reading" << endl;
        }*/
         
    }

    void drinkMenu() {
        cout << "-----------Available Drinks-----------" << endl;
        cout << left << setw(10) << "Drink" << setw(10) << "Volume";
        cout << setw(10) << "Price" << setw(10) << "Quantity" << endl;
        for (int i = 0; i < MAXDRINKS; ++i) {
            cout << i + 1 << ".";
            displayDrink(&machine[i]);
        }
    }

    void displayDrink(const Drink* drink) {
        cout << left << setw(10) << drink->name << setw(10) << drink->volume
            << setw(10) << drink->price << setw(10) << drink->quantity << endl;
    }

    int chooseDrink() {
        bool done = false;
        int sel = 0;
        cout << "Select a drink from the menu (1-" << MAXDRINKS << "): ";
        do {
            cin >> sel;
            clearBuffer();
            if (sel >= 1 && sel <= MAXDRINKS) {
                if (updateDrink(sel) == true)
                    done = true;
                else
                    cout << "Out of stock for that drink, try again: ";
            }
            else
                cout << "Selection was was invalid try again: ";
        } while (!done);
        return sel;
    }

    bool updateDrink(int sel) {
        bool res = false;
        if (machine[sel - 1].quantity > 0) {
            machine[sel - 1].quantity--;
            res = true;
        }
        return res;
    }
}