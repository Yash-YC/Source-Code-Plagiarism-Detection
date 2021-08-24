#include<stdio.h>
#include<sstream>
using namespace std;
char ch[500];
/*bool v[50000000]={0};
bool fo[9][50000000];
bool gd[9][50000000];
int lst[50000000];

bool chk(int n,int b){
	//memset(v,0,sizeof(v));
	//v[n]=1;
	int tn=n;
	int l=0;
	while(!v[n] && !fo[b-2][n] && !gd[b-2][n]){
		lst[l++]=n;
		v[n]=1;
		int ret=0;
		while(n>0){
			int t=n%b;
			ret+=t*t;
			n/=b;
		}
		n=ret;
	}

	for(int i=0;i<l;i++){
		v[lst[i]]=0;
	}
	if(n==1 || gd[b-2][n]){
		for(int i=0;i<l;i++){
			gd[b-2][lst[i]]=1;
		}
		return 1;
	}

	for(int i=0;i<l;i++){
		fo[b-2][lst[i]]=1;
	}
	return 0;
}
*/
int ans[1024];

int main(){
	/*FILE *fout1=fopen("ans","a");
	for(int p=1;p<512;p++){
		printf("%d\n",p);
		memset(fo,0,sizeof(fo));
		memset(gd,0,sizeof(gd));
		int b[10];
		int n=0;
		for(int i=0;i<=8;i++){
			if(p&(1<<i)){
				b[n++]=i+2;
			}
		}
		for(int i=2;;i++){
			if(i>=50000000){
				printf("Error\n");
			}
			bool ok=1;
			for(int j=0;j<n;j++){
				if(!chk(i,b[j])){
					ok=0;
					break;
				}
			}
			if(ok){
				ans[p]=i;
				fprintf(fout1,"%d\n",i);
				fflush(fout1);
				//printf("Case #%d: %d\n",TT,i);
				break;
			}
		}
	}
	fclose(fout1);
	printf("OK\n");
	return 0;*/
	FILE *fin = fopen("ans","r");
	for(int i=1;i<512;i++){
		fscanf(fin,"%d",&ans[i]);
	}
	fclose(fin);
	//freopen("lout.txt","w",stdout);
	int T;
	scanf("%d\n",&T);
	for(int TT=1;TT<=T;TT++){
		gets(ch);
		istringstream is(ch);
		int b[10];
		int n=0;
		int t;
		int val=0;
		while(is>>t){
			val|=(1<<(t-2));
			//b[n++]=t;
		}
		printf("Case #%d: %d\n",TT,ans[val]);
	}
}