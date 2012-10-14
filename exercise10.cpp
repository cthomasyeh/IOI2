// exercise10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int main ()
{
  int i;
  cout << "Please enter an integer value: ";
  cin >> i;
  cout << "The value you entered is " << i;
  cout << " and its double is " << i*2 << ".\n";

  Sleep (5000);
  int a;
  cout << "Enter any number to exit:";       // tell user how to get out. 
  cin >> a; 

  return 0;
}