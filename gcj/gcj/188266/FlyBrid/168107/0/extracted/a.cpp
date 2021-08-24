#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>


using namespace std;

char a[100];
bool p(long long k,int t)
{
	int i;
	int j;
	
	for (i = 0 ; i < 100; i++)
	{
		itoa(k,a,t);
		k = 0;
		for (j = 0 ; j < strlen(a);j++)
		{
			k+=(int)(a[j] - '0') * (int)(a[j] - '0');
		}
		if (k == 1) return true;

	}
	return false;
}

int main()
{
	ifstream cin("a.in");
	ofstream cout("a.out");
	
    int t;
	int b[20];
	int i;
	int j;
	int num = 2;
	bool q;
	int k;
	cin >> t;
	for (i = 0 ; i < t; i++)
	{
		num = 2;
		j = 1;
		cin>>b[0];
		while (cin.get() != '\n')
		{
			cin>>b[j];
			j++;
		}
		while(1)
		{
			q = true;
			for (k = 0; k < j; k++)
			{
				if (!p(num,b[k]))
				{
					q = false;
				     break;
				}
			}
			num++;
			if (q)
			{
				break;
			}
		}
		cout<<"Case #" << i + 1 << ": " << num - 1<<endl;
	}
	
	
	
	
	return 0;
}