#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int happy[11][100000];
int seen[100000];

int testhappy(int base, int i)
{	
	if(happy[base][i] != -1) return happy[base][i];
	
	seen[i] = 1;
	int ans = 0;
	
	int tmpi = i;
	
	while(tmpi > 0)
	{
		ans += (tmpi%base)*(tmpi%base);
		tmpi /= base;
	}
	
	if(happy[base][ans] != -1)
	{
		seen[i] = 0;
		return happy[base][i] = happy[base][ans];
	}
	else if(seen[ans] == 1) 
	{
		seen[i] = 0;
		return happy[base][i] = 0;
	}
	else
	{
		happy[base][i] = testhappy(base, ans);
		seen[i] = 0;
		return happy[base][i];
	}
}


int main()
{
	ofstream fout("A-small.out");
	ifstream fin("A-small-attempt0.in");
	
	for(int i = 0; i < 100000; i++)
	{
		seen[i] = 0;
		for(int base = 0; base <= 10; base++)
			happy[base][i] = -1;
	}	

	for(int base = 2; base <= 10; base++)
	{
		happy[base][1] = 1;
		for(int i = 2; i < 100000; i++)
			happy[base][i] = testhappy(base,i);
	}
	
	
		
	string s;
	getline(fin,s);
	int T = atoi(s.c_str());	
	
	for(int tt = 0; tt < T; tt++)
	{
		fout << "Case #" << tt+1 << ": ";
		getline(fin,s);
		
		stringstream in(s);
		vector<int> num;
		int tmp;
		while(in >> tmp)
			num.push_back(tmp);
		
		int done = -1;
		
		for(int j = 2; j < 100000; j++)
		{
			int ok = 1;
			for(int t = 0; t < num.size(); t++)
				if(happy[num[t]][j] == 0)
				{
					ok = 0;
					break;
				}
			if(ok)
			{
				done = j;
				break;
			}
		}
		if(done == -1) fout << "ERROR\n";
		else fout << done << endl;
		
	}

	return 0;
}
		
