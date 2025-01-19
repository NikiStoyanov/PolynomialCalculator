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
    std::cout << std::endl;
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
    std::cout << std::endl;
}

std::vector<std::pair<int, int>> multiplyPolynomials(const std::vector<std::pair<int, int>> polynomialP, const std::vector<std::pair<int, int>> polynomialQ)
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
    std::cout << std::endl;
}

void dividePolynomials(
    std::vector<std::pair<int, int>>& polynomialP,
    const std::vector<std::pair<int, int>> polynomialB,
    std::vector<std::pair<int, int>>& quotient,
    const bool isGcdComputation = false)
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
    std::cout << std::endl;

    std::cout << "Remainder ";
    printPolynomial('R', 'x', polynomialP, true);
    std::cout << std::endl;
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
    std::cout << std::endl;
}

std::pair<int, int> calculatePolynomialForGivenNumber(const std::vector<std::pair<int, int>> polynomial, const std::pair<int, int> number)
{
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

    return sum;
}

void calculatePolynomialForGivenNumber() 
{
    std::vector<std::pair<int, int>> polynomial = readPolymonial('P', 'x');

    std::cout << "Enter rational number: ";
    std::pair<int, int> number = readFraction();

    std::pair<int, int> sum = calculatePolynomialForGivenNumber(polynomial, number);

    std::cout << "P(";
    printFraction(number);
    std::cout << ") = ";
    printFraction(sum);
    std::cout << std::endl;
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
        std::cout << std::endl;
        return;
    }
    if (degreeOfP == 0 && (polynomialP[degreeOfP] == integerToFraction(0)))
    {
        printPolynomial('B', 'x', polynomialB, false);
        std::cout << std::endl;
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
    std::cout << std::endl;
}

void displayVietasFormulasForGivenPolynomial()
{
    std::vector<std::pair<int, int>> polynomial = readPolymonial('P', 'x');

    std::cout << std::endl;
    std::cout << "Vieta's Formulas for polynomial: ";
    printPolynomial('P', 'x', polynomial, true);
    std::cout << std::endl;

    int polynomialDegree = getPolynomialDegree(polynomial);

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

void representPolynomialInPowersOfXPlusA()
{
    std::vector<std::pair<int, int>> polynomial = readPolymonial('P', 'x');

    std::cout << "Enter rational number a: ";
    std::pair<int, int> a = readFraction();
    std::cout << std::endl;

    std::cout << "P(x";
    if (a.first > 0)
    {
        std::cout << "+";
    }
    printFraction(a);
    std::cout << ") = ";
}

void findRationalRoots()
{
    std::vector<std::pair<int, int>> polynomial = readPolymonial('P', 'x');

    int polynomialDegree = getPolynomialDegree(polynomial);

    if (polynomialDegree == 0)
    {
        std::cout << "No rational roots!";
        return;
    }

    int denominatorsLcm = 1;

    for (int i = 0; i <= polynomialDegree; i++)
    {
        denominatorsLcm = lcm(denominatorsLcm, polynomial[i].second);
    }

    for (int i = 0; i <= polynomialDegree; i++)
    {
        polynomial[i] = multiplyFractions(polynomial[i], integerToFraction(denominatorsLcm / polynomial[i].second));
        polynomial[i].second = 1;
    }

    std::pair<int, int> leadingCoefficient = polynomial[polynomialDegree];

    std::vector<std::pair<int, int>> roots;

    while (polynomialDegree > 0)
    {
        std::vector<std::pair<int, int>> fractions = generateFractions(polynomial[0].first, polynomial[polynomialDegree].first);
        int countOfFractions = fractions.size();

        int rootsCount = roots.size();

        for (int i = 0; i < fractions.size(); i++)
        {
            std::pair<int, int> value = calculatePolynomialForGivenNumber(polynomial, fractions[i]);

            simplifyFraction(value);

            if (value == integerToFraction(0))
            {
                roots.push_back(fractions[i]);

                std::vector<std::pair<int, int>> quotient = createPolynomial(polynomialDegree);
                std::vector<std::pair<int, int>> divider = createPolynomial(1);
                divider[1].first = 1;
                divider[0] = multiplyFractions(fractions[i], integerToFraction(-1));

                dividePolynomials(polynomial, divider, quotient);
                polynomial = quotient;

                polynomialDegree = getPolynomialDegree(polynomial);
            }
        }

        if (rootsCount == roots.size())
        {
            break;
        }
    }

    std::cout << std::endl;
    std::cout << "P(x) = ";
    if (leadingCoefficient != integerToFraction(1))
    {
        printFraction(leadingCoefficient);
    }
    
    std::vector<std::pair<std::pair<int, int>, int>> foldedRoots = countOccurrences(roots);
    int foldedRootsCount = foldedRoots.size();

    for (int i = 0; i < foldedRootsCount; i++)
    {
        std::cout << "(x";
        if (foldedRoots[i].first.first > 0)
        {
            std::cout << "+";
        }
        printFraction(foldedRoots[i].first);
        std::cout << ")";

        if (foldedRoots[i].second > 1)
        {
            std::cout << "^" << foldedRoots[i].second;
        }
    }

    // If there are complex and irrational roots
    if (polynomialDegree > 0 )
    {
        std::cout << '(';
        printPolynomial('P', 'x', polynomial, false);
        std::cout << ')';
    }

    std::cout << "= 0";
    std::cout << std::endl;

    if (roots.size() > 0)
    {
        std::cout << "RATIONAL ROOTS:" << std::endl;
    }
    else
    {
        std::cout << "No rational roots!" << std::endl;
    }
    
    for (int i = 0; i < foldedRootsCount; i++)
    {
        std::cout << "x = ";
        printFraction(foldedRoots[i].first);
        std::cout << " -> " << foldedRoots[i].second << "-fold root" << std::endl;
    }
}

void findNthDerivativeOfPolynomial()
{
    
}