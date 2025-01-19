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
#include "Constants.h"
#include "PolynomialFunctions.h"

bool isDigit(const char symbol)
{
	return symbol >= '0' && symbol <= '9';
}

void validateOptionSelection(char* option)
{
	if (option[1] != TERMINATE_SYMBOL || option[0] == TERMINATE_SYMBOL)
	{
		std::cout << INVALID_OPTION_ERROR_MESSAGE << std::endl;

		readOption(option);
	}

	if (option[0] < 'a' || option[0] > 'k')
	{
		std::cout << INVALID_OPTION_ERROR_MESSAGE << std::endl;

		readOption(option);
	}
}

void validatePolynomialDegree(char* degree)
{
	int index = 0;

	if (degree[0] == '0' && degree[1] != TERMINATE_SYMBOL)
	{
		std::cout << INVALID_POLYNOMIAL_DEGREE_ERROR_MESSAGE << std::endl;

		readPolynomialDegree(degree);
	}

	while (degree[index] != TERMINATE_SYMBOL)
	{
		if (!isDigit(degree[index]))
		{
			std::cout << INVALID_POLYNOMIAL_DEGREE_ERROR_MESSAGE << std::endl;

			readPolynomialDegree(degree);
		}

		index++;
	}
}

void validateNumber(char* number)
{
	int index = 0;

	while (number[index] != TERMINATE_SYMBOL)
	{
		if (!isDigit(number[index]))
		{
			std::cout << INVALID_INTEGER_ERROR_MESSAGE;

			readNumberN(number);
		}

		index++;
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

	str[writeIndex] = TERMINATE_SYMBOL;
}