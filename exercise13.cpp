#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <cstdlib>

using namespace std;


int main () {
 
	int x, y;
	long n=0;
	const long TIMES = 100000000;
	/*
	x = rand();
	y = rand();
	cout << x << '\n';
	cout << y << '\n';
	cout << RAND_MAX << '\n';
	long n=0;
	double dx = (double) x / (double) RAND_MAX;
	cout << dx << '\n';
	double dy = (double) y / (double) RAND_MAX;
	cout << dy << '\n';
	*/

	for (int i=0; i<TIMES; i++) {
		x = rand();
		y = rand();
		double dx = (double) x / (double) RAND_MAX;
		double dy = (double) y / (double) RAND_MAX;
		if (sqrt(dx*dx + dy*dy) < 1.0) n++;
	}
	double pi= 4 * (double) n / TIMES;
	cout << "Pi is: " << pi;
	Sleep(10000);

  return 0;
}