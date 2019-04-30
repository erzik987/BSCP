#pragma once
#include <string>
using namespace  std;

class Exceptions
{
private:
	int exc;
	string mess;
public:
	Exceptions(int exc)
	{
		this->exc = exc;
	};

	string message(void)
	{
		switch (exc)
		{
		case 1: return string("I will accept only real or imag");
		case 2: return string("I will accept only 0 or 1");
		case 3: return string("I will accept only r  or i");
		case 4: return string("You cant divide by zero");
		case 5: return string("Real number could not be smaller than 0");
		default: return string("Unknown error");
		}
	}
};

