
#include <iostream>

#include "Polynomial.h"


int main()
{
	std::cout << "Monomial Test" << std::endl;
	
	Monomial mono1(2, 2); // 2x^2
	Monomial mono2(3, 1); // 3x
	Monomial mono3(1, 0); // 1
	
	std::cout << mono1 << " * " << mono2 << " = " << (mono1 * mono2) << std::endl;
	std::cout << mono1 << " * " << mono3 << " = " << (mono1 * mono3) << std::endl;
	std::cout << mono3 << " * " << mono2 << " = " << (mono3 * mono2) << std::endl;
	
	std::cout << "Polynomial Test" << std::endl;
	
	Polynomial poly1 = mono3 + mono2 + mono1; // poly1 = 2x^2 + 3x + 1
	Polynomial poly2 = mono3 - mono2 + mono1; // poly2 = 2x^2 - 3x + 1
	
	std::cout << mono3 << " + " << mono2 << " + " << mono1 << " = " << poly1 << std::endl;
	std::cout << mono3 << " - " << mono2 << " + " << mono1 << " = " << poly2 << std::endl;
	
	std::cout <<  "(" << poly1 << ") * (" << poly2 << ") = " << (poly1 * poly2) << std::endl;
	
	Polynomial poly3 = Monomial(1, 1) - 1; // poly3 = x - 1
	
	std::cout << "(" << poly1 << ")(" << 3 << ") = " << poly1(3) << std::endl;
	std::cout << "(" << poly1 << ")(" << 3.5 << ") = " << poly1(3.14) << std::endl;
	std::cout << "(" << poly1 << ")(" << poly3 << ") = " << poly1(poly3) << std::endl;
	
	return 0;
}






