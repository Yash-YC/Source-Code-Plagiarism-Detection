#include<cstdio>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

int Ans[512]=
{
	0,
	2,
	3,
	3,
	2,
	2,
	3,
	3,
	5,
	5,
	23,
	23,
	5,
	5,
	23,
	23,
	6,
	6,
	79,
	79,
	6,
	6,
	79,
	79,
	49,
	49,
	79,
	79,
	49,
	49,
	79,
	79,
	7,
	7,
	143,
	143,
	7,
	7,
	143,
	143,
	7,
	7,
	143,
	143,
	7,
	7,
	143,
	143,
	49,
	49,
	2207,
	2207,
	49,
	49,
	2207,
	2207,
	49,
	49,
	2207,
	2207,
	49,
	49,
	2207,
	2207,
	8,
	8,
	27,
	27,
	8,
	8,
	27,
	27,
	27,
	27,
	27,
	27,
	27,
	27,
	27,
	27,
	216,
	216,
	3879,
	3879,
	216,
	216,
	3879,
	3879,
	1975,
	1975,
	3879,
	3879,
	1975,
	1975,
	3879,
	3879,
	1001,
	1001,
	5719,
	5719,
	1001,
	1001,
	5719,
	5719,
	1001,
	1001,
	5719,
	5719,
	1001,
	1001,
	5719,
	5719,
	47089,
	47089,
	47089,
	47089,
	47089,
	47089,
	47089,
	47089,
	48769,
	48769,
	58775,
	58775,
	48769,
	48769,
	58775,
	58775,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	27,
	27,
	27,
	27,
	27,
	27,
	27,
	27,
	415,
	415,
	707,
	707,
	415,
	415,
	707,
	707,
	415,
	415,
	1695,
	1695,
	415,
	415,
	1695,
	1695,
	125,
	125,
	143,
	143,
	125,
	125,
	143,
	143,
	125,
	125,
	143,
	143,
	125,
	125,
	143,
	143,
	2753,
	2753,
	37131,
	37131,
	2753,
	2753,
	37131,
	37131,
	37131,
	37131,
	37131,
	37131,
	37131,
	37131,
	37131,
	37131,
	27,
	27,
	27,
	27,
	27,
	27,
	27,
	27,
	27,
	27,
	27,
	27,
	27,
	27,
	27,
	27,
	4977,
	4977,
	10089,
	10089,
	4977,
	4977,
	10089,
	10089,
	4977,
	4977,
	23117,
	23117,
	4977,
	4977,
	23117,
	23117,
	6393,
	6393,
	35785,
	35785,
	6393,
	6393,
	35785,
	35785,
	6393,
	6393,
	128821,
	128821,
	6393,
	6393,
	128821,
	128821,
	569669,
	569669,
	569669,
	569669,
	569669,
	569669,
	569669,
	569669,
	569669,
	569669,
	569669,
	569669,
	569669,
	569669,
	569669,
	569669,
	7,
	7,
	13,
	13,
	7,
	7,
	13,
	13,
	7,
	7,
	23,
	23,
	7,
	7,
	23,
	23,
	44,
	44,
	79,
	79,
	44,
	44,
	79,
	79,
	49,
	49,
	79,
	79,
	49,
	49,
	79,
	79,
	7,
	7,
	167,
	167,
	7,
	7,
	167,
	167,
	7,
	7,
	7895,
	7895,
	7,
	7,
	7895,
	7895,
	49,
	49,
	6307,
	6307,
	49,
	49,
	6307,
	6307,
	49,
	49,
	7895,
	7895,
	49,
	49,
	7895,
	7895,
	97,
	97,
	219,
	219,
	97,
	97,
	219,
	219,
	219,
	219,
	219,
	219,
	219,
	219,
	219,
	219,
	608,
	608,
	3879,
	3879,
	608,
	608,
	3879,
	3879,
	3879,
	3879,
	3879,
	3879,
	3879,
	3879,
	3879,
	3879,
	34527,
	34527,
	48041,
	48041,
	34527,
	34527,
	48041,
	48041,
	34527,
	34527,
	120407,
	120407,
	34527,
	34527,
	120407,
	120407,
	245035,
	245035,
	697563,
	697563,
	245035,
	245035,
	697563,
	697563,
	245035,
	245035,
	2688153,
	2688153,
	245035,
	245035,
	2688153,
	2688153,
	91,
	91,
	91,
	91,
	91,
	91,
	91,
	91,
	91,
	91,
	91,
	91,
	91,
	91,
	91,
	91,
	1033,
	1033,
	6073,
	6073,
	1033,
	1033,
	6073,
	6073,
	4577,
	4577,
	6073,
	6073,
	4577,
	4577,
	6073,
	6073,
	1337,
	1337,
	1337,
	1337,
	1337,
	1337,
	1337,
	1337,
	29913,
	29913,
	120149,
	120149,
	29913,
	29913,
	120149,
	120149,
	71735,
	71735,
	613479,
	613479,
	71735,
	71735,
	613479,
	613479,
	218301,
	218301,
	711725,
	711725,
	218301,
	218301,
	711725,
	711725,
	1177,
	1177,
	1177,
	1177,
	1177,
	1177,
	1177,
	1177,
	1177,
	1177,
	1177,
	1177,
	1177,
	1177,
	1177,
	1177,
	9867,
	9867,
	28099,
	28099,
	9867,
	9867,
	28099,
	28099,
	28099,
	28099,
	28099,
	28099,
	28099,
	28099,
	28099,
	28099,
	48041,
	48041,
	48041,
	48041,
	48041,
	48041,
	48041,
	48041,
	246297,
	246297,
	346719,
	346719,
	246297,
	246297,
	346719,
	346719,
	2662657,
	2662657,
	4817803,
	4817803,
	2662657,
	2662657,
	4817803,
	4817803,
	11814485,
	11814485,
	11814485,
	11814485,
	11814485,
	11814485,
	11814485,
	11814485
};

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

void Pre_Build()
{
	for(int i=1;i<512;i++)
	{
		Base.clear();
		for(int j=0;j<9;j++) if(i&(1<<j)) Base.push_back(j+2);
		Ans[i]=2;
		for(int j=1;j<i;j++) if((i|j)==i) Ans[i]=max(Ans[i],Ans[j]);
		while(!OK(Ans[i])) Ans[i]++;
	}
}

int main()
{
	freopen("A-Large.in","r",stdin);
	freopen("A-Large.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int Case=1;Case<=T;Case++)
	{
		int N=0;
		Base.clear();
		while(true)
		{
			int B;
			scanf("%d",&B);
			Base.push_back(B);
			N |=1<<(B-2);
			if(getchar()=='\n') break;
		}
		printf("Case #%d: %d\n",Case,Ans[N]);
	}
	return 0;
}