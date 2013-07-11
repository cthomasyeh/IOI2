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
		cout << p[i].name << '\n';
	}

	// setup their giving-receiving relationship and how much money each has
	for (int i=0; i<n; i++) {
		int id=0;   // self ID
		int fid=0;  // friend ID
		getline(myfile, tmpStr);
		id = getIDbyName(p, n, tmpStr); 
		// Assignment 3: add code to show the id of the person
		getline(myfile, tmpStr);
		
		// break the input line into multiple token. We know this line will contain the amt and number of friends
		istringstream iss(tmpStr);
		int count = 0;

		string sub;
		iss>>sub;
		stringstream(sub) >> p[id].money;
		int noFriends;
		iss>>sub;
		stringstream(sub) >> noFriends;
		
		p[id].giveTo = noFriends;
		// Assignment 3: add code to show the amount of money person ID has and how many friends he/she has


	}

	cout << '\n';

	

	myout.close();
	myfile.close();
	delete [] p;
	return 0;
}

