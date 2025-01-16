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
* Source: Operations with polynomials.
*
*/

#include <iostream>

#include "HelperPolynomialFunctions.h"
#include "HelperMathFunctions.h"

void multiplyPolynomialByGivenScalar()
{
    std::vector<std::pair<int, int>> polynomial = readPolymonial('P', 'x');

    std::cout << "Enter rational number: ";
    std::pair<int, int> scalar = readFraction();

    for (int i = polynomial.size() - 1; i >= 0; i--)
    {
        polynomial[i] = multiplyFractions(polynomial[i], scalar);
    }

    std::cout << "Result: ";
    
    printPolynomial('P', 'x', polynomial);
}

void calculatePolynomialForGivenNumber() 
{
    std::vector<std::pair<int, int>> polynomial = readPolymonial('P', 'x');

    std::cout << "Enter rational number: ";
    std::pair<int, int> number = readFraction();

    std::pair<int, int> sum = { 0, 1 };

    for (int i = polynomial.size() - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            sum = addFractions(sum, polynomial[i]);
        }
        else
        {
            sum = addFractions(sum, multiplyFractions(polynomial[i], fractionPow(number, i)));
        }
    }

    std::cout << "P(";
    printFraction(number);
    std::cout << ") = ";
    printFraction(sum);
    std::cout << std::endl;
}