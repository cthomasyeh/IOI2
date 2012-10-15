// exercise10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main ()
{
  string mystr;
  string age;
  int x=0;
  

  
  cout << "What's your full name? ";
  
  getline (cin, mystr);  
  cout << "How old are you? ";
  getline (cin, age);
  stringstream(age) >> x; 
  cout << mystr << " is " <<  x << " years old.\n";
  
  cout << "Hello " << mystr << ".\n";
  cout << "What is your favorite team? ";
  getline (cin, mystr);
  cout << "I like " << mystr << " too!\n";
  
  
  int a;
  cout << "Enter any number to exit:";       // tell user how to get out. 
  cin >> a; 

  return 0;
}