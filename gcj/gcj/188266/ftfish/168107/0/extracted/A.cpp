#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<set>
#include<map>
using namespace std;
const int mn=1000001;
bool f[11][1000001];
char tmp[100];
int visit[1000000],cnt=1;

bool ishappy(int b,int n){
	if(n<1000000&&visit[n]==cnt)return 0;
	visit[n]=cnt;
	itoa(n,tmp,b);
	int s=0;
	for(int k=0;tmp[k];k++)
		s+=(tmp[k]-48)*(tmp[k]-48);	
	if(s==1)return 1;
	if(s>10000000)return 0;
	if(ishappy(b,s))return 1;
	return 0;
}

int main(){
//	for(int i=2;i<=10;i++){
//		f[i][1]=1;
//		for(int j=2;j<mn;j++){
//			itoa(j,tmp,i);
//			s=0;
//			for(int k=0;tmp[k];k++)
//				s+=(tmp[k]-48)*(tmp[k]-48);
//			if(s)
//		}
//	}
	freopen("a.in","r",stdin);
	freopen("out.txt","w",stdout);
	int Tn;
	scanf("%d\n",&Tn);
	char s[100];
	for(int Cn=1;Cn<=Tn;Cn++){
		gets(s);
		istringstream sin(s);
		int n=0,b[100];
		while(sin>>b[n])n++;
		int ans=2;
		memset(visit,0,sizeof(visit));
		while(1){
			bool f=1;
			for(int i=0;i<n&&f;i++){
				if(!ishappy(b[i],ans))f=0;
				cnt++;
			}
			if(f)break;
			ans++;
		}
		
		printf("Case #%d: ",Cn);
		printf("%d\n",ans);
	}
	return 0;
}

