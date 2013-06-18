#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <cstdlib>

using namespace std;


int main () {
 
	int x, y;
	long n=0;
	const long TIMES = 100000000;
	
	x = rand();
	y = rand();
	cout << "random number x: " << x << '\n';
	cout << "random number y: " << y << '\n';
	cout << "maximum random number (RAND_MAX): " << RAND_MAX << '\n';
	double dx = (double) x / RAND_MAX;
	cout << "change random number x to a double between 0 and 1: " << dx << '\n';
	double dy = (double) y / RAND_MAX;
	cout << "change random number y to a double between 0 and 1: " << dy << '\n';
	

	
	Sleep(10000);

  return 0;
}