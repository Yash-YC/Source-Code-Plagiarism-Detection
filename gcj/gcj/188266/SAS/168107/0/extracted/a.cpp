#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
int base[9];
char accept[9][10000000];

int compute(int n,int index){
	int b = base[index];
	if(n == 1){return (accept[index][n] = 1);}
	if(accept[index][n] == 2)return (accept[index][n] = 0);
	if(accept[index][n] != -1)return accept[index][n];
	accept[index][n] = 2;
	int sum = 0;
	int tmpn = n;
	while(n != 0){
		int tmp = n % b;
		sum += (tmp * tmp);
		n /= b;
	}
	return (accept[index][tmpn] = compute(sum,index));
}

int main(){
	int t;
	scanf("%d",&t);
	for(int ca = 0;ca<t;ca++){
		int count = 0;
		{
			char c;
			while(scanf("%d%c",&base[count++],&c) && c != '\n');
			if(base[0] == 2){
				count--;
				for(int i=0;i<count;i++)
					base[i] = base[i+1];
			}
		}
		memset(accept,0xff,sizeof(accept));
		int n = 2;
		while(1){
			int flag = 1;
			for(int i=0;i<count;i++){
				if(compute(n,i) == 0){
					flag = 0;
					break;
				}
			}
			if(flag == 1)break;
			n++;
		}
		printf("Case #%d: %d\n",ca+1,n);
	}
	return 0;
}
