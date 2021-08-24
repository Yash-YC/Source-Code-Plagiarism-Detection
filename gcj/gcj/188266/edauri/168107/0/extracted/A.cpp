#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;
#define MAX 1000000
char eh[11][MAX];
int menor[10];

int bases[10];
int nbases;

int T,TT;

char chama(int b, long long int n) {
	if(n==1)
		return 1;
	if(n<MAX) {
		if(eh[b][n]!=-1)
			return eh[b][n];
		eh[b][n]=0;
	}
	long long int nn=0;
	long long int nnn=n;
	while(nnn!=0) {
		nn+=(nnn%b)*(nnn%b);
		nnn/=b;
	}
	if(chama(b,nn)==1) {
		if(n<MAX)
			eh[b][n]=1;
		return 1;
	}
	return 0;
}
int main(void) {
	cin >> TT;
	memset(eh,-1,sizeof(eh));
		string aux;
		getline(cin,aux);
		memset(eh,-1,sizeof(eh));

	for(T=1;T<=TT;T++) {
		getline(cin,aux);
		stringstream s1(aux);
		nbases=0;
		while(s1 >> bases[nbases++]);
		nbases--;

		int ans=0;
		for(int i=0;i<1000000;i++) {
			for(int j=2,k;;j++) {
				for(k=0;k<nbases;k++)
					if(chama(bases[k],j)==0)
						break;
				if(k==nbases) {
					ans=j;
					break;
				}
			}
			if(ans!=0)
				break;
		}
		printf("Case #%d: %d\n",T,ans);
	}

	return 0;
}
