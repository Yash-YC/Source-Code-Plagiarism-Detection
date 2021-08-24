#include <fstream>
#include <vector>
#include <set>

using namespace std;

set<pair<int,int> > hap;
set<pair<int,int> > nothap;

int next(int n, int b)
{
	int m = 0;
	while(n > 0)
	{
		m += (n%b)*(n%b);
		n /= b;
	}
	return m;
}

bool happy(int n, int b)
{
	set<int> s;
	s.insert(n);
	bool h = false;
	while(true)
	{
		int m = next(n,b);
		if (m == 1)
		{
			h = true;
			hap.insert(make_pair(m,b));
			break;
		}
		else if(hap.find(make_pair(m,b)) != hap.end())
		{
			h = true;
			break;
		}
		else if(nothap.find(make_pair(m,b)) != nothap.end())
		{
			break;
		}
		else if(s.find(m) != s.end())
		{
			nothap.insert(make_pair(m,b));
			break;
		}
		else
		{
			s.insert(m);
			n = m;
		}

	}
	return h;
}

int main()
{
	ifstream f;
	ofstream o;
	f.open("Asmall.txt");
	o.open("Aout.txt");
	int T;
	f >> T;
	for(int i = 0; i < T; i++)
	{
		vector<int> v;
		do
		{
			int t;
			f >> t;
			v.push_back(t);
		} while(f.peek() == ' ');
		int n = 1;
		bool d = false;
		while(!d)
		{
			n++;
			d = true;
			for(int j = 0; j < v.size(); j++)
				d &= happy(n,v[j]);
		}
		o << "Case #" << (i+1) << ": " << n << endl;
	}
	o.close();
	f.close();
}