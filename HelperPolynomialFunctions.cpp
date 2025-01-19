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

void printPolynomial(const char name, const char variable, const const std::vector<std::pair<int, int>> polynomial, const bool includePrefix = true)
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
}

void readPolynomialDegree(char* degree) 
{
    std::cout << "Enter degree of your polynomial: ";

    std::cin >> degree;

    validatePolynomialDegree(degree);
}

std::vector<std::pair<int, int>> readPolymonial(const char name, const char variable)
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
    std::cout << std::endl;

    return polynomial;
}

int getPolynomialDegree(const std::vector<std::pair<int, int>> polynomial)
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

std::vector<std::pair<int, int>> createPolynomial(const int degree)
{
    std::vector<std::pair<int, int>> polynomial(degree + 1);

    for (int i = 0; i <= degree; i++)
    {
        polynomial[i] = {0, 1};
    }

    return polynomial;
}

void swapPolynomials(std::vector<std::pair<int, int>>& polynomialP, std::vector<std::pair<int, int>>& polynomialB)
{
    std::vector<std::pair<int, int>> tempPolynomial = polynomialB;
    polynomialB = polynomialP;
    polynomialP = tempPolynomial;
}

void generateRootCombinations(const int n, const int k, std::vector<int>& combination, bool& isFirstTerm, const int start = 1)
{
    int combinationSize = combination.size();

    if (combinationSize == k)
    {
        if (!isFirstTerm)
        {
            std::cout << " + ";
        }
        isFirstTerm = false;

        for (int i = 0; i < combinationSize; i++) {
            std::cout << "x" << combination[i];
        }
        return;
    }

    for (int i = start; i <= n; ++i) {
        combination.push_back(i);
        generateRootCombinations(n, k, combination, isFirstTerm, i + 1);
        combination.pop_back();
    }
}
