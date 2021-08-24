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

const int MAX=11;
double res[MAX][MAX];

main(){

    FILE *file=fopen("t","r");
    int C,N;
    double R;
    while(fscanf(file,"%d %d %lf",&C,&N,&R)!=EOF){
	res[C][N]=R;
    }

    int T; scanf("%d",&T); for(int test=1;test<=T;test++){

	int c,n; scanf("%d %d",&c,&n);
	printf("Case #%d: ",test);

	// assume c>n, otherwise expected number is 1

	if(c<=n)
	    printf("1\n");
	else{
	    printf("%.7lf\n",res[c][n]);
	}
    }
}
