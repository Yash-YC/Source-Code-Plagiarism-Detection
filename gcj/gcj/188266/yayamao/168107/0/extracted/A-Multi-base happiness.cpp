#include<cstdio>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

vector<int> Base;

string To_BASE_string(int N,int BASE)
{
	string Ans="";
	while(N)
	{
		Ans+=N%BASE+'0';
		N/=BASE;
	}
	for(int i=0;i<Ans.length()/2;i++) swap(Ans[i],Ans[Ans.length()-i-1]);
	return Ans;
}

int To_Next(string s)
{
	int Ans=0;
	for(int i=0;i<s.length();i++) Ans+=(s[i]-'0')*(s[i]-'0');
	return Ans;
}

bool Fit(int N,int BASE)
{
	string s=To_BASE_string(N,BASE);
	bool Hash[1000]={0};
	int Next=To_Next(s);
	Hash[Next]=true;
	while(Next!=1)
	{
		s=To_BASE_string(Next,BASE);
		Next=To_Next(s);
		if(Hash[Next]) return false;
		Hash[Next]=true;
	}
	return true;
}

bool OK(int N)
{
	for(int i=0;i<Base.size();i++) if(!Fit(N,Base[i])) return false;
	return true;
}

int main()
{
	freopen("A-Small.in","r",stdin);
	freopen("A-Small.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int Case=1;Case<=T;Case++)
	{
		Base.clear();
		while(true)
		{
			int B;
			scanf("%d",&B);
			Base.push_back(B);
			if(getchar()=='\n') break;
		}
		int Ans=2;
		while(!OK(Ans)) Ans++;
		printf("Case #%d: %d\n",Case,Ans);
	}
	return 0;
}