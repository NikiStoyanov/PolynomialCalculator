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

void printPolynomial(char name, char variable, const std::vector<std::pair<int, int>> polynomial, bool includePrefix = true);

void readPolynomialDegree(char* degree);

int getPolynomialDegree(std::vector<std::pair<int, int>> polynomial);

std::vector<std::pair<int, int>> readPolymonial(char name, char variable);

std::vector<std::pair<int, int>> createPolynomial(int degree);