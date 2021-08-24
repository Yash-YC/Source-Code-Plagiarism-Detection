#include <bits/stdc++.h>

#define ft first
#define st second
#define mp make_pair
#define pb push_back
#define sz(n) int(n.size())


using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int N = 1e5;
const int inf = 1e9 + 7;
const ll INF = 1e18 + 7;

deque <char> d;
int t;
string s;

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	for (int q = 1; q <= t; q ++)
	{
		cin >> s;
		d.push_back(s[0]);
		for (int i = 1; i < sz(s); i ++)
		{
			if (s[i] >= d.front()) d.push_front(s[i]);
			else d.push_back(s[i]);
		}      

		string t = "";
		for (int i = 0; i < sz(s); i ++)
		{
			t += d.front();
			d.pop_front();	
		}

		cout << "Case #" << q << ": " << t << "\n";
	}

}