// exercise3.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <Windows.h>
#include <iostream>
using namespace std;

// define input and output functions

void main()                               // define main program
{
   
	int a1[13] = { 10, 12, 13, 19, 8, 7, 10, 11,  14, 15, 16, 9, 17};
	int b1[13];
	int i, a;
	
	// add you code here
	
	

	for (i=0; i<=12; i++) cout << b1[i] << ' ';

	cout << "\nEnter any number to exit:";       // tell user how to get out. 
	cin >> a;                              // wait for input before exit.

}                
