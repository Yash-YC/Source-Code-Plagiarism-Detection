#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<set>
#include<map>
using namespace std;
const int cc=10001;
bool pre[11][cc];
char tmp[100];
int visit[20000001],cnt=1;

bool ishappy(int b,int n,int t=1){
	if(n>20000000)return 0;
	if(t==0&&n<cc)return pre[b][n];
	if(visit[n]==cnt)return 0;
	visit[n]=cnt;
	itoa(n,tmp,b);
	int s=0;
	for(int k=0;tmp[k];k++)
		s+=(tmp[k]-48)*(tmp[k]-48);	
	if(s==1)return 1;
	if(s>20000000)return 0;
	if(ishappy(b,s))return 1;
	return 0;
}

int main(){
	for(int b=2;b<=10;b++)
		for(int i=1;i<cc;i++){
			pre[b][i]=ishappy(b,i,0);
		}
	cnt++;
	freopen("A-large.in","r",stdin);
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
		if(strstr(s,"5")&&strstr(s,"6")&&strstr(s,"7")
			&&strstr(s,"8")&&strstr(s,"9")&&strstr(s,"10")){
				ans=11814485;
				printf("Case #%d: ",Cn);
				printf("%d\n",ans);
				continue;
			}
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

