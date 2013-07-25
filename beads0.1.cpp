/*
ID: tyeh1
LANG: C++
PROB: beads
*/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int verify(char* vec, int n) {
	//vector<char> v3(n*3);
	char * v3;
	v3 = new char[n*3];
	for (int i=0; i<n; i++) {
		v3[i]=v3[n+i]=v3[2*n+i]=vec[i];
	}
	int largest = 0, pos = 0;
    for (int i=n; i<n*2; i++) {
        
        char b=v3[i];
        int ac = 1;
        int j = i;
        
        
        while ((b == v3[j+1]) && (j < i+n))  {
             ac++;
             j++;
        }
        
        if (j== n*2) {}
        else {
        	b = v3[i-1];
        	j = i-1;
        	
        	while  ((b == v3[j]) && (j>n))  {
        		ac++;
        		j--;
        	}     
        }   	
        if (ac > largest) {
	    	largest = ac;
        	pos = i+1;
       	}
    }
    //for (int x=0; x<n; x++) cout << vec[x];
    //cout << endl << "---" << largest << endl;
    //cout <<"--- pos: " << pos << endl;
    return largest;
}    
        
int handlew(char* v, int n) {
	int r=0, l=-1, j=0;
	int largest=0;
	for (int i=0; i<n; i++) {
		if (v[i] == 'w') {
			r=0; l=-1;
			j=i;
			while (v[j] == 'w') {
				r++; j++;	
				if (j==n) j=0;
			}
			j = i;
			while (v[j] == 'w') {
				l++; j--;
				if (j==-1) j=n-1;
			}
			int nr=0, nl=0;
			//cout << i << " " << r << " " << l << endl;
			if (i+r > n) nr = i+r-n;
			else nr = i+r;
			if (i-l <= 0) nl = n-(i-l)-1;
			else nl = i-l;
			//cout << "check these: " << nr << " " << nl << endl;
			
			for (int x=0; x<(nr-i); x++) v[i+x] = 'b';
			//for (int x=0; x <n; x++) cout << v[x];
			//cout << endl;
			int a1 = verify(v, n);
			for (int x=0; x<(nr-i); x++) v[i+x] = 'r';
			//for (int x=0; x <n; x++) cout << v[x];
			//cout << endl;
			int a2 = verify(v, n);
			
			if (a1 > a2) {
				for (int x=0; x<(nr-i); x++) v[i+x] = 'b';
				//cout << "***a1*** " << a1<< endl;
				if (a1>largest) largest = a1;
				}
			else {
				for (int x=0; x<(nr-i); x++) v[i+x] = 'r';
				//cout << "***a2*** " << a2<< endl;
				if (a2>largest) largest = a2;
			}
			
		}
		else { // not w
			int a = verify(v, n);
			if (a>largest) largest = a;
		}
	}
	//for (int x=0; x <n; x++) cout << v[x];
	return largest;
}

int main () {
	string line;
	ifstream myfile("beads.in");
	ofstream myout("beads.out");
	getline(myfile,line);
	long n = 0;
	stringstream ss(line);
	ss >> n;
	getline(myfile,line);
	
	char * vec;
	vec = new char[n];
	 
	//vector<char> vec(n);	
	
	
	int largest = 0, pos = 0;
	bool needtochange = false;
	
	for (int l=0; l < n; l++) {				
		vec[l] = line[l];		
		//cout << vec[i];
	}
	
	int value = handlew(vec, n);
	myout << value << endl;
	
	myfile.close();
	myout.close();
	return 0;
}
