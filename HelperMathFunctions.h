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

#include <vector>

int max(const int a, const int b);

int min(const int a, const int b);

int absolute(const int number);

int customAtoi(char* str);

int gcd(int a, int b);

int lcm(const int a, const int b);

void simplifyFraction(std::pair<int, int>& fraction);

std::pair<int, int> addFractions(std::pair<int, int> firstFraction, std::pair<int, int> secondFraction);

std::pair<int, int> subtractFractions(std::pair<int, int> firstFraction, std::pair<int, int> secondFraction);

std::pair<int, int> multiplyFractions(const std::pair<int, int> firstFraction, const std::pair<int, int> secondFraction);

std::pair<int, int> divideFractions(const std::pair<int, int> firstFraction, const std::pair<int, int> secondFraction);

std::pair<int, int> readFraction();

void printFraction(const std::pair<int, int> fraction);

std::pair<int, int> integerToFraction(const int number);

std::pair<int, int> fractionPow(const std::pair<int, int> fraction, const int pow);

std::vector<int> findDivisors(int n);

bool containsElement(const std::vector<std::pair<int, int>> polynomial, const std::pair<int, int> element);

std::vector<std::pair<int, int>> generateFractions(const int a, const int b);

std::vector<std::pair<std::pair<int, int>, int>> countOccurrences(const std::vector<std::pair<int, int>>& roots);