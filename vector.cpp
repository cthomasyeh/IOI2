// vector.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
using namespace std;

void print( const vector<int>& );

void print_backwards( const vector<int> &);

int main() {
	vector<int> v;
	int number;
	cout <<"Input some numbers and then end the input using a non-numerical key stroke\n";
	while(cin>>number){
		v.push_back(number);
	}//while(more)
	print(v);
	print_backwards(v);
}//main

void print_backwards( const vector<int> &a) {
 		for(int i=a.size()-1; i>=0; --i)
 			cout << a[i] << " ";
 		cout << endl;
 		cout << "----------------"<<endl;
}//print_backwards

void print( const vector<int>& a) {
 		for(int i=0; i<a.size(); ++i)
 			cout << a[i] << " ";
 		cout << endl;
 		cout << "----------------"<<endl;
}//print