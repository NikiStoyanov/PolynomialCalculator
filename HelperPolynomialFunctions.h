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

#pragma once

#include <vector>

void printPolynomial(const char name, const char variable, const std::vector<std::pair<int, int>> polynomial, const bool includePrefix = true);

void readPolynomialDegree(char* degree);

std::vector<std::pair<int, int>> readPolymonial(const char name, const char variable);

int getPolynomialDegree(const std::vector<std::pair<int, int>> polynomial);

std::vector<std::pair<int, int>> createPolynomial(const int degree);

void swapPolynomials(std::vector<std::pair<int, int>>& polynomialP, std::vector<std::pair<int, int>>& polynomialB);

void generateRootCombinations(const int n, const int k, std::vector<int>& combination, bool& isFirstTerm, const int start = 1);