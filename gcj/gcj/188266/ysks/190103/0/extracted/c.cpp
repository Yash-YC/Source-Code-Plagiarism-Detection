#include<iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for( int m = 0; m < t; m++ )
	{
		int n, c;
		cin >> c >> n;
		double ans2 = 0;
		for( int i = 1; i <= (c-n); i++ )
		{
			ans2 += (double)c/(double)i;
		}

		double ans = (ans2 / n) + 1;

		cout << "Case #" << (m+1) << ": " << ans << endl;
	}
}
