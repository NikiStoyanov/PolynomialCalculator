/**
* 
* Solution to course project # 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter Semester 2024/2025
* 
* @author Nikolay Stoyanov
* @idnumber 2MI0600435
* @compiler VC
* 
* Description
* 
*/

#include <iostream>

using namespace std;

void displayMenu() 
{
    cout << "Choose one of the following functionalities:" << endl;
    cout << "1) Add polynomials" << endl;
    cout << "2) Subtract polynomials" << endl;
    cout << "3) Multiply polynomials" << endl;
    cout << "4) Divide polynomials" << endl;
    cout << "5) Multiply polynomials by scalar" << endl;
    cout << "6) Find value of polynomial at a given number" << endl;
    cout << "7) Find GCD of two polynomials" << endl;
    cout << "8) Display Vieta's formulas for a given polynomial" << endl;
    cout << "9) Represent a polynomial in powers of (x+a)" << endl;
    cout << "10) Factor polynomial and find its rational roots" << endl;
    cout << "11) Quit program" << endl;
}

void readOption(int& option) {
    cout << "Enter your option here: ";

    cin >> option;

    if (option < 1 || option > 11)
    {
        cout << "This is not a valid option!" << endl;
        
        readOption(option);
    }
}

void listenForOptionSelection() {
    do
    {
        int option;
        readOption(option);

        switch (option)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                cout << "Quitting..." << endl;
                return;
                break;
        }
    } while (true);
}

int main()
{
    cout << "Welcome to Polynomial Calculator - a mini project intended to work with polynomials with rational coefficients" << endl;

    displayMenu();

    cout << endl;
    
    listenForOptionSelection();

    return 0;
}