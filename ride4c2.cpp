/*
ID: tyeh1
LANG: C++
PROB: ride
*/

//#include <stdio.h>
//#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{

	string ufoStr;
	string nameStr;
	int size=0;
	//float f;
	//FILE * pFile;
	ifstream myfile ("ride.in");
	ofstream myout ("ride.out");
	getline(myfile, ufoStr);
	getline(myfile, nameStr);

	
	myout.close();
	myfile.close();
//	Sleep(500000);
	return 0;
}

