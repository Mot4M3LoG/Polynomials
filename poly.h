#pragma once
#include <iostream>
#include <cmath>
#include <map>

using namespace std;

class Poly {
  public:
	map<int, double> Polynomial;
	
	Poly();
	Poly(const double num);
	~Poly();
	
	double& operator[](int exp);
	
	double operator()(double const value) const;
  	
};

ostream& operator<<(ostream &, Poly const& p);

Poly operator+(const Poly& lhs, const Poly& rhs);
Poly operator-(const Poly& lhs, const Poly& rhs);
Poly operator*(const Poly& lhs, const Poly& rhs);

Poly operator-(const Poly& rhs);
