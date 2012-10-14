#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
  string line;
  ifstream myfile ("us-const.txt");
  if (myfile.is_open())
  {
    while ( myfile.good() )
    {
      getline (myfile,line);
      cout << line << endl;
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 
  int a;
  cout << "Enter any number to exit:";       // tell user how to get out. 
  cin >> a; 
  return 0;
}