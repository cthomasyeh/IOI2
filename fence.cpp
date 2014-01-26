#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#define MAX 2000000
int main()
{
	int n;
	ifstream ifs("paint.in");
	ifs >> n; cout << n;

	int step;
	char d;
	long current=MAX/2;
	short f[MAX];
	for (long long i=0; i<MAX; i++) f[i]=0;
	long long answer=0;
       	for (int i=0; i< n; i++)
	{
		ifs >> step >> d;
		cout << step << " " << d << endl; 
		if (d == 'R') 
		{
			for (long i=0; i<step; i++)
			{
				f[current+i] = f[current+i] + 1;
			}
			current += step;
		}
		else 
		{	
			for (long i=0; i<step; i++)
			{
				f[current-i] = f[current-i] + 1;
			}
			current -= step;
		}
	}
	for (long long i=0; i<MAX; i++)
	{
		if (f[i] > 1) answer++;
	}
	cout << answer << endl;
		
}
