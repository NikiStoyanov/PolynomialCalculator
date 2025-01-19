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
#include "Constants.h"

std::vector<std::pair<int, int>> addPolynomials(std::vector<std::pair<int, int>> polynomialP, std::vector<std::pair<int, int>> polynomialQ)
{
    int degreeOfP = getPolynomialDegree(polynomialP);
    int degreeOfQ = getPolynomialDegree(polynomialQ);

    if (degreeOfP >= degreeOfQ)
    {
        for (int i = 0; i <= degreeOfQ; i++)
        {
            polynomialP[i] = addFractions(polynomialP[i], polynomialQ[i]);
        }

        return polynomialP;
    }
    else
    {
        for (int i = 0; i <= degreeOfP; i++)
        {
            polynomialQ[i] = addFractions(polynomialP[i], polynomialQ[i]);
        }

        return polynomialQ;
    }
}

void addPolynomials()
{
    std::vector<std::pair<int, int>> polynomialP = readPolymonial('P', 'x');
    std::cout << std::endl;
    std::vector<std::pair<int, int>> polynomialQ = readPolymonial('Q', 'x');

    std::vector<std::pair<int, int>> result = addPolynomials(polynomialP, polynomialQ);

    std::cout << "P(x)+Q(x) = ";

    printPolynomial('R', 'x', result, false);
}

std::vector<std::pair<int, int>> subtractPolynomials(std::vector<std::pair<int, int>> polynomialP, std::vector<std::pair<int, int>> polynomialQ)
{
    int degreeOfP = getPolynomialDegree(polynomialP);
    int degreeOfQ = getPolynomialDegree(polynomialQ);

    if (degreeOfP >= degreeOfQ)
    {
        for (int i = 0; i <= degreeOfQ; i++)
        {
            polynomialP[i] = subtractFractions(polynomialP[i], polynomialQ[i]);
        }

        return polynomialP;
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

        return polynomialQ;
    }
}

void subtractPolynomials()
{
    std::vector<std::pair<int, int>> polynomialP = readPolymonial('P', 'x');
    std::cout << std::endl;
    std::vector<std::pair<int, int>> polynomialQ = readPolymonial('Q', 'x');

    std::vector<std::pair<int, int>> result = subtractPolynomials(polynomialP, polynomialQ);

    std::cout << "P(x)-Q(x) = ";

    printPolynomial('R', 'x', result, false);
}

std::vector<std::pair<int, int>> multiplyPolynomials(std::vector<std::pair<int, int>> polynomialP, std::vector<std::pair<int, int>> polynomialQ)
{
    int degreeOfP = getPolynomialDegree(polynomialP);
    int degreeOfQ = getPolynomialDegree(polynomialQ);

    int resultDegree = degreeOfP + degreeOfQ;

    std::vector<std::pair<int, int>> result = createPolynomial(resultDegree);

    for (int i = 0; i <= degreeOfP; i++)
    {
        for (int j = 0; j <= degreeOfQ; j++)
        {
            result[i + j] = addFractions(result[i + j], multiplyFractions(polynomialP[i], polynomialQ[j]));
        }
    }
    return result;
}

void multiplyPolynomials()
{
    std::vector<std::pair<int, int>> polynomialP = readPolymonial('P', 'x');
    std::cout << std::endl;
    std::vector<std::pair<int, int>> polynomialQ = readPolymonial('Q', 'x');

    std::vector<std::pair<int, int>> result = multiplyPolynomials(polynomialP, polynomialQ);

    std::cout << "P(x)*Q(x) = ";
    
    printPolynomial('R', 'x', result, false);
}

void dividePolynomials(
    std::vector<std::pair<int, int>>& polynomialP,
    std::vector<std::pair<int, int>> polynomialB,
    std::vector<std::pair<int, int>>& quotient,
    bool isGcdComputation = false)
{
    int degreeOfP = getPolynomialDegree(polynomialP);
    int degreeOfB = getPolynomialDegree(polynomialB);

    if (degreeOfB == 0 && (polynomialB[0] == integerToFraction(0)))
    {
        if (isGcdComputation)
        {
            return;
        }

        std::cout << DIVIDE_BY_ZERO_ERROR_MESSAGE;
        return;
    }

    if (degreeOfB > degreeOfP)
    {
        std::cout << DIVIDE_BY_HIGHER_DEGREE_ERROR_MESSAGE;
        return;
    }

    if (degreeOfB == 0)
    {
        for (int i = 0; i <= degreeOfP; i++)
        {
            polynomialP[i] = divideFractions(polynomialP[i], polynomialB[0]);
        }

        quotient = polynomialP;
        polynomialP = createPolynomial(0);
        return;
    }

    int quotientDegree = degreeOfP - degreeOfB;

    while (degreeOfP >= degreeOfB)
    {
        int currentQuotientDegree = degreeOfP - degreeOfB;

        std::vector<std::pair<int, int>> currentQuotient = createPolynomial(currentQuotientDegree);

        currentQuotient[currentQuotientDegree] = divideFractions(polynomialP[degreeOfP], polynomialB[degreeOfB]);

        quotient = addPolynomials(quotient, currentQuotient);

        std::vector<std::pair<int, int>> remainder = createPolynomial(degreeOfP);

        remainder = subtractPolynomials(polynomialP, multiplyPolynomials(currentQuotient, polynomialB));

        polynomialP = remainder;
        degreeOfP = getPolynomialDegree(polynomialP);
    }
}

void dividePolynomials()
{
    std::vector<std::pair<int, int>> polynomialP = readPolymonial('P', 'x');
    std::cout << std::endl;
    std::vector<std::pair<int, int>> polynomialB = readPolymonial('B', 'x');

    int degreeOfP = getPolynomialDegree(polynomialP);
    int degreeOfB = getPolynomialDegree(polynomialB);

    if (degreeOfB == 0 && (polynomialB[degreeOfB] == integerToFraction(0)))
    {
        std::cout << DIVIDE_BY_ZERO_ERROR_MESSAGE;
        return;
    }
    if (degreeOfB > degreeOfP)
    {
        std::cout << DIVIDE_BY_HIGHER_DEGREE_ERROR_MESSAGE;
        return;
    }

    int quotientDegree = degreeOfP - degreeOfB;

    std::vector<std::pair<int, int>> quotient = createPolynomial(quotientDegree);

    dividePolynomials(polynomialP, polynomialB, quotient);

    std::cout << std::endl;
    std::cout << "Quotient ";
    printPolynomial('Q', 'x', quotient, true);

    std::cout << "Remainder ";
    printPolynomial('R', 'x', polynomialP, true);
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
    
    printPolynomial('R', 'x', polynomial, false);
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

void swapPolynomials(std::vector<std::pair<int, int>>& polynomialP, std::vector<std::pair<int, int>>& polynomialB)
{
    std::vector<std::pair<int, int>> tempPolynomial = polynomialB;
    polynomialB = polynomialP;
    polynomialP = tempPolynomial;
}

void findGcdOfTwoPolynomials()
{
    std::vector<std::pair<int, int>> polynomialP = readPolymonial('P', 'x');
    std::cout << std::endl;
    std::vector<std::pair<int, int>> polynomialB = readPolymonial('B', 'x');

    int degreeOfP = getPolynomialDegree(polynomialP);
    int degreeOfB = getPolynomialDegree(polynomialB);

    if (degreeOfB == 0 && (polynomialB[degreeOfB] == integerToFraction(0)))
    {
        printPolynomial('P', 'x', polynomialP, false);
        return;
    }
    if (degreeOfP == 0 && (polynomialP[degreeOfP] == integerToFraction(0)))
    {
        printPolynomial('B', 'x', polynomialB, false);
        return;
    }

    if (degreeOfB > degreeOfP)
    {
        swapPolynomials(polynomialP, polynomialB);
    }

    int quotientDegree = degreeOfP - degreeOfB;

    std::vector<std::pair<int, int>> quotient = createPolynomial(quotientDegree);
    std::vector<std::pair<int, int>> gcd = polynomialP;

    while (!(degreeOfP == 0 && (polynomialP[degreeOfP] == integerToFraction(0))))
    {
        dividePolynomials(polynomialP, polynomialB, quotient, true);

        gcd = polynomialP;

        swapPolynomials(polynomialP, polynomialB);

        degreeOfP = getPolynomialDegree(polynomialP);
    }

    std::cout << std::endl;
    std::cout << "gcd(P(x), Q(x)) = ";
    printPolynomial('G', 'x', gcd, false);
}

void generateRootCombinations(int n, int k, std::vector<int>& combination, bool& isFirstTerm, int start = 1)
{
    int combinationSize = combination.size();

    if (combinationSize == k)
    {
        if (!isFirstTerm)
        {
            std::cout << " + ";
        }
        isFirstTerm = false;

        for (size_t i = 0; i < combinationSize; ++i) {
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

void displayVietasFormulasForGivenPolynomial()
{
    std::vector<std::pair<int, int>> polynomial = readPolymonial('P', 'x');

    std::cout << std::endl;
    std::cout << "Vieta's Formulas for polynomial: ";
    printPolynomial('P', 'x', polynomial, true);

    int polynomialDegree = getPolynomialDegree(polynomial);

    // a0x^3 + a1x^2 + a2x^1 + a3x^0
    // [a3, a2, a1, a0]
    for (int i = 1; i <= polynomialDegree; i++)
    {
        std::vector<int> combination;
        bool isFirstTerm = true;

        generateRootCombinations(polynomialDegree, i, combination, isFirstTerm);
        std::cout << " = ";

        std::pair<int, int> numerator = polynomial[polynomialDegree - i];
        std::pair<int, int> denomerator = polynomial[polynomialDegree];

        std::pair<int, int> value = divideFractions(numerator, denomerator);

        simplifyFraction(value);

        if (i % 2 != 0)
        {
            value = multiplyFractions(value, integerToFraction(-1));
        }

        printFraction(value);

        std::cout << std::endl;
    }
}