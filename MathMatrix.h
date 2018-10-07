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
	//constructor that initialize matrix that have n of 0's
	MathMatrix(int,int);
	MathMatrix(const MathMatrix&);

	
	~MathMatrix();
	
	//add and get
	int getCol() const;
	int getRow() const;
	bool isempty() const;
	void addMathVector(MathVector&);
	bool isSquare() const;
	// get a identity matrix, size as inputs
	MathMatrix getIdentity(int, int);
			
	
	//debug
	//print
	void print();

	//opeartor
	MathMatrix& operator= ( const MathMatrix&);
	//calculation
	MathMatrix multiply(MathMatrix&, MathMatrix&);
	void transpose();
	MathMatrix elim(double , int , int);
	void updateSize();
	MathMatrix dotProduct(const MathMatrix&, const MathMatrix&);
};
#endif
