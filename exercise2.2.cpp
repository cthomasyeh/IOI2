// exercise3.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <Windows.h>
#include <iostream>
using namespace std;

// define input and output functions

void main()                               // define main program
{
   
    int two=1; //two is a variable
	if (two == 1) cout << "question 1 true\n";
	else cout << "question 1 false\n";

	int a = 5;
	int b = 10;
	int c = a + b;
	if (c == 15) cout << "question 2 true\n";
	else cout << "question 2 false\n";

	if ((c==15) && (a ==5)) cout << "question 3 true\n";
	else cout << "question 3 false\n";
	if (a=500) cout << "question 4 true\n";
	else cout << "question 4 false\n";
	if ((c==15) || (1==0)) cout << "question 5 true\n";
	else cout << "question 5 false\n";
	if ((c==15) && (1==0))	cout << "question 6 true\n";
	else cout << "question 6 false\n";
	if ((c==15) && !(1==0)) cout << "question 7 true\n";
	else cout << "question 7 false\n";
   
	int a1;
	cout << "Enter any number to exit:";       // tell user how to get out. 
	cin >> a;                              // wait for input before exit.
}                
