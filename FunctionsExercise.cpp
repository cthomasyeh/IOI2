#include <iostream>
using namespace std;

int main()
{
// Turn these into a function
// parameters: none
// return: void
cout << "Welcome to the calculator \n"
	<< "I add, subtract, multiply or divide numbers \n";

// parameters: none
// return: int
int response;
cout << "Which mathematical operation? "
	<< "(1.Add / 2.Subtract / 3.Multiply / 4. Divide) ";
cin >> response;

//paramters: none
// return: int
int num1;
cout << "Enter first number: ";
cin >> num1;

//parameters: none
// return: int
int num2;
cout << "Enter second number: ";
cin >> num2;

//********************************************
int answer;
switch(response)
{
case 1:
	//parameters int num1, int num2
	//return int
	answer = num1 + num2;
	break;
case 2:
	//parameters int num1, int num2
	//return int
	answer = num1 - num2;
	break;
case 3:
	//parameters int num1, int num2
	//return int
	answer = num1 * num2;
	break;
case 4:
	//parameters int num1, int num2
	//return int
	answer = num1 / num2;
	break;
default:
	cout << "Incorrect selection";
//*******************************************
}

cout << "The answer is: " << answer;
cout << endl;
system("pause");
return 0;
}


