#include "poly.h"
#include <iostream>
#include <ostream>

using namespace std;

Poly::Poly(){
	map<int, double> Polynomial;
}

Poly::Poly(const double num){
	Polynomial[0] = num;
}

Poly::~Poly(){}

double& Poly::operator[](int exp){
	auto i = Polynomial.find(exp);
	
	if (i != Polynomial.end()){
		return i->second;
	}
	else {
		return Polynomial[exp];
	}
}

Poly operator+(const Poly& lhs, const Poly& rhs)
{
	Poly p;
	
	for (const auto& element : lhs.Polynomial){
		p.Polynomial[element.first] += element.second;
	}
	
	for (const auto& element : rhs.Polynomial){
		p.Polynomial[element.first] += element.second;
	}
	
	return p;
}

Poly operator-(const Poly& lhs, const Poly& rhs)
{
	Poly p;
	
	for (const auto& element : lhs.Polynomial){
		p.Polynomial[element.first] += element.second;
	}
	
	for (const auto& element : rhs.Polynomial){
		p.Polynomial[element.first] -= element.second;
	}
	
	return p;
}

Poly operator*(const Poly& lhs, const Poly& rhs)
{
	Poly p;
	
	for (const auto& element1 : lhs.Polynomial){
		for (const auto& element2 : rhs.Polynomial){
			int exp = element1.first + element2.first;
			double coef = element1.second * element2.second;
			
			p.Polynomial[exp] += coef;
		}	
	}
	
	return p;
}

Poly operator-(const Poly& rhs)
{	
	Poly p;
	
	for(const auto& element : rhs.Polynomial)
	{
		p.Polynomial[element.first] -= element.second;
	}
	return p;
}

double Poly::operator()(double const value) const
{
	double result = 0;
	for (const auto& element : this->Polynomial)
	{
		result += element.second * pow(value, element.first);
	}
	return result;
}

ostream& operator<<(ostream& os, Poly const& p)
{
	bool is_first = true;
	for (const auto& element : p.Polynomial)
	{
		if (!is_first){
			if(element.second == 0.0)
			{
				continue;
			}
		}
		
		if(!is_first && element.second > 0)
		{
			os << "+ ";
		}
		
		if (element.first == 0.0)
		{
			os << element.second << " ";
		}
		else{
			if (element.second != 1.0)
			{
				os << element.second;
			}
			os << "x^" << element.first << " ";
		}
		is_first = false;		
	}
	return os;
}

