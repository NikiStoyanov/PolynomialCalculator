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
* Source: Helper functions for polynomials operations.
*
*/

#include <iostream>
#include <vector>

#include "ValidationFunctions.h"
#include "HelperMathFunctions.h"

void printPolynomial(char name, const std::vector<std::pair<int, int>> polynomial)
{
    std::cout << name << "(x) = ";

    bool isLeadingCoefficient = true;

    for (int i = polynomial.size() - 1; i >= 0; i--)
    {
        if (polynomial[i].first != 0)
        {
            if (!isLeadingCoefficient)
            {
                std::cout << (polynomial[i].first > 0 ? "+" : "");
            }

            if (!((polynomial[i].first == 1 || polynomial[i].first == -1) && polynomial[i].second == 1) || i == 0)
            {
                printFraction(polynomial[i]);
            }

            if (i > 0)
            {
                std::cout << "x";
            }

            if (i > 1)
            {
                std::cout << "^" << i;
            }

            if (isLeadingCoefficient)
            {
                isLeadingCoefficient = false;
            }
        }
    }

    if (isLeadingCoefficient)
    {
        std::cout << 0;
    }

    std::cout << std::endl;
}

void readPolynomialDegree(int& degree) 
{
    std::cout << "Enter degree of your polynomial: ";

    std::cin >> degree;

    validatePolynomialDegree(degree);
}

std::vector<std::pair<int, int>> readPolymonial(char name)
{
    std::cout << "Enter Polynomial " << name << "(x)" << std::endl;

    int degree;
    readPolynomialDegree(degree);

    std::vector<std::pair<int, int>> polynomial(degree + 1);

    for (int i = degree; i << degree >= 0; i--)
    {
        std::cout << "Enter coefficient before x^" << i << ": ";
        
        std::pair<int, int> coefficient = readFraction();

        polynomial[i] = coefficient;
    }

    printPolynomial(name, polynomial);

    return polynomial;
}