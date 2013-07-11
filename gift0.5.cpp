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
	int size=0;

	ifstream myfile ("gift1.in");
	ofstream myout ("gift1.out");
	getline(myfile, tmpStr);
	stringstream(tmpStr) >> n;
	//cout << n;
	person * p;
	p = new person[n];
	for (int i=0; i<n; i++) {
		p[i].money = p[i].giveTo = p[i].left = p[i].received = 0;
	}
	
	//getting the list of every person
	for (int i=0; i<n; i++) {
		getline(myfile, tmpStr);
		p[i].name = tmpStr;
		//cout << p[i].name << '\n';
	}

	// setup their giving-receiving relationship and how much money each has
	for (int i=0; i<n; i++) {
		int id=0;
		int fid=0;
		getline(myfile, tmpStr);
		id = getIDbyName(p, n, tmpStr); 
		//cout << "\n\nsetup " << tmpStr << "'s friend\n";
		getline(myfile, tmpStr);
		
		istringstream iss(tmpStr);
		int count = 0;

		string sub;
		iss>>sub;
		stringstream(sub) >> p[id].money;
		int noFriends;
		iss>>sub;
		stringstream(sub) >> noFriends;
		//cout << "money: " << p[id].money<< "  number of friends: " << noFriends << '\n';
		p[id].giveTo = noFriends;

		for (int k=0; k<noFriends; k++) {
			getline(myfile, tmpStr); 
			fid = getIDbyName(p, n, tmpStr); 
			//cout << tmpStr << "'s ID is: " << fid << '\n';
			p[id].f[k] = fid;
		}
		//cout << p[id].name << "'s friends: ";
		//for (int l=0; l<noFriends; l++) cout << p[id].f[l] << " ";

	}

	cout << '\n';

	for (int i=0; i<n; i++) {
		if (p[i].giveTo == 0) {}  // do nothing
		else {
			// Assignment 5: add two lines of code to calculate homw much money is to given to each friend, and how much moeny is left after giving
			
		}
	}

	for (int i=0; i<n; i++) myout << p[i].name << " " << p[i].left + p[i].received - p[i].money << '\n';

	myout.close();
	myfile.close();
	delete [] p;
	return 0;
}

