#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>    
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cfloat>
using namespace std;

double dp[1000][100];
long long comb[41][41];

int main(){
    int ts, c, n;
    freopen("input.txt","r",stdin); 
	freopen("output.txt","w",stdout);

	for(int i=0;i<=40;i++){
		comb[i][i] = 1;
		comb[i][0] = 1;
	}
	for(int i=0;i<=40;i++){
		for(int j=1;j<i;j++){
			comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
		}
	}
	
    scanf("%d\n",&ts);
	for(int st=1;st<=ts;st++){
		memset(dp,0,sizeof(dp));
		double ans = 0.0, tot = 0.0;
		scanf("%d %d",&c,&n);

		dp[0][0] = 1.0;
		for(int i=0;i<1000;i++){
			for(int j=0;j<=c;j++){
				for(int k=0;k<=j;k++){
					dp[i][j] += (double)comb[k][n-(j-k)] * (double)comb[c-k][j-k]/(double)comb[c][n] * dp[i-1][k];
				}
			}
			if(i >= 1){
				ans += i*(dp[i][c]-dp[i-1][c]);
			}
		}
		
		printf("Case #%d: %lf\n",st,ans);
    } 
    return 0;
}
