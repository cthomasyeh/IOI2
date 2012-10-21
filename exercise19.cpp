// test1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	int numbers[5];
	int * p;
	p = numbers; //set the pointer at the beginning of the array  
	*p = 10;	 // *p is equivalent to p[0] at this point;
	p++;  *p = 20;  // p++ is equivalent to p[0+1]
	p = &numbers[2];  // this is wquivalent to p= &( numbers[2] );
	*p = 30;
	p = numbers + 3;  // move the address pinted by p by 3
	*p = 40;
	p = numbers;  
	*(p+4) = 50;  // move the address pointed by p by 4
	
	for (int n=0; n<5; n++)
		cout << numbers[n] << ", ";
	Sleep(5000);
}



