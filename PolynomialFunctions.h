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

std::vector<std::pair<int, int>> multiplyPolynomials(const std::vector<std::pair<int, int>> polynomialP, const std::vector<std::pair<int, int>> polynomialQ);

void multiplyPolynomials();

void dividePolynomials(
	std::vector<std::pair<int, int>>& polynomialP, 
	const std::vector<std::pair<int, int>> polynomialB, 
	std::vector<std::pair<int, int>>& quotient, 
	const bool isGcdComputation = false);

void dividePolynomials();

void multiplyPolynomialByGivenScalar();

std::pair<int, int> calculatePolynomialForGivenNumber(const std::vector<std::pair<int, int>> polynomial, const std::pair<int, int> number);


void calculatePolynomialForGivenNumber();

void findGcdOfTwoPolynomials();

void generateRootCombinations(int n, int k, std::vector<int>& combination, bool& isFirstTerm, int start = 1);

void displayVietasFormulasForGivenPolynomial();

void representPolynomialInPowersOfXPlusA();

void findRationalRoots();