// test1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	int a = 10;
	int b = a;
	int *c;

	c = &a;

	cout << "c holds the value of: " << *c << '\n';
	cout << "c is a pointer pointing to: " << c << '\n';
	cout << "b is: " << b << ". a is: " << a << '\n';

	a = 15;
	cout << "c holds the value of: " << *c << '\n';
	cout << "c is a pointer pointing to: " << c << '\n';
	cout << "b is: " << b << ". a is: " << a << '\n';

	Sleep(150000);
}

