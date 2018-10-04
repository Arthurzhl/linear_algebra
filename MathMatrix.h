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
	MathMatrix(const MathMatrix&);
	MathMatrix addMathVector(MathVector&);
	~MathMatrix();
	
	void transpose();
	double dot(MathMatrix&);
	MathMatrix dotProduct(const MathMatrix&, const MathMatrix&);
	int getCol();
	int getRow();
	
	//debug
	//print
	void print();

	//opeartor
	MathMatrix& operator= ( const MathMatrix&);
	MathMatrix& operator* ( const MathMatrix&);

};
#endif
