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
    std::cout << "k) Quit program" << std::endl;
}

void readOption(char& option)
{
    std::cout << "Enter your option here: ";

    std::cin >> option;

    if (option < 'a' || option > 'k')
    {
        std::cout << "Not a valid option! ";
    }
}

void listenForOptionSelection()
{
    do
    {
        std::cout << std::endl;

        char option;
        readOption(option);

        switch (option)
        {
        case 'a': addPolynomials(); break;
        case 'b': subtractPolynomials(); break;
        case 'c': multiplyPolynomials(); break;
        case 'd': break;
        case 'e': multiplyPolynomialByGivenScalar(); break;
        case 'f': calculatePolynomialForGivenNumber(); break;
        case 'g': break;
        case 'h': break;
        case 'i': break;
        case 'j': break;
        case 'k':
            std::cout << "Quitting..." << std::endl;
            return;
            break;
        }
    } 
    while (true);
}