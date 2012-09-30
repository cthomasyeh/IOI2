#include "stdafx.h"
#include <Windows.h>
#include <iostream>
using namespace std;

// define input and output functions

void main()                               // define main program
{
   
   int index, a;
   for (index=1; index <= 10; index++) cout << index << endl;

   cout << endl;

   index=11;
   while (index <= 20) { 
	   cout << index << endl;
	   index++;
   }
   cout << endl;

   index=21;
   do {
	   cout << index << endl;
	   index++;
   } while (index != 31);
  
   //for (;;) cout << "I get stuck here forever\n";
   cout << "Enter any number to exit:";       // tell user how to get out. 
   cin >> a;                             // wait for input before exit.
}                
