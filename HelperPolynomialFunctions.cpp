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
#include "Constants.h"

void printPolynomial(char name, char variable, const std::vector<std::pair<int, int>> polynomial, bool includePrefix = true)
{
    if (includePrefix)
    {
        std::cout << name << "(" << variable << ") = ";
    }

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

            if (polynomial[i].first == -1 && polynomial[i].second == 1 && i != 0)
            {
                std::cout << "-";
            }

            if (i > 0)
            {
                std::cout << variable;
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

void readPolynomialDegree(char* degree) 
{
    std::cout << "Enter degree of your polynomial: ";

    std::cin >> degree;

    validatePolynomialDegree(degree);
}

std::vector<std::pair<int, int>> readPolymonial(char name, char variable)
{
    std::cout << "Enter Polynomial " << name << "(" << variable << ")" << std::endl;

    char degreeInput[MAX_DEGREE_LENGTH];
    readPolynomialDegree(degreeInput);

    int degree = customAtoi(degreeInput);

    std::vector<std::pair<int, int>> polynomial(degree + 1);

    for (int i = degree; i << degree >= 0; i--)
    {
        std::cout << "Enter coefficient before " << variable <<"^" << i << ": ";
        
        std::pair<int, int> coefficient = readFraction();

        polynomial[i] = coefficient;
    }

    printPolynomial(name, variable, polynomial);

    return polynomial;
}

int getPolynomialDegree(std::vector<std::pair<int, int>> polynomial)
{
    for (int i = polynomial.size() - 1; i >= 0; i--)
    {
        if (polynomial[i].first != 0)
        {
            return i;
        }
    }

    return 0;
}

std::vector<std::pair<int, int>> createPolynomial(int degree)
{
    std::vector<std::pair<int, int>> polynomial(degree + 1);

    for (int i = 0; i <= degree; i++)
    {
        polynomial[i] = {0, 1};
    }

    return polynomial;
}