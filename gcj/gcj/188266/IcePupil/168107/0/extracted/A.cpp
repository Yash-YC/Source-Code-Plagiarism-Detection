#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,b[20];
bool F[12][1000],Done[12][1000];

inline int Calc(int b,int n)
{
	int ret=0;
	for (;n;n/=b)
		ret+=(n%b)*(n%b);
	return ret;
}

inline bool DP(int b,int n)
{
	if (Done[b][n]) return F[b][n];
	Done[b][n]=1;
	int m=Calc(b,n);
	return F[b][n]=DP(b,m);
}

inline bool Check(int b,int n)
{
	if (n<1000) return F[b][n];
	return F[b][Calc(b,n)];
}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	for (int i=2;i<=10;i++) {
		Done[i][1]=F[i][1]=1;
		for (int j=2;j<1000;j++)
			DP(i,j);
	}
	int Test;
	scanf("%d",&Test);
	for (int Case=1;Case<=Test;Case++) {
		for (n=0;;n++) {
			char ch;
			scanf("%d%c",&b[n],&ch);
			if (ch!=' ') break;
		}
		n++;
		int ret=2;
		for (;;ret++) {
			bool flag=1;
			for (int i=0;i<n;i++)
			if (!Check(b[i],ret)) {
				flag=0;break;
			}
			if (flag) break;
		}
		printf("Case #%d: %d\n",Case,ret);
	}
	return 0;
}
