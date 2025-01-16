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

void addPolynomials()
{
    std::vector<std::pair<int, int>> polynomialP = readPolymonial('P', 'x');
    std::cout << std::endl;
    std::vector<std::pair<int, int>> polynomialQ = readPolymonial('Q', 'x');

    int degreeOfP = polynomialP.size() - 1;
    int degreeOfQ = polynomialQ.size() - 1;

    std::cout << "P(x)+Q(x) = ";

    if (degreeOfP >= degreeOfQ)
    {
        for (int i = 0; i <= degreeOfQ; i++)
        {
            polynomialP[i] = addFractions(polynomialP[i], polynomialQ[i]);
        }

        printPolynomial('P', 'x', polynomialP, false);
    }
    else
    {
        for (int i = 0; i <= degreeOfP; i++)
        {
            polynomialQ[i] = addFractions(polynomialP[i], polynomialQ[i]);
        }

        printPolynomial('Q', 'x', polynomialQ, false);
    }
}

void subtractPolynomials()
{
    std::vector<std::pair<int, int>> polynomialP = readPolymonial('P', 'x');
    std::cout << std::endl;
    std::vector<std::pair<int, int>> polynomialQ = readPolymonial('Q', 'x');

    int degreeOfP = polynomialP.size() - 1;
    int degreeOfQ = polynomialQ.size() - 1;

    std::cout << "P(x)-Q(x) = ";

    if (degreeOfP >= degreeOfQ)
    {
        for (int i = 0; i <= degreeOfQ; i++)
        {
            polynomialP[i] = subtractFractions(polynomialP[i], polynomialQ[i]);
        }

        printPolynomial('P', 'x', polynomialP, false);
    }
    else
    {
        for (int i = 0; i <= degreeOfP; i++)
        {
            polynomialQ[i] = subtractFractions(polynomialQ[i], polynomialP[i]);
        }

        for (int i = 0; i <= degreeOfQ; i++)
        {
            polynomialQ[i] = multiplyFractions(polynomialQ[i], integerToFraction(-1));
        }

        printPolynomial('Q', 'x', polynomialQ, false);
    }
}

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
    
    printPolynomial('P', 'x', polynomial, false);
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