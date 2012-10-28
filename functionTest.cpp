#include "stdafx.h"
#include <Windows.h>
#include <iostream>
using namespace std;

extern int thomas(int, int);
extern int jeffery(int[], int);
extern int leo(int[], int);
extern float daniel(int[], int);
extern float matt(int, int);

void main () {

	int index, a;
	int selection = 0;
	int answer;
	float d_answer;
	int x[5] = { 1, 24, 301, 46, 90}, y=5;

	

	for (;;) {
		cout << "\nEnter a number to select the function call: \n";
		cout << "1: Thomas\n2: Jeffery\n3: Leo\n4: Daniel\n5: Matt\n";
		cin >> selection;
		switch (selection) {
		case 1: 
			cout << "calling Thomas... Thomas is working hard... \n";
			answer = thomas(10, 20);
			cout << "\nThomas finishes his works... \n";
			cout << "Thomas said: Adding 10 and 20 together is: " <<  answer << '\n';
			break;
		case 2:
			cout << "calling Jeffery... Jeffery is working hard... \n";
			answer = jeffery(x, y);
			cout << "\nJeffery finishes his works... \n";
			cout << "Jeffery said: The larget number in the array is: " << answer << '\n';
			break;
		case 3:
			cout << "calling Leo... Leo is working hard... \n";
			answer = leo(x, y);
			cout << "\nLeo finishes his works... \n";
			cout << "Leo said: adding all the element io array x... The summation is: " << answer << '\n';
			break;			
		case 4:
			d_answer = daniel(x, y);
			cout << "daniel said: the average value of array x is: " << d_answer << '\n'; 
			break;
		case 5:
			d_answer = matt(100, 12);
			cout << "Matt said: the division of the two integers 100 and 12 is: " << answer << '\n';
			break; 
		default:
			break;

		}

	}
  


}
