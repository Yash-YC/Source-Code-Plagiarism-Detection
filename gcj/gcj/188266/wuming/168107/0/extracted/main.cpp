//pku
#include "iostream"
#include "sstream"
#include "iomanip"
#include "algorithm"
#include "string"
#include "functional"
#include "list"
#include "vector"
#include "stack"
#include "deque"
#include "set"
#include "map"
#include "utility"
#include "numeric"
#include "cmath"
using namespace std;

#define min(a, b) ((a)<(b)?(a):(b))
#define min3(a, b, c) ((a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c)))
#define max(a, b) ((a)>(b)?(a):(b))
#define max3(a, b, c) ((a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c)))

#define INF 0x7fffffff
#define Pi acos(-1.0)
#define  Eps 1e-6

#ifdef _GNUC_
#define int64 long long
#define Printf64(n) printf("%lld\n", n)
#else /* MSVC, say */
#define int64 __int64
#define Printf64(n) printf("%I64d\n", n)
#endif 

#define MAX 50001

int dp[11][MAX];
char flag[MAX];

void Wuming()
{
#ifndef ONLINE_JUDGE 
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout); 
#endif 
}

void init()
{
	int i, j, k, m, n;

	char buff[128];
	stack<int> s;

	for(int base=2; base<11; ++base)
	{
		dp[base][1]=1;
		for(int n=2; n<MAX; ++n)
		{
			m=n;
			while(m!=1 && dp[base][m]==0 && !flag[m])
			{
				flag[m]=true;
				s.push(m);
				itoa(m, buff, base);
				m=0;
				for(i=0; buff[i]; ++i)
					m+=(buff[i]-'0')*(buff[i]-'0');
			}
			if(dp[base][m]==0)
				dp[base][m]=-1;					
			while(!s.empty())
			{
				dp[base][s.top()] = dp[base][m];
				flag[s.top()]=false;
				s.pop();
			}
		}
	}

//	for(base=2; base<11; ++base)
//	{
//		int pos=0;
//		for(i=2; i<MAX; ++i)
//			if(dp[base][i]==1)
//				dp[base][pos++]=i;
//	}
}

int main()
{
	int i, j, k, n, m,  test, cnt=0;

	init();

	Wuming();
	char buff[128];

	stack<int> s;

	scanf("%d\n", &test);
	int outT=0;
	while(test--)
	{
		int base[12], bCnt=0;
		gets(buff);
		istringstream strbuf(buff);
		while(strbuf>>base[bCnt]) ++bCnt;

		//int p[11]={0};
		int pos=2;
		while(1)
		{
			for(i=0; i<bCnt; ++i)
				if(dp[base[i]][pos]!=1) break;
			if(i>=bCnt) break;
			++pos;
		}
		printf("Case #%d: %d\n", ++outT, pos);
	}

	return 0;
}

