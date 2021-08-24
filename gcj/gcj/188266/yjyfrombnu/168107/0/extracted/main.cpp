#include <stdio.h>
#include <string.h>
const int SIZE = 1000;
const int BASE = 11;
const int INF = 1<<25;
int dp[BASE][SIZE];
bool tmp[SIZE];
bool used[BASE];
void init();
bool check(int ,int );
int small(int ,int);
int work();
int main(){
	//freopen("../../dat.in","r",stdin);
	memset(dp,-1,sizeof(dp));
	int cas;
	scanf("%d",&cas);
	int i;
	for (i=1;i<=cas;i++){
		init();
		int ans = work();
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}
int work(){
	int i,j;
	for (i=2;i<INF;i++){
		bool ok=true;
		for (j=2;j<BASE;j++){
			if (used[j]){
				memset(tmp,false,sizeof(tmp));
				if (!check(i,j)){
					ok=false;
					break;
				}	
			}
		}
		if (ok){
			return i;
		}
	}
}
void init(){
	memset(used,false,sizeof(used));
	int pos;
	char ch;
	while (true){
		scanf("%d",&pos);
		used[pos]=true;
		if (scanf("%c",&ch)==EOF)
			break;
		if (ch=='\n')
			break;
	}
}
int small(int num,int base){
	int sum=0;
	while (num>0){
		int pos= num%base;
		sum+=(pos*pos);
		num/=base;
	}
	return sum;
}
bool check(int num,int base){
	if (num==1){
		return (dp[base][num]=1);
	}
	if (num<SIZE){
		if(dp[base][num]!=-1){
			return dp[base][num];
		}
		if (tmp[num]){
			return (dp[base][num]=0);
		}else{
			tmp[num]=true;
			int next = small(num,base);
			return (dp[base][num]=check(next,base));
		}
		
	}else{
		int next = small(num,base);
		return check(next,base);
	}
		
}