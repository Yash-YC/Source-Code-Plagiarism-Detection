#include<stdio.h>
#include<sstream>
using namespace std;

double ans[1024];
int c,n;

double getac(int v){
	if(ans[v]>-0.5) return ans[v];
	if(v==((1<<c)-1)) return 0;
	double &ret=ans[v];
	ret=0;
	int pnow=0;
	int num=0;
	for(int i=0;i<(1<<c);i++){
		int cnt=0;
		int v2=v;
		for(int j=0;j<c;j++){
			if(i&(1<<j)){
				v2|=1<<j;
				cnt++;
			}
		}
		
		if(cnt==n){
			if(v2==v){
				pnow++;
			}else{
				ret+=getac(v2)+1;
			}
			num++;
		}
	}
	ret/=num;
	double p=1.0*pnow/num;
	ret=(ret+p)/(1.0-p);
	return ret;
}

int main(){
	int T;
	scanf("%d\n",&T);
	for(int TT=1;TT<=T;TT++){		
		scanf("%d%d",&c,&n);
		//getac(0);
		for(int i=0;i<(1<<c);i++){
			ans[i]=-1;
		}
		printf("Case #%d: %.8lf\n",TT,getac(0));
	}
}