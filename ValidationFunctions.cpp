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
* Source: Methods that validate user's input.
*
*/

#include <iostream>

#include "UserInterface.h"
#include "HelperPolynomialFunctions.h"

const char NON_NUMERIC_OPTION_ERROR_MESSAGE[] = "You should enter a numeric value.";
const char NOT_LISTED_OPTION_ERROR_MESSAGE[] = "This is not a listed option!";
const char INVALID_POLYNOMIAL_DEGREE_ERROR_MESSAGE[] = "This is not a valid polynomial degree!";
const char TERMINATE_SYMBOL = '\0';

bool isDigit(char symbol)
{
	return symbol >= '0' && symbol <= '9';
}

void validatePolynomialDegree(int& degree)
{
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << NON_NUMERIC_OPTION_ERROR_MESSAGE << std::endl;

		readPolynomialDegree(degree);
	}

	if (degree < 0)
	{
		std::cout << INVALID_POLYNOMIAL_DEGREE_ERROR_MESSAGE << std::endl;

		readPolynomialDegree(degree);
	}
}

void removeWhitespaces(char* str)
{
	unsigned readIndex = 0, writeIndex = 0;

	while (str[readIndex] != TERMINATE_SYMBOL)
	{
		if (str[readIndex] != ' ')
		{
			str[writeIndex++] = str[readIndex];
		}
		readIndex++;
	}

	str[writeIndex] = TERMINATE_SYMBOL; // Null-terminate the cleaned string
}