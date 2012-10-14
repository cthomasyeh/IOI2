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
  begin = myfile.tellg();

  myfile.seekg (0, ios::end);
  end = myfile.tellg();

  cout << "size is: " << end << " bytes.\n";
  myfile.seekg (0);
  for (i=begin; i< (end-5); i++) {
	  myfile.read(s, 5);
	  
	  //for (int j=0; j<3 ; j++) cout << s[j];
	  //cout << '\n';
	  if ( (s[0]=='S') && (s[1]=='t') && (s[2]=='a') && (s[3]=='t') && (s[4]=='e')  ) {
		  cout << "State token found at: " << i <<'\n';
		  cout << "use tellg: " << myfile.tellg() << '\n';
		  //break;
	  }
	  myfile.seekg(i+1);
  }
  myfile.close();
  int a;
  cout << "Enter any number to exit:";       // tell user how to get out. 
  cin >> a; 
  return 0;
}