// exercise3.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <Windows.h>
#include <iostream>
using namespace std;

// define input and output functions

void main()                               // define main program
{
   
    int a;
	a = 3 * 1.5;
	cout << "a is: " << a << '\n';

   
	{
		int a;
		cout << "Enter any number to exit:";       // tell user how to get out. 
		cin >> a; // wait for input before exit.
	}
}                
