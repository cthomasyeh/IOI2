//
//  scalar.c
//  
//
//  Created by Thomas Yeh on 3/15/14.
//
//

#include <iostream>
#include <string>

using namespace std;

const int ARRAY_SIZE = 10;
struct student {
    int grade;
    int studentID;
    string name;
    
};

int main()
{
    
    student studentArray[ARRAY_SIZE] = {
        {87, 10001, "Fred"},
	{28, 10002, "Tom"},
	{100, 10003, "Ali"},
	{78, 10004, "Sasha"},
	{84, 10005, "Erin"},
	{98, 10006, "Belina"},
	{75, 10007, "Leslie"},
	{70, 10008, "Candy"},
	{81, 10009, "Athina"},
	{68, 10010, "Monica"}
    };
    for (int i=0; i< 10; i++) 
	cout << studentArray[i].name << endl;    
}
