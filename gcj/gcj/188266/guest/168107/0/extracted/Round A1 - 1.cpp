#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
using namespace std;
#define N 100
//#define P 20000
bool no[10241024]={0};
bool vst[10241024]={0};
int main()
{
	int n,base[11],b;
	char str[100],line[1000];
	int t,ans,c;
	int x,y,z;
	int sum,r,tsum,s;
	bool yn;
	//stack<int> sta;
	FILE *fin=fopen("A-small.in","r"),*fout=fopen("A-small.out","w");
	fscanf(fin,"%d",&c);
	fgets(line,1000,fin);
	for(x=1;x<=c;++x)
	{
		fgets(line,1000,fin);
		ans=b=t=0;
		while(sscanf(line+t,"%s",str))
		{
			t+=strlen(str)+1;
			sscanf(str,"%d",&base[b++]);
			if(t>=strlen(line))
				break;
		}
		for(n=2;!ans;++n)
		{
			sum=n;
			yn=1;
			for(y=0;y<b && yn;++y)
			{
				//memset(vst,0,sizeof(vst));
				sum=n;
				for(r=0;r<4000;++r)
				{
					/*if(no[sum] || vst[sum])
					{
						yn=0;
						break;
					}
					vst[sum]=1;
					sta.push(sum);*/
					tsum=0;
					for(z=0;sum;++z)
					{
						s=sum%base[y];
						tsum+=s*s;
						sum/=base[y];
					}
					if(tsum==1)
						break;
					sum=tsum;
				}
				if(r==4000)
					yn=0;
				/*if(!yn)
				{
					while(!sta.empty())
					{
						no[sta.top()]=1;
						sta.pop();
					}
				}*/
			}
			if(yn)
			{
				fprintf(fout,"Case #%d: %d\n",x,n);
				break;
			}
		}
	}
	//scanf(" ");
	return 0;
}
