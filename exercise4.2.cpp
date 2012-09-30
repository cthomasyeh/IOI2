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

  int i=0;
  for (i=0; i<=128; i++) {
    // hint: you need to know when to print space and when to print newline '\ '. 
	// you can chekc if the value of i is the multiple of 10. If it is, print newline, otherwise print space
	// begin your modification here  
    cout << (char) i << ' ';
  }
    
  cout << "\nEnter any number to exit:";       // tell user how to get out. 
  cin >> a;                              // wait for input before exit.
}                
