#include "stdafx.h"
#include <Windows.h>
#include <iostream>
using namespace std;

int func1(int x, int y) {
	return (x + y);
}

int func2(int[], int);

extern int func3(int[], int);


void main () {

	int index, a;
	int selection = 0;
	int answer;
	float d_answer;
	int x[5] = { 1, 24, 301, 46, 90}, y=5;

	

	for (;;) {
		cout << "\nEnter a number to select the function call: \n";
		cout << "1: Addition\n2: Find largest\n3: Summation\n\n";
		cin >> selection;
		switch (selection) {
		case 1: 
			cout << "calling func1()... \n";
			answer = func1(10, 20);
			cout << "Return value from func1(): " <<  answer << '\n';
			break;
		case 2:
			cout << "calling func2()... \n";
			answer = func2(x, y);
			cout << "The largest number in the array is: " << answer << '\n';
			break;
		case 3:
			cout << "calling func3()... \n";
			answer = func3(x, y);
			cout << "Adding all the element in array x... The summation is: " << answer << '\n';
			break;			
		default:
			exit (0);

		}
	}  
}

int func2(int a[], int b) {
	int largest = -99999;
	for (int i=0; i< b; i++) {
		if (a[i] > largest) largest = a[i];
	}
	return largest;
}

