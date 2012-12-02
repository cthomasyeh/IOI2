#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
using namespace std;

struct students {
  string firstName;
  string lastName;
  int year;
} student1;

void printStudents (students student);

int main ()
{
  string mystr;

  student1.firstName = "Yeh";
  student1.year = 2012;

  cout << "Enter first name: ";
  getline (cin,student1.firstName);
  cout << "Enter last name: ";
  getline (cin,student1.lastName);
  cout << "Enter year: ";
  getline (cin,mystr);
  stringstream(mystr) >> student1.year;

  cout << "Student info:\n";
  printStudents (student1);
  Sleep(5000);
  return 0;
}

void printStudents (students student)
{
  cout << student.lastName << " ";
  cout << student.firstName << " ";
  cout << student.year << " ";
}

