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

#include "PolynomialFunctions.h"
#include "ValidationFunctions.h"
#include "Constants.h"

void displayMenu()
{
    std::cout << "Choose one of the following functionalities:" << std::endl;
    std::cout << "a) Add polynomials" << std::endl;
    std::cout << "b) Subtract polynomials" << std::endl;
    std::cout << "c) Multiply polynomials" << std::endl;
    std::cout << "d) Divide polynomials" << std::endl;
    std::cout << "e) Multiply polynomials by scalar" << std::endl;
    std::cout << "f) Find value of polynomial at a given number" << std::endl;
    std::cout << "g) Find GCD of two polynomials" << std::endl;
    std::cout << "h) Display Vieta's formulas for a given polynomial" << std::endl;
    std::cout << "i) Represent a polynomial in powers of (x+a)" << std::endl;
    std::cout << "j) Factor polynomial and find its rational roots" << std::endl;
    std::cout << "k) Find N-th derivative of a given polynomial" << std::endl;
    std::cout << "l) Quit program" << std::endl;
}

void readOption(char* option)
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

        char optionInput[OPTION_MAX_LENGTH];
        readOption(optionInput);

        char option = optionInput[0];
        switch (option)
        {
            case 'a': addPolynomials(); break;
            case 'b': subtractPolynomials(); break;
            case 'c': multiplyPolynomials(); break;
            case 'd': dividePolynomials(); break;
            case 'e': multiplyPolynomialByGivenScalar(); break;
            case 'f': calculatePolynomialForGivenNumber(); break;
            case 'g': findGcdOfTwoPolynomials(); break;
            case 'h': displayVietasFormulasForGivenPolynomial(); break;
            case 'i': representPolynomialInPowersOfXPlusA(); break;
            case 'j': findRationalRoots(); break;
            case 'k': findNthDerivativeOfPolynomial(); break;
            case 'l':
                std::cout << "Quitting..." << std::endl;
                return;
                break;
        }

        std::cout << std::endl;
    } 
    while (true);
}