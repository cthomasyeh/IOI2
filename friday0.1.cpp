/*
ID: tyeh
LANG: C++
PROB: friday
*/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>

using namespace std;

int answer1=0, answer2=0, answer3=0, answer4=0, answer5=0, answer6=0, answer7=0;

bool isLeapYear(int year) {
	if ( (year%400 == 0) ) return true;
	else {
		// add your magic here
	}
}



int main()
{

	string tmpStr;
	int n=0;
	int s=0;
	int year=0;
	ifstream myfile ("friday.in");
	ofstream myout ("friday.out");
	getline(myfile, tmpStr);
	
	stringstream (tmpStr) >> n;
	//cout << n;
	
	cout << "enter a year from 1900 to 2012: ";
	cin >> year;

	int accu = 0;
	
	if (isLeapYear(year)) cout << year << " is a leap year.\n";
	else cout << year << " is not a leap year.\n";
	

	myout << answer6 << " " << answer7 << " " << answer1 << " " << answer2 << " " << answer3 << " " << answer4 << " " << answer5 << '\n';
	
	myout.close();
	myfile.close();
	
	return 0;
}

