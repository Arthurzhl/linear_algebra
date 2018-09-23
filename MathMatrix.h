#ifndef M_MATRIX
#define M_MATRIX
#include "MathVector.h"
#include <vector>
using namespace std;
class MathMatrix
{
private:

	vector<MathVector> mvalues;
	int mCol;
	int mRow;

public:
	MathMatrix();
	
	MathMatrix(double, double, double,
		double, double, double,
		double, double, double);
	MathMatrix(double, double,
				   double, double);
	MathMatrix::MathMatrix(const MathMatrix&);
	MathMatrix addMathVector(MathVector&);
	
	void transpose(const MathMatrix&);
	double dot(MathMatrix&);
	MathMatrix crossProduct(const MathMatrix&, const MathMatrix&);
	
	~MathMatrix();


};
#endif
