#include<bits/stdc++.h>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define FZ(n) memset((n),0,sizeof(n))
#define FMO(n) memset((n),-1,sizeof(n))
#define MC(n,m) memcpy((n),(m),sizeof(n))
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define FOR(x,y) for(__typeof(y.begin())x=y.begin();x!=y.end();x++)
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
// Let's Fight!

const int MAXN = 111;
const int MAXM = 10;
const int INF = 1029384756;

int N, M;
int arr[MAXN][MAXM];
int dp[MAXN*MAXN];
int ord[MAXN];

bool cmp(int a, int b)
{
  return arr[a][0] + arr[a][1] < arr[b][0] + arr[b][1];
}

void input()
{
  cin>>N>>M;
  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)
      cin>>arr[i][j];
}

int calc()
{
  if(M == 1)
  {
    int ans = 0;
    for(int i=0; i<N; i++)
      ans += max(arr[i][0], 0);
    return ans;
  }

  int a[4], b[4];
  for(int i=0; i<4; i++)
    a[i] = b[i] = 0;

  for(int i=0; i<MAXN*MAXN; i++)
    dp[i] = -INF;
  dp[0] = 0;

  for(int i=0; i<N; i++)
    ord[i] = i;
  sort(ord, ord+N, cmp);

  for(int ii=0; ii<N; ii++)
  {
    int i = ord[ii];
    int state = (arr[i][0]>=0) * 2 + (arr[i][1]>=0);
    a[state] += arr[i][0];
    b[state] += arr[i][1];

    int x = arr[i][0], y = arr[i][1];
    if(state == 2)
    {
      assert(x>=0&&y<0);
      for(int j=MAXN*MAXN-1-x; j>=0; j--)
      {
        if(dp[j] < 0) continue;
        int v = max(0, dp[j] + y);
        dp[j+x] = max(dp[j+x], v);
      }
    }
    else if(state == 1)
    {
      for(int j=0; j<MAXN*MAXN; j++)
      {
        int k = max(0, j+x);
        dp[k] = max(dp[k], dp[j] + y);
      }
    }
  }

  int q = 0;
  for(int i=0; i<MAXN*MAXN; i++)
  {
    q = max(q, i+dp[i]);
  }

  int ans = (a[3]+b[3]) + q;
  return ans;  
}

int main(int argc, char** argv)
{
  IOS;
  int T;
  cin>>T;
  int nT = atoi(argv[1]);
  for(int i=1; i<=nT; i++)
    input();

  int ans = calc();
  cout<<"Case #"<<nT<<": "<<ans<<endl;

	return 0;
}
