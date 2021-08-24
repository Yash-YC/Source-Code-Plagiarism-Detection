#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int M[1000][11];
int ret[2050] = {};

bool happy(int x, int i)
{
	bool w[15000] = {};
	while (1)
	{
		int sum = 0;
		while (x)
		{
			int tmp = x%i;
			x /= i;
			sum += tmp*tmp;
		}
		if (M[sum][i])
			return true;
		if (w[sum])
			return false;
		w[sum] = 1;
		x = sum;
	}
}

void mask_lower(int mask, int x)
{
	for (int i=2; i<=10; i++)
	{
		int tmp = mask & (1<<i);
		if (tmp)
		{
			tmp = mask ^ tmp;
			if (!ret[tmp])
			{
				ret[tmp] = x;
				mask_lower(tmp,x);
			}
		}
	}
}

int main()
{
/*	freopen("tmp.txt","w",stdout);
	int kol = 0;
	for (int i=0; i<11; i++)
		M[1][i] = 1;
	for (int x = 2; !ret[2044]; x++)
	{
		int mask = 0;
		for (int i=2; i<=10; i++)
			if (happy(x,i))
			{
				if (x < 1000)
					M[x][i] = 1;
				mask |= 1<<i;
			}
		if (!ret[mask])
		{
			kol++;
			ret[mask] = x;
			mask_lower(mask,x);
		}
	}
	for (int i=0; i<2050; i++)
		cout << ret[i] << endl;*/
	freopen("tmp.txt","r",stdin);
	for (int i=0; i<2050; i++)
		cin >> ret[i];
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int N;
	cin >> N;
	char t[10];
	cin.getline(t,5);
	for (int i=0; i<N; i++)
	{
		char buf[1000];
		int mask = 0;
		cin.getline(buf,900);
		stringstream tmp;
		tmp.clear();
		tmp << buf;
		while (1)
		{
			int tec;
			if (!(tmp >> tec))
				break;;
			mask |= 1 << tec;
		}
		cout << "Case #" << i+1 << ": " << ret[mask] << endl;
	}
	return 0;
}