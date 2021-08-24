#include<stdio.h>
#include<string.h>


const int MAXN = 450000;
int base[5000000];
int flag[9][MAXN];
char ff[MAXN];
int num[2*MAXN];
int solve(void)
{
	int i, j, c=0;
	do{
		scanf("%d", &base[c]);
		c++;
	} while(getchar()==' ');
	
	for(i=2; i<MAXN; i++){
		for(j=0; j<c; j++)
			if(flag[base[j]-2][i]==0)
				break;
		if(j==c) break;
	}
	return i;
}

bool  dfs(int b, int x)
{
	int c, k, sum;
	if(x==1) return true;
	if(ff[x]==0) ff[x] = 1;
	else return false;
	c = 0;
	k = x;
	while(k){
		num[c++] = k%b;
		k/=b;
	}
	for(k=sum=0; k<c; k++)
		sum += num[k]*num[k];
	if(sum>=MAXN || flag[b-2][sum]==-1){
		if(dfs(b, sum)){
			if(sum<MAXN)
				flag[b-2][sum] = 1;
			return true;
		}
		else{
			if(sum<MAXN)
				flag[b-2][sum] = 0;
			return false;
		}
	}
	return (flag[b-2][sum]==1)?true:false;
}

void initialize(void)
{
	int i, j;
	for(i=2; i<11; i++){
		memset(flag+i-2, -1, sizeof(int)*MAXN);
		flag[i-2][1] = 1;
		for(j=2; j<MAXN; j++)
			if(flag[i-2][j]==-1){
				memset(ff, 0, sizeof(ff));
				if(dfs(i, j)) flag[i-2][j] = 1;
				else flag[i-2][j] = 0;
			}
	}
	return;
}

int main()
{
	int t, i;
	
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	
	initialize();

	scanf("%d", &t);
	for(i=1; i<=t; i++)
		printf("Case #%d: %d\n", i, solve());
	
	return 0;
}


