#include "stdafx.h"
#include "MathMatrix.h"


MathMatrix::MathMatrix()
{
	mvalues[0] = { NAN };
}


MathMatrix::MathMatrix(double x1, double y1, double z1,
	double x2, double y2, double z2,
	double x3, double y3, double z3)
{
	mvalues[0].push_back(x1);
	mvalues[0].push_back(x2);
	mvalues[0].push_back(x3);
	mvalues[1].push_back(y1);
	mvalues[1].push_back(y2);
	mvalues[1].push_back(y3);
	mvalues[2].push_back(z1);
	mvalues[2].push_back(z2);
	mvalues[2].push_back(z3);
}


MathMatrix::MathMatrix(double x1, double y1, 
	double x2, double y2)
{
	mvalues[0].push_back(x1);
	mvalues[0].push_back(x2);
	mvalues[1].push_back(y1);
	mvalues[1].push_back(y2);
}


MathMatrix::~MathMatrix()
{
}
