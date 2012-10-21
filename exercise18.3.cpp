// test1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	int a = 5;
	int b = 15;
	int *pointerA, *pointerB;

	pointerA = &a;
	pointerB = &b;
	*pointerA = 10;
	*pointerB = *pointerA;
	// question 1: what is the value of a and b now?
	cout << "a is: " << a << '\n';
	cout << "b is: " << b << '\n';
	pointerA = pointerB;
	// question 2: what is the value of a and b now?
	// question 3: what is the value of pointerA and pointerB now?
	// question 4: What is the meaning of pinterA? Does it still point to a?
	cout << "a is: " << a << '\n';
	cout << "b is: " << b << '\n';
	*pointerA = 20;
	// question 5: what is the value of a and b now?
	cout << "a is: " << a << '\n';
	cout << "b is: " << b << '\n';

	Sleep(50000);
}

