#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

int main () {
string line;
ifstream myfile("prob2.txt");
ofstream myout("output2.txt");
getline(myfile,line);
long n = 0;
stringstream ss(line);
int r,c;
ss >> r; ss >> c;
cout << r << " " << c << endl;
vector< vector<char> > vec(r, vector<char>(c));	


for (int i=0; i < r; i++) {
getline(myfile,line);

for (int j=0; j< c; j++) {
vec[i][j] = line [j]; 
cout << vec[i][j];
}
cout << endl;
}

for (int i=0; i < r; i++) {		
for (int j=0; j< c; j++) {
if (vec[i][j] == '*') {}
else {
if ((i==0) && (j==0)) {
cout << "do something on 3 neighbors east to south" << endl;
int m=0;
if (vec[0][1] == '*') m++;
if (vec[1][1] == '*') m++;
if (vec[1][0] == '*') m++;
vec[0][0] = (char) m+48;
}
else if ((i==0) && (j==(c-1))) {
// do something on 3 neighbors west to south
int m=0;
if (vec[0][c-2] == '*') m++;
if (vec[1][c-2] == '*') m++;
if (vec[1][c-1] == '*') m++;
vec[0][c-1] = (char) m+48;
}
else if ((i==(r-1)) && (j==0)) {
//cout << "do something on 3 neighbors east to north" << endl;
int m=0;
if (vec[r-2][0] == '*') m++;
if (vec[r-2][1] == '*') m++;
if (vec[r-1][1] == '*') m++;
vec[r-1][0] = (char) m+48;
}  
else if ((i==(r-1)) && (j==(c-1))) {
// do something on 3 neighbors west to north
int m=0;
if (vec[r-1][c-2] == '*') m++;
if (vec[r-2][c-2] == '*') m++;
if (vec[r-2][c-1] == '*') m++;
vec[r-1][c-1] = (char) m+48;
}
else if (i==0) {
// do something on 5  neighbors
int m=0;
if (vec[0][j-1] == '*') m++;
if (vec[1][j-1] == '*') m++;
if (vec[0][j] == '*') m++;
if (vec[1][j+1] == '*') m++;
if (vec[0][j+1] == '*') m++;
vec[i][j] = (char) m+48;
}
else if (j==0) {
// do something on 5 neighbors
int m=0;
if (vec[i-1][0] == '*') m++;
if (vec[i-1][1] == '*') m++;
if (vec[i][1] == '*') m++;
if (vec[i+1][1] == '*') m++;
if (vec[i+1][0] == '*') m++;
vec[i][j] = (char) m+48;
}
else if (i== (r-1)) {
// do something on 5 neighbors
int m=0;
if (vec[i][j-1] == '*') m++;
if (vec[i-1][j-1] == '*') m++;
if (vec[i-1][j] == '*') m++;
if (vec[i-1][j+1] == '*') m++;
if (vec[i][j+1] == '*') m++;
vec[i][j] = (char) m+48;
}
else if (j== (c-1)) {
// do something on 5 neighbors
int m=0;
if (vec[i-1][j] == '*') m++;
if (vec[i-1][j-1] == '*') m++;
if (vec[i][j-1] == '*') m++;
if (vec[i+1][j-1] == '*') m++;
if (vec[i+1][j] == '*') m++;
vec[i][j] = (char) m+48;
}
else {
// do something on all 8 neighbors
int m = 0;
for (int l=0; l<3; l++) if (vec[i-1][j-1+l] == '*') m++;
for (int l=0; l<3; l++) if (vec[i+1][j-1+l] == '*') m++;
if (vec[i][j-1] == '*') m++;
if (vec[i][j+1] == '*') m++;
vec[i][j] = (char) m+48;
}	

}

}
//cout << endl;
}
cout << endl;
for (int i=0; i < r; i++ ) {
for (int j=0; j< c; j++) {
cout << vec[i][j];
}
cout << endl;
}
cout << endl;

myfile.close();
myout.close();
Sleep(100000);
return 0;
}