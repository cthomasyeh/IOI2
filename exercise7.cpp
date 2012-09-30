// exercise3.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <Windows.h>
#include <iostream>
using namespace std;

// define input and output functions

void main()                               // define main program
{
   
	int studentAge[12] = { 10, 12, 13, 19, 8, 7, 10, 11,  14, 15, 16, 9};
	int i, a;
	int greater12=0;
	int oldest=0;
	int youngest=100;

	
	cout << '\n';

    cout << "The first student is " << studentAge[0] << " years old.\n";

	cout << "\nEnter any number to exit:";       // tell user how to get out. 
	cin >> a;                              // wait for input before exit.

}                
