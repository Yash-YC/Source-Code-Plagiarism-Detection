#include <stdio.h>

inline int minn(int &a,int b){
	if(b<a)
		a=b;
}

inline int fn(int st,int s,int w,int t){
	int stm=st%(s+w);
	t%=(s+w);
	if(t==0){
		if(stm<s)
			return st;
		else
			return st+(s+w)-stm;
	}
	else if(t==w){
		if(stm>=s)
			return st;
		else
			return st+w-stm;
	}
	else if(t<w){
		if(stm>=t && stm<t+s)
			return st;
		else if(stm<t)
			return st+t-stm;
		else
			return st+w-(stm-(t+s));
	}
	else{
		if(stm<t-w)
			return st;
		else if(stm>=t)
			return st;
		else
			return st+t-stm;
	}
}

inline int fw(int st,int s,int w,int t){
	int stm=st%(s+w);
	t%=(s+w);
	if(t==0){
		if(stm<s){
		//	printf("fw %d %d %d %d re %d\n",st,s,w,t,st+s-stm);
			return st+s-stm;
		}
		else
			return st;
	}
	else if(t==w){
		if(stm>=w)
			return st+(s+w)-stm;
		else
			return st;
	}
	else if(t<w){
		if(stm>=t && stm<t+s)
			return st+t+s-stm;
		else if(stm<t)
			return st;
		else
			return st;
	}
	else{
		if(stm<t-w)
			return st+t-w-stm;
		else if(stm>=t)
			return st+s-(stm-t);
		else
			return st;
	}
}

int main(){
	int ecase,ecount;
	int er,ec;
	int es[30][30],ew[30][30],et[30][30];
	int dp[100][100];
	int i,j;
	scanf("%d",&ecase);
	for(ecount=1;ecount<=ecase;ecount++){
		scanf("%d%d",&er,&ec);
		for(i=0;i<er;i++)
			for(j=0;j<ec;j++)
				scanf("%d%d%d",&es[i][j],&ew[i][j],&et[i][j]);
		for(i=0;i<er*2;i++)
			for(j=0;j<ec*2;j++)
				dp[i][j]=999999999;
		dp[0][0]=0;
		for(i=0;i<=er*2-1;i++)
			for(j=0;j<=ec*2-1;j++){
				if(i<er*2-1){
					if(i%2==0){
						minn(dp[i+1][j], fn(dp[i][j],es[i/2][j/2],ew[i/2][j/2],et[i/2][j/2])+1);
					}
					else{
						minn(dp[i+1][j],dp[i][j]+2);
					}
				}
				if(j<ec*2-1){
					if(j%2==0){
						minn(dp[i][j+1], fw(dp[i][j],es[i/2][j/2],ew[i/2][j/2],et[i/2][j/2])+1);
					}
					else{
						minn(dp[i][j+1],dp[i][j]+2);
					}
				}
			}
		printf("Case #%d: %d\n",ecount,dp[er*2-1][ec*2-1]);
/*		for(i=0;i<2*er;i++){
			for(j=0;j<2*ec;j++)
				printf("%d\t",dp[i][j]);
			printf("\n");
		}*/

	}
	return 0;
}
