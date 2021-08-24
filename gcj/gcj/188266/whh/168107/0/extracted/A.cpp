#include<cstdio>
#include<cstring>
int Z,z,i,j,N,p[10],b[10],n,q,l,t,ans[10],mn,cnt;
char c[1000];
bool ok;
short int a[11][5000005];
short int whh(int k){
	int t,s;
//if (i==10 && k<=100)	printf("%d %d\n",i,k);

	if (a[0][k]==1) return a[i][k] = -1;

	a[0][k] = 1;
	t = k;
	s = 0;

	while (t){
		s += (t%i)*(t%i);
		t/=i;
	}
	if (s<5000000){
		if (a[i][s]==0){
			t = whh(s);
			a[0][k] = 0;
			return a[i][k] = t;
		}else{
			a[0][k] = 0;
			return a[i][k] = a[i][s];
		}
	}


}


int main(){
/*	a[10][1]=1;i=10;whh(10);
	
	for (i=1;i<=100;++i){
		printf("%d %d\n",i,a[10][i]);
	}
	scanf("%d",&i);
*/	for (i=2;i<=10;++i){
		for (j=1;j<=5000000;++j) a[0][j] = 0;
		a[i][1] = 1;
		for (j=1;j<=500000;++j){
			whh(j);
//			whh2(j);
		}
	}

	
/*	for (i=1;i<=100;++i){
		printf("%d %d\n",i,a[10][i]);
	}
*/	scanf("%d",&Z);
	gets(c);
	for (z=1;z<=Z;++z){
		gets(c);
		l = strlen(c);
		n = 1;
		for (i=1;i<=9;++i) b[i] = 0;
		for (i=0;i<l;++i){
			if (c[i]==' ') ++n;
			else b[n] = (b[n]*10 + (c[i]-'0'));
		}
		for (i=1;i<=n;++i){
//			printf("%d\n",b[i]);
			ans[i]=2;
			while (a[b[i]][ans[i]]!=true){
				++ans[i];
			}
		}
		ok = false;
		while (!ok){
			mn = 2000000000;
			cnt = 0;
			for (i=1;i<=n;++i){
				if (ans[i]<mn){
					mn = ans[i];
					cnt = 1;
				}else if (ans[i]==mn) ++cnt;
			}

			if (cnt == n){
				ok = true;
				printf("Case #%d: %d\n",z,mn);
			}else{
				for (i=1;i<=n;++i){
					if (ans[i]==mn){
						++ans[i];
						while (a[b[i]][ans[i]]==-1) ++ans[i];
					}
				}
			}
			
		}

		
	
	}


	return 0;
}
