#include "stdafx.h"
#include "MathMatrix.h"
#include <stdlib.h>
#include <iostream>

MathMatrix::MathMatrix()
{
	mCol = sizeof(mvalues);
	mRow = mvalues[0].size(); 
}

MathMatrix::MathMatrix(const MathMatrix& x) {
	for (auto it = x.mvalues.begin(); it != x.mvalues.end(); ++it) {
		mvalues.push_back(*it);
	}


}


MathMatrix::MathMatrix(double x1, double y1, double z1,
	double x2, double y2, double z2,
	double x3, double y3, double z3)
{
	mvalues[0].values.push_back(x1);
	mvalues[0].values.push_back(x2);
	mvalues[0].values.push_back(x3);
	mvalues[1].values.push_back(y1);
	mvalues[1].values.push_back(y2);
	mvalues[1].values.push_back(y3);
	mvalues[2].values.push_back(z1);
	mvalues[2].values.push_back(z2);
	mvalues[2].values.push_back(z3);
}


MathMatrix::MathMatrix(double x1, double y1, 
	double x2, double y2)
{
	mvalues[0].values.push_back(x1);
	mvalues[0].values.push_back(x2);
	mvalues[1].values.push_back(y1);
	mvalues[1].values.push_back(y2);
}



MathMatrix::~MathMatrix()
{
}

void MathMatrix::transpose(const MathMatrix& x){
		vector<double> temp;
	auto X_w = x.mvalues.size();
	auto X_h = x.mvalues[0].size();
	auto temp_h = X_w;
	auto temp_w = X_h; 
	//need to check
	mvalues.clear();
	//iterate thru all rows of x

	for (int rowInX = 0; rowInX < X_h; ++rowInX){// there are h of rows in x
			
			
		//for every single column of x, push back element to each row of temp
		for ( int colInTemp = 0; colInTemp < temp_h; ++colInTemp){
			temp.push_back(x.mvalues[rowInX].values[colInTemp]);
		}
		mvalues.push_back(MathVector(temp));
	}

}



MathMatrix MathMatrix::crossProduct(const MathMatrix& x, const MathMatrix& y) {
	double dot;
	double scalar = NAN;
	MathMatrix tempM;
	MathVector tempV;

	if (y.mRow == x.mCol && y.mCol == x.mRow) {
		// there is mcol of vectors in *this
		for (int i = 0; i < mCol; ++i) {
			// go thru each row of x to sum scalars for each vectors of m
			for (int j = 0; j < y.mCol; ++j) {
				scalar += y.mvalues[j].values[i];
			}
			tempV = x.mvalues[i];
			tempV = tempV* scalar;
			tempM.mvalues.push_back(tempV);
			tempV.values.clear();
		}
	}
	else {
		throw runtime_error("matirx size dont fit");
	}

	return tempM;
}