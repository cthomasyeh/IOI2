#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;

// correct this program so it swaps properly

void swap (int a, int b)
{
  int temp;
  temp = a;
  a = b;
  b = temp;
}

int main ()
{
  int z, a, b;
  a = 5;
  b = 6;
  swap (a, b); 
  cout << "The value of a is: " << a <<'\n';
  cout << "The value of b is: " << b <<'\n';
  Sleep(5000);
  return 0;
}