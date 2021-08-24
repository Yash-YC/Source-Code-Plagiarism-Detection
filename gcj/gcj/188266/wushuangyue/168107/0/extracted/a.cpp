 #include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <sstream>


using namespace std;

#define rep(i,n) for(i=0;i<(n);i++)
#define foru(i,a,b) for(i=(a);i<=(b);i++)
#define ford(i,a,b) for(i=(a);i>=(b);i--)

int n;
char s[1000];
int num[20];
int tot;
int ans;

const int maxn=50000000;
int b[maxn];
int number;

int c[100];

bool check(int ans , int base){
	int i,j,k,len;
	number++;
	b[ans]=number;
	while (1) {
		len=0;
		while (ans>0) {
			len++;
			c[len]=ans % base;
			ans=ans/base;
		}
		ans=0;
		foru(i,1,len) ans=ans + c[i]*c[i];
		if (ans==1) return true;
		if (b[ans]==number) return false;
		b[ans]=number;
	}
}

int main(){
    freopen("a.in","r",stdin);
	freopen("output.txt","w",stdout);
    int i,j,k,test,cases=0;
    scanf("%d\n",&test);
    memset(b,0,sizeof(b));
    number=0;
    while (test){
		test--;
		gets(s);
		tot=0;
		int len=strlen(s);
		i=0;
		while (i<len) {
			while (i<len && !isdigit(s[i])) i++;
			if (i>=len) break;
			tot++;
			num[tot]=0;
			while (i<len && isdigit(s[i])) {
				num[tot]=num[tot]*10 + s[i]-'0';
				i++;
			}
		}
		ans=1;
		cases++;
		printf("Case #%d: ",cases);
		while (1) {
			ans++;
			if (ans>=maxn) {
				printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");	
				break;
			}
			bool flag=true;
			ford(i,tot,1) if (!check(ans,num[i])) {
				flag=false;
				break;
			}
			if (flag) break;
		}
		printf("%d\n",ans);
	}
    
    
    return 0;
}
    
