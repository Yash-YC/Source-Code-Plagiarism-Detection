#include<stdio.h>

 double bin[41][41];
 double from[41],to[41];

void bingen(){
	int i,j;
	for(i=0;i<=40;i++)bin[i][0]=1.0;
	for(i=0;i<=40;i++)bin[i][i]=1.0;
	for(i=1;i<=40;i++)for(j=1;j<i;j++){
		bin[i][j]=bin[i-1][j]+bin[i-1][j-1];
	}
}

int main(){
	int k,i,j,l,t,count,c,n;
	double ans;
	scanf("%d",&t);
	bingen();
	for(l=0;l<t;l++){
		scanf("%d%d",&c,&n);
		ans=1.0;
		for(i=0;i<=40;i++)from[i]=0.0;
		from[c]=1.0;
		for(count=1;count<100000;count++){
			for(i=0;i<=c;i++)to[i]=0.0;
			for(i=0;i<=c;i++)
				for(j=0;j<=i;j++){
					if(n<i-j) continue;
					to[j]+=from[i]*(bin[i][i-j]*bin[c-i][n-(i-j)])/(bin[c][n]);
				}
			for(i=0;i<=c;i++)from[i]=to[i];
//			for(i=0;i<=c;i++)printf("%f ",from[i]);
//			printf("\n");
			ans += (1.0-from[0]);
		}
		printf("Case #%d: %.7f\n",l+1, ans);
	}
}
