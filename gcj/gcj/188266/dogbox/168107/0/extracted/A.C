#include<vector>
#include<list>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
using namespace std;

const int MAX = 100000;

int n;
int base[10];
int memo[MAX][10];
bool viz[MAX][10];

string tostring(int x,int b){
    string s;
    while(x){
	s=char(x%b+'0')+s;
	x/=b;
    }
    return s;
}

bool happy(int x,int b){ // is x a happy number in base b?

    if(x==1) return 1;

    int &m=memo[x][b];
    if(viz[x][b]){
	if(m==-1)
	    return 0;
	else return m;
    }

    viz[x][b]=1;

    string s=tostring(x,b);
    int l=s.length();

    int nx=0;
    for(int i=0;i<l;i++){
	int k=s[i]-'0';
	nx+=k*k;
    }

    return m=happy(nx,b);

}

main(){

    memset(memo,-1,sizeof(memo));

    int T; scanf("%d\n",&T); for(int test=1;test<=T;test++){

	string s;
	getline(cin,s);

	n=0;
	stringstream ss(s);
	int x;
	while(ss>>x)
	    base[n++]=x;

	for(int i=2;;i++){
	    bool f=1;
	    for(int j=0;j<n;j++)
		if(!happy(i,base[j])){
		    f=0;
		    break;
		}
	    if(f){
		printf("Case #%d: %d\n",test,i);
		break;
	    }
	}

    }
}
