#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#define e 1e-8
#define SIZE 80
int c,n;
double pro;

double dfs(double a,char now[20],int level){
	int flag = 0;
	for(int i=0;i<c;i++){
		if(now[i] == '0'){
			flag = 1;
			break;
		}
	}
	if(flag == 0){
		return a * level;
	}
	if(a < e)return 0.0;

	char arr[20];
	for(int i=c-n;i<c;i++)
		arr[i] = '1';
	for(int i=0;i<c-n;i++)
		arr[i] = '0';
	a *= pro;
	double sum = 0.0;
	do{
		char ready[20];
		for(int i=0;i<c;i++)
			ready[i] = now[i];
		for(int i=0;i<c;i++)
			if(arr[i] == '1')ready[i] = '1';
		sum += dfs(a,ready,level + 1);
	}while(std::next_permutation(arr,arr+c));
	return sum;

}

double cx_n[SIZE + 1][SIZE + 1];
int main(){
	int t;
	scanf("%d",&t);
	for(int ca=0;ca<t;ca++){
		double count[SIZE + 1];
		scanf("%d %d",&c,&n);
		pro = 1.0;
		for(int i=0;i<n;i++){
			pro /= (c - i);
			pro *= (i + 1);
		}
		double k = 1.0;
		cx_n[0][0] = 1.0;
		for(int i=1;i<=SIZE;i++){	
			k *= 2.0;
			cx_n[i][0] = 1.0;
			for(int j=1;j<=i;j++){
				cx_n[i][j] = cx_n[i][j-1]*(i - j + 1) / (j);
			}
			for(int j = i + 1;j<=SIZE;j++){
				cx_n[i][j] = -1.0;
			}
		}
		double a = 1.0;
		for(int i=0;i<=SIZE;i++)
			count[i] = 0.0;
		count[0] = 1.0;
		double ans = 0.0;
		int step = 0;
		for(int u=0;u<1000;u++){
			step++;
			a *= pro;
			double next[SIZE + 1];
			for(int i=0;i<=SIZE;i++)
				next[i] = 0.0;
			for(int i=0;i<c;i++){
				for(int j=i;j<=i+n;j++){
					double tmp = (count[i] * cx_n[c-i][j-i] * cx_n[i][n-j+i]) * pro;
					if(n-j+i > i)tmp = 0.0;
					if(j-i > c-i)tmp = 0.0;
					if(j > c){
						next[c] += tmp;
					}else{
						next[j] += tmp;
					}
				}
			}
			for(int i=0;i<=SIZE;i++)
				count[i] = next[i];
			ans += count[c] * step;
		}
		printf("Case #%d: %lf\n",ca+1,ans);
	}
	return 0;
}
