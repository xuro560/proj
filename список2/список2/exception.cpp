// exception.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "string"
using namespace std;

class DoubleListException
{
private:
	string str;
public:
	DoubleListException(string message) : str (message) {}
	string what()
	{
		return str;
	}
};
