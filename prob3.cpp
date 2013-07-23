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
	
	while (n !=0)
	{
		vector<double> vec(n);	
	
		for (int i=0; i < n; i++) {				
			double money;
			getline(myfile, line);
			stringstream ss(line);
			ss>>money;
			vec[i]=money;		
			//cout << vec[i]<< endl;			
		}
	
		double total = 0.0;
		double changehand=0;
		for (int i=0; i<n; i++) total = total + vec[i];
		double share = total / n;
		for (int i=0; i<n; i++) {
			if (vec[i] > share)
				changehand = changehand + (vec[i] - share);
		}
		cout << '$' <<changehand << endl;
		getline(myfile, line);
		stringstream ss(line);
		ss >> n;
	}
	
	myfile.close();
	myout.close();
	return 0;
}
