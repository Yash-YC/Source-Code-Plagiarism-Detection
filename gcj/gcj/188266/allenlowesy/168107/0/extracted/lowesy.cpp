#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool vst[100005];
int B[10],T,cas;
char str[100];
bool app[100005][10];

bool isHappy(int num,int base)
{
	int k=num;
	memset(vst,false,sizeof(vst));
	while(true)
	{
		string s="";
		int l=0;
		vst[k]=true;
		while(k)
		{
			l+=(k%base)*(k%base);
			k/=base;
		}
		while(l)
		{
			s+='0'+l%base;
			l/=base;
		}
		k=0;
		for(int i=s.size()-1;i>=0;i--)
			k=k*base+s[i]-'0';
		if(k==1) return true;
		else if(vst[k]) break;
	}
	return false;
}

int main()
{
	freopen("d://A-small-attempt1.in","r",stdin);
	freopen("d://1.txt","w",stdout);
	for(int i=2;i<=10;i++)
	{
		for(int j=2;j<=100000;j++)
			if(isHappy(j,i)) app[j][i-1]=true;
	}
	scanf("%d",&T);
	getchar();
	int cn=0,cas=1;
	while(T--)
	{
		cn=0;
		int num=0;
		gets(str);
		for(int i=0;str[i];i++)
		{
			if(str[i]==' ')
			{
				if(num) B[cn++]=num;
				num=0;
			}
			else if(str[i]>='0'&&str[i]<='9')
				num=num*10+str[i]-'0';
		}
		if(num) B[cn++]=num;
		int res;
		for(int i=2;i<=100000;i++)
		{
			bool f=true;
			for(int j=0;j<cn&&f;j++)
			{
				if(!app[i][B[j]-1])
					f=false;
			}
			if(f) { res=i; break; }
		}
		printf("Case #%d: %d\n",cas++,res);
	}
	return 0;
}
