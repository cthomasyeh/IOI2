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
  char c;
  int greater12=0;  // boundary condition  
  int oldest=0;		// boundary condition

  // add your code here
  for (i=0; i<12; i++) {
	  cout << "i = " << i << endl;
	  if (studentAge[i] > 12) greater12++;
	  cout << "number of students older than 12: " << greater12 << endl;
	  scanf("%c",&c);

  }


  cout << "Students older than 12: " << greater12 << '\n';
 
  cout << "Oldest student age: " << oldest << '\n';

  cout << "\nEnter any number to exit:";       // tell user how to get out. 
  cin >> a;                              // wait for input before exit.
}                
