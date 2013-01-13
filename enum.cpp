#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

enum Country {             
   USA,            
   Canada,          
   Mexico,              
};

enum City {
	DC,
	Toronto,
	MexicoCity,
};

struct Capital {
	Country countryName;
	City capitalCity;
};

string printCountry(Country c) {
	switch (c) {
      case USA:
         return ("United States of America");
         break;
	  case Canada:
         return ("Our northern neighbor");
         break;
	  case Mexico:
         return ("Our Southern neighbor");
         break;
      default: 
         return ("Does not exist");
   }

}

void printCity(City c) {
}

void printCapital(Capital c) {
	cout << printCountry(c.countryName) << "'s capital is: " << c.capitalCity;
}

int main() {   
   
   Capital c1, c2, c3;
   c1.countryName = USA;
   c1.capitalCity = DC;
   c2.countryName = Canada;
   c2.capitalCity = Toronto;
   c3.countryName = Mexico;
   c3.capitalCity = MexicoCity;
   printCapital (c1);

   Sleep(10000);
}