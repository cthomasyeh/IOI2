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
		if ((year%4 == 0) && (year%100 != 0) ) return true;
		else return false;
	}
}


int main()
{

	string tmpStr;
	int n=0;
	int s=0;
	int y=0;
	ifstream myfile ("friday.in");
	ofstream myout ("friday.out");
	getline(myfile, tmpStr);
	
	stringstream (tmpStr) >> n;
	//cout << n;
	
	cout << "enter a year since 1900 and calculate the number of days starting from Jan 1, 1900: \n";
	cin >> y;
	n = y - 1900;

	int accu = 0;
	
	for (int year=1900; year<1900+n; year++) {
		
		// your magic here
		
		//cout << " days so far: " << accu << '\n';
	}
	

	myout << answer6 << " " << answer7 << " " << answer1 << " " << answer2 << " " << answer3 << " " << answer4 << " " << answer5 << '\n';
	
	myout.close();
	myfile.close();
	
	return 0;
}

