#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i,n) for (int i=0,_n=n; i<_n; i++)
#define FOR(i,a,b) for (int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for (int i=(a),_b=(b); i>=_b; i--)

#define MAXD 50

vector<int> arr[11][11];

double rec(int C, int N, int G, int len, double prob){
	//printf("%d %d %d %d %lf\n",C,N,G,len,prob);
	if ((1<<C)-1==G) return len * prob;
	if (prob < 1e-6) return prob;


	double ret = 0;
	vector<int> &a = arr[C][N];
	REP(i,a.size()){
		ret += rec(C,N,G|a[i], len+1, prob/a.size());
	}
	return ret;
}

int main(){
	REP(j,10){
		int C = j+1;
		REP(k,C+1){
			int N = k+1;
			REP(i,1<<C){
				if (__builtin_popcount(i)==N){
					arr[C][N].push_back(i);
				}
			}
		}
	}

	int nTC,C,N;
	scanf("%d",&nTC);
	FOR(TC,1,nTC){
		scanf("%d %d",&C,&N);
		double res = rec(C,N,0,0,1);
		fprintf(stderr,"Case #%d: %.7lf\n",TC,res);
		printf("Case #%d: %.7lf\n",TC,res);
	}
}
