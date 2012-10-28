#include "stdafx.h"
#include <iostream>
#include <limits.h>

using namespace std;

int main () {
  int x=1;
  int y=2;
  int z=0;


  int max=INT_MAX;
  cout << "The largest integer in my system is: " << max << '\n';

  z= x + y;

  if (x==1) {
   x = 100;
   int z = x + y;
   cout << "z equal to: " << z << '\n';
  }

  if (y==2) {
	int y = 20;
  }

  z=x;
  cout << "z equal to: " << z << '\n';
  cout << "y is equal to: " << y << '\n';

  int a;
  cout << "Enter any number to exit:";       // tell user how to get out. 
  cin >> a; 
  return 0;
}