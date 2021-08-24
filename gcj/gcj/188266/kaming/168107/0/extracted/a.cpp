#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<map>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

using namespace std;

bool dp[100000];
bool dp2[100000];

int chh(int num,int base){
	memset(dp,0,sizeof(dp));
	while(1){
		if(dp[num]==1)return 0;
		if(num==1)return 1;
		dp[num]=1;int tmp=0;
		while(num!=0){tmp+=(num%base)*(num%base);num/=base;}
		num=tmp;
	}
}

int main(){
	int tn;scanf("%d ",&tn);
	for(int ttt=0;ttt<tn;ttt++){
		char str[40]={0};gets(str);
		int nums[12]={0};int numsnum=0;int tmp=0;
		for(int i=0;str[i];i++){
			if(str[i]==' '){
				nums[numsnum++]=tmp;tmp=0;
			}
			else{
				tmp*=10;tmp+=(str[i]-'0');
			}
		}
		nums[numsnum++]=tmp;tmp=0;
		memset(dp2,0,sizeof(dp2));
		//for(int i=0;i<numsnum;i++)cerr<<nums[i]<<" ";cout<<endl;
		for(int i=2;;i++)if(dp2[i]==0){
				//cout<<i<<endl;
			int ok=1;
			for(int j=0;j<numsnum;j++){
				int tp=chh(i,nums[j]);
				if(tp==0)for(int k=i;k<100000;k*=nums[j])dp2[k]=1;
				ok&=tp;
			}
			if(ok==1){
				cout<<"Case #"<<(ttt+1)<<": "<<i<<endl;
				break;
			}
		}
	}
	return 0;
}
