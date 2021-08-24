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

int c[41][41];

void makec(){
	memset(c,0,sizeof(c));
	for(int i=1;i<=10;i++){
		c[i][1]=i;c[i][i]=1;
	}
	for(int i=1;i<=10;i++){
		for(int j=2;j<=i;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
}

int main(){
	int tn;cin>>tn;
	makec();
	/*for(int i=0;i<41;i++){
		for(int j=0;j<41;j++)cout<<c[i][j]<<" ";cout<<endl;
	}*/
	for(int ttt=0;ttt<tn;ttt++){
		int C,n;cin>>C>>n;double ans=0.0;
		int tmpc=C;
		while(C>0){
			if(C>=n)ans+=((double)c[tmpc][n]/(double)c[C][n]);
			else{ans+=((double)c[tmpc][n]/(double)c[tmpc-C][n-C]);}
			C-=n;
		}
		printf("Case #%d: %.7f\n",(ttt+1),ans);
		//cout<<"Case #"<<(ttt+1)<<": "<<ans<<endl;
	}
}
