// vector.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
using namespace std;



//void print_backwards( const vector<int> &);

struct triangle {
	float base;
	float height;
	float area;
};

void area( vector<triangle> );

int main() {
	vector<triangle> v;
	int number;
	triangle t0, t1;
	t0.base = 1.05;
	t0.height = 2.34;
	v.push_back(t0);
	t1.base = 2.34;
	t1.height = 3.07;
	v.push_back(t1);

	area(v);
	
}//main


void area( vector<triangle> a) {
 		for(int i=0; i<a.size(); ++i) {
			a[i].area = (a[i].base * a[i].height)/2;
 			cout << a[i].area << " ";
		}
 		cout << endl;
 		cout << "----------------"<<endl;
}//print