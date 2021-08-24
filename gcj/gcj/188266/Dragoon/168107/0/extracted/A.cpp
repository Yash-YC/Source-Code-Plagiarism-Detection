#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
#include<stack>
#include<string.h>
#include<string>
#include<map>
#include<sstream>
using namespace std;

#define MIN(A,B) ((A) < (B) ? (A) : (B))
#define MAX(A,B) ((A) > (B) ? (A) : (B))
#define S(X) ((X)*(X))
#define ABS(X) ((X) > 0 ? (X) : (-(X)))

vector<int> V;
char line[1000];
int mark[100000];
int pp=0;

int convertTo10(int x,int base)
{
	int ans = 0, b=1,t;
	while(x)
	{
		t = x%10;
		x/=10;
		ans+=t*b;
		b*=base;
	}

	return ans;
}

int convertToB(int num,int base)
{
	int real=0,b=1;
	while(num)
	{
		int x = num%base;
		num/=base;
		real+=x*b;
		b*=10;
	}

	return real;
}


int OK(int num,int base)
{
	pp++;

	int real,x,t;

	real = convertToB(num,base);

	memset(mark,0,sizeof(mark));

	while(1)
	{
		if(mark[num]==pp) return 0;

		mark[num]=pp;
		num=0;
		while(real)
		{
			x=real%10;
			real/=10;
			t=convertTo10(x,base);
			num+=t*t;
		}

		real = convertToB(num,base);

		if(real==1) return 1;
	}

}

int main()
{
	freopen("a.out","w",stdout);

	int T,ks,a,sz,i,ok,j;

	gets(line);
	sscanf(line,"%d",&T);
	for(ks=1;ks<=T;ks++)
	{
		gets(line);
		istringstream iS(line);
		V.clear();
		while(iS>>a)
		{
			V.push_back(a);
		}

		sz=V.size();
		for(i=2;;i++)
		{
			ok=1;
			for(j=0;j<sz && ok;j++)
				if(!OK(i,V[j]))
					ok=0;

			if(ok) break;
		}

		printf("Case #%d: %d\n",ks,i);

	}


	return 0;
}