#include"stdafx.h"


#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <ctime>
#include <fstream>
//#include <windows.h>
using namespace std;
using std::vector;

typedef unsigned long long int64;
//typedef vector<int,int,int> v3i;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

#define _CRT_SECURE_NO_WARNINGS
#define For(i,a,b) for (int64 i(a),_b(b); i <= _b; ++i)
#define Ford(i,a,b) for (int64 i(a),_b(b); i >= _b; --i)
#define Rep(i,n) for (int64 i(0),_n(n); i < _n; ++i)
#define Repd(i,n) for (int64 i((n)-1); i >= 0; --i)
#define Fill(a,c) memset(&a, c, sizeof(a))
#define MP(x, y) make_pair((x), (y))
#define All(v) (v).begin(), (v).end()

int64 ans=0;

template<typename T, typename S> T cast(S s)
{
	stringstream ss;
	ss << s;
	T res;
	ss >> res;
	return res;
}


int L,D,N;

int main()
{
	ifstream fin("ReadMe.txt");
	fin>>N;
	ofstream fout("out.txt");
	char str[2000];
	//fin.getline(str,1000);
	
		fin.getline(str,2000);
	Rep(ti,N)
	{
		int fi[20],size=0;				
		string s;
		getline(fin,s);
		istringstream ss(s);
		int t;
		while(ss>>t) 
		{
			fi[size++]=t;
		}
		
		
		for(int j=2;j<1e6;j++)
		{
			int sod,i;
			int chk=1;
			for(i=0;i<size;i++)
			{
				int base=fi[i];
				int no=j;
				int prev[1000],prevno=0;
				while(1)
				{
					sod=0;
					int bcup=no;
					prev[prevno++]=no;
					for(int k=0;no>0;no/=base,k++)
						sod+=(no%base)*(no%base);
					
					if(find(prev,prev+prevno,sod)!=(prev+prevno) || sod==1)
						break;
					else
						prev[prevno++]=sod;
					no=sod;
				}
				if(sod!=1)
				{
					chk=0;
					break;
				}
			}
			if(chk==1)
			{
				ans=j;
				break;
			}

		}
	
		
		fout<<"Case #"<<ti+1<<": "<<ans<<endl;
		cout<<"Case #"<<ti+1<<": "<<ans<<endl;
	}
	fin.close();
	fout.close();
	getchar();
	return 0;
}