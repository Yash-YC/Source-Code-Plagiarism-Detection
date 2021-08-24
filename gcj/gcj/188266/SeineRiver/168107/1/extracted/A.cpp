#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <queue>
#include <time.h>

using namespace std;

#define RP(a,h) for(int (a)=0; (a)<(h); (a)++)
#define FR(a,l,h) for(int (a)=(l); (a)<=(h); (a)++)
#define INF 2000000000
#define sz size()
#define pb push_back
#define sv(v) sort((v).begin(), (v).end())
#define ABS(x) (((x)>0)?(x):(-(x)))


#define IMAX 30000000
int check[IMAX+1][11];

int isHappy(int number, int base)
{	
	if (check[number][base] == 0 || check[number][base] == 1) return check[number][base];
	if (check[number][base] == 2) 
	{
		check[number][base] = 0;
		return 0;
	}
	
	int& res = check[number][base];
	res = 2;
	
	int sum = 0;
	int tmp = number;
	while (tmp > 0)
	{
		sum += (tmp%base) * (tmp%base);
		tmp /= base;
	}		
//	cout << number << " " << sum << endl;
	if (sum < base && sum * sum < base)
	{
		if (sum == 1) res = 1;
		else res = 0;
	}
	else if (sum == number)
	{
		res = 0;
	}
	else
	{
		res = isHappy(sum, base);
	}
	
	return res;
}

int main()
{   
	int n, b;
	string s;
	vector<int> base;
	
	memset(check, -1, sizeof(check));
//	cout << isHappy(91, 9) << endl;
//	return 0;

    cin >> n;
    getline(cin, s);
	    
	FR(i, 2, IMAX)
	{
		FR(j, 2, 10) check[i][j] = isHappy(i, j);
	}	
	    
    RP(test, n)
    {
		getline(cin, s);
		//cout << s << endl;
		istringstream iss(s);
		base.clear();
		while (iss >> b) base.pb(b);
		
		bool res = false;		
		FR(i, 2, IMAX) 
		{
			bool ok = true;
			RP(j, base.sz)
			{
				//cout << i << " " << base[j] << " " << check[i][base[j]] << endl;
				if (check[i][base[j]] == 0) { ok = false; break; }
			}
			if (ok) 
			{
				res = true;
				cout << "Case #" << test+1 << ": " << i << endl;
				break;
			}
		}
		if (!res) cout << "Case #: no res" << endl;
		
	}
    
    return 0;
}
