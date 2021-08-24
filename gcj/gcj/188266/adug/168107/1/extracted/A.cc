#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int hp[100000][9]={0};
int check(int t,int a)
{
	int m,s=0,b=a+2,tt=t;
	while (tt>0)
	{
		m=tt%b;
		s+=m*m;
		tt/=b;
	}
	if (s==t) hp[t][a]=-1;
	if (hp[s][a]==1 || hp[s][a]==-1) hp[t][a]=hp[s][a]; 
	else 
	{
		if (hp[s][a]==2) hp[t][a]=-1;
		if (hp[s][a]==0) 
		{
			hp[t][a]=2;
			check(s,a);
			hp[t][a]=hp[s][a];
		}
	}
	return 0;
}
int main()
{
	int i,j,ri,rp,bs[9],bc,k;
	stringstream ss;
	string st;
	for (i=0;i<9;i++)
	{
		hp[0][i]=-1;
		hp[1][i]=1;
	}
	for (i=2;i<100000;i++)
	{
		int t=i,m,s=0;
		for (j=0;j<9;j++)
		{
			if (!hp[i][j]) check(i,j);
		}
	}
	/*for (i=2;i<200;i++)
	{
		for (j=0;j<9;j++)
			if (hp[i][j]==1) cout<<i<<", "; else cout<<" , ";
		cout<<endl;
	}*/
	cin>>rp;
	getline(cin,st);
	for (ri=0;ri<rp;ri++)
	{
		getline(cin,st);
		ss.clear();
		ss<<st;
		bc=0;
		while (ss>>bs[bc]) bc++;
		for (i=2;i<11814486;i++)
		{
			for (k=0;k<bc;k++)
			{
				int j=bs[k];
				int m,s=0,b=j,t=i;
				while (t>0)
				{
					m=t%b;
					s+=m*m;
					t/=b;
				}
				if (hp[s][j-2]!=1) break;
			}
			if (k==bc) {cout<<"Case #"<<ri+1<<": "<<i<<endl;break;}
		}
	}
	return 0;
}
			
	
			