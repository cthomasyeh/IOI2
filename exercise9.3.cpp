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

	int i, j;

	for (i=0; i<3; i++)
		for (j=0; j<5; j++)
			cout << anArray[i][j] << ' ';
		

	
	int a;
	cout << "Enter any number to exit:";       // tell user how to get out. 
    cin >> a; 

}