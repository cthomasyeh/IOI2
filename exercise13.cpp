#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


int main () {
  ofstream myfile;
  string line;
  
  cout << "Enter your text here:\n";
  myfile.open (name);
  getline(cin, line);
  myfile << line;
  //myfile << "Writing this to a file.\n";
  myfile.close();
  return 0;
}