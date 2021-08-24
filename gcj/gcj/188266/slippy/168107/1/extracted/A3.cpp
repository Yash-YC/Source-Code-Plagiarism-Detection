#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

#define NUM 300

bool seen[NUM];

int testhappy(int base, int i)
{	
	while(i >= NUM)
	{
		int ans = 0;
		while(i > 0)
			ans += (i%base)*(i%base), i /= base;
		i = ans;
	}	
	
	int orig = i;
	
	seen[i] = 1;
	int ans = 0;
	while(i > 0)
		ans += (i%base)*(i%base), i /= base;
	
	if(ans == 1) { seen[orig] = 0; return 1; }
	else if(seen[ans] == 1) {seen[orig] = 0; return 0; }
	else
	{
		int a = testhappy(base,ans); 
		seen[orig] = 0;
		return a;
	}
	
}


map<int,long long> M;


int main()
{
	ofstream fout("Aprecompute.txt");
	
	for(int tt = 1; tt < 512; tt++)
	{
		vector<int> num;
		for(int u = 0; u < 9; u++)
		if((tt>>u)%2 == 1)
			num.push_back(u+2);
		
		int mask = 0;
		for(int t = 0; t < num.size(); t++)
			mask += (1<<num[t]);
		fout << "M[" << mask << "] = ";
		
		if(M.find(mask) != M.end())
		{
			fout << M[mask] << endl;
			continue;
		}		
		
		long long j = 2;
		
		while(1)
		{
			for(int t = 0; t < num.size(); t++)
			{
				int a = testhappy(num[t],j);
				if(a == 0)
					j++, t = -1;
			}
			fout << j << ";\n";
			break;
		}
	}

	return 0;
}
		
