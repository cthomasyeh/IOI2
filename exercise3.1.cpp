// exercise10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main ()
{
  string mystr;
  
  int a;
  char x;
  int i=0;
  cout << "Type a single lower case letter: \n";

  cin >> x;

  // add your code here
  cout << "The letter you typed is: " << x << '\n';
	  
  cout << "Enter any number to exit:";       // tell user how to get out. 
  cin >> a;
}