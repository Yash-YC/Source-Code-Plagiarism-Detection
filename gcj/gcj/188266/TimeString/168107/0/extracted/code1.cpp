#include <stdio.h>

int ans[10000000][10];

int ask(int n,int b){
	if(n==1)
		return 2;
	else if(ans[n][b]==3)
		return 1;
	else if(ans[n][b]==0){
		ans[n][b]=3;
		int array[100],amany;
		int tn;
		tn=n;
		amany=0;
		while(tn>0){
			array[amany++]=tn%b;
			tn/=b;
		}
		tn=0;
		for(int i=0;i<amany;i++){
			tn+=array[i]*array[i];
		}
		ans[n][b]=ask(tn,b);
	}
	return ans[n][b];
}

int main(){
	char input[10000];
	int base[10],bmany;
	int ecase,ecount;
	int i,j;
	int t;
/*
	for(i=2;i<10000000;i++){
		int tcount=0;
		//printf("i=%8d   ",i);
		for(j=2;j<=10;j++){
			if(ask(i,j)==2)
				tcount++;
		//	if(ask(i,j)==2)
		//		printf("o ");
		//	else
		//		printf("x ");
		}
		//printf("\n");
		//if(i%10000==0)
		//	printf("i=%d\n",i);
		if(tcount==9)
			break;
	}
*/
	scanf("%d",&ecase);
	gets(input);

	for(ecount=1;ecount<=ecase;ecount++){
		gets(input);
		bmany=0;
		for(i=0;input[i];i++){
			if(input[i]=='1')
				base[bmany++]=10;
			else if('2'<=input[i] && input[i]<='9')
				base[bmany++]=input[i]-'0';
		}

		for(i=2;;i++){
			int tcount=0;
			for(j=0;j<bmany;j++)
				if(ask(i,base[j])==2)
					tcount++;
			if(tcount==bmany)
				break;
		}
		printf("Case #%d: %d\n",ecount,i);
	}
	return 0;
}
