#ifndef Polynomial_H
#define Polynomial_H

#include<vector>
#include<iostream>
#include <math.h>
#include <complex>

class Polynomial
{
	//define members as protected for inheritance used in other classes
protected:
	std::vector<double> mCoeffs;
	unsigned int mDegree;
public:
	//Constructors
	Polynomial() { this->mDegree = 0; this->mCoeffs = std::vector<double>(0, 0);}
	Polynomial(unsigned int Degree) {this->mDegree = 0; this->mCoeffs = std::vector<double>(Degree, 0); }
	Polynomial(const std::vector<double>& Coeffs) { this->mCoeffs = Coeffs; this->mDegree = Coeffs.size(); }

	//Destructors
	~Polynomial() { this->mDegree = 0; }

	//Operators
	double& operator[](unsigned int index);
	double operator[](unsigned int index) const;
	Polynomial operator+(const Polynomial& rhs) const;
	Polynomial operator*(const Polynomial& rhs) const;
	Polynomial operator*=(const double constant) const;
	Polynomial operator/=(const double constant) const;

	//Methods
	Polynomial derivate(unsigned int x);
	double calculate(double value) const;
	std::complex<double> calculate(const std::complex<double>& value) const;

	//Getters & Setters
	unsigned int getDegree() { return this->mDegree; }
	//realized too late that i should return this->mDegree-1 instead of this->mDegree
	unsigned int getDegree() const { return this->mDegree; }

	//Virtual Methods
	virtual std::vector<std::complex<double>> roots() const
	{
		std::cout << "Implementation for method roots for polynomials with degree=" << this->mDegree << " is not available. \n";
		return std::vector<std::complex<double>>(0, 0);
	}

};
#endif

