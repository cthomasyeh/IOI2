#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void doubling (int* a)
{
  *a = (*a) * 2;
}

int main ()
{
  int z, a;
  a = 5;
  doubling (&a); // this is a function without return value
  cout << "\nUsing void as the return value of the function... The value of a is: " << a <<'\n';
  Sleep(5000);
  return 0;
}