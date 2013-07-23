#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


int main () {
	string line;
	ifstream myfile("prob3.txt");
	ofstream myout("output3.txt");
	getline(myfile,line);
	long n = 0;
	stringstream ss(line);
	ss >> n;
	
	vector<double> vec(n);	
	
	for (int i=0; i < n; i++) {				
		double money;
		getline(myfile, line);
		stringstream ss(line);
		ss>>money;
		vec[i]=money;		
	}
	
	double total = 0.0;
	double changehand=0;
	cout << '$' <<changehand << endl;
	
	myfile.close();
	myout.close();
	return 0;
}
