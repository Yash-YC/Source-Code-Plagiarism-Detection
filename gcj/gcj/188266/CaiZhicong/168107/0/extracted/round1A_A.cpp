#include <iostream>
#include <sstream>
using namespace std;
int strToInt(string s) { istringstream sin(s); int r; sin >> r; return r;} 
int b[3];
int t = 0;
int T;
string line;
char pl[10];
int table[11][11];
int table2[11][11][11];
// 10 -> b
string chg(int n, int b)
{// 14 ,3 --- > 112
	string nn = "";
	int s = 1;
	while(n)
	{
		int t = n%b;
		n/=b;
		nn = char(t+'0')+nn;
		s*=10;
	}
	return nn;
}

//int fchg(int n,int b)
//{
//	if( b==10) return n;
//	int ret = 0;
//	int t = 1;
//	int s = 1;
//	while(n)
//	{
//		int t = n%10;
//		n/=10;
//		ret = t*s + ret;
//		s *= 10;
//	}
//	return ret;
//}

bool happy(int n,int b)
{
	bool tag[301];
	//memset(tag,0,sizeof(tag));
	string sn = chg(n,b);
	//while(tag[fchg(n,b)]==0)
	for(int g = 0; g< 50; ++g)
	{
	//	tag[fchg(n,b)] = true;
		n = 0;
		for(int i = 0; i< sn.length(); ++i) n += (sn[i]-'0')*(sn[i]-'0');
		if(n==1) return true;
		sn = chg(n,b);
	}
	return false;
}

bool ok(int n)
{
	for(int i = 0; i< t; ++i)
	{
		if(happy(n,b[i]) == false) return false;
	}
	return true;
}
int GetHappy(int i,int j)
{
	return 0;
}
void SetTable()
{

	for(int i = 2; i<= 10; ++i)
	{
		for(int j = 2; j<= 10; ++j)
		{
			table[i][j] = GetHappy(i,j);
		}
	}
}
int main()
{
	
	scanf("%d",&T);
	//if(happy(T,7)) cout << "YES\n";
	//else cout << "NO\n";
	//SetTable();
	getchar();
	for(int u = 0; u< T; ++u)
	{
		gets(pl);
		line = pl;
		istringstream sin(line);
		int tmp;
		t = 0;
		while(sin >> tmp)
		{
			b[t++] = tmp;
		}
		int ans = 2;
		while(true)
		{
			if(ok(ans)) break;
			ans ++;
		}
		printf("Case #%d: %d\n",u+1,ans);
	}
}