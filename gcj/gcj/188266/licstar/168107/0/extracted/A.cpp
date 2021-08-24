#include<stdio.h>
#include<sstream>
using namespace std;
char ch[500];
bool v[1000000];
bool chk(int n,int b){
	memset(v,0,sizeof(v));
	//v[n]=1;
	while(!v[n]){
		v[n]=1;
		int ret=0;
		while(n>0){
			int t=n%b;
			ret+=t*t;
			n/=b;
		}
		n=ret;
	}
	if(n==1) return 1;
	return 0;
}

int main(){
	int T;
	scanf("%d\n",&T);
	for(int TT=1;TT<=T;TT++){
		gets(ch);
		istringstream is(ch);
		int b[10];
		int n=0;
		int t;
		while(is>>t){
			b[n++]=t;
		}
		for(int i=2;;i++){
			bool ok=1;
			for(int j=0;j<n;j++){
				if(!chk(i,b[j])){
					ok=0;
					break;
				}
			}
			if(ok){
				printf("Case #%d: %d\n",TT,i);
				break;
			}
		}
	}
}