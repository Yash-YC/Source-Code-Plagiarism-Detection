#include <iostream>
#include <cstdio>
#include <sstream>
#include <cmath>

using namespace std;

void logic()
{
	long y;
	double ans = 0;
	double c, n;
	cin >> c >> n;
	double con = (c-n)/c;
	double cur_prob, acc_prob = 0;
	//cout << "c, n, con: " << c << " " << n << " " << con << "\n";
	for(y = long((c+n-1)/n); y <= 200; y++)
	{
		// y == cnt
		cur_prob = powl(1-powl(con, y-1),  c-n);
		ans += (cur_prob - acc_prob) * y;
		acc_prob = cur_prob;
		//cout << "ans==" << ans << "\n";
	}
	printf("%0.6lf", ans);
}
int main()
{
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	
	long y, t;
	cin >> t;
	for(y = 1; y <= t; y++)
	{
		cout << "Case #" << y << ": ";
		logic();
		cout << "\n";
	}
}

