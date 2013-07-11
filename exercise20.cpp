#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>

using namespace std;

int main()
{
	string tmpStr = "this is the first string";
	string tmpStr2 = "begin the second string, end of second string";
	
	tmpStr = tmpStr + tmpStr2;
	cout << tmpStr << endl;

}