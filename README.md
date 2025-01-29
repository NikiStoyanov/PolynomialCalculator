# Polynomial Calculator Documentation

## Introduction

This project is a **Polynomial Calculator** that works with polynomials having **rational coefficients**. The main functionalities of the program include polynomial addition, subtraction, multiplication, division, scalar multiplication, evaluation at a given point, GCD calculation using the Euclidean algorithm, Vieta's formulas, representation of polynomials in powers of (x + a), and factoring polynomials to find rational roots. This program is implemented in C++ using `std::vector` and `std::pair` for efficient storage and manipulation of polynomial data.

## Features

The **Polynomial Calculator** supports the following features:

1. [**Add Polynomials**](#add-polynomials): Adds two polynomials `P(x)` and `Q(x)`;
2. [**Subtract Polynomials**](#subtract-polynomials): Subtracts polynomial `Q(x)` from polynomial `P(x)`;
3. [**Multiply Polynomials**](#multiply-polynomials): Multiplies two polynomials `P(x)` and `Q(x)`;
4. [**Divide Polynomials**](#divide-polynomials): Divides polynomial `P(x)` by polynomial `Q(x)` (with `Q(x)` ≠ 0 and degree of `P(x)` ≥ degree of `Q(x)`);
5. [**Multiply Polynomial by Scalar**](#multiply-polynomial-by-scalar): Multiplies a polynomial `P(x)` by a rational scalar;
6. [**Calculate Polynomial for a Given Number**](#calculate-polynomial-for-a-given-number): Calculates the value of polynomial `P(x)` for a given rational number;
7. [**Find GCD of Two Polynomials**](#find-gcd-of-two-polynomials): Computes the greatest common divisor (GCD) of two polynomials using the Euclidean algorithm;
8. [**Display Vieta's Formulas**](#display-vietas-formulas): Displays Vieta's formulas for a given polynomial;
9. [**Represent Polynomial in Powers of (x + a)**](#represent-polynomial-in-powers-of-x--a): Rewrites a polynomial in terms of powers of `(x + a)`;
10. [**Factor Polynomial and Find Rational Roots**](#factor-polynomial-and-find-rational-roots): Factors a polynomial (if possible) and finds its rational roots;
11. [**Display N-th derivative of a given polynomial**](#display-n-th-derivative-of-a-given-polynomial): Computes the N-th derivative of the polynomial `P(x)` and displays it.

## How to Use - User interface
### Add polynomials
```
Enter Polynomial P(x)
Enter degree of your polynomial >> 2
Enter coefficient before x^2 >> 1
Enter coefficient before x^1 >> 3
Enter coefficient before x^0 >> -2/3
P(x) = x^2 + 3x - 2/3

Enter Polynomial Q(x)
Enter degree of your polynomial >> 3
Enter coefficient before x^3 >> -1/7
Enter coefficient before x^2 >> 0
Enter coefficient before x^1 >> 1/2
Enter coefficient before x^0 >> -6
Q(x) = -1/7x^3 + 1/2x - 6

P(x) + Q(x) = -1/7x^3 + x^2 + 7/2x - 20/3
```
### Subtract polynomials
```
Enter Polynomial P(x)
Enter degree of your polynomial: 2
Enter coefficient before x^2: 1
Enter coefficient before x^1: 3
Enter coefficient before x^0: -2/3
P(x) = x^2+3x-2/3

Enter Polynomial Q(x)
Enter degree of your polynomial: 3
Enter coefficient before x^3: -1/7
Enter coefficient before x^2: 0
Enter coefficient before x^1: 1/2
Enter coefficient before x^0: -6
Q(x) = -1/7x^3+1/2x-6

P(x)-Q(x) = 1/7x^3+x^2+5/2x+16/3
```
### Multiply Polynomials
```
Enter Polynomial P(x)
Enter degree of your polynomial: 1
Enter coefficient before x^1: 1
Enter coefficient before x^0: -1
P(x) = x-1

Enter Polynomial Q(x)
Enter degree of your polynomial: 1
Enter coefficient before x^1: 1
Enter coefficient before x^0: 1
Q(x) = x+1

P(x)*Q(x) = x^2-1
```
### Divide Polynomials
```
Enter Polynomial P(x)
Enter degree of your polynomial: 3
Enter coefficient before x^3: 1
Enter coefficient before x^2: -1
Enter coefficient before x^1: 1
Enter coefficient before x^0: -1
P(x) = x^3-x^2+x-1

Enter Polynomial B(x)
Enter degree of your polynomial: 1
Enter coefficient before x^1: 2
Enter coefficient before x^0: 1
B(x) = 2x+1

Quotient Q(x) = 1/2x^2-3/4x+7/8
Remainder R(x) = -15/8
```
### Multiply Polynomial by Scalar
```
Enter Polynomial P(x)
Enter degree of your polynomial: 2
Enter coefficient before x^2: -3/5
Enter coefficient before x^1: 1/10
Enter coefficient before x^0: 2
P(x) = -3/5x^2+1/10x+2
Enter rational number: 20

Result: -12x^2+2x+40
```
### Calculate Polynomial for a Given Number
```
Enter Polynomial P(x)
Enter degree of your polynomial: 4
Enter coefficient before x^4: 3
Enter coefficient before x^3: 0
Enter coefficient before x^2: 0
Enter coefficient before x^1: 0
Enter coefficient before x^0: -1
P(x) = 3x^4-1
Enter rational number: 1/2

P(1/2) = -13/16
```
### Find GCD of Two Polynomials
```
Enter Polynomial P(x)
Enter degree of your polynomial: 3
Enter coefficient before x^3: 1
Enter coefficient before x^2: -2
Enter coefficient before x^1: -1
Enter coefficient before x^0: 2
P(x) = x^3-2x^2-x+2

Enter Polynomial B(x)
Enter degree of your polynomial: 2
Enter coefficient before x^2: 1
Enter coefficient before x^1: 0
Enter coefficient before x^0: -1
B(x) = x^2-1

gcd(P(x), Q(x)) = x^2-1
```
### Display Vieta's Formulas
```
Enter Polynomial P(x)
Enter degree of your polynomial: 4
Enter coefficient before x^4: 6
Enter coefficient before x^3: 2
Enter coefficient before x^2: -5
Enter coefficient before x^1: -1
Enter coefficient before x^0: 3
P(x) = 6x^4+2x^3-5x^2-x+3

Vieta's Formulas for polynomial: P(x) = 6x^4+2x^3-5x^2-x+3
x1 + x2 + x3 + x4 = -1/3
x1x2 + x1x3 + x1x4 + x2x3 + x2x4 + x3x4 = -5/6
x1x2x3 + x1x2x4 + x1x3x4 + x2x3x4 = 1/6
x1x2x3x4 = 1/2
```
### Represent Polynomial in Powers of (x + a)
```
Enter Polynomial P(x)
Enter degree of your polynomial: 4
Enter coefficient before x^4: 1
Enter coefficient before x^3: 8
Enter coefficient before x^2: 24
Enter coefficient before x^1: 50
Enter coefficient before x^0: 90
P(x) = x^4+8x^3+24x^2+50x+90
Enter rational number a: 2

P(t) = t^4+18t+38, t = x+2
```
### Factor Polynomial and Find Rational Roots
```
Enter Polynomial P(x)
Enter degree of your polynomial: 4
Enter coefficient before x^4: 1
Enter coefficient before x^3: 0
Enter coefficient before x^2: -33
Enter coefficient before x^1: -100
Enter coefficient before x^0: -84
P(x) = x^4-33x^2-100x-84

P(x) = (x-2)^2(x-3)(x+7)= 0
RATIONAL ROOTS:
x = -2 -> 2-fold root
x = -3 -> 1-fold root
x = 7 -> 1-fold root
```
### Display N-th derivative of a given polynomial
```
Enter Polynomial P(x)
Enter degree of your polynomial: 4
Enter coefficient before x^4: 3
Enter coefficient before x^3: 9
Enter coefficient before x^2: 2
Enter coefficient before x^1: 2
Enter coefficient before x^0: 193
P(x) = 3x^4+9x^3+2x^2+2x+193
Enter n, an integer number: 3

P^(3)(x) = 72x+54
```
## Conclusion

This **Polynomial Calculator** provides a robust and efficient way to work with polynomials of rational coefficients. It supports a variety of polynomial operations, making it a useful tool for both learning and practical applications in algebra.
