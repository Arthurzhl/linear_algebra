#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
#include <string>
#include <cmath>
using namespace std;


class MathVector {
	
	private:
		vector<double>	values;
	
	public:
		MathVector();
		MathVector(vector<double>);
		MathVector (const MathVector&);
		MathVector (double, double);
		MathVector (double, double, double);		
		MathVector (string& s);
		
		virtual ~MathVector();

		double dot(const MathVector&);
		vector<double>::size_type size() const;	
		vector<double>::const_iterator begin() const;
		vector<double>::const_iterator end() const;
		

		MathVector& operator=(const MathVector&);
		MathVector  operator+(const MathVector&);	
		MathVector  operator-(const MathVector&);
		MathVector  operator*(double scalar);
		bool isempty();
		void print();
		void printVector(vector<double>&);
	friend class MathMatrix;

};		
#endif
	
		


