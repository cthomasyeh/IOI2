#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


int main () {
	string line;
	ifstream myfile("beads.in");
	ofstream myout("beads.out");
	getline(myfile,line);
	long n = 0;
	stringstream ss(line);
	ss >> n;
	getline(myfile,line);
	
	vector<char> vec(n);	
	
	for (int i=0; i < n; i++) {				
		vec[i] = line[i];		
		//cout << vec[i];
	}
	int largest = 0, pos = 0;
	for (int i=0; i<n; i++) {
		char b=vec[i];
		int ac = 1;
		int j = i;
		while ( (b == vec[j+1]) && (j+1 < n) ) {
			ac++;
			j++;
		}
		b = vec[i-1];
		j = i-1;
		while ( (j >= 0) && (b == vec[j]) ) {
			ac++;
			j--;
		}
		if (ac > largest) {
			largest = ac;
			//pos = i+1;
		}
		//cout << ac << endl;
	}
	cout << largest << endl;
	
	myfile.close();
	myout.close();
	return 0;
}
