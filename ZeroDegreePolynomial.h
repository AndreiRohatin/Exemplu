#ifndef ZeroDegreePolynomial_H
#define ZeroDegreePolynomial_H
#include "Polynomial.h"
class ZeroDegreePolynomial : public Polynomial
{
public:
	//Constructors
	ZeroDegreePolynomial(const std::vector<double>& Coeffs) :Polynomial(Coeffs) {
		if (Coeffs.size() != 1)
			throw "Zero Degree Polynomial need to have 1 element";
	}
	//Overloaded virtual method
	std::vector<std::complex<double>>roots() const {
		std::cout << "Polynomials with 0 degree doesn't have roots.\n";
		return std::vector<std::complex<double>>(0, 0);
	}
};
#endif
