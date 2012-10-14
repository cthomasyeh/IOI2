#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


int main () {
  ofstream myfile;
  myfile.open ("output.txt");
  myfile << "Writing this to a file.\n";
  myfile.close();
  return 0;
}