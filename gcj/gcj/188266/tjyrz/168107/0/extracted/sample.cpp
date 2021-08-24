#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	fstream inf,outf;
	inf.open("F:\A-small-attempt1.in", ios::in);
	outf.open("F:\out.txt", ios::out);
	
	string in;
	
	int T;
	inf >> T;
	getline(inf, in);
	int base[10];
	
	set <int> memo;
	for(int c=1; c<=T; ++c)
	{
		getline(inf, in);
		istringstream is(in);
		int t;
		int p =0;
		while(is >> t)
		{
			base[p++] = t;
		}
		
		int num;
		for(num = 2; ; num++)
		{
			bool flag = 1;
			int tn;
			int bn;
			for(int i=0; i<p; i++)
			{
				tn = num;
				bn = 0;
				int tt =1;
				while(tn>0)
				{
					bn += (tn%base[i]) * tt;
					tt *= 10;
					tn /= base[i];
				}
				memo.clear();
				memo.insert(bn);
				while(bn!=1)
				{          
					int t =0;
					while(bn>0)
					{
						t += (bn%10)*(bn%10);
						bn /= 10;
					}
					if(t==1)
					{
						break;
					}
					else if(memo.find(t)!=memo.end())
					{
						flag = 0;
						break;
					}		
					memo.insert(t);		
					bn = 0;
					int tt =1;				
					while(t>0)
					{
						bn += (t%base[i]) * tt;
						tt *= 10;
						t /= base[i];
					}
				//	  cout << bn << " ";
				}	
				if(flag == 0) break;
			}
			if(flag)
			{
				break;
			}
	//		cout << num << endl;
			
		}
		outf << "Case #" << c << ": " << num << endl;
	//	cout << "Case #" << c << ": " << num << endl;
	}		
	return 0;
}
