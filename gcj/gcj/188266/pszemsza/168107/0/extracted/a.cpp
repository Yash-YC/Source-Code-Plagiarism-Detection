#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;

int lim = 80;

vector <int> tobase(int n, int base)
{
	vector <int> r, rt;
	while (n)
	{
		rt.push_back(n % base);
		n /= base;
	}
	for (int i=rt.size()-1; i>=0; i--) r.push_back(rt[i]);
	return r;
}

bool go(int num, int base)
{
	//printf("\n # %d %d", num, base);
	int i,t=0, val;
	vector <int> n = tobase(num, base);
	while (1)
	{
		//printf("\nt=%d: ", t);
		//for (i=0; i<n.size(); i++) printf("%d ", n[i]);
		val = 0;
		for (i=0; i<n.size(); i++) val += n[i] * n[i];
		if (val == 1) return true;
		n = tobase(val, base);
		t++;
		if (t > lim) return false;
	}
}

int main()
{
	int i,l,k,j;
	int T;

	int val = 0;
	int pot = 1;
	char c,c2;

	char buf[80];
	scanf("%d", &T);
	scanf("%c", &c);
	for (k=0; k<T; k++)
	{
		vector <int> base;
		
		val = 0;
		while (1)
		{
			if (scanf("%c", &c) == EOF) break;
			if (c == 0 || c==EOF) break;
			if (c>='0' && c<='9')
			{
				val *= 10;
				val += (c-'0');
			}
			else if (c == ' ') 
			{
				base.push_back(val);
				val = 0;
			}
			else break;
		}

		base.push_back(val);

		int sol = 2;
		for (j=2; ; j++) // probujemy kolejne liczby
		{
			bool ok = true;
			for (i=0; i<base.size(); i++)
			{
				if (!go(j, base[i])) ok = false;

			}
			if (ok) 
			{
				sol = j;
				break;
			}
		}

		printf("Case #%d: %d\n", k+1, sol);	
	}
	return 0;
}
