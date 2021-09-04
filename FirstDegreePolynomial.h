#ifndef FirstDegreePolynomial_H
#define FirstDegreePolynomial_H
#include "Polynomial.h"
class FirstDegreePolynomial :public Polynomial
{
public:
	//Constructors
	FirstDegreePolynomial(const std::vector<double>& Coeffs) :Polynomial(Coeffs) {
		if (Coeffs.size() != 2)
			throw "First Degree Polynomial need to have 2 elements";
	}
	//Overloaded virtual method
	std::vector<std::complex<double>>roots() const {
		double root = -this->mCoeffs[1] / this->mCoeffs[0];
		return std::vector<std::complex<double>>(1, root);
	}
};
#endif

