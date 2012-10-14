#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
	string line;
	ifstream myfile ("c:\\us-const.txt");
	if (myfile.is_open()) {
		// your magic here	
    myfile.close();
	}

	else cout << "Unable to open file"; 
	int a1;
	cout << "Enter any number to exit:";       // tell user how to get out. 
	cin >> a1; 
  return 0;
}