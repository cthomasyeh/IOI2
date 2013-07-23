#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//vector< vector<char> > vec;



int main () {
	string line;
	ifstream myfile("prob4.txt");
	ofstream myout("output4.txt");
	getline(myfile,line);
	long n = 0;
	stringstream ss(line);
	int s;
	string num;
	ss >> s; ss >> num;
	cout << s << " " << num << endl;
	int r = 2*s + 3;
	int c = s + 2;
	int offset = 0;
	vector< vector<char> > vec(r, vector<char>( c ));	
	
	 
	for (int i=0; i < r; i++) {				
		for (int j=0; j< c; j++) {
			vec[i][j] = ' '; 
			cout << vec[i][j];			
		}
		cout << endl;
	}
	
	cout << "c=" << c << "r=" << r<< endl;
	
	for (int i=1; i<r/2; i++) {		
		vec[i][0] = '|';
		vec[i][c-1] = '|';
		vec[r/2+i][0] = '|';
		vec[r/2+i][c-1]='|';
	}
	for (int j=1; j<c-1; j++) {
		vec[0][j] = '-';
		vec[r/2][j] = '-';
		vec[r-1][j] = '-';
	}
	offset = offset + c + 1;
	
	for (int i=0; i < r; i++ ) {
		for (int j=0; j< c; j++) {
			cout << vec[i][j];
		}
		cout << endl;
	}
	cout << endl;
	
	myfile.close();
	myout.close();
	return 0;
}
