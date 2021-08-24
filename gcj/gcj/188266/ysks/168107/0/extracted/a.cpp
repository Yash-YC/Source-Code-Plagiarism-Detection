#include<iostream>
#include<map>
#include<vector>
#include<sstream>
using namespace std;

void i2v( int n, vector<int> &v, int base )
{
	if( base == 1 )
	{
		cout << "erroe" << endl;
		return;
	}
	v.clear();
	while( n != 0 )
	{
		v.push_back( n % base );
		n /= base;
	}
}

bool is_happy( int n, int b, map<int,bool> &c )
{
	vector<int> m;
	i2v( n, m, b );
	int ans = 0;
	for( int i = 0; i < m.size(); i++ )
	{
		ans += m[i] * m[i];
	}

	if( ans == 1 )
	{
		return true;
	}
	else if( c.find(ans) != c.end() )
	{
		return false;
	}
	else
	{
		c[ans] = true;
		return is_happy( ans, b, c );
	}
}

int main()
{
	int T;
	cin >> T;
	string line;
	getline( cin, line );
	for( int n = 0; n < T; n++ )
	{
		string line;
		getline( cin, line );
		
		stringstream ss;
		ss.str(line);

		vector<int> bases;
		while( !ss.eof() )
		{
			int temp;
			ss >> temp;
			bases.push_back(temp);
		}

		int ans = -1;
		for( int i = 2; i < 99999; i++ )
		{
			int b = 0;
			for( b = 0; b < bases.size(); b++ )
			{
				map<int,bool> c;
				if( !is_happy( i, bases[b], c ) )
				{
					break;
				}
			}

			if( b == bases.size() )
			{
				ans = i;
				break;
			}
		}

		cout << "Case #" << (n+1) << ": " << ans << endl;
	}
}
