#include "stdafx.h"
#include <iostream>
#include <Windows.h>

using namespace std;

/*

Please follow me to type he code for class

*/

int main () {
	int y=0;
	
	cout << "Enter an amount: " << '\n';
	cin >> y;

	ChangeMachine myMachine(y);

	myMachine.calculator();

	cout << myMachine.showAmount() << " Cents are made up of " << 
			myMachine.getQuarter() << " Quarter(s), " << 
			myMachine.getDime() << " Dimes(s), " << 
			myMachine.getNickel() << " Nickel(s) and " << 
			myMachine.getPenny() << " Penny(s)" << endl;

	Sleep (5000);
	return 0;
}