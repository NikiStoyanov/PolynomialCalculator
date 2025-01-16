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
* Header: Helper functions for math operations.
*
*/

#pragma once

int gcd(int a, int b);

int lcm(int a, int b);

void simplifyFraction(std::pair<int, int>& fraction);

std::pair<int, int> addFractions(std::pair<int, int> firstFraction, std::pair<int, int> secondFraction);

std::pair<int, int> subtractFractions(std::pair<int, int> firstFraction, std::pair<int, int> secondFraction);

std::pair<int, int> multiplyFractions(std::pair<int, int> firstFraction, std::pair<int, int> secondFraction);

std::pair<int, int> divideFractions(std::pair<int, int> firstFraction, std::pair<int, int> secondFraction);

std::pair<int, int> readFraction();

void printFraction(std::pair<int, int> fraction);

std::pair<int, int> integerToFraction(int number);