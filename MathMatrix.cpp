//#include "stdafx.h"
#include "MathMatrix.h"
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;

//important!! column first, mvalues[col].values[row]

MathMatrix::MathMatrix()
{
	mvalues.clear();
	
}

MathMatrix::MathMatrix(const MathMatrix& x) {
	if (x.isempty()) {
		cerr << "error! either Matrix is empty" << endl;
		exit(-1);
	}
	for (auto it = x.mvalues.begin(); it != x.mvalues.end(); ++it) {
		mvalues.push_back(*it);
	}
	this->updateSize();

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
//initialize a empty matrix with all 0s
MathMatrix::MathMatrix(int row,int col){
	mvalues.clear();
	for(int i = 0; i< col; ++i){
		vector<double> v(row,0);
		MathVector vtemp(v);
		mvalues.push_back(vtemp);
	}
	this->updateSize();
}


MathMatrix::~MathMatrix()
{
}

void MathMatrix::transpose(){
	if(mvalues.empty() || mvalues[0].values.empty()){
		cerr << "error! Matrix is empty" << endl;
		exit(-1);
	}
	//temp is one of the columns of transposed matrix
	vector<double> temp;

	//get a copy
	MathMatrix tempMtx(*this);

	//now clear this for new incomming matrix
	mvalues.clear();
	//now get a row from tempMtx and change it to to a MathVector
	//thats row loop outside column loop
	for (int i = 0; i < tempMtx.mRow; ++i){// there are h of rows in x
			
			
		//now row loop
		for ( int j = 0; j < tempMtx.mCol; ++j){
			//get all values in a row, mvalues[col].values[row] 
			temp.push_back(tempMtx.mvalues[j].values[i]);
		}
		mvalues.push_back(MathVector(temp));
		temp.clear();
	}
	this->updateSize();

}

// add a MathVector 
void MathMatrix::addMathVector(MathVector& v){
	mvalues.push_back(v);
	this->updateSize();
}



// get col and row
int MathMatrix::getCol() const{
	return mCol;
}
int MathMatrix::getRow() const {
	return mRow;
}

//update size
void MathMatrix::updateSize() {
	if (mvalues.empty() || mvalues[0].values.empty()) {
		cerr << "error! Matrix is empty" << endl;
		exit(-1);
	}
	mRow = mvalues[0].size();
	mCol = mvalues.size();
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
	tempM.updateSize();
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
MathMatrix MathMatrix::multiply(MathMatrix& x,MathMatrix& y){
	if(x.isempty() || y.isempty()){
		cerr<<"error! either Matrix is empty"<<endl;
		exit(-1);
	}
	const int productCol = x.mRow;
	const int productRow = y.mCol;
	MathMatrix product(productCol,productRow);
	x.transpose();
	// secondly, go thru all rows
	//product index C(i,j)
	for( int j = 0; j < productCol; ++j){
		// first go thru all columns
		for( int i =0; i < productRow;++i){
			product.mvalues[j].values[i] = x.mvalues[i].dot(y.mvalues[j]);
		}	
	}
	product.updateSize();
	return product;
	
}

//is square
bool MathMatrix::isSquare() const{
	if(mRow == mCol) { 
		return true;
	}else{
		return false;
	}
}
	

//isempty
bool MathMatrix::isempty()const {
	for(auto it = mvalues.begin();it != mvalues.end(); ++it){
		if(it->isempty()){ 
			return true;
		}
	}
	if (mvalues.size() == 0) { return true; }
	return false;
}
// print

void MathMatrix::print(){
	if(mvalues.empty() || mvalues[0].values.empty()){
		cerr<< "error! matrix empty"<<endl;
		return; 
	}
	// need to print by row, thats every column in same row
	// and go thru all rows
	// thats mRow outside loop
	for (auto i = 0; i < mRow; ++i){
		cout<<"|";
		// now mCol inside
		for (auto j = 0; j < mCol; j++){
			cout<<mvalues[j].values[i];
			if(j == mCol - 1){ break;}
			else{ cout<<setw(5);}
		}
		cout<<"|"<< endl;
	}
}
			
// this function does get an idendity matrix according to current matrix
MathMatrix MathMatrix::getIdentity(int row, int col){
	if (! this->isSquare()){
		cerr<<" error! input matrix ix not a square matrix"<<endl;
	}
	// get 0's
	MathMatrix Iden = MathMatrix(row,col);
	for (int i = 0; i < Iden.mRow; ++i){
		Iden.mvalues[i].values[i] = 1;
	}
	return Iden;
}
	
	
// this function does the row elimination process
MathMatrix MathMatrix::elim(double multiple, int rowBeingSubtracted, int subtractor){
	if (!this->isSquare()){
		cerr<<" error! input matrix ix not a square matrix"<<endl;
	}
	if ((rowBeingSubtracted -2) < mRow && (subtractor - 2) < mCol){
		//elimination matrix, modified from identity matrix, same size as x
		MathMatrix E = getIdentity(mRow,mCol);	
		E.mvalues[subtractor -1].values[rowBeingSubtracted - 1] = multiple;
		return multiply(E,*this);
	}else{
		cerr<< "error!  row number exceeds matrix size" << endl;
		exit(-1);
	}
}
		




