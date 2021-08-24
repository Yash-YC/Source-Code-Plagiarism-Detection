#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<map>
#include<cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)

/*long long buscar_cota(long long b)
{
	long long i;
	for(i=1;i<10;i++)
	{
		cout<<(i*(b-1)*(b-1)-(long long)(pow)(b,i)+1)<<endl;
		if((i*(b-1)*(b-1)-(long long)(pow)(b,i)+1)*((i+1)*(b-1)*(b-1)-(long long)(pow)(b,i+1)+1)<=0)break;
	}
	return i;
}*/

bool data[12000000][11];

long long reemplazo(long long x,int b)
{
	long long res=0;
	while(x>0)
	{
		res+=(x%b)*(x%b);
		x/=b;
	}
	return res;
}

bool is_happy(long long x,int b)
{
	map<long long,long long> m;
	m[x]++;
	while(true)
	{
		x=reemplazo(x,b);
		if(m[x]==0)m[x]++;else return false;
		if(x==1)return true;
	}
	return false;
}

int load()
{
	int i,j;
	for(i=2;i<12000000;i++)for(j=2;j<11;j++)data[i][j]=is_happy(i,j);
}

int main()
{
	int nc,c,a;
	fstream ff("A-large.in");
	load();
	cerr<<"ready?"<<endl;
	cin>>a;
	string s;
	vector<int>bs;
	ff>>nc;getline(ff,s);
	for(c=0;c<nc;c++)
	{
		long long x=2;
		getline(ff,s);
		stringstream ss;
		ss<<s;
		bs.clear();
		while(ss>>a)bs.pb(a);
		while(true)
		{
			for(a=0;a<bs.size();a++)if(!data[x][bs[a]])break;
			if(a==bs.size())
			{
				cout<<"Case #"<<c+1<<": "<<x<<endl;
				break;
			}
			x++;
			//if(x%1000000==0)cerr<<"procesando "<<x<<endl;
		}
	}
	return 0;
}
