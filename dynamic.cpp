#include "stdafx.h"
#include <iostream>
#include <new>
#include <Windows.h>
using namespace std;

int main ()
{
  int i,n;
  int * p;
  cout << "How many numbers would you like to create, Master? ";
  cin >> i;
  p= new (nothrow) int[i];
  if (p == 0)
    cout << "Error: memory could not be allocated";
  else
  {
    for (n=0; n<i; n++)
    {
      cout << "Enter number: ";
      cin >> p[n];
    }
    cout << "You have created: ";
	for (n=0; n<i; n++)
      cout << p[n] << ", ";
	cout << '\n';
    Sleep(3000);
	cout << "All numbers will be deleted before I exit!\n";
	cout << "What is consequence of not deleting them?\n";
	Sleep(5000);
	
    delete[] p;
  }
  return 0;
}