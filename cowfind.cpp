/*
ID: tyeh
LANG: C++
PROB: cowfind
*/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>

using namespace std;



int main()
{

	string tmpStr;
	int n=0;
	int s=0;
	
	ifstream myfile ("cowfind.in");
	ofstream myout ("cowfind.out");
	getline(myfile, tmpStr);


	myout.close();
	myfile.close();
	
	return 0;
}

