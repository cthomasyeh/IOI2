/*
ID: 
LANG: C++
PROB: greetings
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
	int * bpath;
	int * epath;
	string tmpStr;
	int answer=0;
	int s=0;
	int B=0;
	int E=0; 
	
	bpath = new int[1000000];
	epath = new int[1000000];

	ifstream myfile ("greetings.in");
	ofstream myout ("greetings.out");
	getline(myfile, tmpStr);
	s= tmpStr.length();
	//cout << s;

	stringstream into;
	into << tmpStr;
	into >> B >> E;

	cout << B << " " <<E << endl;
	bpath[0] = epath[0] = 0;
	for (int i=0; i<B; i++) {
		getline(myfile, tmpStr);
		stringstream into;
		into << tmpStr;
		int step;
		char direction;
		into >> step >> direction;
		
		
	}	

	for (int i=0; i< B; i++) cout << bpath[i] << " ";

	

	//myout << answer << endl;
	myout.close();
	myfile.close();
	
	return 0;
}

