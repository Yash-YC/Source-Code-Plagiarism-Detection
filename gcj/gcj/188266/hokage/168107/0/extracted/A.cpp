#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <set>

#define SZ(a) (int)(a).size()
#define PB push_back
#define ALL(a) (a).begin(),(a).end()
#define INF (int)1e9

#define ll long long
#define vi vector<int>
#define vs vector<string>

using namespace std;

int toInt(string str)
{
	stringstream ss;
	int t;
	ss<<str;
	ss>>t;
	return t;
}

vi splitString (string a, char c)
{
	vector <int> res;
	
	string buff = "";
	a += c;
	
	for(int i = 0; i < a.size(); i++)
	{
		if(a[i] == c)
		{
			if(buff.size() > 0)
				res.push_back(toInt(buff));
			buff = "";
		}	
		else
			buff.push_back(a[i]);
	}
	return res;
}

bool valid(long long num, int base)
{
	set <long long> map;
	
	long long actsqr = 0, mul = 1;
	int rem;
	while(num != 0)
	{
		rem = num % base;
		num /= base;
		actsqr += rem * mul;
		mul *= 10;
	}
		
	num = actsqr;
	map.insert(num);
	long long n = num / 10;
	int r = num % 10;
	
	while( true )
	{
		if((n == 0 && r == 1) || (n == 0 && r * r == base))
			return true;
		/*
		if(n == 0)
		{
			if(r == 1)
				return true;
			if(r * r == base)
				return true;
			return false;
		}*/
		
		long long sqr = 0;
		while(num != 0)
		{
			rem = num % 10;
			num /= 10;
			sqr += rem * rem;
		}
		
		actsqr = 0;
		mul = 1;
		while(sqr != 0)
		{
			rem = sqr % base;
			sqr /= base;
			actsqr += rem * mul;
			mul *= 10;
		}
		
		//cout << actsqr << endl;
		int t = SZ(map);
		map.insert(actsqr);
		if(t == SZ(map))
			return false;
		num = actsqr;
		n = num / 10;
		r = num % 10;
	}
	
}

bool correct(int num, vi &bases)
{
	int cnt = 0;
	for(int i = 0; i < SZ(bases); i++)
	{
		if(valid(num, bases[i]))
			cnt++;
		else
			break;
	}
	
	return cnt == SZ(bases);
}

int main()
{
	int T;
	cin >> T;
	cin.ignore();
	
	//cout << valid(13, 7) << endl;
	for(int cas = 1; cas <= T; cas++)
	{
		char ipp[100];
		cin.getline(ipp, 100);
		string ip = ipp;
		
		vi bases = splitString(ip, ' ');
		
		int ans;
		bool done = false;
		for(ans = 2; ; ans++)
		{
			done = correct(ans, bases);
			if(done)
				break;
		}
		cout << "Case #" << cas << ": " << ans << endl;
		
	}
		
		
	return 0;
}
