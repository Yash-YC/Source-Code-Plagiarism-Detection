#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std; 
int a[101*101],ans[101];
int main(){
	int T;
	freopen("B-large.in.txt","r",stdin);
	freopen("B-large.in.out","w",stdout);
	scanf("%d",&T);
	for (int cases=1;cases<=T;cases++){
		int n,m=0;
		scanf("%d",&n);
		for (int i=1;i<2*n;i++)
			for (int j=1;j<=n;j++)
				scanf("%d",&a[++m]);
		sort(a+1,a+1+m);
		int p=0;
		n=0;
		a[0]=-1; 
		for (int i=1;i<=m;i++){ 
			if (a[i]==a[i-1]){
				p++;
				continue;
			} 
			if (p%2==1)
				ans[++n]=a[i-1];  
			p=1;
		}
		if (p%2==1)
			ans[++n]=a[m];  
		sort(ans+1,ans+1+n);
		printf("Case #%d: ",cases);
		for (int i=1;i<=n;i++)
			printf("%d ",ans[i]);
		puts("");
	}
}