#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int a = 5;
int b = 6;

void swap ()
{
  int temp;
  temp = a;
  a = b;
  b = temp;
}

int main ()
{ 
  swap (); 
  cout << "The value of a is: " << a <<'\n';
  cout << "The value of b is: " << b <<'\n';
  Sleep(5000);
  return 0;
}