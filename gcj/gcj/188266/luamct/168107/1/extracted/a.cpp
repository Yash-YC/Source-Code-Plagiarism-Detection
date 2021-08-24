
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

#define FORI(a) for(int i=0;i<a;i++)
#define FORJ(a) for(int j=0;j<a;j++)
#define FORK(a) for(int k=0;k<a;k++)

int
f(int n , int rdx)
{
	int k = 0,m;
	
	while(n){
		m = n % rdx;  /* m is least significant digit */ 
		n = n / rdx;
		k += m*m;
	}
	return k;
}


bool isHappy(int n, int rdx)
{
	int j,old_n,loops=10;
	while(true){
		old_n = n;
		for(j=loops;j>0;j--)
			if((n = f(n,rdx))== old_n)break;
		if(n==old_n)break;
		loops += 10;
	}
	return n == 1 ? true : false;
}


int main() {
	int cases;
	scanf("%d\n", &cases);
	int size=0, m, n;
	int bases[10];
	FORI(cases)
	{
		size=0;
		while (true) {
			scanf("%d", bases+size++);
			if (getc(stdin)=='\n') break;
		}
		
		int small=1;
label:
			small++;
			FORK(size) {
				if (!isHappy(small, bases[k])) {
					goto label;
				}
			}
		
		///////////////////////////
		cout << "Case #" << (i+1) << ": " << small << endl;
	}
}