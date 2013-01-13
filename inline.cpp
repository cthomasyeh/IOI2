#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int multiple(int a, int b)
{
    return a * b;
}

int main(void)
{
	
	int a = 10;
	char b = 'b';
    cout << "Multiplication of " << a << " and " << b << " is: " << multiple(a, b) << endl;
	a = 25;
	b = 35;
	cout << "Multiplication of " << a << " and " << b << " is: " << multiple(a, b) << endl;
	a = 71;
	b = 94;
	cout << "Multiplication of " << a << " and " << b << " is: " << multiple(a, b) << endl;
	a = 71;
	b = 94;
	
    Sleep (10000);
	return (0);
}