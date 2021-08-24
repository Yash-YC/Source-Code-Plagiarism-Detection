#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

#define CLEAR(x,with) memset(x,with,sizeof(x))  
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define sz(a) int((a).size())
#define MAXHAPPY 50000

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;

long long convert(long long i, int jj)
{
	long long ret = 0;
	long long j = jj;
	int power = 1;

	while(i)
	{
		long long div = i / j;
		long long rem = i - div*j;
		ret += power * rem;
		i = div;
		power *= 10;
	}
	return ret;
}

long long happy(long long i, int jj)
{
	long long ret = 0, ret2 = 0;
	long long j = jj;
	while(i)
	{
		long long div = i / 10;
		long long rem = i - div*10;
		ret += rem*rem;
		i = div;
	}
	int power = 1;

	while(ret)
	{
		long long div = ret / j;
		long long rem = ret - div*j;
		ret2 += power * rem;
		ret = div;
		power *= 10;
	}
	return ret2;
}

int main()
{
	int N;
	string A;

	cin >> N;
	getline(cin, A);

	bool check[11][MAXHAPPY+1] = {false};

	for(long long i=2; i<=MAXHAPPY; i++)
	{
		for(int j=2; j<=10; j++) // bases
		{
			if(j==2 || j==4) goto always_true;
			long long num = convert(i, j);

			while( true )
			{
				num = happy(num, j);

				if( j == 3 && (num == 2 || num == 12 || num == 22) ) goto next_step;
				if( j == 5 && (num == 4 || num == 23 || num == 33) ) goto next_step;
				if( j == 6 && num == 32 ) goto next_step;
				if( j == 7 && (num == 2 || num == 34 || num == 13 || num == 23 || num == 63 || num == 44) ) goto next_step;
				if( j == 8 && (num == 4 || num == 5 || num == 32 || num == 24 || num == 64) ) goto next_step;
				if( j == 9 && (num == 55 || num == 58 || num == 45 || num == 75) ) goto next_step;
				if( j == 10 && num == 4 ) goto next_step;

				if(num == 1) break;
			}
always_true:;
			check[j][i] = true;
next_step:;
		}
	}


	long long ans[11][11][11] = {0};
	for(int ii=2; ii<=10; ii++)
	{
		for(int jj=2; jj<=10; jj++)
		{
			for(int kk=2; kk<=10; kk++)
			{
				for(long long iii=1; iii<=MAXHAPPY; iii++)
				{
					if( check[ii][iii] && check[jj][iii] && check[kk][iii] )
					{
						ans[ii][jj][kk] = iii;
						break;
					}
				}
			}
		}
	}

	for(int c=1; c<=N; c++)
	{
		getline(cin, A);
		stringstream ss(A);
		int x1, x2, x3;
		long long ansans = 0;
		if((int)A.size() < 5)
		{
			ss >> x1 >> x2;
			ansans = ans[x1][x2][2];
			for(int i=3; i<=10; i++)
				if( ansans > ans[x1][x2][i] )
					ansans = ans[x1][x2][i];
		}
		else
		{
			ss >> x1 >> x2 >> x3;
			ansans = ans[x1][x2][x3];
		}
		cout << "Case #" << c << ": " << ansans << endl;
	}

	return 0;
}
