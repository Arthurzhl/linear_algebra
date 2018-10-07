// linear_algebra.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <string>
#include "MathVector.h"
#include "MathMatrix.h"
using namespace std;



int main(int argc, char *argv[]) {

	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	MathVector v1(s1), v2(s2);
	MathVector v3;
	double dp = NAN;
	dp = v1.dot(v2); 
	cout << "v1 = " << endl; 
	v1.print();
	cout << endl << "v2 = " << endl; 
	v2.print();
	MathVector v4;
	v4 = v3*(-10);
	v4.print();
	
	cout << "dot product is " << dp << endl;

	MathMatrix x1;
	x1.addMathVector(v1);
	x1.addMathVector(v2);
	cout<< "x1 =  "<<endl;
	x1.print();
	MathMatrix x2(x1);
	cout<< " x2 =  "<<endl;
	x2.transpose();
	x2.print();
	MathMatrix result = x1.multiply(x1,x2);	
	cout<< "result is = " << endl;
	result.print();
	MathMatrix Iden = result.getIdentity(result.getRow(), result.getCol());
	cout<< "identity is = ="<<endl;
	Iden.print();
	result = result.elim(-1,1,2);
	cout<<"result = " << endl;
	result.print();	


	return 0;



}
