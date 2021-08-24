#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

const int mm=10000;

int a[1500], l;
double f[mm][1100];


int count(int x){
	int res =0;
	while (x!=0){
		res+=x&1;
		x>>=1;
	}
	return res;
}

int main(){
	freopen("C-small.in", "r", stdin);
	freopen("C-small.out", "w", stdout);
	int t; cin>>t;
	cout.precision(6);
	cout<<fixed;
	for (int o=0; o<t; o++)
	{
		int c, n;
		cin>>c>>n;
		l=0;
		int m=(1<<c);
		for (int i=0; i<m; i++)
			if (count(i)==n) a[l++]=i;
		memset(f,0, sizeof f);
		f[0][0]=1;
		for (int i=0; i<mm-1; i++)
			for (int j=0; j<m-1; j++)
				if (fabs(f[i][j])>1e-9)
				for (int k=0; k<l; k++)
					f[i+1][j|a[k]]+=f[i][j]/l;
		double res=0;
		for (int i=0; i<mm; i++)
			res+=i*f[i][m-1];
		cout<<"Case #"<<o+1<<": "<<res<<"\n";
	}
	return 0;
}