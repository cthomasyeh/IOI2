// test1.cpp : Defines the entry point for the console application.
//

#include "StdAfx.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	int a;
	int b;
	int *pointer;

	pointer = &a;
	*pointer = 10;
	pointer = &b;
	*pointer = 20;

	cout << "a is : " << a << '\n';
	cout << "b is: " << b << '\n';

	Sleep(150000);
}

