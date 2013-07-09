#include "stdafx.h"
#include <Windows.h>
#include <iostream>
using namespace std;

int func3(int x[], int y) {
	int sum=0;
	for (int i=0; i< y; i++)
		sum = sum + x[i];
	return sum;

}