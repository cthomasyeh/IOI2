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
	int first, second;
	cout << "Enter first number: \n";
	cin >> first;
	cout << "Enter second number: \n";
	cin >> second;
	
	first = second;
	second = first;

	cout << "First number is: " << first << '\n';
	cout << "Second number is: " << second << '\n';

	cout << "\nEnter any number to exit:";       // tell user how to get out. 
	cin >> a;                              // wait for input before exit.

}                
