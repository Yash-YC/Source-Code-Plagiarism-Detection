#include<stdio.h>
#include<sstream>
using namespace std;
char p[11][11814486];
bool find(int i,const int &j)
{
	//printf("%d %d\n",i,j);
	if(p[j][i])return (p[j][i]>0);
	int ii=i;
	p[j][i]=-1;
	int r=0;
	for(;i;i/=j)r+=(i%j)*(i%j);
	if(find(r,j))p[j][ii]=1;
	return (p[j][ii]>0);
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	for(int i=2;i<11;i++)p[i][1]=1;
	for(int i=2;i<11814486;i++)for(int j=2;j<11;j++)find(i,j);
	int t;
	scanf("%d",&t);
	char s[100];
	gets(s);
	for(int tt=1;tt<=t;tt++)
	{
		gets(s);
		string st(s);
		istringstream in(st);
		int n=0,z[10];
		while(in>>z[n])n++;
		for(int i=2;i<11814486;i++)
		{
			int j=0;
			for(;j<n;j++)if(p[z[j]][i]<0)break;
			if(j==n)
			{
				printf("Case #%d: %d\n",tt,i);
				break;
			}
		}
	}
}
