// linear_algebra.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "MathVector.h"
using namespace std;


int main() {
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	MathVector v1(s1), v2(s2);
	MathVector v3;
	double dp = NAN;
	//	dp = v1.dot(v2); 
	cout << "v1 = " << endl; 
	v1.print();
	cout << endl << "v2 = " << endl; 
	v2.print();
	v3 = v1 + v2;
	v3.print();
	v3 = v1 - v2;

	cout << "dot product is " << dp << endl;


	return 0;



}



