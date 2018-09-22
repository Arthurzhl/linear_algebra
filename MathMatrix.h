#pragma once
#include "MathVector.h"
#include <vector>
using namespace std;
class MathMatrix
{
private:

	vector<vector<double>> mvalues;

public:
	MathMatrix();
	MathMatrix(double, double, double,
		double, double, double,
		double, double, double);
	MathMatrix(double, double,
				   double, double);

	MathMatrix addMathVector(MathVector&);
	void transpose(MathMatrix&);
	double dot(MathMatrix&);
	MathMatrix crossProduct(MathMatrix&, MathMatrix&);
	~MathMatrix();


};

