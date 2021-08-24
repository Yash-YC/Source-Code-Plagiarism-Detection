#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int c,n,m,e,b[15],AC;
char s[1000];

int f(int x,int y){
	int k=0,p[100],S;
	char s[100];
	map<int,int> v;
	p[0]=1;
	k=0;
		while (p[k]<=1000000000) k++,p[k]=p[k-1]*y;
	v.clear();
		for (int i=k;i>=0;i--){
		s[i]=x/p[i];
		x-=s[i]*p[i];
		}
	S=0;
		for (int i=0;i<=k;i++) S+=s[i]*s[i];
	v[S]=1;
		while (!v[1]){
			for (int i=k;i>=0;i--){
			s[i]=S/p[i];
			S-=s[i]*p[i];
			}					
		S=0;
			for (int i=0;i<=k;i++) S+=s[i]*s[i];
			if (v[S]) break;
			else v[S]=1;			
		}
	return v[1];
}

int main(){
	scanf("%d%*c",&c);
	for (int k=1;k<=c;k++){
	gets(s);
	n=0;
	m=strlen(s);
		for (int i=0;i<m;i++){
			if (s[i]=='1') b[++n]=10;
			else if (s[i]>='2'&&s[i]<='9') b[++n]=s[i]-'0';
		}
	e=0;
		for (int i=2;!e;i++){
		e=1;
		AC=i;
			for (int j=1;j<=n&&e;j++)
				if (!f(i,b[j])) e=0;
		}
	printf("Case #%d: %d\n",k,AC);
	}
	return 0;
}
