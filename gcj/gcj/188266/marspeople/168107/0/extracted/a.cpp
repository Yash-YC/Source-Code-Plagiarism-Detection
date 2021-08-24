#include <cstdio>
#include <cstring>
#define LIM 100000

char l[1000],v[20];
bool us[100001];

bool check(int x, int b) {
	memset(us,0,sizeof(us));
	
	while (x!=1 && !us[x]) {
		us[x]=true;
		int x2=x;
		x=0;
		
		while (x2>0) {
			int d=x2%b;
			x+=d*d;
			x2/=b;
		}
	}
	
	if (x==1) return true;
	return false;
}

int main() {
	int nt;
	
	scanf(" %d",&nt);
	gets(l);
	for (int ct=1; ct<=nt; ct++) {
		int n=0;
		memset(l,0,sizeof(l));
		gets(l);
		
		char *pl=l;
		int x;
		
		while (sscanf(pl," %d",&x)==1) {
			v[n++]=x;
			if (x==10) pl+=3;
			else pl+=2;
		}
		
		int res=-1;
		for (int i=2; i<=LIM; i++) {
			bool deu=true;
			for (int j=0; j<n; j++) if (!check(i,v[j])) {
				deu=false;
				break;
			}
			if (deu) {
				res=i;
				break;
			}
		}
				
		printf("Case #%d: %d\n",ct,res);
	}
	
	return 0;
}
		
