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

  while ((name != ".end") && (name != ".End")) {

	myfile.open (name);
    getline (cin, line);
    while (line != ".new") {
 	  myfile << line << '\n';
	  getline (cin, line);
      
	}
    myfile.close();
    cout << "Please enter the file name of your letter:\n";
    getline(cin, name);

    cout << "===========================Begin writing==========================\n";
  }
  myfile.close();
  return 0;
}