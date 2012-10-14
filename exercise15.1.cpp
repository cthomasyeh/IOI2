#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main () {
  long begin,end;
  long i=0;
  char s[10];
  ifstream myfile ("us-const.txt");
  
  myfile.seekg(0, ios::beg);
  begin = myfile.tellg();

  myfile.seekg (0, ios::end);
  end = myfile.tellg();

  cout << "File size is: " << end << " bytes.\n";
  
  myfile.close();
  int a;
  cout << "Enter any number to exit:";       // tell user how to get out. 
  cin >> a; 
  return 0;
}