#include <map>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

map<int, int> dp;

bool isHappy(int n, int b)
{
	if(n==1) return true;
	if( dp.count(n) ) return false;
	dp[n]=1;
	int t=0;
	while(n) { int p=n%b; t+=p*p; n/=b; }
	return isHappy(t, b);
}

int main()
{
	int index=0;

	string line;
	getline(cin, line);

	stringstream sst;
	sst<< line;
	int T;
	sst >> T;

	for(int k=1; k<=T; k++)
	{
		vector<int> v;
		int b;
		stringstream ss;
		getline(cin, line);
		ss << line;
		while(ss>>b) v.push_back(b);

		for(int i=2; ; i++)
		{
			bool ok=true;
			for(int j=0; j<v.size(); j++)
			{
				dp.clear();
				if( isHappy(i, v[j])==false ) { ok=false; break; }
			}
			if( ok )
			{
				cout << "Case #" << k <<": " << i  << endl;
				break;
			}
		}
	}
	return 0;

}
