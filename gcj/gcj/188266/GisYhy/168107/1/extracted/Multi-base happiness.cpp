

#include <iostream>
using namespace std;

bool rel[11][50000000];
bool sign[11][50000000];
int ok(int base,int num);
int main()
{
	freopen("E://A-large.in","r",stdin);
	//freopen("E://yhy.txt","r",stdin);
	freopen("E://yyy.txt","w",stdout);
	int t=1,T;
	memset(rel,false,sizeof(rel));
	memset(sign,false,sizeof(sign));
	cin>>T;
	char c[20];
	cin.getline(c,20);
	while(t<=T)
	{
		cin.getline(c,20);
		int p[10],k=-1;
		for(int i=0;c[i];i++)
		{
			if(c[i]!=' ')
			{
				if(c[i]=='1')
				{
					p[++k]=10;
					i++;
				}
				else
					p[++k]=c[i]-'0';
			}
		}
		int x;
		for(x=2;;x++)
		{
			bool b=true;
			for(int i=0;i<=k;i++)
			{
				if(rel[p[i]][x] || ok(p[i],x)==1)
					rel[p[i]][x]=true;
				else
				{
					b=false;
					break;
				}
			}
			if(b)break;
		}
		cout<<"Case #"<<t<<": "<<x<<endl;
		t++;
	}
	return 0;
}
int ok(int base,int num)
{
	if(num==1 || rel[base][num])return 1;
	if(sign[base][num])return -1;
	int p,sum=0;
	sign[base][num]=true;
	while(num)
	{
		p=num%base;
		sum+=p*p;
		num/=base;
	}
	if(ok(base,sum)==1)
		rel[base][sum]=true;
	return rel[base][sum];
}