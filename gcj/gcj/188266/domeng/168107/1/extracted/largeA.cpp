#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <stdio.h>
#include <map>
using namespace std;
typedef long long ll;
map<int,int> real;

int calc(int& b,int x)
{
	int ret=0,m;
	while (x)
	{
		m=x%b;
		ret+=m*m;
		x/=b;
	}
	return ret;
}

int val[12000005];
int buff[12000005];
int rev[12000005];
int ans[1000];
void preproc()
{
	for (int b=2;b<=10;++b)
	{//11814485
		fprintf(stderr,"%d",b);
		for (int q=2;q<=12000000;++q) 
		{
			buff[q]=0;
			rev[q]=0;
		}
		buff[1]=1;
		for (int q=2;q<=12000000;++q)
		{
			if (q%1000000==0) fprintf(stderr,".");
			int x=calc(b,q);
			while (x>=q)
			{
				if (rev[x]==q) break;
				rev[x]=q;
				x=calc(b,x);
			}
			if (x<q) buff[q]=buff[x];
			if (buff[q]) val[q] |= 1<<(b-2);
		}
		fprintf(stderr,"\n");
	}
	for (int q=2;q<=12000000;++q)
		if (val[q] && ans[val[q]]==0) 
			ans[val[q]]=q;
			
}

int main()
{
	preproc();
	string str;
	int T;
	while (true)
	{
		getline(cin,str);
		stringstream slo(str);
		if (slo >> T) break;
	}
	for (int Kase=1;Kase<=T;Kase++)
	{
		vector<int> vec;
		getline(cin,str);
		stringstream slo(str);
		int x,flag=0;
		while (slo >> x) flag |= 1<<(x-2);
		int best=0;
		for (int q=0;q<512;q++)
			if (ans[flag|q])
				if (!best || ans[flag|q]<best)
					best=ans[flag|q];
		cout << "Case #" << Kase <<": " << best << endl;
	}
	return 0;
}
