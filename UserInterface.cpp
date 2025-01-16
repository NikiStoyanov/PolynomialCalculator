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
* Source: Methods that load the user interface.
*
*/

#include <iostream>

#include "ValidationFunctions.h"
#include "PolynomialFunctions.h"

void displayMenu()
{
    std::cout << "Choose one of the following functionalities:" << std::endl;
    std::cout << "1) Add polynomials" << std::endl;
    std::cout << "2) Subtract polynomials" << std::endl;
    std::cout << "3) Multiply polynomials" << std::endl;
    std::cout << "4) Divide polynomials" << std::endl;
    std::cout << "5) Multiply polynomials by scalar" << std::endl;
    std::cout << "6) Find value of polynomial at a given number" << std::endl;
    std::cout << "7) Find GCD of two polynomials" << std::endl;
    std::cout << "8) Display Vieta's formulas for a given polynomial" << std::endl;
    std::cout << "9) Represent a polynomial in powers of (x+a)" << std::endl;
    std::cout << "10) Factor polynomial and find its rational roots" << std::endl;
    std::cout << "11) Quit program" << std::endl;
}

void readOption(int& option)
{
    std::cout << "Enter your option here: ";

    std::cin >> option;

    validateOptionSelection(option);
}

void listenForOptionSelection()
{
    do
    {
        std::cout << std::endl;

        int option;
        readOption(option);

        switch (option)
        {
        case 1: break;
        case 2: break;
        case 3: break;
        case 4: break;
        case 5: multiplyPolynomialByGivenScalar(); break;
        case 6: calculatePolynomialForGivenNumber(); break;
        case 7: break;
        case 8: break;
        case 9: break;
        case 10: break;
        case 11: 
            std::cout << "Quitting..." << std::endl;
            return;
            break;
        }
    } 
    while (true);
}