#include "stdafx.h"
#include <Windows.h>
#include <string>
#include <iostream>
using namespace std;

void charF (char image[250][250], int r, int c, int x, int y, char color)
{
	char previousColor = image[x][y];
	image[x][y] = color;
	if ((c > 0) && (r > 0) && (x > 0) && (y > 0) && (y < r) && (x < c))
	{
		if (image[x][y+1] == previousColor)
		{
			charF(image, r, c, x, y+1, color);
		}
		if (image[x][y-1] == previousColor)
		{
			charF(image, r, c, x, y-1, color);
		}
		if (image[x+1][y] == previousColor)
		{
			charF(image, r, c, x+1, y, color);
		}
		if (image[x-1][y] == previousColor)
		{
			charF(image, r, c, x-1, y, color);
		}
		if (image[x-1][y-1] == previousColor)
		{
			charF(image, r, c, x-1, y-1, color);
		}
		if (image[x+1][y-1] == previousColor)
		{
			charF(image, r, c, x+1, y-1, color);
		}
		if (image[x+1][y+1] == previousColor)
		{
			charF(image, r, c, x+1, y+1, color);
		}
	}
}

int main()
{
	char first;
	int c, r;
	char image[250][250] = {'O'};
	while ((cin >> first) && (first != 'X'))
	{
		if (first == 'I')
		{
			cin >> c >> r;
			for (int i=1; i<=r; i++)
			{
				for (int j=1; j<=c; j++)
				{
					image[i][j] = 'O';
				}
			}
		}
		if (first == 'C')
		{
			for (int i=1; i<=r; i++)
			{
				for (int j=1; j<=c; j++)
				{
					image[i][j] = 'O';
				}
			}
		}
		if (first == 'L')
		{
			int x,y;
			cin >> x >> y;
			cin >> image[y][x];
		}
		if (first == 'V')
		{
			int x,y,z;
			char a;
			cin >> x >> y >> z >> a;
			if (z < y)
			{
				int temp = z;
				z = y;
				y = temp;
			}
			for (int i=y; i<=z; i++)
			{
				image[i][x] = a;
			}
		}
		if (first == 'H')
		{
            int y, x, z;
            char a;
            cin >>  x >> z >> y >> a;
            if (z < x)
            {
                int tmp = x;
                x = z;
                z = tmp;
            }
            for (int i=x; i<=z;i++) 
			{
				image[y][i] = a;
			}
        }
		if (first == 'K')
        {
            int y, z, w, x;
            char a;
            cin >> w >> y >> x >> z >> a;
            for (int i=y; i<=z; i++) 
			{
				for (int j=w; j<=x; j++) 
				{
					image[i][j] = a;
				}
			}
        } 
		if (first == 'F')
		{
			int x, y;
			char a;
			cin >> x >> y >> a;
			charF(image, c, r, y, x, a);
		}
		if (first == 'S')
		{
			string tempStr;
			cin >> tempStr;
			cout << tempStr << '\n';
			for (int i=1; i<=r; i++)
			{
				for (int j=1; j<=c; j++)
				{
					cout << image[i][j];
				}
				cout << '\n';
			}
		}
	}	
	return 0;
}
