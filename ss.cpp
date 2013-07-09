#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <Windows.h>

using namespace std;

int binarysearch(int[],int,int);
void bubblesort(int[],int);

int main(void)
{
    int arr_size; // user defined static array size
    int rand_size = 1000000; // user defined randomize range

    cout << "Please Enter Array size : " << endl;
    cin >> arr_size;
    
	int *a = new int[arr_size];
    int i,searchkey,index;

    srand(time(NULL));
    for(i=0; i<arr_size; i++)
    {
        a[i]=rand()%rand_size+1;
        //a[i] = rand();
        cout << "a[" << i << "] = " << a[i] << endl;
        
    }

    bubblesort(a,arr_size); // sort random emelents for binary search

    cout << "Array is sorted (increase)\n";

    for(i=0; i<arr_size; i++) // show sorted list
    {
        cout << "a[" << i << "] = " << a[i] << endl;
    }

    cout << "\nPlease enter a number for binary search between 1 and " << rand_size << endl;
    cin >> searchkey;

    index=binarysearch(a,searchkey,arr_size); // jump binarySearch function

    if(index!=-1)
    {
        cout << "\nIndex number is : " << index << endl;
    }
    else
    {
        cout << "\nValue is not found" << endl;
    }
	Sleep(15000);
    return 0;
}


void bubblesort(int a[], int size)
{
  
}


int binarysearch(int a[], int searchkey, int size)
{
    
}