#ifndef SecondDegreePolynomial_H
#define SecondDegreePolynomial_H
#include "Polynomial.h"
class SecondDegreePolynomial : public Polynomial
{
public:
	//Constructors
	SecondDegreePolynomial(const std::vector<double>& Coeffs) :Polynomial(Coeffs) {
		if (Coeffs.size() != 3)
			throw "Second Degree Polynomial need to have 3 elements";
	}
	//Overloaded virtual method
	std::vector<std::complex<double>>roots() const {
		std::vector<std::complex<double>> retObj(0, 0);

		double a = this->mCoeffs[0];
		double b = this->mCoeffs[1];
		double c = this->mCoeffs[2];
		double delta = b * b - 4 * a * c;
		double im = 0;
		double re = 0;
		if (delta < 0){
			//append re=-b/(2*a) and im=sqrt(abs(delta))))/(2*a)
			re = -b / (2 * a);
			im = sqrt(abs(delta)) / (2 * a);
			retObj.push_back(std::complex<double>(re, im));
			im = -sqrt(abs(delta)) / (2 * a);
			retObj.push_back(std::complex<double>(re, im));
		}
		else if(delta==0) retObj.push_back(std::complex<double>(-b / (2 * a), 0));
		else {
			//delta>0
			im = 0;
			re = (-b + sqrt(delta)) / (2 * a);
			retObj.push_back(std::complex<double>(re, im));
			re = (-b - sqrt(delta)) / (2 * a);
			retObj.push_back(std::complex<double>(re, im));
		}
		return retObj;
	}
};
#endif

