// ===================================================================================
//  Workshop: #1
//  Part: 1 (Lab) 
// ===================================================================================
//  Student Name  : Mohammadhossein Sobhanmanesh
//  Student ID    : 116523200
//  Student Email : msobhanmanesh@myseneca.ca
//  Course Section: OOP244-NAA
// ===================================================================================

#include <iostream>
#include "drink.h"
#include "util.h"
using namespace std;
using namespace sdds;


int main() {

    bool done = false;
    
    loadDrinks();



    cout << "Welcome to the Seneca Vending Machine" << endl << endl;
    while (!done) {
        drinkMenu();
        chooseDrink();
        cout << "\nDo you want to order another drink? (Y)es or (N)o: ";
        done = !confirm();
        cout << endl;
    }

    drinkMenu();
    cout << "\nThank you and come again" << endl;
    return 0;
}