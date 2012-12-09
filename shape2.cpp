// vector.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

//void print_backwards( const vector<int> &);

struct triangle {
	float base;
	float height;
	float area;
};

struct rectangle {
	float width;
	float height;
	float area;
};

void area( vector<triangle> a) {
 		for(int i=0; i<a.size(); ++i) {
			a[i].area = (a[i].base * a[i].height)/2;
 			cout << a[i].area << " ";
		}
 		cout << endl;
 		cout << "----------------"<<endl;
}//print

void area( vector<rectangle> a) {
 		for(int i=0; i<a.size(); ++i) {
			a[i].area = a[i].width * a[i].height;
 			cout << a[i].area << " ";
		}
 		cout << endl;
 		cout << "----------------"<<endl;
}//print

int main() {
	vector<triangle> v;
	vector<rectangle> r;
	int number;
	triangle t0, t1;
	t0.base = 1.05;
	t0.height = 2.34;
	v.push_back(t0);
	t1.base = 2.34;
	t1.height = 3.07;
	v.push_back(t1);

	rectangle r0;
	r0.width = 7.8;
	r0.height = 6.5;
	r.push_back(r0);

	area(v);
	area(r);

	Sleep(10000);
}//main


