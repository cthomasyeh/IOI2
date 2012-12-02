#include "stdafx.h"
#include <iostream>
#include <new>
#include <Windows.h>
using namespace std;

void main() {
	int* a = NULL;   // Pointer to int, initialize to nothing.
	int n;           // Size needed for array
	cout << "What is the size of the array you wish, Master?\n";
	cin >> n;        // Read in the size
	cout << "As you wish...\n";
	a = new int[n];  // Allocate n ints and save ptr in a.
	for (int i=0; i<n; i++) {
		a[i] = i;    // Initialize all elements to zero.
	}
	delete [] a;  // When done, free memory pointed to by a.
	a = NULL;     // Clear a to prevent using invalid memory reference.
	Sleep(5000);
}