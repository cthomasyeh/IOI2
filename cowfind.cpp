/*
ID: tyeh
LANG: C++
PROB: cowfind
*/
//#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>
//#include <Windows.h>

using namespace std;



int main()
{

	string tmpStr;
	int n=0;
	int s=0;
	
	ifstream myfile ("cowfind.in");
	ofstream myout ("cowfind.out");
	getline(myfile, tmpStr);
	s= tmpStr.length();
	cout << s;
	int answer=0;

	for (int i=0; i<s; i++) {
		if ((tmpStr[i] == '(') && (tmpStr[i+1] == '(')) 
			for (int j=i+2; j < s; j++) {
				if ((tmpStr[j] == ')') && (tmpStr[j+1] == ')'))
					answer++;
			}
	}

	myout << answer << '\n';

	myout.close();
	myfile.close();
//	Sleep (10000);
	return 0;
}

