#include "Polynomial.h"
//Operators
double& Polynomial::operator[](unsigned int index) {
	return this->mCoeffs[index];
}

double Polynomial::operator[](unsigned int index) const{
	return this->mCoeffs[index];
}

Polynomial Polynomial::operator+(const Polynomial& rhs) const {
	//treat each case possible:
	//same degree
	//different degree
	//initiliaze the vector of new coeffs with the longest degree
	std::vector<double> retObj = std::vector<double>(this->mDegree > rhs.mDegree ? this->mDegree : rhs.mDegree, 0);

	
	unsigned int minimum = this->mDegree < rhs.mDegree ? this->mDegree : rhs.mDegree;
	for (int i = 0; i < minimum; i++)
		retObj[i] = this->mCoeffs[i] + rhs.mCoeffs[i];

	for (int i = minimum; i < this->mDegree; i++)
		retObj[i] = this->mCoeffs[i];

	for (int i = minimum; i < rhs.mDegree; i++)
		retObj[i] = rhs.mCoeffs[i];
	
	return Polynomial(retObj);
}

Polynomial Polynomial::operator*(const Polynomial& rhs) const {
	std::vector<double> retObj = std::vector<double>(this->mDegree > rhs.mDegree ? this->mDegree : rhs.mDegree, 0);
	for (int i = 0; i < this->mDegree; i++)
		for (int j = 0; j < rhs.mDegree; j++)
			retObj[i + j] += this->mCoeffs[i] * rhs.mCoeffs[j];
	return Polynomial(rhs);
}

Polynomial Polynomial::operator*=(const double constant) const {
	std::vector<double> retObj = this->mCoeffs;
	for (int i = 0; i < this->mDegree; i++)
		retObj[i] = retObj[i] * constant;
	return Polynomial(retObj);
}

Polynomial Polynomial::operator/=(const double constant) const {
	std::vector<double> retObj = this->mCoeffs;
	for (int i = 0; i < this->mDegree; i++)
		retObj[i] = retObj[i] / constant;
	return Polynomial(retObj);
}
//Methods
double Polynomial::calculate(double value) const {
	double retObj = 0;
	for (int i = 0; i < this->mDegree; i++) {
		//substract -i-1 since greatest power is mDegree-1
		retObj = this->mCoeffs[i] * pow(value, mDegree - i - 1);
	}
	return retObj;
}

std::complex<double> Polynomial::calculate(const std::complex<double>& value) const {
	std::complex<double> retObj = 0;
	for (int i = 0; i < this->mDegree; i++) {
		//substract -i-1 since greatest power is mDegree-1
		//we can use basically the same method since pow defines in header files std::complex
		retObj = this->mCoeffs[i] * pow(value, mDegree - i - 1);
	}
	return retObj;
}

Polynomial Polynomial::derivate(unsigned int x) {
	if (x > this->mDegree) {
		return Polynomial(0);
	}
	std::vector<double> retObj =mCoeffs;
	while (x--) {
		retObj.pop_back();
		int currentSize = (int)retObj.size();
		for (int i = 0; i<currentSize; i++) {
			//cast to double to avoid memory overflow (casting from 4 bit to 8 bit)
			retObj[i] = retObj[i] * ((double)currentSize - (double)i);
		}
	}
	return Polynomial(retObj);
}


