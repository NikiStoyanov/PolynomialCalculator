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
* Source: Helper functions for math operations.
*
*/

#include <iostream>

#include "HelperMathFunctions.h"
#include "ValidationFunctions.h"
#include "Constants.h"

int max(int a, int b)
{
    return a >= b ? a : b;
}

int min(int a, int b)
{
    return a <= b ? a : b;
}

int absolute(int number)
{
    return number < 0 ? -number : number;
}

int customAtoi(char* str) 
{
    int sign = 1;
    int result = 0;

    removeWhitespaces(str);

    if (str[0] == '-')
    {
        sign = -1;
    }

    int index = 0;

    if (str[0] == '+' || str[0] == '-')
    {
        index++;
    }

    while (str[index] != TERMINATE_SYMBOL) {
        int digit = str[index] - '0';

        result = result * 10 + digit;

        index++;
    }

    return result * sign;
}

int gcd(int a, int b)
{
    a = absolute(a);
    b = absolute(b);

    if (a == 0)
    {
        return b;
    }

    return gcd(b % a, a);
}

int lcm(int a, int b)
{
    if (a == 0 || b == 0)
    {
        return 0;
    }

    return absolute(a * b) / gcd(a, b);
}

void simplifyFraction(std::pair<int, int>& fraction)
{
    int greatestCommonDivisor = gcd(fraction.first, fraction.second);

    if (greatestCommonDivisor != 1)
    {
        fraction.first /= greatestCommonDivisor;
        fraction.second /= greatestCommonDivisor;
    }
}

std::pair<int, int> addFractions(std::pair<int, int> firstFraction, std::pair<int, int> secondFraction)
{
    if (firstFraction.second != secondFraction.second)
    {
        int leastCommonDenominator = lcm(firstFraction.second, secondFraction.second);

        firstFraction.first *= leastCommonDenominator / firstFraction.second;
        firstFraction.second = leastCommonDenominator;

        secondFraction.first *= leastCommonDenominator / secondFraction.second;
        secondFraction.second = leastCommonDenominator;
    }

    std::pair<int, int> result = { firstFraction.first + secondFraction.first, firstFraction.second };

    simplifyFraction(result);

    return result;
}

std::pair<int, int> subtractFractions(std::pair<int, int> firstFraction, std::pair<int, int> secondFraction)
{
    if (firstFraction.second != secondFraction.second)
    {
        int leastCommonDenominator = lcm(firstFraction.second, secondFraction.second);

        firstFraction.first *= leastCommonDenominator / firstFraction.second;
        firstFraction.second = leastCommonDenominator;

        secondFraction.first *= leastCommonDenominator / secondFraction.second;
        secondFraction.second = leastCommonDenominator;
    }

    std::pair<int, int> result = { firstFraction.first - secondFraction.first, firstFraction.second };

    simplifyFraction(result);

    return result;
}

std::pair<int, int> multiplyFractions(std::pair<int, int> firstFraction, std::pair<int, int> secondFraction)
{
    std::pair<int, int> result;
    
    result.first = firstFraction.first * secondFraction.first;
    result.second = firstFraction.second * secondFraction.second;

    simplifyFraction(result);

    return result;
}

std::pair<int, int> divideFractions(std::pair<int, int> firstFraction, std::pair<int, int> secondFraction)
{
    std::pair<int, int> result;
    
    result.first = firstFraction.first * secondFraction.second;
    result.second = firstFraction.second * secondFraction.first;

    simplifyFraction(result);

    return result;
}

std::pair<int, int> readFraction()
{
    char fraction[MAX_FRACTION_SIZE];
    std::cin >> fraction;

    removeWhitespaces(fraction);

    unsigned index = 0, numIndex = 0, denIndex = 0;
    char numerator[MAX_FRACTION_SIZE] = { 0 };
    char denominator[MAX_FRACTION_SIZE] = { 0 };
    bool isNumerator = true;

    while (fraction[index] != TERMINATE_SYMBOL) {
        if (!isDigit(fraction[index]) && fraction[index] != '-' && fraction[index] != '/')
        {
            std::cout << INVALID_CHARACTER_ERROR_MESSAGE;

            return readFraction();
        }

        if (fraction[index] == '/')
        {
            isNumerator = false;
        }
        else if (isNumerator)
        {
            numerator[numIndex++] = fraction[index];
        }
        else
        {
            denominator[denIndex++] = fraction[index];
        }

        index++;
    }

    numerator[numIndex] = TERMINATE_SYMBOL;
    denominator[denIndex] = TERMINATE_SYMBOL;

    int num = customAtoi(numerator);
    int den = (denIndex > 0) ? customAtoi(denominator) : 1;

    if (den == 0)
    {
        std::cout << ZERO_DENOMINATOR_ERROR_MESSAGE;
        return readFraction();
    }

    std::pair<int, int> result = { num, den };

    simplifyFraction(result);

    if (result.second < 0)
    {
        result.first = -result.first;
        result.second = -result.second;
    }

    return result;
}

void printFraction(std::pair<int, int> fraction)
{
    if (fraction.second == 1)
    {
        std::cout << fraction.first;
    }
    else
    {
        std::cout << fraction.first << '/' << fraction.second;
    }
}

std::pair<int, int> integerToFraction(int number)
{
    return { number, 1 };
}

std::pair<int, int> fractionPow(std::pair<int, int> fraction, int pow)
{
    std::pair<int, int> result = { 1, 1 };

    for (unsigned i = 0; i < pow; i++)
    {
        result = multiplyFractions(fraction, result);
    }

    return result;
}