#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
using namespace std;


class MathVector {
	
	private:
		vector<double>	values;
	
	public:
		MathVector();
		MathVector(vector<double>);
		MathVector (MathVector&);
		MathVector (double, double);
		MathVector (double, double, double);		

		virtual ~MathVector();

		double dot(const MathVector&);
		vector<double>::size_type size() const;	
		vector<double>::const_iterator begin() const;
		vector<double>::const_iterator end() const;

		MathVector& operator=(const MathVector&);
		MathVector  operator+(const MathVector&);				
		void print();


};		
#endif
	
		


