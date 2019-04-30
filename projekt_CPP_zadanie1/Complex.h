#pragma once
#include <ostream>
#include <stdexcept>
#include <iostream>
#include "Exceptions.h"
using namespace std;

template<class T>
class Complex
{
protected:
	T real, imag;
public:

	//Default constructor
	Complex()
	{
		real = 0;
		imag = 0;
	}

	//Constructor
	Complex(double Real,double Imag)
	{
		real = Real;
		imag = Imag;
	};

	//Copy constructor
	Complex(const Complex &c)
	{
		this->real = c.real;
		this->imag = c.imag;
	}

	//Converse constructor
	Complex(double c)
	{
		this->real = this->imag = c;
	}

	Complex(int c)
	{
		this->real = this->imag = c;
	}

	Complex(float c)
	{
		this->real = this->imag = c;
	}

	//Getters and Setters
	void setReal(T Real)
	{
		real = Real;
	}

	void setImag(T Imag)
	{
		imag = Imag;
	}

	double getReal()
	{
		return real;
	}

	double getImag()
	{
		return imag;
	}

	double getModul()
	{
		if (real == 0)
		{
			throw (Exceptions(4));
		}
		else if (real < 0)
		{
			throw (Exceptions(5));
		}
		else
		{
			return sqrt(real*  real + imag * imag);
		}
	}

	double getPhase()
	{
		if (real == 0)
		{
			throw (Exceptions(4));
		}else if (real < 0 )
		{
			throw (Exceptions(5));
		}
		else
		{
			return atan(imag / real);
		}
		
	}

	//Friend operators
	friend istream& operator>>(istream &inputStream,Complex<double> &C);
	friend ostream& operator<<(ostream &out, const Complex &C);
	friend Complex operator+(const Complex &ComplexA, const Complex &ComplexB);
	friend Complex operator-(const Complex &ComplexA);
	friend Complex operator-(const Complex &ComplexA, const Complex &ComplexB);
	friend Complex operator*(const Complex &ComplexA, const Complex &ComplexB);
	friend Complex operator/(const Complex &ComplexA, const Complex &ComplexB);
	friend Complex operator+=(Complex &ComplexA, const Complex &ComplexB);
	friend Complex operator-=(Complex &ComplexA, const Complex &ComplexB);
	friend Complex operator*=(Complex &ComplexA, const Complex &ComplexB);
	friend Complex operator/=(Complex &ComplexA, const Complex &ComplexB);
	friend Complex operator~(const Complex &ComplexA);
	friend bool operator ==(const Complex &ComplexA, const Complex &ComplexB);
	friend bool operator !=(const Complex &ComplexA, const Complex &ComplexB);

	void operator =(Complex &ComplexA)
	{
		real = ComplexA.real;
		imag = ComplexA.imag;
	}

	double& operator[] (string str) {
		if (str == "real" || str == "Real" || str == "REAL")
		{
			return real;
		}else if (str == "imag" || str == "Imag" || str == "IMAG")
		{
			return  imag;
		}
		else
		{
			throw (Exceptions(1));
		}
	}

	double& operator[] (int str) {
		if (str == 0)
		{
			return real;
		}
		else if (str == 1)
		{
			return  imag;
		}
		else
		{
			throw (Exceptions(2));
		}
	}

	double& operator[] (char str) {
		if (str == 'r' || str == 'R')
		{
			return real;
		}
		else if (str == 'i' ||str == 'I')
		{
			return  imag;
		}
		else
		{
			throw (Exceptions(3));
		}
	}


	//NEPOTREBNY ALE FUNKCNY

	/*istream& operator>>(istream &in)
	{
		cout << "Realna: ";
		in >> real;
		cout << "Imaginarna: ";
		in >> imag;
		return  in;
	}*/
};

