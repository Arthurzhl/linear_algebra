#include "MathVector.h"

#include "iostream"
#include <vector>
#include <stdlib.h>
using namespace std;


// constructors
MathVector :: MathVector(){
	values = {0};
}



//copy constructor
MathVector :: MathVector(vector<double> vector){
	values = vector;

}
//move constructor
MathVector :: MathVector(MathVector& mvector){
	values = mvector.values;
	

}

MathVector :: MathVector (double x, double y){
	values = {x,y};

}

MathVector :: MathVector (double x, double y, double z){
	values = {x,y,z};

}
//destructor
MathVector::~MathVector (){

}

//member function

double MathVector::dot(const MathVector& v2){
	// checking if v1 or v2 are empty
	if (this->begin() == this->end()){throw runtime_error("vector can not be empty");}
	if (v2.begin() == v2.end()){throw runtime_error("second vector can not be empty");}
	//continue
	if (this->size() == v2.size()){
		double dotp;
		for (int i=0; i<this->size();++i){
			dotp += this->values[i]*v2.values[i];	
		}

		return dotp;
	}else{
		throw runtime_error("two vectors are not same size");	
	
	
	}
	cout<<"returning flase"<<endl;
	return false;	
}

//get useful vector function for MathVector
vector<double>::size_type MathVector::size() const {
	return values.size();
}

vector<double>::const_iterator MathVector::begin() const {
	return values.cbegin();
}

vector<double>::const_iterator MathVector::end() const {
	return values.cend();
}

// operator overloading
//assignment
MathVector& MathVector::operator=(const MathVector& v){
	if (this == &v) { return *this;}
	
	values = v.values;
	
	return *this;

}	

//addition
MathVector MathVector::operator+(const MathVector& v){	
	// checking if v is empty
	if (v.begin() == v.end()){throw runtime_error("vector can not be empty");}
	//continue
	if (values.size() == v.size()){
		for (int i=0; i<v.size();++i){
			values[i]-= v.values[i];	
		}

		return *this;
	}else{
		throw runtime_error("two vectors are not same size");	
	
	}	
}


// print

void MathVector::print(){	
	double a;
	if (this->begin() == this->end()){throw runtime_error("vector can not be empty");}
	for(auto it = values.begin(); it != values.end(); ++it){
		cout<<*it<<endl;	
	//	a = atof(*(it->c_str()));
	//	cout<<"|"<<a<<"|"<<endl;
	}




}
























