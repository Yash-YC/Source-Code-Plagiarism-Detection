#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int b[20][501];
int c[20];
int t;
int f[20][501];
void solve(int k1, int k2)
{
	int i1;
	
	if (k1 == 19)
	{
		t++;
		if (t == 10000)
		{
			t = 0;
		}
	}
	else
	{
	for (i1 = 0 ; i1 < c[k1] ; i1++)
	{
		if (b[k1][i1] > k2)
		{
			solve(k1+1,b[k1][i1]);
		}
	}
	}
	
}
int main()
{
	ifstream cin("c.in");
	ofstream cout("d.out");
	int n;
	cin>>n;
	cin.get();
	int i;
	char s[1000];
	int j,k;
	int w;
	char a[20];
	a[0] = 'w';
	a[1] = 'e';
	a[2] = 'l';
	a[3] = 'c';
	a[4] = 'o';
	a[5] = 'm';
	a[6] = 'e';
	a[7] = ' ';
	a[8] = 't';
	a[9] = 'o';
	a[10] = ' ';
	a[11] = 'c';
	a[12] = 'o';
	a[13] = 'd';
	a[14] = 'e';
	a[15] = ' ';
	a[16] = 'j';
	a[17] = 'a';
	a[18] = 'm';
	
	for (i = 0 ; i < n ; i++)
	{
		for (j = 0 ; j <= 18 ; j++)
		{
			c[j] = 0;
		}
		cin.getline(s,1000,'\n');
		
		for (j = 0 ; j < strlen(s) ; j++)
		{
			for (k = 0 ; k <= 18 ; k++)
			{
				if (a[k] == s[j])
				{
					b[k][c[k]] = j;
					c[k]++;
					
				}
			}

		}
		
		t = 0;
		for (j = 0; j <= 18; j++)
		{
			for (k = 0 ; k < c[j]; k++)
			{
				f[j][k] = 0;
			}
		}
		for (j = 0; j < c[18]; j++)
		{
			f[18][j] = 1;
		}
		for (j = 17; j >=0; j--)
		{
			for (k = 0; k < c[j]; k++)
			{
				for (w = 0; w < c[j+1]; w++)
				{
					if (b[j][k] < b[j+1][w])
					{
						f[j][k] += f[j+1][w];
						if (f[j][k] > 10000)
						{
							f[j][k] = f[j][k] - f[j][k]/10000*10000;
						}
					}
				}
			}
		}
		
		for (j = 0 ; j < c[0]; j++)
		{
			t += f[0][j];
			if (t > 10000)
			{
				t = t - t/10000*10000;
			}
		}
		
		
		//solve(0,-1);
		w = t;
		j = 0;
		while (w > 0)
		{
			w = w/10;
			j++;
		}
		if (j == 0)
		{
			j = 1;
		}
		
		cout<<"Case #" << i+1 << ": ";
		for (k = 0; k < 4 - j; k++)
		{
			cout<<'0';
		}
		cout<<t<<endl;
        /*
		for (j = 0 ; j <=18 ; j++)
		{
			for (k = 0 ; k < c[j]; k++)
			{
				cout<< b[j][k] ;
			}
			cout<< endl;
		}
		*/
		
	}
	
	
	
	return 0;
}