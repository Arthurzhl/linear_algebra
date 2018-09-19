#include <iostream>
#include <string>
#include "MathVector.h"
using namespace std;

MathVector getInput();

int main(){
	
	MathVector v1, v2;
	v1 = getInput();
	v2 = getInput();
	v1.print();
	v2.print();
//	double dp;
//	dp = v1.dot(v2); 
	

//	cout<<"dot product is "<<dp <<endl;
	

	return 0;
	
	

}




MathVector getInput(){
	string vectorInLine;
	vector<double> temp;
	getline(cin,vectorInLine);
	for (auto it = vectorInLine.begin(); it != vectorInLine.end();++it){
		if(!isspace(*it)){
			const char cstr = it->c_str;	
			temp.push_back(atof(cstr));
		}
	
	}
	
	MathVector v(temp);
	v.print();
	return v;




}
