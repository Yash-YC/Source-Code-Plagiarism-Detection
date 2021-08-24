#include <stdio.h>
#include <iostream>
#include <sstream>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <string>

using namespace std;

#define infile ".in"
#define outfile ".out"
#define FOR(i, n) for (int i = 0; i <(n); i++)
#define DFOR(i, n) for (int i = (n) - 1; i >= 0; i--)
#define PB push_back
#define MP make_pair
#define ALL(x) x.begin(), x.end()
#define LL long long
#define SQR(x) ((x) * (x))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define CLR(a, b) memset((a), (b), sizeof(a))
#define SS stringstream
#define PII pair<int, int>
#define VPII vector < PII >

void init(){
	freopen(infile, "r", stdin);
	freopen(outfile, "w", stdout);
}

#define maxn 10

int n, m;
int s[maxn][maxn], w[maxn][maxn], t[maxn][maxn];
int commands;
int c[100];
int T;
int i,j,sost;

int bit(int x, int i){
	return ((x & (1<<i))!=0)?1:0;
}

void solvecase(){
	int ans = 1e9;
	commands = 2*n+2*m-2;
	FOR(mask, 1<<(2*commands)){
		FOR(i, commands) c[i] = 2*bit(mask, 2*i+1) + bit(mask, 2*i);
		bool good = true;
		FOR(i, commands)if(i) if(c[i]==c[i-1]) good = false;
		if(!good) continue;
		T = 0;
		i = j = sost = 0;
		FOR(k, commands){
			if(i>=n || j>=m) {good=false; break;}
			if(sost==0 && c[k]>=2){good=false; break;}
			if(sost==1 && (c[k]==1 || c[k]==2)){good=false; break;}
			if(sost==2 && (c[k]==0 || c[k]==3)){good=false; break;}
			if(sost==3 && (c[k]<=1)){good=false; break;}

			if(c[k]==0){
				//.....
				int wait = T-t[i][j];
				int mod = s[i][j]+w[i][j];
				wait %= mod;
				if(wait<0) wait+=mod;
				if(wait>=s[i][j]) T+=(mod-wait);
				T++;
				sost+=2;				
			}
			if(c[k]==1){
				//...
				int wait = T-t[i][j];
				int mod = s[i][j]+w[i][j];
				wait %= mod;
				if(wait<0) wait+=mod;
				if(wait<s[i][j]) T+=(s[i][j]-wait);

				T++;
				sost++;
			}

			if(c[k]==2){
				i++;
				T+=2;
				sost-=2;
			}
			if(c[k]==3){
				j++;
				T+=2;
				sost--;
			}
		}
		if(!good) continue;
		if((i==n-1) && (j==m-1) && (sost==3)) ans = min(ans, T);
	}
	cout << ans;
}

void solve(){
	int C;
	cin >> C;
	FOR(q, C){
		printf("Case #%d: ", q+1);
		cin >> n >> m;
		FOR(i, n) FOR(j, m) cin >> s[i][j] >> w[i][j] >> t[i][j];
		FOR(i, n/2) FOR(j, m){
			swap(s[i][j], s[n-i-1][j]);
			swap(w[i][j], w[n-i-1][j]);
			swap(t[i][j], t[n-i-1][j]);
		}
		solvecase();
		printf("\n");
	}

}

int main(){
	init();
	solve();
	return 0;
}