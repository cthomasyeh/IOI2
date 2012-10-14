// exercise10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main () { 
 	string mystr; 
	int price=0; 
	int quantity=0; 
	
	cout << "Enter price: "; 
	getline (cin,mystr); 
	stringstream(mystr) >> price; 
	
	cout << "Enter quantity: "; 
	getline (cin,mystr); 
	stringstream(mystr) >> quantity; 
	cout << "Total price: " << price*quantity << endl; 

    int a;
	cout << "Enter any number to exit:";       // tell user how to get out. 
	cin >> a; 

	return 0;
}