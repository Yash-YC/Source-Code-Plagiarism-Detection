#include<cstdio>
#include<cstring>
#include<cmath>
#define eps 1e-8
#define maxa 2000000000


int s[22][22],w[22][22],t[22][22];
int tt[80][80];
int n,m;
int main(){
	int nn;
	scanf("%d",&nn);
	for(int ii=1;ii<=nn;ii++){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)for(int j=0;j<m;j++){
			scanf("%d%d%d",&s[i][j],&w[i][j],&t[i][j]);
			
				//s[i][j]-=1;
				//w[i][j]+=1;
				while(t[i][j]>0)t[i][j]-=s[i][j]+w[i][j];
		}
		for(int i=0;i<2*n+4;i++)for(int j=0;j<2*m+4;j++)tt[i][j]=maxa;
		tt[2][2]=0;
		int did=1;
		int tm,tc;
		while(did){
			did = 0;
			for(int i=2;i<2*n+2;i++){
				for(int j=2;j<2*m+2;j++){
					tm = tt[((i+1)^1)-1][j]+2;
					if(tm<tt[i][j]){tt[i][j]=tm;did=1;}
					tm = tt[i][((j+1)^1)-1]+2;
					if(tm<tt[i][j]){tt[i][j]=tm;did=1;}
					
					{
						tc = tt[i^1][j];
						int ss = s[(i-2)/2][(j-2)/2];
						int ww = w[(i-2)/2][(j-2)/2];
						int ttt = t[(i-2)/2][(j-2)/2];
						int wi = (tc - ttt)%(ss+ww);
						//printf(" %d-%d, %d %d %d %d",i^1,j,ss,ww,ttt,wi);
						if(ss>=1){
							if(wi<=ss-1){
								tm = tc + 1;
							}else{
								tm = tc + 1 + (ss+ww-wi);
							}
						//printf(" w %d\n",tm);
							if(tm<tt[i][j]){tt[i][j]=tm;did=1;}
						}
					}
					
					{
					tc = tt[i][j^1];
					int ss = s[(i-2)/2][(j-2)/2];
					int ww = w[(i-2)/2][(j-2)/2];
					int ttt = t[(i-2)/2][(j-2)/2];
					int wi = (tc - ttt)%(ss+ww);
					if(ww>=1){
					if(wi>=ss){
						tm = tc + 1;
					}else{
						tm = tc + 1 + (ss-wi);
					}
					if(tm<tt[i][j]){tt[i][j]=tm;did=1;}
					}
					}
				}
			}
		}
		printf("Case #%d: %d\n",ii, tt[2*n+1][2*m+1]);
	}
	return 0;
}
