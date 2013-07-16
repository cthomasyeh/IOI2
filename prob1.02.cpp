#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int compute(long i) {
	int counter = 1;
	if ( i == 0 || i >= 1000000) return -1;
	if (i == 1) return 0;
	while (i != 1) { 
		
	}
	
	return counter;
}


int main () {
	string line[1000];
	ifstream myfile("prob1.txt");
	ofstream myout("output1.txt");
	getline(myfile,line[0]);
	long n = 0;
	while (line[n] != "") {
		n++;
		getline(myfile,line[n]);
	}
	for (int k=0; k<n; k++) {		
		stringstream ss(line[k]);
		int i,j, result, largest=0;
		ss >> i;
		ss >> j;
		for (int index=i; index <= j; index++) {
			result = compute(index);
			if (result == -1) return 0;
			//cout << index << " : " << result << endl;
			if (result > largest) largest = result;;
		}
		cout << i << " " << j << " " << largest << endl;
	}
	myfile.close();
	myout.close();
	return 0;
}
