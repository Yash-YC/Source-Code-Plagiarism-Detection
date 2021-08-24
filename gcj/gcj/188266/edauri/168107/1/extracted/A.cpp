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

char chama(long long int b, long long int n) {
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
int melhor[1<<12];
int main(void) {
	cin >> TT;
	memset(melhor,0x3F,sizeof(melhor));
	memset(eh,-1,sizeof(eh));
	string aux;
	getline(cin,aux);
	memset(eh,-1,sizeof(eh));


	for(int j=2,k;j<=11814485;j++) {
		int bit=0;
		for(k=2;k<=10;k++)
			if(chama(k,j)==1)
				bit+=1<<k;
		for(int bit2=bit;bit2>0;bit2=(bit2-1)&bit)
			melhor[bit2]=min(melhor[bit2],j);
		if(bit==(1<<11)-1 -(1<<0) - (1<<1)) {
			break;
		}
	}

	for(T=1;T<=TT;T++) {
		getline(cin,aux);
		stringstream s1(aux);
		nbases=0;
		int base;
		int bit=0;
		while(s1 >> base)
			bit+=1<<base;

		printf("Case #%d: %d\n",T,melhor[bit]);
	}

	return 0;
}
