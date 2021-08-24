#include<cstdio>
#include<sstream>
#include<set>

using namespace std;

int gcd(int a,int b){return !b?a:gcd(b,a%b);}

int T,tmp,ans,len;
int xl[1000];
char s[10000];

bool calc(int a,int b){
	set<int> hash;
	while (a>1){
		int tmp=0;
		while (a) tmp+=(a%b)*(a%b),a/=b;
		if (hash.find(tmp)!=hash.end()) return false;
		hash.insert(tmp);
		a=tmp;
	}
	return a==1;
}

int i,j,I;

int main(){
	scanf("%d",&T);gets(s);
	while (T--){
		gets(s);
		istringstream in(s);
		len=0;
		while (in>>tmp) xl[len++]=tmp;
		for (i=2;;++i){
			for (j=0;j<len;++j)
				if (!calc(i,xl[j])) break;
			if (j==len) break;
		}
		printf("Case #%d: %d\n",++I,i);
	}
}
