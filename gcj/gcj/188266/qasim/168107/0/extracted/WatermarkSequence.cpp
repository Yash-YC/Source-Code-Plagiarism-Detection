#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <queue>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>

using namespace std;

bool happy(int i,int b)
{
	int k = 0;
	int sum=0;
	int n=i;
	while(k<100)
	{
		sum = 0;
		while (n) 
		{
		  sum+=(n%b)*(n%b);
		  n/=b;
		}
		if(sum == 1)
			return true;
		k++;
		n=sum;
	}
	return false;
}

int getN(vector<int> bases)
{
	int k = 2;
	while(k<100000)
	{
		int i;
		for(i = 0;i<bases.size();i++)
		{
			if(!happy(k,bases[i]))
			{
				break;
			}
		}
		if(i == bases.size())
		{
			return k;
		}
		k++;
	}
	return -1;

}

int main()
{
	ifstream ifs("small.in",ios::in);
	ofstream cout("small.out",ios::out);
	char str[1000]="";
	ifs.getline(str,1000);
	int n = atoi(str);
	for(int i = 0;i<n;i++)
	{
		ifs.getline(str,1000);
		stringstream ss(str);
		vector<int> v;
		int k;
		while(ss>>k)
		{
			v.push_back(k);
		}
		cout<<"Case #"<<(i+1)<<": "<<getN(v)<<""<<endl;

	}

}