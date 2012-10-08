#include "stdafx.h"
#include <Windows.h>
#include <iostream>
using namespace std;

int main()
{

	 int anArray[3][5] =
		{
			{ 1, 2, 3, 4, 5, },
			{ 6, 7, 8, 9, 10, },
			{ 11, 12, 13, 14, 15 }
		};

	//cout<< anArray[1][4];
	
	//solution for question 1:
	int i,j;
	int answer=0;
	int answer1=0;
	int answer2=0;
	int answer3=0;
	for (i=0; i <3; i++) {
		for (j=0; j<5; j++) {
			cout << "Index 1 is: " << i << ' ';
			cout << "Index 2 is: " << j << ' ';
			answer = (answer + anArray[i][j]);
			cout << "Summation so far: " << answer << '\n';			
		}
		
	}
	cout << answer << '\n';


	// solution for question 2:
	for (j=0; j<5; j++)
		answer1 = answer1 + anArray[0][j];

	for (j=0; j<5; j++)
		answer2 = answer2 + anArray[1][j];

	for (j=0; j<5; j++)
		answer3 = answer3 + anArray[2][j];

	
	cout << answer1 << '\n';
	cout << answer2 << '\n';
	cout << answer3 << '\n';

	// Please add your solution for question 3 below

	// solution for question 2:

	answer1 = answer2 = answer3 = 0;
	int answer4 = 0;
	int answer5 = 0;
	for (i=0; i<3; i++)
		answer1 = answer1 + anArray[i][0];

	for (i=0; i<3; i++)
		answer2 = answer2 + anArray[i][1];

	for (i=0; i<3; i++)
		answer3 = answer3 + anArray[i][2];

	for (i=0; i<3; i++)
		answer4 = answer4 + anArray[i][3];

	for (i=0; i<3; i++)
		answer5 = answer5 + anArray[i][4];
	
	cout << answer1 << '\n';
	cout << answer2 << '\n';
	cout << answer3 << '\n';
	cout << answer4 << '\n';
	cout << answer5 << '\n';
	int a;
	cout << "Enter any number to exit:";       // tell user how to get out. 
   cin >> a; 

}