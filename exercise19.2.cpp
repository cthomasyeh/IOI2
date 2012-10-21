// test1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	int numbers[30];
	int * p;
	p = numbers; //set the pointer at the beginning of the array  
	for (int i=0; i<10; i++) *(p+i) = 100;

	for (int i=0; i<=10; i++) numbers[19-i] = 200;
	
	for (int n=0; n<20; n++)
		cout << numbers[n] << ", ";
	Sleep(5000);
}



