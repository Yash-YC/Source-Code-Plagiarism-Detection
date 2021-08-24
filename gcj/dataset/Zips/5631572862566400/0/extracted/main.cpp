#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define max_N 1003
using namespace std;

int T;
int N;
int TO[max_N];
int cyc[max_N];
int ST[max_N];
int top;

void findcyc(int j){
	int isin = 0;
	for(int i=0; i<top; i++){
		if(ST[i] == j) isin = i;
	}
	if(isin != 0){
		for(int i=0; i<isin; i++)
			cyc[ST[i]] = 0;
		for(int i=isin; i<top; i++)
			cyc[ST[i]] = top - isin;
		return;
	}
	ST[top] = j;
	top++;
	findcyc(TO[j]);
}

int dept(int j){
	int r = 1;
	for(int i=1; i<=N; i++){
		if(TO[i] == j && TO[j] != i ){
			if(r < dept(i) + 1) r = dept(i) + 1;
		}
	}
	return r;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int ans;
	int t;

	scanf("%d", &T);

	for(int i=0; i<T; i++){
		scanf("%d", &N);
		for(int j=1; j<=N; j++){
			scanf("%d", &TO[j]);
			cyc[j] = -1;
		}
		printf("Case #%d: ", i+1);

		for(int j=1; j<=N; j++){
			if(cyc[j]==-1){
				top = 0;
				findcyc(j);
			}
		}

		ans = 0;
		for(int j=1; j<=N; j++){
			if(ans<cyc[j]) ans = cyc[j];
		}

		t=0;

		for(int j=1; j<=N; j++){
			if(cyc[j] == 2){
				t += dept(j) + dept(TO[j]);
			}
		}
		t /=2;
			if(ans<t) ans = t;

		printf("%d\n", ans);
	}

	return 0;
}
