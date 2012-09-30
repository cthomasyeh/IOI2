// exercise5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
using namespace std;

int main()
{
  int input;
  int a;
  
  for (;;) {
	cout<<"1. Play Single Player Game\n";
	cout<<"2. Play Two Players Game\n";
	cout<<"3. Play Multiplayer Game\n";
	cout<<"4. Exit\n";
	cout<<"Selection: ";
	cin>> input;

  switch ( input ) {
	case 1:            // Note the colon, not a semicolon
		cout << "Play Single Player game selected\n\n";
		break;
	case 2:            // Note the colon, not a semicolon
		cout << "Play Two Players Game selected\n\n";
		break;
	case 3:            // Note the colon, not a semicolon
		cout << "Play multiplayer game selected\n\n";
		break;
	case 4:			   // Note the colon, not a semicolon
		cout << "Thank you for playing!\n\n";
		return 0;
	}

  }
  
}