#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;

#define MULTIPLY(a, b)    (a * b)

#define A_VERY_BIG_INTEGER  99999

int main(void)
{
	int a = 10;
	int b = 30;
    cout << "Multiplication of " << a << " and " << A_VERY_BIG_INTEGER << " is: " << MULTIPLY(a, A_VERY_BIG_INTEGER) << endl;
	//cout << A_VERY_BIG_INTEGER;
    Sleep (10000);
	return (0);
}