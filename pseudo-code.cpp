#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main () {
  ofstream myfile;
  string line;
  string name;
  cout << "Please enter the file name of your letter:\n";
  getline(cin, name);

  cout << "===========================Begin writing==========================\n";
  // while name is not equal to .end, go into a loop that:
		// open the file using myfile.open (name)
		// getline from keyboard
		// while the line is not equal to .end, go into another loop that:
				// getline from keyboard
				// use myfile << line << endl; to populate the letter
				// until line is equal to .end
		// if breaks out the loop, close the file using myfile.close(). This will save the test to file
		// ask user to enter the file name of next letter
		// until the name of the file is also equal to .end
  // exit the loop and close the last doc and exit program
  
  return 0;
}