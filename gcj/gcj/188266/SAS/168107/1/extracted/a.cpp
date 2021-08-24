#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define SIZE 50000000
int base[9];
char accept[9][SIZE];
int used[9];

int compute(int n,int index){
	int b = base[index];
	if(used[index] < n)
		used[index] = n;
	if(n >= SIZE){
		printf("n = %d overflow\n",n);
		return 1;
	}
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
	int count = 9;
	for(int i =0;i<count;i++)
		used[i] = SIZE;
	for(int ca = 0;ca<t;ca++){
		for(int i=0;i<count;i++)
			memset(accept[i],0xff,used[i] + 1);
		count = 0;
		{
			char c;
			while(scanf("%d%c",&base[count++],&c) && c != '\n');
			if(base[0] == 2){
				count--;
				for(int i=0;i<count;i++)
					base[i] = base[i+1];
			}
		}
		for(int i =0;i<count;i++)
			used[i] = 0;
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
