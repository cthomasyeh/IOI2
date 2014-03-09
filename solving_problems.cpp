#include <iostream>
#include <algorithm>
using namespace std;

int a0[6] = { 3, 5, 1, 4, 10, 6 };
int a1[10] = { 2, 5, 7, 8, 90, 110, 200, 250, 300, 410};
int a2[10] = { 2, 5, 7, 8, 90, 110, 200, 250, 300, 10};
int a3[1] = {0};
int a4[2] = {1, 1};
int a5[10] = { 5, 6, 5, 60, 7, 7, 5, 16, 17, 4};
int a6[6] = { 6, 5, 4, 3, 2, 1 };

int e0[2] = {1, 2};
int f0[2] = {3, 4};
int e1[3] = { 15, 16, 17};
int f1[5] = { 1, 2, 3, 4, 5};

int r0[3] = {1, 6, 4};
int r1[2] = {1, 4};
int r2[1] = {1};
int r3[5] = {1, 9, 4, 6, 6};

int b0[20] = { 7, -10, 5, 8, 7, 7, 20, -23, 50, 8, 7, 51, 8, 50, 6, 4, -10, -10, 7, 9};
int b1[12] = { 4, 7, 3, 8, 9, 7, 3, 9, 9, 3, 3, 10};
int b2[1] = {0};
int b3[3] = {1, 2, 3};
int b4[3] = {5, 11, 9};
int b5[5] = {7, 0, 0, 0, 0};
int b6[5] = {1, 2, 1, 1, 3};
int b7[7] = {1, 4, 2, 1, 4, 1, 4};
int b8[1] = {1};
int b9[2] = {3, 9};

int c0[4] = {1, 3, 1, 4};
int c1[7] = {1, 3, 1, 4, 4, 3, 1};
int c2[7] = {2, 3, 2, 3, 2, 4, 4};
int c3[3] = {3, 1, 4};
int c4[1] = {1};
int c5[1] = {1};
int c6[6] = {3, 1, 1, 3, 4, 4};

int d0[5] = {1, 1, 1, 2, 1};
int d1[5] = {2, 1, 1, 2, 1};
int d2[2] = {10, 10};
int d3[5] = {10, 0, 1, -1, 10};
int d4[5] = {1, 1, 1, 1, 4};
int d5[1] = {1};

//Given base and n that are both 1 or more, compute recursively (no loops) 
//the value of base to the n power, so powerN(3, 2) is 9 (3 squared). 

//power(3, 1) should return 3
//power(5, 5) should return 3125
//power(10, 3 ) should return 1000
int power(int base, int n)
{
	return 0;
}



// find the largest number in the array a
int findLargest(int a[], int len)
{
	return 0;
}

// return the average of all numbers in array a
double findAverage(int a[], int len)
{
	return 0.0;
}

// given 2 arrays, find the larger array (which is defined as having the 
// larger sum of all elements, and return its sum
int biggerArray(int a[], int alen, int b[], int blen)
{
	return 0;

}

// Given an array of ints, compute recursively if the array contains a 6. 
// We'll use the convention of considering only the part of the array that 
// begins at the given index. In this way, a recursive call can pass index+1 
// to move down the array. The initial call will pass in index as 0. 

// find6InArray({1, 6, 4}, 3, 0) should return true
// find6InArray({1, 4}, 2, 0) should return false
// find6InArray({6}, 1, 0) should return true
bool find6InArray(int a[], int len, int index)
{
	return false;
}


// Given an array of ints, compute recursively the number of times that the 
// value 6 appears in the array. We'll use the convention of considering only 
// the part of the array that begins at the given index. In this way, a recursive 
// call can pass index+1 to move down the array. The initial call will pass in index as 0. 

// count6IArray({1, 2, 6}, 3, 0) should return 1
// count6InArray({6, 6}, 2, 0) should return 2
// count6InArray({1, 2, 3, 4}, 4, 0) should return 0
int count6InArray(int a[], int len, int index)
{
	return 0;
}

void sortMe(int a[], int len)
{
	sort(a, a+len);
	for (int i=0; i<len; i++)
		cout << a[i] << " ";
	cout << endl;
}

// Return true if the array is sorted in ascending order
bool isSorted(int a[], int len)
{
	return false;
}

void reverseArray(int a[], int len)
{
	
}


// Return true if the array is sorted either ascending or descending
bool isSortedEitherWay(int a[], int len)
{
	return false;
}


// find the number that most frenquently appears in the array
// and return the number of its appearances
// findMode({1, 7, 6, 7, 8, 9}, 6) -> 2
int findMode(int a[], int len)
{
	return 0;
}

//Given an array of integer of any length, "rotated the element left" 
//so {1, 2, 3} yields {2, 3, 1}. 
//print the array using a for loop before eding the function
void rotateLeft(int a[], int len)
{
	
}		


//Consider the leftmost and righmost appearances of some value in an array. 
//We'll say that the "span" is the number of elements between the two inclusive. 
//A single value has a span of 1. Returns the largest span found in the given array.
int maxSpan(int a[], int len)
{
	return 0;
}


//Re-arrange an array so that every 3 is immediately followed by a 4. 
//Do not move the 3's, but every other number may move. The array 
//contains the same number of 3's and 4's, every 3 has a number after 
//it that is not a 3 or 4, and a 3 appears in the array before any 4. 
//print the array using a for loop before eding the function
// example: fix34({1, 3, 1, 4}) → {1, 3, 4, 1}
// another example: fix34({3, 2, 2, 4}) → {3, 4, 2, 2}
void fix34(int a[], int len)
{
	
}

// Given a non-empty array, return true if there is a place to split 
// the array so that the sum of the numbers on one side is equal to 
// the sum of the numbers on the other side. 
//canBalance({1, 1, 1, 2, 1}) → true
//canBalance({2, 1, 1, 2, 1}) → false
//canBalance({10, 10}) → true
bool canBalance(int a[], int len)
{
	return false;
}

int main()
{
	
	cout << power(2, 3) << endl;
	cout << "power(2, 3): expecting 8\n---------------\n";
	cout << power(3, 6) << endl;
	cout << "power(3, 6): expecting 729\n---------------\n";
	cout << power(0, 2) << endl;
	cout << "power(0, 2): expecting 0\n---------------\n";
	cout << power(5, 0) << endl;
	cout << "power(5, 0): expecting 1\n---------------\n";
	
	
	cout << findLargest(a0, 6) << endl;
	cout << "findLargest(a0, 6): expecting 10\n------------\n";

	cout << findAverage(a0, 6) << endl;
	cout << "findAverage(a0, 6): epecting 4.8333\n------------\n";

	cout << biggerArray(e0, 2, f0, 2) << endl;
	cout << "biggerArray(e0, 2, f0, 2): expecting 7\n------------\n";
	cout << biggerArray(e1, 3, f1, 5) << endl;
	cout << "biggerArray(e1, 3, f1, 5): expecting 48\n------------\n";

	cout << find6InArray(r0, 3, 0) << endl;
	cout << "find6InArray(r0, 3, 0): expecting 1\n----------------\n";
	cout << find6InArray(r1, 2, 0) << endl;;
	cout << "find6InArray(r1, 2, 0): expecting 0\n----------------\n";	
	cout << find6InArray(r2, 0, 0) << endl;;
	cout << "find6InArray(r2, 0, 0): expecting 0\n----------------\n";
	cout << find6InArray(r3, 5, 0) << endl;
	cout << "find6InArray(r3, 5, 0): expecting 1\n----------------\n";
	
	cout << count6InArray(r0, 3, 0) << endl;
	cout << "count6InArray(r0, 3, 0): expecting 1\n----------------\n";
	cout << count6InArray(r1, 2, 0) << endl;;
	cout << "count6InArray(r1, 2, 0): expecting 0\n----------------\n";	
	cout << count6InArray(r2, 0, 0) << endl;;
	cout << "count6InArray(r2, 0, 0): expecting 0\n----------------\n";
	cout << count6InArray(r3, 5, 0) << endl;
	cout << "count6InArray(r3, 5, 0): expecting 2\n----------------\n";
	
	sortMe(a0, 6);
	cout << "sortMe(a0, 6): expecting: 1 3 4 5 6 10\n------------\n";

	cout << isSorted(a1, 10) << endl;
	cout << "isSorted(a1, 10): expecting 1\n------------\n";
	cout << isSorted(a2, 10) << endl;
	cout << "isSorted(a2, 10): expecting 0\n------------\n";
	cout << isSorted(a3, 1) << endl;
	cout << "isSorted(a3, 1): expecting 1\n------------\n";
	cout << isSorted(a4, 2) << endl;
	cout << "isSorted(a4, 2): expecting 1\n------------\n";
	cout << isSorted(a6, 6) << endl;
	cout << "isSorted(a6, 6): expecting 0\n------------\n";
	cout << isSortedEitherWay(a6, 6) << endl;
	cout << "isSortedEitherWay(a6, 6): expecting 1\n------------\n";
	
	cout << findMode(b0, 20) << endl;
	cout << "findMode(b0, 20): expecting 5\n------------\n";
	cout << findMode(b1, 12) << endl;
	cout << "findMode(b1, 12): expecting 4\n------------\n";
	cout << findMode(b2, 1) << endl;
	cout << "findMode(b2, 1): expecting 1\n------------\n";

	rotateLeft(b3, 3);
	cout << "rotateLeft(b3, 3): expecting 2 3 1\n------------\n";
	rotateLeft(b4, 3);
	cout << "rotateLeft(b4, 3): expecting 11 9 5\n------------\n";
	rotateLeft(b5, 5);
	cout << "rotateLeft(b5, 5): expecting 0 0 0 0 7\n------------\n";
	
	cout << maxSpan(b6, 5) << endl;
	cout << "maxSpan(b6, 5): expecting 4\n------------\n";
	cout << maxSpan(b7, 7) << endl;
	cout << "maxSpan(b7, 7): expecting 6\n------------\n";
	cout << maxSpan(b8, 0) << endl;
	cout << "maxSpan(b8, 0): expecting 0\n------------\n";
	cout << maxSpan(b9, 2) << endl;
	cout << "maxSpan(b9, 2): expecting 1\n------------\n";
	
	fix34(c0, 4);
	cout << "fix34(c0, 4): expecting 1 3 4 1\n------------\n";
	fix34(c1, 7);
	cout << "fix34(c1, 7): expecting 1 3 4 1 1 3 4\n------------\n";
	fix34(c2, 7);
	cout << "fix34(c2, 7): expecting 2 3 4 3 4 2 2\n------------\n";
	fix34(c3, 3);
	cout << "fix34(c3, 3): expecting 3 4 1\n------------\n";
	fix34(c4, 1);
	cout << "fix34(c4, 1): expecting 1\n------------\n";
	fix34(c5, 0);
	cout << "fix34(c5, 0): expecting (nothing)\n------------\n";
	fix34(c6, 6);
	cout << "fix34(c6, 6): expecting 3 4 1 3 4 1\n------------\n";

	cout << canBalance(d0, 5) << endl;
	cout << "canBalance(d0, 5): expecting 1\n--------------\n";
	cout << canBalance(d1, 5) << endl;
	cout << "canBalance(d0, 5): expecting 0\n--------------\n";
	cout << canBalance(d2, 2) << endl;
	cout << "canBalance(d0, 2): expecting 1\n--------------\n";
	cout << canBalance(d3, 5) << endl;
	cout << "canBalance(d0, 5): expecting 1\n--------------\n";
	cout << canBalance(d4, 5) << endl;
	cout << "canBalance(d0, 5): expecting 1\n--------------\n";
	cout << canBalance(d5, 1) << endl;
	cout << "canBalance(d0, 1): expecting 0\n--------------\n";
	system("pause");
}
