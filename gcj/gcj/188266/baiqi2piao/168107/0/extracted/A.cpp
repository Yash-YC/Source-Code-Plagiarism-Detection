//poj 

#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<math.h>
#include<vector>
#include<set>
#include<queue>

using namespace std;
typedef long long llt;

#define maxv 5010

#define LEN 200
#define myAbs(x) ((x)>=0?(x):-(x))
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define inf 1999999999
#define MOD 200039
#define eps 1e-8
#define EPS 1e-8
#define M_PI 3.14159265358979323846


int n;
char str[LEN];
int slen;
int base[10];
int len;
int ttt;
int bbb[20];
int blen;
char flag[100000];

int con(int x ,int m){
	int i;
	blen=0;
	while(x){
		bbb[blen++]= x%m;
		x/= m;
	}
}
int test(int x){
	int i,j,k;
	int xx=x;
	for(k=0;k<len;++k){
		xx=x;
		memset(flag, 0, sizeof(flag));
		while(xx!=1){
			if(!flag[xx])
				flag[xx]=1;
			else
				return 0;
			con(xx, base[k]);
			/*
			blen=0;
			while(xx){
				bbb[blen++]= xx%m;
				xx/= m;
			}*/
			
			xx=0;
			for(i=0;i<blen;++i){
				xx += bbb[i]*bbb[i];
			}
		}
	}
	return 1;
}
void solve(){
	int i,j,k;
	int tmp;
	gets(str);
	slen=strlen(str);
	len=0;
	for(i=0;i<slen;++i){
		if(str[i]>='0' && str[i]<='9'){
			tmp = str[i]-'0';
			if(str[i+1]>='0' && str[i+1]<='9'){
				tmp *= 10;
				tmp += str[i+1]-'0';
				++i;
			}
			base[len++]=tmp;
		}
	}
	//for(i=2;i<400;++i){
	for(i=2;;++i){
		if(test(i))
			break;
	}
	
	printf("Case #%d: %d\n",++ttt, i);
}
int main(){
	//freopen("out.txt","w",stdout);
	int t;
	scanf("%d", &t);
	while(getchar()!='\n');
	ttt=0;
	while(--t>=0)
		solve();
	//system("PAUSE");
	return 0;
}



/*
388
2 3
2 3 7
9 10

*/
