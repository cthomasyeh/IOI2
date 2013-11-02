#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() 
{
	ifstream ifs("ageArray.txt");
	const int SIZE=12;
	int age[SIZE];
	for (int i=0; i<SIZE; i++) {
		ifs >> age[i];
	}
}