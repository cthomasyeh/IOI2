/*
ID: tyeh1
LANG: C++
PROB: gift1
*/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>

using namespace std;

struct person {
	string name;
	int money;
	int giveTo;
	int left;
	int received;
	int f[10];
};


int getIDbyName(person * p, int n, string a) {
	int found = -1;
	for (int j=0; j<n; j++) {
		if (strcmp(&a[0], &(p[j].name)[0]) == 0) {//equal
			found = j;
			break;
		}
	}
	return found;
}


int main()
{

	string tmpStr;
	int n=0;
	
	ifstream myfile ("gift1.in");
	ofstream myout ("gift1.out");
	getline(myfile, tmpStr);
	stringstream(tmpStr) >> n;
	//cout << n;
	person * p;
	
	// create a person array with n number of elements
	p = new person[n];
	
	// initialize the variable so they won't contain garbage
	for (int i=0; i<n; i++) {
		p[i].money = p[i].giveTo = p[i].left = p[i].received = 0;
	}
	
	//getting the list of every person
	for (int i=0; i<n; i++) {
		getline(myfile, tmpStr);
		p[i].name = tmpStr;
		// Assignment 0.2: add code to print what you have just input into the name field using cout
	}



	

	myout.close();
	myfile.close();
	delete [] p;
	return 0;
}

