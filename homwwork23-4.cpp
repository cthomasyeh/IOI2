#include "stdafx.h"
#include <iostream>


using namespace std;

int main () {
  
	int ar[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int sum=0;
	
	// solution 1
	sum = ar[0] + ar[1] + ar[2];

	// solution 2
	ar[0] = ar[0] + ar[1];
	ar[0] = ar[0] + ar[2];
	ar[0] = ar[0] + ar[3];

	// solution 3
	sum = sum + ar[0];
	sum = sum + ar[1];
	sum = sum + ar[2];


	cout << '\n';
	int a;  
	cout << "Enter any number to exit:";       // tell user how to get out. 
	cin >> a; 
	return 0;
}