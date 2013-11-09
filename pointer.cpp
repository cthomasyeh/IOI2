#include <iostream>
using namespace std;

int main()
{
 	string myHome = "Yeh familiy";
	cout << &myHome << endl;
	string *myAddress;
	myAddress = &myHome;
	cout << myAddress << endl;
	cout << *myAddress << endl;

	int a[5] = {1, 2, 3, 4, 5};
	int * p = new int[50];

	p = a;
	cout << p[3] << endl;

}
