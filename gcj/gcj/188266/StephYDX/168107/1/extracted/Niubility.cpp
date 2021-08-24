//#include <cstdio>
//#include <cstring>
//long long cb[41][41];
//void CB(){
//	memset(cb,0,sizeof(cb));
//	cb[0][0]=1;
//	for(int i=1;i<=40;++i){
//		cb[i][0]=cb[i][i]=1;
//		for(int j=1;j<i;++j) cb[i][j]=cb[i-1][j]+cb[i-1][j-1];
//	}
//}
//double dp[41];
//int main(){
//	freopen("C-large.in","r",stdin);
//	freopen("out.txt","w",stdout);
//	CB();
//	int T;
//	scanf("%d",&T);
//	for(int cas=1;cas<=T;++cas){
//		int n,m;
//		scanf("%d %d",&n,&m);
//		memset(dp,0,sizeof(dp));
//		dp[m]=1;
//		double ans=dp[n],pp=dp[n];
//		for(int L=2;pp<1-1e-9;++L){
//			dp[n]=0;
//			for(int i=n;i>=m;--i){
//				dp[i]=dp[i]*cb[i][m]/cb[n][m];
//				for(int j=1;j<=m;++j){
//					dp[i]+=dp[i-j]*cb[i-j][m-j]*cb[n-i+j][j]/cb[n][m];
//				}
//			}
//			ans+=dp[n]*L;
//			pp+=dp[n];
//		}
//		printf("Case #%d: %f\n",cas,ans);
//	}
//	return 0;
//}

#include <cstdio>
#include <cstring>
const int Max=15000000,Max2=1000;
int calc(int n,int b){
	int res=0,d;
	for(;n;n/=b){
		d=n%b;
		res+=d*d;
	}
	return res;
}
bool valid[9][Max];
bool vst[Max2];
void init(){
	memset(valid,0,sizeof(valid));
	for(int b=2;b<=10;++b){
		for(int i=1;i<Max2;++i){
			int tmp=i;
			memset(vst,0,sizeof(vst));
			while(tmp!=1&&!vst[tmp]){
				vst[tmp]=true;
				tmp=calc(tmp,b);
			}
			valid[b-2][i]=(tmp==1);
		}
		for(int i=Max2;i<Max;++i){
			valid[b-2][i]=valid[b-2][calc(i,b)];
		}
	}
}
char s[100];
int bs[10],nb;
int main(){
	init();
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T=0;
	scanf("%d",&T);gets(s);
	for(int cas=1;cas<=T;++cas){
		gets(s);
		nb=0;
		for(int i=0;s[i];++i){
			if(s[i]=='1') bs[nb++]=10;
			else if('2'<=s[i]&&s[i]<='9') bs[nb++]=s[i]-'0';
		}
		int ans=-1;
		for(int i=2;i<Max;++i){
			bool ok=true;
			for(int j=0;j<nb&&ok;++j) if(!valid[bs[j]-2][i]) ok=false;
			if(ok){ans=i;break;}
		}
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}
