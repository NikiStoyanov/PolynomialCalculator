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
* Constants used over the application
*
*/

#pragma once

const char INVALID_OPTION_ERROR_MESSAGE[] = "This is not a valid option!";
const char DIVIDE_BY_HIGHER_DEGREE_ERROR_MESSAGE[] = "You cannot divide by a polynomial of a higher degree!";
const char DIVIDE_BY_ZERO_ERROR_MESSAGE[] = "You cannot divide by zero!";
const char ZERO_DENOMINATOR_ERROR_MESSAGE[] = "The denominator could not be 0! Re-enter the coefficient:";
const char INVALID_CHARACTER_ERROR_MESSAGE[] = "Invalid character detected. Re-enter the fraction: ";
const char INVALID_POLYNOMIAL_DEGREE_ERROR_MESSAGE[] = "This is not a valid polynomial degree!";
const char TERMINATE_SYMBOL = '\0';

constexpr int MAX_FRACTION_SIZE = 30;
constexpr int OPTION_MAX_LENGTH = 10;
constexpr int MAX_DEGREE_LENGTH = 15;