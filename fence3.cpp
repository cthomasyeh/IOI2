#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#define MAX 200000 

struct paint
{
	long begin;
	long end;
};

int main()
{
	int n;
	ifstream ifs("paint.in");
	ofstream ofs("paint.out");
	ifs >> n; 

	int step;
	char d;
	long current=MAX/2;
	paint p[MAX];
	int c[MAX];
	int answer[MAX];
	for (int i=0; i<MAX; i++) answer[i] = 0;
       	for (int i=0; i< n; i++)
	{
		ifs >> step >> d;
		if (d == 'R') 
		{
			p[i].begin = current;
			p[i].end = current + step;	
			c[i] = p[i].begin;
			current += step;
		}
		else 
		{	
			p[i].begin = current;
   			p[i].end = current-step;	
			c[i] = p[i].begin;
			current -= step;
		}
	}
	c[n]=current;
	sort (c, c+n+1);
	cout << "0\n";
	for (int i=0; i<=n; i++)
	{
		if (p[i].begin > p[i].end) 
		{
			long tmp = p[i].begin;
			p[i].begin = p[i].end;
			p[i].end = tmp;
		}
		//cout << p[i].begin << "  :  " << p[i].end << endl;	
		//cout << i << ": " << c[i] << endl;
	}
	cout << "1\n";
	for (int i=0; i<=n; i++)
	{
		for (int j=0; j<n; j++)
		{
			if (c[i]>=p[j].begin && c[i+1]<=p[j].end) 
			{
				answer[i]++; 
			//	cout << "got somthings: answer["<< i<< "]: " << answer[i] << " at p = " << j << endl;
			}
		}
	}
	cout << "2\n";
	int output=0;
	for (int i=0; i<n; i++) if (answer[i]> 1) output = output + c[i+1] - c[i];

	ofs << output << endl;

	//cout << answer << endl;
		
}
