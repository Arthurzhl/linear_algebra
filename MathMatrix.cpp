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


MathMatrix::MathMatrix(double u1, double v1, double w1,
	double u2, double v2, double w2,
	double u3, double v3, double w3)
{
	mRow = mCol = 3;
	MathVector vv1(u1, u2, u3);
	MathVector vv2(v1, v2, v3);
	MathVector vv3(w1, w2, w3);
	
	mvalues.push_back(vv1);
	mvalues.push_back(vv2);
	mvalues.push_back(vv3);
}


MathMatrix::MathMatrix(double u1, double v1, 
	double u2, double v2)
{
	mRow = mCol = 2;
	MathVector vv1(u1, u2);
	MathVector vv2(v1, v2);
	mvalues.push_back(vv1);
	mvalues.push_back(vv2);
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


// get col and row
int MathMatrix::getCol() {
	return mCol;
}
int MathMatrix::getRow() {
	return mRow;
}


MathMatrix MathMatrix::dotProduct(const MathMatrix& x, const MathMatrix& y) {
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



MathMatrix& MathMatrix::operator= ( const MathMatrix& x){
	mvalues = x.mvalues;
	mCol = x.mCol;
	mRow = x.mRow;
	return *this;
}	
	 
