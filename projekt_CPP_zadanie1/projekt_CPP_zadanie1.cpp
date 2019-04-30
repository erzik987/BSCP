#include "pch.h"
#include <iostream>
#include "Complex.h"
#include "Exceptions.h"

using namespace std;

istream& operator>>(istream &inputStream,Complex<double> &C);
ostream& operator<<(ostream &out, const Complex<double> &C);
Complex<double> operator+(const Complex<double> &ComplexA, const Complex<double> &ComplexB);
Complex<double> operator-(const Complex<double> &ComplexA);
Complex<double> operator-(const Complex<double> &ComplexA, const Complex<double> &ComplexB);
Complex<double> operator*(const Complex<double> &ComplexA, const Complex<double> &ComplexB);
Complex<double> operator/(const Complex<double> &ComplexA, const Complex<double> &ComplexB);
Complex<double> operator+=(const Complex<double> &ComplexA, const Complex<double> &ComplexB);
Complex<double> operator-=(Complex<double> &ComplexA, const Complex<double> &ComplexB);
Complex<double> operator*=(Complex<double> &ComplexA, const Complex<double> &ComplexB);
Complex<double> operator/=(Complex<double> &ComplexA, const Complex<double> &ComplexB);
Complex<double> operator~(const Complex<double> &ComplexA);

bool operator !=(const Complex<double> &ComplexA, const Complex<double> &ComplexB);
bool operator ==(const Complex<double> &ComplexA, const Complex<double> &ComplexB);

int main()
{

	Complex<double> example(0, 0);
	Complex<double> example2(0, 0);

	int volba1;
	do
	{
		cout << endl;
		cout << "vyber z moznosti" << endl;
		cout << "1 - operacie s jedonu komplexnou rovnicou" << endl;
		cout << "2 - operacie s dvomi komplexnymi rovnicami" << endl;
		cout << "9 - koniec" << endl;
		cin >> volba1;
		switch (volba1)
		{
		case 1:
			cout << "zadaj realnu a imaginarnu zlozku danej rovnice" << endl;
			cin >> example;

			int volba;
			do
			{
				cout << endl;
				cout << "Vyber akciu ktoru chces vykonat pre zadane komplexne cislo " << example << endl;
				cout << "1 - zaporna hodnota" << endl;
				cout << "2 - zaporna hodnota imag casti" << endl;
				cout << "3 - modul" << endl;
				cout << "4 - faza" << endl;
				cout << "5 - zadaj rovnicu znova" << endl;
				cout << "9 - koniec" << endl;

				cout << "zadaj volbu" << endl;
				cin >> volba;
				switch (volba)
				{
				case 1:
					cout << -example << endl;
					break;
				case 2:
					cout << ~example<< endl;
					break;
				case 3:
					try
					{
						cout << example.getModul() << endl;
					}
					catch (Exceptions& e)
					{
						cout << "Exception: " << e.message() << "\n";
					}
					break;
				case 4:
					try
					{
						cout << example.getPhase() << endl;
					}
					catch (Exceptions& e)
					{
						cout << "Exception: " << e.message() << "\n";
					}
					break;
				case 5:
					cout << "zadaj realnu a imaginarnu zlozku danej rovnice" << endl;
					cin >> example;
					break;
				}
			} while (volba != 9);

			break;
		case 2:
			cout << "zadaj realnu a imaginarnu zlozku prvej rovnice" << endl;
			cin >> example;
			cout << "zadaj realnu a imaginarnu zlozku druhej rovnice" << endl;
			cin >> example2;

			int volba2;
			do
			{
				cout << "Vyber akciu ktoru chces vykonat pre zadane komplexne cisla" << example << " a " << example2 << endl;
				cout << "1 - scitanie" << endl;
				cout << "2 - odcitannie" << endl;
				cout << "3 - nasobenie" << endl;
				cout << "4 - delenie" << endl;
				cout << "5 -porovnanie" << endl;
				cout << "6 - zadaj znovu prvu komplexnu rovnicu" << endl;
				cout << "7 - zadaj znovu druhu komplexnu rovnicu" << endl;
				cout << "9 - koniec" << endl;

				cout << "zadaj volbu" << endl;
				cin >> volba2;
				switch (volba2)
				{
				case 1:
					cout << example + example2 << endl;
					break;
				case 2:
					cout << example - example2 << endl;
					break;
				case 3:
					cout << example * example2 << endl;
					break;
				case 4:
					try
					{
						cout << example / example2 << endl;
					}
					catch (Exceptions& e)
					{
						cout << "Exception: " << e.message() << "\n";
					}
					
					break;
				case 5:
					if (example == example2)
					{
						cout << "tieto dve cisla su rovnake" << endl;
					}
					else
					{
						cout << "tieto dve cisla NIE SU ronake" << endl;
					}
					break;
				case 6:
					cout << "zadaj realnu a imaginarnu zlozku danej rovnice" << endl;
					cin >> example;
					break;
				case 7:
					cout << "zadaj realnu a imaginarnu zlozku danej rovnice" << endl;
					cin >> example2;
					break;
				}
			} while (volba2 != 9);
			break;
		}
	}
	while (volba1 =! 9);

	system("pause");
	return 0;
}

ostream& operator<<(ostream &out, const Complex<double> &C)
{
	if (C.real == 0)
	{
		out << C.imag;
		out << "i";
	}
	else if (C.real != 0)
	{
		out << C.real;
		if (C.imag > 0)
		{
			out << "+";
			out << C.imag;
			out << "i";
		}else if (C.imag < 0)
		{
			out << C.imag;
			out << "i";
 		}
	}
	return out;
};

istream& operator>>(istream &inputStream,Complex<double> &C)
{
	inputStream >>C.real;
	inputStream >>C.imag;
	return inputStream;
};

Complex<double> operator+(const Complex<double> &ComplexA, const Complex<double> &ComplexB)
{
	Complex<double> result;
	result.real = ComplexA.real + ComplexB.real;
	result.imag = ComplexA.imag + ComplexB.imag;
	return result;
};

Complex<double> operator-(const Complex<double> &ComplexA, const Complex<double> &ComplexB)
{
	Complex<double> result;
	result.real = ComplexA.real - ComplexB.real;
	result.imag = ComplexA.imag - ComplexB.imag;
	return result;
};

Complex<double> operator*(const Complex<double> &ComplexA, const Complex<double> &ComplexB)
{
	Complex<double> result;
	result.real = ComplexA.real * ComplexB.real - ComplexA.imag * ComplexB.imag;
	result.imag = ComplexA.real * ComplexB.imag + ComplexA.imag * ComplexB.real;
	return result;
};

Complex<double> operator/(const Complex<double> &ComplexA, const Complex<double> &ComplexB)
{
	if (ComplexB.real == 0 && ComplexB.imag == 0)
	{
		throw (Exceptions(4));
	}
	else
	{
		Complex<double> result;
		result.real = (((ComplexA.real)*(ComplexB.real)) + ((ComplexA.imag)*(ComplexB.imag))) / (pow(ComplexB.real, 2) + pow(ComplexB.imag, 2));
		result.imag = (((ComplexB.real)*(ComplexA.imag)) - ((ComplexA.real)*(ComplexB.imag))) / (pow(ComplexB.real, 2) + pow(ComplexB.imag, 2));
		return result;
	}
};

Complex<double> operator+=(Complex<double> &ComplexA,const Complex<double> &ComplexB)
{
	ComplexA.real = ComplexA.real + ComplexB.real;
	ComplexA.imag = ComplexA.imag + ComplexB.imag;
	return ComplexA;
};

Complex<double> operator-=(Complex<double> &ComplexA, const Complex<double> &ComplexB)
{
	ComplexA.real = ComplexA.real - ComplexB.real;
	ComplexA.imag = ComplexA.imag - ComplexB.imag;
	return ComplexA;
};

Complex<double> operator*=(Complex<double> &ComplexA, const Complex<double> &ComplexB)
{
	ComplexA.real = ComplexA.real * ComplexB.real - ComplexA.imag * ComplexB.imag;
	ComplexA.imag = ComplexA.real * ComplexB.imag + ComplexA.imag * ComplexB.real;
	return ComplexA;
};

Complex<double> operator/=(Complex<double> &ComplexA, const Complex<double> &ComplexB)
{
	if (ComplexB.real == 0 && ComplexB.imag == 0)
	{
		throw (Exceptions(4));
	}else
	{
		ComplexA.real = (((ComplexA.real)*(ComplexB.real)) + ((ComplexA.imag)*(ComplexB.imag))) / (pow(ComplexB.real, 2) + pow(ComplexB.imag, 2));
		ComplexA.imag = (((ComplexB.real)*(ComplexA.imag)) - ((ComplexA.real)*(ComplexB.imag))) / (pow(ComplexB.real, 2) + pow(ComplexB.imag, 2));
		return ComplexA;
	}
	
};

Complex<double> operator-(const Complex<double> &ComplexA)
{
	Complex<double> result;
	result.real = -ComplexA.real;
	result.imag = -ComplexA.imag;
	return result;
};

Complex<double> operator~(const Complex<double> &ComplexA)
{
	Complex<double> result;
	result.real = ComplexA.real;
	result.imag = -ComplexA.imag;
	return result;
};

bool operator ==(const Complex<double> &ComplexA,const Complex<double> &ComplexB)
{
	if (ComplexA.real == ComplexB.real && ComplexA.imag == ComplexB.imag)
	{
		return  true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const Complex<double> &ComplexA, const Complex<double> &ComplexB)
{
	if (ComplexA.real == ComplexB.real && ComplexA.imag == ComplexB.imag)
	{
		return  false;
	}
	else
	{
		return true;
	}
}






