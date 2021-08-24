#include <stdio.h>
int N,C;

inline int bitCount(int x){
	int count=0;
	while(x){
		count+=x&1;
		x>>=1;
	}
	return count;
}

double cache[1<<10];
double getExpected(int owned){
	if(cache[owned]>=0){
		return cache[owned];
	}
	if(owned==((1<<C)-1)){
		return cache[owned]=0;
	}
	double sumNonSubsets=0;
	double numNonSubsets=0;
	double sumSubsets=0;
	double total=0;
	
	for(int i=0;i<(1<<C);++i)if(bitCount(i)==N){
		total+=1;
		if((i|owned)==owned){//i is subset of owned
			sumSubsets+=1;
		}else{
			sumNonSubsets+=1+getExpected(owned|i);
			numNonSubsets+=1;
		}
	}
	sumSubsets/=total;
	sumNonSubsets=sumNonSubsets/=total;
	cache[owned]=(sumSubsets+sumNonSubsets)/(1-sumSubsets);
	return cache[owned];
}

int main(){
	int T;
	scanf("%d\n", &T);
	for(int caseNum=1;caseNum<=T;++caseNum){
		scanf("%d%d", &C, &N);		
		for(int i=0;i<(1<<C);++i){
			cache[i]=-1;
		}
		double sol=getExpected(0);
		printf("Case #%d: %lf\n",caseNum, sol);
	}
	return 0;
}
