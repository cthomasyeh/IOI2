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

void addAnswer(int accu) {
	int x=0;
	x = accu%7;
	switch (x) {
		case 0: answer7++; break;
		case 1: answer1++; break;
		case 2: answer2++; break;
		case 3: answer3++; break;
		case 4: answer4++; break;
		case 5: answer5++; break;
		case 6: answer6++; break;
	}
}

int main()
{

	string tmpStr;
	int n=0;
	int s=0;
	
	ifstream myfile ("friday.in");
	ofstream myout ("friday.out");
	getline(myfile, tmpStr);
	
	stringstream (tmpStr) >> n;
	//cout << n;
	
	int accu = 0;
	
	for (int year=1900; year<1900+n; year++) {
		accu = accu + 13;  
		addAnswer(accu);	// check Jan
		accu = accu + 31; 
		addAnswer(accu);	// check Feb
		if (isLeapYear(year)) accu = accu + 29;
		else accu = accu + 28;
		addAnswer(accu);	// check Mar
		accu = accu + 31;
		addAnswer(accu);	// check Apr
		accu = accu + 30;
		addAnswer(accu);	// check May
		accu = accu + 31;
		addAnswer(accu);	// check Jun
		accu = accu + 30;
		addAnswer(accu);	// check July
		accu = accu + 31;
		addAnswer(accu);	// check Aug
		accu = accu + 31;
		addAnswer(accu);	// check Sep
		accu = accu + 30;
		addAnswer(accu);	// check Oct
		accu = accu + 31;
		addAnswer(accu);	// check Nov
		accu = accu + 30;
		addAnswer(accu);	// check Dec
		accu = accu + 31 - 13;
		
		//cout << " days so far: " << accu << '\n';
	}
	

	myout << answer6 << " " << answer7 << " " << answer1 << " " << answer2 << " " << answer3 << " " << answer4 << " " << answer5 << '\n';
	
	myout.close();
	myfile.close();
	
	return 0;
}

