// exercise3.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <Windows.h>
#include <iostream>
using namespace std;

// define input and output functions

void main()                               // define main program
{
   
	int age[5];
	int i=0 , a;
	int value;
	
	cout << "Enter an integer value and Enter. Enter 0 to end: \n"; 	
	
	
	cin >> age[0];
		
	while (age[i] != 0) {
		i++;
		cin >> age[i];
	}
		
	
	cout << "\nEnter any number to exit:";       // tell user how to get out. 
	cin >> a;                              // wait for input before exit.

}      