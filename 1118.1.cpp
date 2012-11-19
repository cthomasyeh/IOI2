#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void addition (int * z, int a, int b)
{
  *z=a+b;
}

int main ()
{
  int z;
  addition (&z, 5,3);
  cout << "The result is " << z;
  Sleep(5000);
  return 0;
}