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
* Header: Operations with polynomials.
*
*/

#pragma once

#include <vector>

std::vector<std::pair<int, int>> addPolynomials(std::vector<std::pair<int, int>> polynomialP, std::vector<std::pair<int, int>> polynomialQ);

void addPolynomials();

std::vector<std::pair<int, int>> subtractPolynomials(std::vector<std::pair<int, int>> polynomialP, std::vector<std::pair<int, int>> polynomialQ);

void subtractPolynomials();

std::vector<std::pair<int, int>> multiplyPolynomials(std::vector<std::pair<int, int>> polynomialP, std::vector<std::pair<int, int>> polynomialQ);

void multiplyPolynomials();

void dividePolynomials(std::vector<std::pair<int, int>>& polynomialP, std::vector<std::pair<int, int>> polynomialB, std::vector<std::pair<int, int>>& quotient);

void dividePolynomials();

void multiplyPolynomialByGivenScalar();

void calculatePolynomialForGivenNumber();

void findGcdOfTwoPolynomials();