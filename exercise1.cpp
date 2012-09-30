        

// myFirstApp.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;

// define input and output functions

void main()                               // define main program
{
   
   int a, b, sum, difference;             // define four integer variables.
   cout << "My first C++ program\n\n";    // output text. "\n" means new line.
   

   cout << "Input first number: \n";        // ask the user for the first number.5
   cin >> a;
   
   cout << "Input second number: \n";     // ask the user for the second number.
   cin >> b;                              // read the second number.

   sum = a + b;  difference = a - b;      // calculate sum and difference.


   cout << "  The sum is " << sum << '\n';        // output sum.
   cout << "  The difference is " << difference << '\n';  // output difference.


   cout << "Enter any number to exit:";       // tell user how to get out. 
   cin >> a;                              // wait for input before exit.
}                                  
                                 
