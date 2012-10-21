#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main () {
  long begin,end;
  int answer=0;
  long i=0;
  char s[10], t[25];
  ifstream myfile ("us-const.txt");
  begin = myfile.tellg();

  myfile.seekg (0, ios::end);
  end = myfile.tellg();

  myfile.seekg (0);
  for (i=begin; i< (end-5); i++) {
	  myfile.read(s, 5);
	  
	  if ( (s[0]=='S') && (s[1]=='t') && (s[2]=='a') && (s[3]=='t') && (s[4]=='e')  ) {
		  cout << "'State' token found around: ";
		  myfile.seekg(i-10);
		  myfile.read(t, 25);
		  for (int j=0; j<25; j++) cout << t[j];
		  cout << '\n';
		  answer = answer + 1;
	  }
	  myfile.seekg(i+1);
  }
  myfile.close();
  int a;
  cout << "Total number of 'State' occurance is: " << answer << '\n';
  cout << "Enter any number to exit:";       // tell user how to get out. 
  cin >> a; 
  return 0;
}