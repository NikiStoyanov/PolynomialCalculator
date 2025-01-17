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
* Entry point of the program
* 
*/

#include <iostream>

#include "UserInterface.h"
#include "HelperMathFunctions.h"

int main()
{
    std::cout << "Welcome to Polynomial Calculator - a mini project intended to work with polynomials with rational coefficients" << std::endl;

    displayMenu();
    
    listenForOptionSelection();

    return 0;
}