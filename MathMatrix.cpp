//#include "stdafx.h"
#include "MathMatrix.h"
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;

MathMatrix::MathMatrix()
{
	mvalues.clear();
	
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

void MathMatrix::transpose(){
	if(mvalues.empty() || mvalues[0].values.empty()){
		throw runtime_error(" matrix empty"); 
	}
	vector<double> temp;
	auto X_w = mvalues.size();
	auto X_h = mvalues[0].size();
	auto temp_h = mCol;
	auto temp_w = mRow; 
	MathMatrix m(*this);
	//need to check
	mvalues.clear();
	//iterate thru all rows of x

	for (int row = 0; row < X_h; ++row){// there are h of rows in x
			
			
		//for every single column of x, push back element to each row of temp
		for ( int colInTemp = 0; colInTemp < temp_h; ++colInTemp){
			temp.push_back(m.mvalues[colInTemp].values[row]);
		}
		mvalues.push_back(MathVector(temp));
		temp.clear();
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




// opeartor

MathMatrix& MathMatrix::operator= ( const MathMatrix& x){
	mvalues = x.mvalues;
	mCol = x.mCol;
	mRow = x.mRow;
	return *this;
}	
	 
// multiplication
MathMatrix& MathMatrix::operator* (const MathMatrix& x){
	if(mvalues.empty() || mvalues[0].values.empty()){
		throw runtime_error(" matrix empty"); 
	}

	if(x.mvalues.empty() || x.mvalues[0].values.empty()){
		throw runtime_error("x matrix empty"); 
	}


	double scalar = NAN;
	MathMatrix tempM;
	MathVector tempV;

	if (mCol == x.mRow) {
		// there is mcol of vectors in *this
		for (int i = 0; i < mCol; ++i) {
			// go thru each row of x to sum scalars for each vectors of m
			for (int j = 0; j < x.mCol; ++j) {
				scalar += x.mvalues[j].values[i];
			}
			tempV = mvalues[i];
			tempV = tempV* scalar;
			tempM.mvalues.push_back(tempV);
			tempV.values.clear();
		}
	}
	else {
		throw runtime_error("matirx size dont fit");
	}
	*this = tempM;

	return *this;
}

// print

void MathMatrix::print(){
	if(mvalues.empty() || mvalues[0].values.empty()){
		cerr<< "error! matrix empty"<<endl;
		return; 
	}
	// for everysingle column
	for (auto i = 0; i < mCol; ++i){
		cout<<"|";
		// for everysingle row, print
		for (auto j = 0; j < mRow; j++){
			cout<<mvalues[j].values[i];
			if(j == mRow - 1){ break;}
			else{ cout<<setw(5);}
		}
		cout<<"|"<< endl;
	}
}
			
		
		




