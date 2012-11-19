#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int doubling (int* a)
{
  *a = (*a) * 2;
  return (*a);
}

int main ()
{
  int z, a;
  a = 5;
  z = doubling (&a);
  cout << "The result is " << z;
  cout << "\nHowever, the value of a is: " << a <<'\n';
  Sleep(5000);
  return 0;
}