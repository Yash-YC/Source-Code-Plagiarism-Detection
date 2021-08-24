#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
#define SIZE 100000
int m[9][SIZE]={0};
int main() {
  int tcase,Tcase;
	int i,j,n,k,b,bb;
	int a[10];
	char s[1000];
	for (b=2;b<=10;b++){
		bb=b-2;
		m[bb][0]=2;
		m[bb][1]=1;
		for (i=2;i<SIZE;i++)
		if (!m[bb][i]){
			n=i;
			m[bb][n]=2;
		//	printf("%d:",i);
			do{
				k=0;
				while(n){
					k=k+(n%b)*(n%b);
					n/=b;
				}
				n=k;
			//	printf("%d ",n);
				if (n<SIZE){
					if (m[bb][n]==0) m[bb][n]=2;
					else break;
				}
			}while(1);
		//	printf("@%d\n",m[bb][n]);
			if (m[bb][n]==1){
				j=n;
				n=i;
				m[bb][n]=1;
				do{
					k=0;
					while(n){
						k=k+(n%b)*(n%b);
						n/=b;
					}
					n=k;
					if (n<SIZE) m[bb][n]=1;
				}while(n!=j);
			}
		}
	}
	scanf("%d\n",&Tcase);
	for (tcase=1;tcase<=Tcase;tcase++){
		printf("Case #%d: ",tcase);
		gets(s);
		stringstream ss(s);
		k=0;
		while(ss>>n){
			a[k++]=n-2;
		}
		for (i=2;i<SIZE;i++){
			for (j=0;j<k;j++)
			if (m[a[j]][i]!=1) break;
			if (j==k) break;
		}
		if (i==SIZE) fprintf(stderr,"ERROR");
		printf("%d\n",i);
	}
  return 0;
}
