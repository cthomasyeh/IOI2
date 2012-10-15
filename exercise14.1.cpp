#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
	char line[10];
	ifstream myfile ("us-const.txt");
	if (myfile.is_open()) {
		// your magic here	

		cout << "The answer is: " << line[0] << '\n';
		
    myfile.close();
	}

	else cout << "Unable to open file"; 
	int a1;
	cout << "Enter any number to exit:";       // tell user how to get out. 
	cin >> a1; 
  return 0;
}