#include <iostream>
#include <set>
using namespace std;

int res[512];
bool has[100000000];
//int yz[11][100000000];
int s[10000000];
int sn;

int getac(int n, int base)
{
	sn = 0;

	while (n != 1) 
	{
		/*if (yz[base][n] != 0) 
		{
			for (int i = 0; i < sn; i++)
			{
				has[s[i]] = false;
			}
			return yz[base][n]>0?1:0;
		}*/
		if (has[n]) 
		{
			for (int i = 0; i < sn; i++)
			{
				//yz[base][s[i]] = -1;
				has[s[i]] = false;
			}
			return 0;
		}
		has[n] = true;
		s[sn++] = n;
		int m = 0;
		int t;
		while (n)
		{
			t = n % base;
			m += t * t;
			n /= base;
		}
		n = m;
	}
	for (int i = 0; i < sn; i++)
	{
		//yz[base][s[i]] = 1;
		has[s[i]] = false;
	}
	return 1;
}

int main()
{
	memset(res, 0, sizeof(res));
	//memset(yz, 0, sizeof(yz));
	memset(has, 0, sizeof(has));
	for(int i = 2; !res[511]; i++)
	{
		int ind = 0;
		for (int b = 2; b <= 10; b++)
		{
			ind = (ind << 1) + (getac(i, b)?1:0);
		}
		if (!res[ind])
		{
			res[ind] = i;
			printf("%d i=%d\n", ind, i);
		}
	}
	FILE *fp = fopen("table1.txt", "w");
	for (int i = 0; i < 512; i++)
	{
		fprintf(fp, "%d ", res[i]);
	}
	fclose(fp);
}