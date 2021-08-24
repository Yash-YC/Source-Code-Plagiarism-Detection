#include <bits/stdc++.h>

#define ft first
#define st second
#define mp make_pair
#define pb push_back
#define sz(n) int(n.size())


using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int N = 123;
const int inf = 1e9 + 7;
const ll INF = 1e18 + 7;

int n, f, x, a[N][N], d[N], t[N][N];
pii p[N];
bool u[N], pu[N];

bool check()
{
	memset(u, false, sizeof u);
	memset(pu, false, sizeof pu);
	for (int i = 0; i < n; i ++)
	{
		u[p[d[i]].st] = true;
		for (int j = 0; j < n; j ++)
		{
		 	t[i][j] = a[p[d[i]].st][j];
		}
	}

	int g = 0;
	for (int i = 0; i < 2 * n - 1; i ++)
	{
		if (!u[i])
		{
			for (int j = 0; j < n; j ++)
			{
				if (!pu[j])
				{
					int l = 0;
					while (a[i][l] == t[l][j] && l < n) l ++;
					//cout << l;
					if (l == n)
					{
						u[i] = true;
						pu[j] = true;
						g ++;
					}
				}	
			}
		}	
	}

	if (g == n - 1) return true;
	return false;
}

int main ()
{
	cin >> f;
	for(int q = 1; q <= f; q ++)
	{
		cin >> n;
		for (int i = 0; i < 2 * n - 1; i ++)
		{
			for (int j = 0; j < n; j ++)
			{
				cin >> a[i][j];
			}
			p[i] = mp(a[i][n - 1], i);
		}
		sort(p, p + 2 * n - 1);

		for (int i = 0; i < n; i ++)
		{
			d[i] = i;
		}

		int pos = n - 1;
		for (d[0] = 0; d[0] < n; d[0] ++)
		for (d[1] = d[0] + 1; d[1] < n + 1; d[1] ++)
		for (d[2] = d[1] + 1; d[2] < n + 2; d[2] ++)
		for (d[3] = d[2] + 1; d[3] < n + 3; d[3] ++)
		for (d[4] = d[3] + 1; d[4] < n + 4; d[4] ++)
		for (d[5] = d[4] + 1; d[5] < n + 5; d[5] ++)
		for (d[6] = d[5] + 1; d[6] < n + 6; d[6] ++)
		for (d[7] = d[6] + 1; d[7] < n + 7; d[7] ++)
		for (d[8] = d[7] + 1; d[8] < n + 8; d[8] ++)
		for (d[9] = d[8] + 1; d[9] < n + 9; d[9] ++)
		{
			if (check())
			{
				cout << "Case #" << q << ": "; 
				for (int i = 0; i < n; i ++)
				{
					cout << p[d[i]].ft << " ";
				}
				cout << "\n";
				goto awe;
			}
			/*for (int i = 0; i < n; i ++)
			{
				cout << d[i] << " ";
			}
			cout << endl;*/
			//d[pos] ++;                                              			
			//while (d[pos] == 2 * n - 1 || d[pos] + 2 == d[pos + 1]) pos --;
			//cout << d[pos] + 1 << " " << d[pos + 1] << endl;
			/*if (pos != n - 1)
			{
				d[pos] ++;
				for (int i = pos + 1; i < n; i ++)
				{
					d[i] = d[i - 1] + 1; 
				}
				pos = n - 1;
			}*/
		}
		awe:;
	}
}